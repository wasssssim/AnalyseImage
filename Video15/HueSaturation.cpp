#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <math.h>

void detectHSColor(const cv::Mat &img, cv::Mat &mask,double MinHue, double MaxHue, double MinSat, double MaxSat){


    cv::Mat hsv;
    cv::cvtColor(img,hsv,cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> channels;
    cv::split(hsv,channels);
    cv::Mat mask1;
    cv::threshold(channels[0],mask1,MaxHue,255,cv::THRESH_BINARY_INV);// on seuille les valeurs de HUE
    cv::Mat mask2;
    cv::threshold(channels[0],mask2,MinHue,255,cv::THRESH_BINARY);// on seuille les valeurs de HUE

    cv::namedWindow("mask1");
    cv::imshow("mask1",mask1);


    cv::namedWindow("mask2");
    cv::imshow("mask2",mask2);

    cv::Mat hueMask;
}

int main(){
    cv::Mat img = cv::imread("boldt.jpg");
    cv::Mat mask;
    detectHSColor(img,mask,170,179,150,255);
    cv::waitKey(0);
    return 0;
}