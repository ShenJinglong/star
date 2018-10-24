#pragma once

#include <opencv2/opencv.hpp>

class cameraDriver
{
public:
	bool openCamera(cv::VideoCapture &capture);
public:
	cv::Mat camera_matrix;
	cv::Mat dist_coeffs;
private:
	void setExposureTime(std::string camID, int val);
private:
	std::string usb_cam_id;
	int exposure_time;
	std::string video_path;
};