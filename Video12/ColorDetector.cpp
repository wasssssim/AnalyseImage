#include "ColorDetector.h"
#include<vector>
cv::Mat ColorDetector::process(const cv::Mat &img){
    result.create(img.size(),CV_8U);
    if(useLab)
        cv::cvtColor(img,converted,cv::COLOR_BGR2Lab);
    cv::Mat_<cv::Vec3b>::const_iterator it = img.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = img.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator itout = result.begin<uchar>();

    if(useLab){
        it=converted.begin<cv::Vec3b>();
        itend=converted.end<cv::Vec3b>();
    }
    for(;it!=itend;++it,++itout){
        if(getDistanceToTargetColor(*it)<maxDist)
            *itout=255;
        else
            *itout=0;
    }

    return result;


}
