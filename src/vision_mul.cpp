#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "getCube.hpp"
#include "setCamera.hpp"

void vision_mul(void)
{
	cubedetector detector;
	cameraDriver camera;
	cv::VideoCapture capture;
	cv::Mat frame;
	std::vector<cv::RotatedRect> RRect_previous_v;
	std::vector<cv::RotatedRect> RRect_result_v;

	camera.openCamera(capture);
	while (1)
	{
		capture >> frame;
		detector.findCube(frame, RRect_previous_v);
		detector.filterCube(RRect_previous_v, RRect_result_v);
		detector.drawResult(frame, RRect_result_v);


		cv::imshow("", frame);
		RRect_previous_v.clear();
		RRect_result_v.clear();
		if (cv::waitKey(2) == 27)
			break;
	}	
}