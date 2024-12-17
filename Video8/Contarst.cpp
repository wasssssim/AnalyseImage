#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <random>


void sharpen(const cv::Mat &img , cv::Mat &result){

    result.create(img.size(),img.type());
    int NbChannels= img.channels();
    
    
    for(int j=1;j<img.rows-1;j++){


        // uchar* est un pointeur sur un tableau d'entiers non signés
        const uchar* previous= img.ptr<uchar>(j-1);
        const uchar* current= img.ptr<uchar>(j);
        const uchar* next= img.ptr<uchar>(j+1);
        uchar* output= result.ptr<uchar>(j);


        for(int i=NbChannels;i<NbChannels*(img.cols-1);i++){
            // on multiplie par 5 la valeur du pixel courant
            *output++= cv::saturate_cast<uchar>(5*current[i]-current[i-NbChannels]-current[i+NbChannels]-previous[i]-next[i]);
        }
    }
    // on met à 0 les bords de l'image
    result.row(0).setTo(cv::Scalar(0));
    //
    result.row(result.rows-1).setTo(cv::Scalar(0));
    result.col(0).setTo(cv::Scalar(0));
    result.col(result.cols-1).setTo(cv::Scalar(0));

}

void sharpen2D(const cv::Mat &img , cv::Mat &result){

    // on crée un noyau de convolution
    cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
    kernel.at<float>(1,1)= 5.0;
    kernel.at<float>(0,1)= -1.0;
    kernel.at<float>(2,1)= -1.0;
    kernel.at<float>(1,0)= -1.0;
    kernel.at<float>(1,2)= -1.0;

    cv::filter2D(img,result,img.depth(),kernel);
}

int main(){

    cv::Mat img= cv::imread("boldt.jpg");
    if(!img.data){
        return 0 ;  
    }
    cv::Mat result; 
    sharpen2D(img,result);
    cv::imshow("Image de départ",img);
    cv::imshow("Image de sortie",result);
    cv::waitKey(0);




    return 0 ;
}