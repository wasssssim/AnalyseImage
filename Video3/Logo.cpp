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

    imageRoi=img(cv::Range(img.rows-logo.rows,img.rows),cv::Range(img.cols-logo.cols,img.cols));
/*

    cv::Mat imageRoi=img.rowRange(start,end);
    cv::Mat imageRoi=img.colRange(start,end); */ 
    // copyto prend en argument l'image de destination et le masque 
    // le masque est une image binaire qui définit les pixels à copier

    
    logo.copyTo(imageRoi,mask);
    cv::imshow("Image Original", img);
    cv::waitKey(0);
    return 0;


}