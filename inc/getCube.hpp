#pragma once

#include <opencv2/opencv.hpp>

class cubedetector
{
public:
	void findCube(const cv::Mat &src, std::vector<cv::RotatedRect> &RRect_previous_v);
	void filterCube(std::vector<cv::RotatedRect> &RRect_previous_v, std::vector<cv::RotatedRect> &RRect_result_v);
	void drawResult(cv::Mat &frame, std::vector<cv::RotatedRect> &RRects, std::vector<double> &angleSolverResult);
	void calcBoundingRect(std::vector<cv::RotatedRect> &RRect_result_v);
	void adjustRRect(cv::RotatedRect &RRect);
	void noiseReduction(std::vector<cv::RotatedRect> &RRect_v, int val);
	void subNoiseReduction(const std::vector<cv::RotatedRect> &data_v, std::vector<cv::RotatedRect> &result_v, int val);
	float calcVariance(const std::vector<float>::iterator &begin, const std::vector<float>::iterator &end);
public:
	cv::Rect2f targetRect;
private:
	cv::Mat frame;
	cv::Mat gray;
	std::vector<std::vector<cv::Point2i> > contours;
	std::vector<cv::Vec4i> hierarchy;
};
