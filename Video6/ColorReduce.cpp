#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <random>


void ColorReduce10(cv::Mat img,int div=64){

    int nl= img.rows;
    int nc= img.cols*img.channels();
    
    // vérifier si l'image est continue
    // (c'est-à-dire s'il n'y a pas de pixels de remplissage)
    if(img.isContinuous()){
        img.reshape(1,1);

    }


    // n est le nombre de bits pour représenter div 
    int n= static_cast<int>(log(static_cast<double>(div))/log(2.0)+0.5);
    u_char mask= 0xFF<<n; 
    u_char div2= div>>1; 

    for(int j=0;j<nl;j++){

        // pointeur sur la ligne j
        uchar* data= img.ptr<uchar>(j);

        // parcourir chaque pixel de la ligne j
        for(int i=0;i<nc;i++){
    
                // diviser la valeur du pixel par div
                *data &= mask;
                *data++ += div2;
        }
    }

}
int main(){

    return 0;


}