
#include <opencv2/opencv.hpp>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/videodev2.h>
#include "setCamera.hpp"

//#define DEBUG
//#define USE_VIDEO

bool cameraDriver::openCamera(cv::VideoCapture &capture)
{
	std::string xmlAddress = "../conf/camera.xml";
	cv::FileStorage fs(xmlAddress, cv::FileStorage::READ);
	if (!fs.isOpened())
	{
		std::cout << "openCamera: Can't open [" << xmlAddress << "], please check if the file is exist.";
		return false;
	}
	fs["cam_id"] >> usb_cam_id;
	fs["video_path"] >> video_path;
	fs["exposure_time"] >> exposure_time;
	fs["Camera_Matrix"] >> camera_matrix;
	fs["Distortion_Coefficients"] >> dist_coeffs;
	fs.release();

#ifdef DEBUG
	std::cout << "Open config file successful..." << std::endl;
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

	setExposureTime(usb_cam_id, exposure_time);

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

#ifdef DEBUG
	std::cout << "open camera successful..." << std::endl;
#endif

	return true;
}

void cameraDriver::setExposureTime(std::string camID, int val)
{
	int cam_fd;
	if ((cam_fd = open(camID.c_str(), O_RDWR)) == -1)
	{
		std::cerr << "Camera open error" << std::endl;
		return;
	}

	struct v4l2_control control_s;
	control_s.id = V4L2_CID_EXPOSURE_AUTO;
	control_s.value = V4L2_EXPOSURE_MANUAL;
	ioctl(cam_fd, VIDIOC_S_CTRL, &control_s);

	control_s.id = V4L2_CID_EXPOSURE_ABSOLUTE;
	control_s.value = val;
	ioctl(cam_fd, VIDIOC_S_CTRL, &control_s);
	close(cam_fd);

	return;
}