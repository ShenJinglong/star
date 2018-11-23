#include <opencv2/opencv.hpp>
#include "colorRecognition.hpp"

//#define DEBUG

void colorReco::getROI(cv::Mat &src, cv::Mat &dst, cv::Rect2f &targetRect)
{
    cv::Point left_up(targetRect.x < 0 ? 0 : targetRect.x, targetRect.y < 0 ? 0 : targetRect.y);
    cv::Point right_down(targetRect.x + targetRect.width > src.size().width ? src.size().width : targetRect.x + targetRect.width,
        targetRect.y + targetRect.height > src.size().height ? src.size().height : targetRect.y + targetRect.height);

    cv::Mat temp(src, cv::Rect(left_up, right_down));
    temp.copyTo(dst);
}

bool colorReco::judge(cv::Mat &src, cv::Rect2f &targetRect)
{
    cv::Mat imgROI;
    cv::Mat imgRED;
    cv::Mat imgORANGE;
    cv::Mat imgWHITE;
    cv::Mat imgYELLOW;
    cv::Mat imgGREEN;
    cv::Mat imgBLUE;
    getROI(src, imgROI, targetRect);

#ifdef DEBUG
    cv::imshow("ROI", imgROI);
#endif

/*
    char ch = cv::waitKey(0);
    if (ch == 'r')
        cv::imwrite("../conf/red.jpg", imgROI);
    else if (ch == 'o')
        cv::imwrite("../conf/orange.jpg", imgROI);
    else if (ch == 'w')
        cv::imwrite("../conf/white.jpg", imgROI);
    else if (ch == 'y')
        cv::imwrite("../conf/yellow.jpg", imgROI);
    else if (ch == 'g')
        cv::imwrite("../conf/green.jpg", imgROI);
    else if (ch == 'b')
        cv::imwrite("../conf/blue.jpg", imgROI);
*/  

    imgRED = cv::imread("../conf/red.jpg");
    imgORANGE = cv::imread("../conf/orange.jpg");
    imgWHITE = cv::imread("../conf/white.jpg");
    imgYELLOW = cv::imread("../conf/yellow.jpg");
    imgGREEN = cv::imread("../conf/green.jpg");
    imgBLUE = cv::imread("../conf/blue.jpg");

#ifdef DEBUG
    cv::imshow("RED", imgRED);
    cv::imshow("ORANGE", imgORANGE);
    cv::imshow("WHITE", imgWHITE);
    cv::imshow("YELLOW", imgYELLOW);
    cv::imshow("GREEN", imgGREEN);
    cv::imshow("BLUE", imgBLUE);
#endif

    cv::cvtColor(imgROI, imgROI, cv::COLOR_BGR2HSV);
    cv::cvtColor(imgRED, imgRED, cv::COLOR_BGR2HSV);
    cv::cvtColor(imgORANGE, imgORANGE, cv::COLOR_BGR2HSV);
    cv::cvtColor(imgWHITE, imgWHITE, cv::COLOR_BGR2HSV);
    cv::cvtColor(imgYELLOW, imgYELLOW, cv::COLOR_BGR2HSV);
    cv::cvtColor(imgGREEN, imgGREEN, cv::COLOR_BGR2HSV);
    cv::cvtColor(imgBLUE, imgBLUE, cv::COLOR_BGR2HSV);

    int h_bins = 50; int s_bins = 60;
    int histSize[] = {h_bins, s_bins};

    float h_ranges[] = {0, 256};
    float s_ranges[] = {0, 180};
    const float *ranges[] = {h_ranges, s_ranges};
    int channels[] = {0, 1};

    cv::MatND ROIHist;
    cv::MatND RedHist;
    cv::MatND OrangeHist;
    cv::MatND WhiteHist;
    cv::MatND YellowHist;
    cv::MatND GreenHist;
    cv::MatND BlueHist;

    cv::calcHist(&imgROI, 1, channels, cv::Mat(), ROIHist, 2, histSize, ranges, true, false);
    cv::normalize(ROIHist, ROIHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    cv::calcHist(&imgRED, 1, channels, cv::Mat(), RedHist, 2, histSize, ranges, true, false);
    cv::normalize(RedHist, RedHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
    
    cv::calcHist(&imgYELLOW, 1, channels, cv::Mat(), YellowHist, 2, histSize, ranges, true, false);
    cv::normalize(YellowHist, YellowHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    cv::calcHist(&imgWHITE, 1, channels, cv::Mat(), WhiteHist, 2, histSize, ranges, true, false);
    cv::normalize(WhiteHist, WhiteHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    cv::calcHist(&imgORANGE, 1, channels, cv::Mat(), OrangeHist, 2, histSize, ranges, true, false);
    cv::normalize(OrangeHist, OrangeHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    cv::calcHist(&imgGREEN, 1, channels, cv::Mat(), GreenHist, 2, histSize, ranges, true, false);
    cv::normalize(GreenHist, GreenHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    cv::calcHist(&imgBLUE, 1, channels, cv::Mat(), BlueHist, 2, histSize, ranges, true, false);
    cv::normalize(BlueHist, BlueHist, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    double ROI_RED = cv::compareHist(ROIHist, RedHist, 0);
    double ROI_ORANGE = cv::compareHist(ROIHist, OrangeHist, 0);
    double ROI_WHITE = cv::compareHist(ROIHist, WhiteHist, 0);
    double ROI_YELLOW = cv::compareHist(ROIHist, YellowHist, 0);
    double ROI_GREEN = cv::compareHist(ROIHist, GreenHist, 0);
    double ROI_BLUE = cv::compareHist(ROIHist, BlueHist, 0);

#ifdef DEBUG
    std::cout << "ROI_RED: " << ROI_RED << std::endl;
    std::cout << "ROI_ORANGE: " << ROI_ORANGE << std::endl;
    std::cout << "ROI_WHITE: " << ROI_WHITE << std::endl;
    std::cout << "ROI_YELLOW: " << ROI_YELLOW << std::endl;
    std::cout << "ROI_GREEN: " << ROI_GREEN << std::endl;
    std::cout << "ROI_BLUE: " << ROI_BLUE << std::endl;
#endif

    if (ROI_RED > 0.5 || ROI_ORANGE > 0.5 || ROI_WHITE > 0.5 || ROI_YELLOW > 0.5 || ROI_GREEN > 0.5 || ROI_BLUE > 0.5)
        return true;
    else
        return false;
}