#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <cmath>
#include <cstdlib> 


class ColorDetector {
    private :
    int maxDist;
    bool useLab;
    cv::Vec3b target;
    cv::Mat converted;
    cv::Mat result;
    
    public : 
    
    ColorDetector(): maxDist(100),useLab(false),target(0,0,0) {
    }
    ColorDetector(bool useLAb):useLab(useLAb),maxDist(100),target(0,0,0){}

    ColorDetector(uchar blue, uchar green, uchar red, int mxDist = 100,bool useLab=false) : maxDist(mxDist),useLab(useLab) {

        setTargetColor(blue,green,red);
    }


    cv::Mat process(const cv::Mat &img); 
    cv::Mat operator()(const cv::Mat &img){
        cv::Mat input;
        if(useLab){
            cv::cvtColor(img,input,cv::COLOR_BGR2Lab);
        }else
        {
            input = img;
        }
        cv::Mat output;

        cv::absdiff(input,cv::Scalar(target),output); // absdiff est une fonction qui calcule la valeur absolue de la différence entre deux matrices
        std::vector<cv::Mat> images; // on crée un vecteur de matrices
        cv::split(output,images); // on sépare les 3 canaux de couleurs de l'image
        output = images[0] + images[1] + images[2]; // on additionne les 3 canaux de couleurs
        cv::threshold(output,output,maxDist,255,cv::THRESH_BINARY_INV); // on applique un seuillage c'est à dire on met à 0 les pixels qui sont inférieurs à maxDist et on met à 255 les pixels qui sont supérieurs à maxDist
        return output;
    }

    cv::Vec3b getTargetColor()const{
        return target;
    }


    int getDistanceToTargetColor(const cv::Vec3b &color) const {
        return getColorDistance(color,target);
    }

    int getColorDistance(const cv::Vec3b &color,const cv::Vec3b &color2) const {
        return abs(color[0] - color2[0]) + abs(color[1] - color2[1]) + abs(color[2] - color2[2]);
    }

    void setColorDistanceThreshold(int distance){
        if(distance<0)
            distance = 0;
        maxDist = distance;
    }

    void setTargetColor(uchar blue, uchar green, uchar red){
        target= cv::Vec3b(blue,green,red);
        if(useLab){
            cv::Mat tmp(1,1,CV_8UC3);
            tmp.at<cv::Vec3b>(0,0) = cv::Vec3b(blue,green,red);
            cv::cvtColor(tmp,tmp,cv::COLOR_BGR2Lab);
            target = tmp.at<cv::Vec3b>(0,0);
        }
    }

    void setTargetColor(cv::Vec3b color){
        target = color;
    }



};


#endif 