#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

cv::Mat function()
{

    cv::Mat ima(500, 500, CV_8UC3, 50);    

    return ima;
}

int main()
{

// cv::mat argumentts sont : nombre de lignes, nombre de colonnes, type de données, valeur initiale
cv::Mat image1(240,320, CV_8UC3, 100);


//image.create est une fonction qui crée une image avec une taille spécifique et un type de données spécifique
image1.create(200,200, CV_8UC3);
image1=200;

//image2 est une image de taille 240x320, de type CV_8UC3, et de couleur rouge
cv::Mat image2(240,320, CV_8UC3, cv::Scalar(0,0,255));

cv::Mat image3 = cv::imread("tesst.jpeg");

cv::Mat image4 (image3);
image1=image3;
image3.copyTo(image2);
cv::Mat image5 = image3.clone();
cv::flip(image3, image3, 1);

cv::imshow("image1", image1);
cv::imshow("image2", image2);
cv::imshow("image3", image3);
cv::imshow("image4", image4);
cv::imshow("image5", image5);

cv::Mat gray=function();
image1=cv::imread("tesst.jpeg", cv::IMREAD_GRAYSCALE);

image1.convertTo(image2,CV_32F,1/255.0,0.0 );

cv::Matx33d matrix(
    3.0 , 2.0 , 1.0,
    2.0,  1.0,    3.0,
    1.0,  2.0,    3.0
);
 cv::Matx31d vector(5.0,1.0,3.0);
 cv::Matx31d result = matrix * vector;

 cv::waitKey(0);




}