#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <math.h>

void wave(const cv::Mat &image,cv::Mat &result){

    // Create an image with the same size as the input image
    cv::Mat srcX(image.rows,image.cols,CV_32F);
    cv::Mat srcY(image.rows,image.cols,CV_32F);

    for(int i=0;i<image.rows;i++){
        for(int j=0;j<image.cols;j++){
            // srcX.at permet de modifier la valeur d'un pixel
            srcX.at<float>(i,j) = j;
            srcY.at<float>(i,j) = i + 5 * sin(j / 10.0);
        }
    }

    cv::remap(image,result,srcX,srcY,cv::INTER_LINEAR);
}
int main() {
    // Load images
    cv::Mat img1 = cv::imread("boldt.jpg");
    cv::Mat img2 = cv::imread("rain.jpg");

    // Check if images are loaded successfully
    if (!img1.data || !img2.data) {
        std::cout << "Impossible de lire l'image !" << std::endl;
        return 0;
    }

    cv::Mat result;
    
    wave(img1,result);
    cv::namedWindow("Résultat");
    cv::imshow("Résultat", result);
    cv::waitKey(0);
}