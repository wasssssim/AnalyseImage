#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <random>


void ColorReduce10(cv::Mat img,int div=64){


    // n est le nombre de bits pour représenter div 
    int n= static_cast<int>(log(static_cast<double>(div))/log(2.0)+0.5);
    u_char mask= 0xFF<<n; 
    u_char div2= div>>1; 

    cv::Mat_<cv::Vec3b>::iterator it= img.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::iterator itend= img.end<cv::Vec3b>();

    for(;it!=itend;++it){
        // diviser la valeur du pixel par div
        (*it)[0]&= mask;
    
        (*it)[0]+= div2;

        (*it)[1]&= mask;
        (*it)[1]+= div2;

        (*it)[2]&= mask;
        (*it)[2]+= div2;
    }

}

void ColorReduce11(cv::Mat img,int div=64){
    cv::Mat_<cv::Vec3b> cimg= img;
    cv::Mat_<cv::Vec3b>::iterator it= img.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::iterator itend= img.end<cv::Vec3b>();
    uchar div2= div>>1;

    for(;it!=itend;++it){
        // diviser la valeur du pixel par div
        (*it)[0]= (*it)[0]/div*div+div2;
        (*it)[1]= (*it)[1]/div*div+div2;
        (*it)[2]= (*it)[2]/div*div+div2;
    }

}
int main(){

    return 0;


}