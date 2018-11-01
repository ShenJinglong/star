#pragma once

#include <opencv2/opencv.hpp>

class angleSolver
{
public:
	angleSolver(cv::Mat &camera_matrix, cv::Mat &dist_coeffs) :camera_matrix(camera_matrix), dist_coeffs(dist_coeffs)
	{
		std::string xmlAddress = "../conf/camera.xml";
		cv::FileStorage fs(xmlAddress, cv::FileStorage::READ);
		if (!fs.isOpened())
		{
			std::cout << "angleSolver: Can't open [" << xmlAddress << "], please check if the file is exist.";
		}
		fs["real_width"] >> real_width;
		fs.release();
	}
	std::vector<double> getResult(cv::Rect2f &targetRect);
private:
	cv::Mat camera_matrix;
	cv::Mat dist_coeffs;
	float real_width;
};