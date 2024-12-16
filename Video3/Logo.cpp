#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main()
{
    cv::namedWindow("Image Original");
    cv::Mat img = cv::imread("puppy.bmp");
    cv::Mat logo = cv::imread("smalllogo.png");

    // cv::Rect est une structure qui définit un rectangle
    cv::Mat imageRoi(img,cv::Rect(img.cols-logo.cols,img.rows-logo.rows,logo.cols,logo.rows));

    // copier le logo dans l'image

    logo.copyTo(imageRoi);
    cv::imshow("Image Original", img);

    cv::waitKey(0);

    img=cv::imread("puppy.bmp");

    imageRoi=img(cv::Rect(img.cols-logo.cols,img.rows-logo.rows,logo.cols,logo.rows));
    cv::Mat mask(logo);

    logo.copyTo(imageRoi,mask);
    cv::imshow("Image Original", img);
    cv::waitKey(0);
    return 0;


}