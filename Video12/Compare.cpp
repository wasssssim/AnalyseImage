#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <math.h>
#include <ColorDetector.h>

int main(){

    ColorDetector cdetect;
    cv::Mat img = cv::imread("boldt.jpg");
    cv::Mat result;
    if(img.empty()){
        std::cout << "Impossible de lire l'image !" << std::endl;
        return 0;
    }
    cdetect.setTargetColor(230,190,130);

    cv::namedWindow("Résultat");
    cv::imshow("Résultat", cdetect.process(img));
    cv::waitKey(0);

    cv::floodFill(img, cv::Point(100, 50), cv::Scalar(255, 255, 255), (cv::Rect*)0, cv::Scalar(35, 35, 35), cv::Scalar(35, 35, 35)
    , cv::FLOODFILL_FIXED_RANGE);   // le floodfill est une fonction qui permet de remplir une
                                    // zone de l'image avec une couleur donnée les, arguments sont : img, le point de départ, la couleur, le rectangle, 
                                    // la couleur de la limite basse, la couleur de la limite haute et le type de floodfill
    cv::namedWindow("Flood fill resultat") ;
    cv::imshow("Flood fill result", img);

    cv::Mat colors(100, 300, CV_8UC3, cv::Scalar(100, 200, 150));
    cv::Mat range = colors.colRange(0, 100);
    range = range + cv::Scalar(10, 10, 10);
    range = colors.colRange(200, 300);
    range = range + cv::Scalar(-10, -10, -10);

    cv::namedWindow("3 colors");
    cv::imshow("3 colors", colors);

    cv::Mat labImage(100, 300, CV_8UC3, cv::Scalar(100, 200, 150));
    cv::cvtColor(labImage, labImage, cv::COLOR_BGR2Lab);
     cv::waitKey(0);




    return 0;
}