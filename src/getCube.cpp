
#include <opencv2/opencv.hpp>
#include "getCube.hpp"
#include <algorithm>

#define DEBUG

void cubedetector::findCube(const cv::Mat &src, std::vector<cv::RotatedRect> &RRect_previous_v)
{
	src.copyTo(frame);
	cv::cvtColor(src, gray, CV_BGR2GRAY);
	cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0, 0);
	cv::adaptiveThreshold(gray, gray, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 11, 1);
	cv::medianBlur(gray, gray, 3);

#ifdef DEBUG
	cv::imshow("afterProcess", gray);
#endif

	cv::findContours(gray, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	for (size_t i = 0; i < contours.size(); ++i)
	{
		cv::RotatedRect RRect = cv::minAreaRect(contours[i]);
		adjustRRect(RRect);
		float ratio_cur = RRect.size.width / RRect.size.height;
		float angle = RRect.angle;
		float RRect_area = RRect.size.area();
		float contour_area = cv::contourArea(contours[i]);
		if (ratio_cur > 0.8 && ratio_cur < 1.2 &&
			angle > -20 && angle < 20 &&
			RRect.size.width > 10 && RRect.size.width < frame.cols / 5)
		{
			RRect_previous_v.push_back(RRect);
		}
	}
}

void cubedetector::filterCube(std::vector<cv::RotatedRect> &RRect_previous_v, std::vector<cv::RotatedRect> &RRect_result_v)
{
	if (RRect_previous_v.size() <= 15 && RRect_previous_v.size() > 9)
	{

#ifdef DEBUG
		std::cout << "before: " << RRect_previous_v.size();
#endif

		noiseReduction(RRect_previous_v, 5, "width");

#ifdef DEBUG
		std::cout << "  width: " << RRect_previous_v.size();
#endif

		noiseReduction(RRect_previous_v, 3, "angle");

#ifdef DEBUG
		std::cout << "  angle: " << RRect_previous_v.size();
#endif

		if (RRect_previous_v[0].size.width >= 20)
		{
			noiseReduction(RRect_previous_v, (3500/42)*RRect_previous_v[0].size.width-3500/3, "x");

#ifdef DEBUG
		std::cout << "  x: " << RRect_previous_v.size();
#endif

			noiseReduction(RRect_previous_v, (3500/42)*RRect_previous_v[0].size.width-3500/3, "y");

#ifdef DEBUG
		std::cout << "  y: " << RRect_previous_v.size();
#endif
		}

/*
		noiseReduction(RRect_previous_v, RRect_previous_v[0].size.width < 20 ? 
			5*RRect_previous_v[0].size.width*RRect_previous_v[0].size.width-100*RRect_previous_v[0].size.width+500 : 
			(3500/42)*RRect_previous_v[0].size.width-3500/3, "x");

		noiseReduction(RRect_previous_v, RRect_previous_v[0].size.width < 20 ? 
			5*RRect_previous_v[0].size.width*RRect_previous_v[0].size.width-100*RRect_previous_v[0].size.width+500 : 
			(3500/42)*RRect_previous_v[0].size.width-3500/3, "y");
*/

		if (RRect_previous_v.size() > 9)
		{
			float dist_map[15][15] = { 0 };

			for (int i = 0; i < RRect_previous_v.size(); ++i)
			{
				for (int j = i + 1; j < RRect_previous_v.size(); ++j)
				{
					float d = (RRect_previous_v[i].center.x - RRect_previous_v[j].center.x)*(RRect_previous_v[i].center.x - RRect_previous_v[j].center.x) + 
						(RRect_previous_v[i].center.y - RRect_previous_v[j].center.y) * (RRect_previous_v[i].center.y - RRect_previous_v[j].center.y);
					dist_map[i][j] = d;
					dist_map[j][i] = d;
				}
			}

			int center_idx = 0;
			float min_dist = 100000000;
			for (int i = 0; i < RRect_previous_v.size(); ++i)
			{
				float cur_d = 0;
				for (int j = 0; j < RRect_previous_v.size(); ++j)
				{
					cur_d += dist_map[i][j];
					if (cur_d < min_dist)
					{
						min_dist = cur_d;
						center_idx = i;
					}
				}
			}

			std::vector<std::pair<float, int> > dist_center;
			for (int j = 0; j < RRect_previous_v.size(); ++j)
			{
				dist_center.push_back(std::make_pair(dist_map[center_idx][j], j));
			}

			std::sort(dist_center.begin(), dist_center.end(), [](const std::pair<float, int> &p1, const std::pair<float, int> &p2) {return p1.first < p2.first;});
			if (RRect_previous_v.size() >= 9)
			{
				for (int i = 0; i < 9; ++i)
				{
					RRect_result_v.push_back(RRect_previous_v[dist_center[i].second]);
				}
			}
			else
			{
				for (int i = 0; i < RRect_previous_v.size(); ++i)
				{
					RRect_result_v.push_back(RRect_previous_v[dist_center[i].second]);
				}
			}
		}
		else
		{
			RRect_result_v = RRect_previous_v;
		}
	}
	else
	{
		return;
	}

#ifdef DEBUG
	std::cout << "  Before filter: " << RRect_previous_v.size() << "  After filter: " << RRect_result_v.size() << std::endl;
#endif

}

void cubedetector::drawResult(cv::Mat &frame, std::vector<cv::RotatedRect> &RRects, std::vector<double> &angleSolverResult)
{
#ifdef DEBUG
	int counter = 0;
	for (auto &RRect_single : RRects)
	{
		cv::Point2f points_[4];
		RRect_single.points(points_);
		for (int i = 0; i < 4; ++i)
		{
			line(frame, points_[i], points_[(i + 1) % 4], cv::Scalar(0, 0, 255), 2, 2);
		}
		++counter;
		cv::putText(frame, std::to_string(counter), points_[0], CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);
	}
#endif
	cv::rectangle(frame, targetRect, cv::Scalar(0, 255, 255), 2);
	std::string str = "Yaw: ";
	str += std::to_string(angleSolverResult[0]);
	str += ", Pitch: ";
	str += std::to_string(angleSolverResult[1]);
	str += ", Distance: ";
	str += std::to_string(angleSolverResult[2]);
	cv::putText(frame, str, cv::Point(15, 15), CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);
}

void cubedetector::calcBoundingRect(std::vector<cv::RotatedRect> &RRect_result_v)
{
	float boundingRectWidth = 0, center_x = 0, center_y = 0;
	std::vector<double> widths;
	for (auto &RRect_single : RRect_result_v)
	{
		widths.push_back(RRect_single.size.width);
		center_x += RRect_single.center.x;
		center_y += RRect_single.center.y;
	}
	std::sort(widths.begin(), widths.end());
	widths.pop_back();
	widths.erase(widths.begin());
	for (int i = 0; i < widths.size(); ++i)
	{
		boundingRectWidth += widths[i];
	}
	boundingRectWidth /= widths.size();
	boundingRectWidth *= 4;
	center_x /= RRect_result_v.size();
	center_y /= RRect_result_v.size();
	targetRect = cv::Rect(center_x - boundingRectWidth / 2, center_y - boundingRectWidth / 2, boundingRectWidth, boundingRectWidth);
}

void cubedetector::adjustRRect(cv::RotatedRect &RRect)
{
	if (RRect.angle < -45)
	{
		float temp = 0;
		temp = RRect.size.width;
		RRect.size.width = RRect.size.height;
		RRect.size.height = temp;
		RRect.angle += 90;
	}
}

void cubedetector::subNoiseReduction(const std::vector<cv::RotatedRect> &_data_v, std::vector<cv::RotatedRect> &result_v, int val, std::string type)
{
	std::vector<cv::RotatedRect> data_v = _data_v;
	float cur_result = 0, sub_result = 0;
	std::vector<float> num_v;

	if (type == "width")
	{
		for (int i = 0; i < data_v.size(); ++i)
		{
			num_v.push_back(data_v[i].size.width);
		}
	}
	else if (type == "x")
	{
		for (int i = 0; i < data_v.size(); ++i)
		{
			num_v.push_back(data_v[i].center.x);
		}
	}
	else if (type == "y")
	{
		for (int i = 0; i < data_v.size(); ++i)
		{
			num_v.push_back(data_v[i].center.y);
		}
	}
	else if (type == "angle")
	{
		for (int i = 0; i < data_v.size(); ++i)
		{
			num_v.push_back(data_v[i].angle);
		}
	}

	cur_result = calcVariance(num_v.begin(), num_v.end());

	if (cur_result < val)
	{
		result_v = data_v;
		return;
	}
	else
	{
		sub_result = calcVariance(num_v.begin() + 1, num_v.end());
		if (sub_result < cur_result)
		{
			std::vector<cv::RotatedRect> temp(data_v.begin() + 1, data_v.end());
			subNoiseReduction(temp, result_v, val, type);
		}
		else
		{
			result_v = data_v;
		}
	}
	return;
}

float cubedetector::calcVariance(const std::vector<float>::iterator &begin, const std::vector<float>::iterator &end)
{
	std::vector<float>::iterator _begin = begin;
	float sum = 0, count = 0, ave = 0;
	while (_begin != end)
	{
		sum += *_begin;
		++_begin;
		++count;
	}
	ave = sum / count;
	_begin = begin;
	sum = 0;
	while (_begin != end)
	{
		sum += (*_begin - ave) * (*_begin - ave);
		++_begin;
	}
	return sum / count;
}

void cubedetector::noiseReduction(std::vector<cv::RotatedRect> &RRect_v, int val, std::string type)
{
	std::sort(RRect_v.begin(), RRect_v.end(), [](const cv::RotatedRect &rect1, const cv::RotatedRect &rect2){return rect1.size.width < rect2.size.width;});
	subNoiseReduction(RRect_v, RRect_v, val, type);
	std::reverse(RRect_v.begin(), RRect_v.end());
	subNoiseReduction(RRect_v, RRect_v, val, type);
	std::reverse(RRect_v.begin(), RRect_v.end());
	subNoiseReduction(RRect_v, RRect_v, val, type);
}