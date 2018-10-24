
#include <opencv2/opencv.hpp>
#include "angleSolver.hpp"

std::vector<double> angleSolver::getResult(cv::Rect2f &targetRect)
{
	std::vector<cv::Point3f> obj_p;
	std::vector<cv::Point2f> img_p;

	obj_p.push_back(cv::Point3f(0.0, 0.0, 0.0));
	obj_p.push_back(cv::Point3f(real_width, 0.0, 0.0));
	obj_p.push_back(cv::Point3f(real_width, real_width, 0.0));
	obj_p.push_back(cv::Point3f(0.0, real_width, 0.0));

	cv::Mat rot = cv::Mat::eye(3, 3, CV_64FC1);
	cv::Mat rvec = cv::Mat::ones(3, 1, CV_64F);
	cv::Mat tvec = cv::Mat::ones(3, 1, CV_64F);

	double angle_x, angle_y, angle_z;
	std::vector<cv::Point2f> targetRectPoints;

	targetRectPoints.push_back(cv::Point2f(targetRect.x, targetRect.y));
	targetRectPoints.push_back(cv::Point2f(targetRect.x + targetRect.width, targetRect.y));
	targetRectPoints.push_back(cv::Point2f(targetRect.x + targetRect.width, targetRect.y + targetRect.height));
	targetRectPoints.push_back(cv::Point2f(targetRect.x, targetRect.y + targetRect.height));

	cv::solvePnP(obj_p, targetRectPoints, camera_matrix, dist_coeffs, rvec, tvec);

	angle_z = tvec.at<double>(2) / 1000.0;

	const double *_xyz = (const double *)tvec.data;
	double xyz[3] = { _xyz[0], _xyz[1], _xyz[2] };

	angle_x = atan2(xyz[0], xyz[2]);
	angle_y = atan2(xyz[1], xyz[2]);
	angle_x = angle_x * 180 / 3.1415926;
	angle_y = angle_y * 180 / 3.1415926;

	std::vector<double> angles;
	angles.push_back(angle_x);
	angles.push_back(angle_y);
	angles.push_back(angle_z);

	return angles;
}