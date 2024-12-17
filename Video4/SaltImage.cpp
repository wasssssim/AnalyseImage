#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <random>

void salt(cv::Mat img, int n){

    std::default_random_engine generator;
    std::uniform_int_distribution<int> randomRow(0, img.rows-1);
    std::uniform_int_distribution<int> randomCol(0, img.cols-1);

    int i, j;
    for(int k=0;k<n;k++){


        j=randomRow(generator);
        i=randomCol(generator);

        if (img.type()==CV_8UC1) { 

            // image en niveaux de gris
            // img.at<uchar>(j,i) est une fonction qui retourne la valeur du pixel à la position (x, y)
            img.at<uchar>(j,i)=255;


        } 

        else if (img.type()==CV_8UC3) { 

            // image en couleur
            img.at<cv::Vec3b>(j,i)[0]=255;
            img.at<cv::Vec3b>(j,i)[1]=255;
            img.at<cv::Vec3b>(j,i)[2]=255;

        }

    }



}

int main(){


    // imread prend 2 arguments le nom de l'image et le type de l'image
    cv::Mat img = cv::imread("boldt.jpg",1);
    salt(img,3000);

    cv::namedWindow("Image abvec bruit");
    cv::imshow("Image abvec bruit", img);
    

    cv::waitKey(0);
    return 0;




}