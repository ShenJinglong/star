#pragma once
#include <opencv2/opencv.hpp>

class colorReco
{
public:
    void getROI(cv::Mat &src, cv::Mat &dst, cv::Rect2f &targetRect);
    bool judge(cv::Mat &src, cv::Rect2f &targetRect);
};