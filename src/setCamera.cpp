#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "setCamera.hpp"

//#define DEBUG
//#define USE_VIDEO

bool cameraDriver::openCamera(cv::VideoCapture &capture)
{
	std::string xmlAddress = "camera.xml";
	cv::FileStorage fs("camera.xml", cv::FileStorage::READ);
	if (!fs.isOpened())
		std::cout << "Can't open [" << xmlAddress << "], please check if the file is exist.";
	fs["cam_id"] >> usb_cam_id;
	fs["video_path"] >> video_path;
	fs["exposure_time"] >> exposure_time;
	fs["Camera_Matrix"] >> camera_matrix;
	fs["Distortion_Coefficients"] >> dist_coeffs;

#ifdef DEBUG
	std::cout << usb_cam_id << std::endl;
#endif

	capture.set(CV_CAP_PROP_FPS, 120);
	
#ifndef USE_VIDEO
	capture.open(usb_cam_id);
#else
	capture.open(video_path);
#endif // !USE_VIDEO

	capture.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	capture.set(CV_CAP_PROP_EXPOSURE, exposure_time);

#ifndef USE_VIDEO
	if (!capture.isOpened())
	{
		std::cout << "Can't open camera [" << usb_cam_id << "]." << std::endl;
		return false;
	}
#else
	if (!capture.isOpened())
	{
		std::cout << "Can't open video [" << video_path << "]." << std::endl;
		return false;
	}
#endif
	return true;
}

