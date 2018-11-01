
#include <opencv2/opencv.hpp>
#include "getCube.hpp"

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
		float ratio_cur = RRect.size.width / RRect.size.height;
		float angle = RRect.angle;
		float RRect_area = RRect.size.area();
		float contour_area = cv::contourArea(contours[i]);
		if (ratio_cur > 0.8 && ratio_cur < 1.2 &&
			(angle > -20 || angle < -70) &&
			RRect.size.width > 20 && RRect.size.width < frame.cols / 5 &&
			RRect_area / contour_area <= 1.5)
		{
			RRect_previous_v.push_back(RRect);
		}
	}
}

void cubedetector::filterCube(std::vector<cv::RotatedRect> &RRect_previous_v, std::vector<cv::RotatedRect> &RRect_result_v)
{
	if (RRect_previous_v.size() <= 15 && RRect_previous_v.size() > 9)
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

		for (int i = 0; i < 9; ++i)
		{
			RRect_result_v.push_back(RRect_previous_v[dist_center[i].second]);
		}
	}
	else
	{
		return;
	}

#ifdef DEBUG
	std::cout << "Before filter: " << RRect_previous_v.size() << "\tAfter filter: " << RRect_result_v.size() << std::endl;
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
	cv::rectangle(frame, targetRect, cv::Scalar(0, 0, 255), 2);
	std::string str = "Yaw: ";
	str += std::to_string(angleSolverResult[0]);
	str += ", Pitch: ";
	str += std::to_string(angleSolverResult[1]);
	str += ", Distance: ";
	str += std::to_string(angleSolverResult[2]);
	cv::putText(frame, str, cv::Point(targetRect.x, targetRect.y), CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);
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
	boundingRectWidth *= 3;
	center_x /= RRect_result_v.size();
	center_y /= RRect_result_v.size();
	targetRect = cv::Rect(center_x - boundingRectWidth / 2, center_y - boundingRectWidth / 2, boundingRectWidth, boundingRectWidth);
}