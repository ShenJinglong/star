
#include <opencv2/opencv.hpp>
#include "getCube.hpp"
#include "setCamera.hpp"
#include "angleSolver.hpp"

#define DEBUG

void vision_mul(void)
{
	cubedetector detector;
	cameraDriver camera;
	cv::VideoCapture capture;
	cv::Mat frame;
	std::vector<cv::RotatedRect> RRect_previous_v;
	std::vector<cv::RotatedRect> RRect_result_v;
	std::vector<double> angleSolverResult;

	if (!camera.openCamera(capture))
	{
		return;
	}

	angleSolver solver(camera.camera_matrix, camera.dist_coeffs);
	RRect_previous_v.clear();
	RRect_result_v.clear();

#ifdef DEBUG
	std::cout << "Initialize complete, begin to process..." << std::endl;
#endif

	while (1)
	{
		capture >> frame;
		detector.findCube(frame, RRect_previous_v);

#ifdef DEBUG
	std::cout << "findCube complete..." << std::endl;
#endif

		detector.filterCube(RRect_previous_v, RRect_result_v);

#ifdef DEBUG
	std::cout << "filterCube complete..." << std::endl;
#endif

		if (RRect_result_v.size() == 9)
		{
			detector.calcBoundingRect(RRect_result_v);

#ifdef DEBUG
	std::cout << "calcBoundingRect complete..." << std::endl;
#endif

			angleSolverResult = solver.getResult(detector.targetRect);

#ifdef DEBUG
	std::cout << "solveAngle complete..." << std::endl;
#endif

			detector.drawResult(frame, RRect_result_v, angleSolverResult);
		}

		cv::imshow("", frame);
		RRect_previous_v.clear();
		RRect_result_v.clear();
		if (cv::waitKey(2) == 27)
			break;
	}	
}