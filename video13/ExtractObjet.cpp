#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <math.h>

int main(){
    cv::Mat img = cv::imread("boldt.jpg");
    if(!img.data){
        std::cout << "Impossible de lire l'image !" << std::endl;
        return 0;
    }

    cv::Rect rect(50,25,210,180);

    cv::Mat result;
    cv::Mat BgModel, FgModel;
    cv::grabCut(img,result,rect,BgModel,FgModel,5,cv::GC_INIT_WITH_RECT);// on initialise le grabcut c'est à dire avec un rectangle
    cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ); // on compare les résultats obtenus avec le grabcut

    cv::Mat foreground(img.size(),CV_8UC3,cv::Scalar(255,255,255)); // on crée une image de la taille de l'image d'origine avec un fond blanc
    img.copyTo(foreground,result); // on copie les pixels de l'image d'origine dans l'image foreground
    cv::rectangle(img,rect,cv::Scalar(255,255,255),1); // on dessine un rectangle sur l'image d'origine 

    cv::namedWindow("Image d'origine");
    cv::imshow("Image d'origine",img);
    cv::namedWindow("Foreground");
    cv::imshow("Foreground",foreground);
    cv::waitKey(0);

}