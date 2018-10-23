#pragma once

#include <opencv2/opencv.hpp>

class cubedetector
{
public:
	void findCube(const cv::Mat &src, std::vector<cv::RotatedRect> &RRect_previous_v);
	void filterCube(std::vector<cv::RotatedRect> &RRect_previous_v, std::vector<cv::RotatedRect> &RRect_result_v);
	void drawResult(cv::Mat &frame, std::vector<cv::RotatedRect> &RRects);
public:
	cv::Rect2f targetRect;
private:
	cv::Mat frame;
	cv::Mat gray;
	std::vector<std::vector<cv::Point2i> > contours;
	std::vector<cv::Vec4i> hierarchy;
};
