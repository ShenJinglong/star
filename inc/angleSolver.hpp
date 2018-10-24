#pragma once

#include <opencv2/opencv.hpp>

class angleSolver
{
public:
	angleSolver(cv::Mat &camera_matrix, cv::Mat &dist_coeffs, double real_width) :camera_matrix(camera_matrix), dist_coeffs(dist_coeffs), real_width(real_width) {}
	std::vector<double> getResult(cv::Rect2f &targetRect);
private:
	cv::Mat camera_matrix;
	cv::Mat dist_coeffs;
	float real_width;
};