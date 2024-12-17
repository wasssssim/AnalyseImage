#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void onmouse(int event, int x, int y, int flags, void* param)

{

    cv::Mat* img = reinterpret_cast<cv::Mat*>(param);
    switch (event)
    {
        // cv::EVENT_LBUTTONDOWN est un événement qui se produit lorsque le bouton gauche de la souris est enfoncé
        case cv::EVENT_LBUTTONDOWN:
        std::cout << "x: " << x << " y: " << y << ") value is "
        // img->at<uchar>(cv::Point(x, y)) est une fonction qui retourne la valeur du pixel à la position (x, y)
                  << static_cast<int>(img->at<uchar>(cv::Point(x, y))) << std::endl;
        break;  

      }





}







int main()
{
    cv::Mat img ;
        std::cout<<"rows: " << img.rows << " cols: " << img.cols << " channels: " << img.channels() << std::endl;

        // fonction imread pour lire l'image prend en argument le nom de l'image et le type de l'image cv::IMREAD_GRAYSCALE ou cv::IMREAD_COLOR
        img= cv::imread("tesst.jpeg" , cv::IMREAD_GRAYSCALE);

        //agrandir l'image
        cv::resize(img, img, cv::Size(800, 700));
    
    
    
    if(img.empty())
    {
        std::cout << "Impossible de lire l'image: tessst.jpg" << std::endl;
        return 1;
    }



    // fonction namedWindow pour créer une fenêtre
    cv::namedWindow("Image Original");
    
    cv::setMouseCallback("Image Original", onmouse, reinterpret_cast<void*>(&img));  

    // fonction imshow pour afficher l'image
    cv::imshow("Image Original", img);

    cv::Mat result;
    // fonction flip pour retourner l'image
    cv::flip(img, result, 1);

    cv::namedWindow("Image output");
    cv::imshow("Image output", result);

    cv::imwrite("output.jpg", result);

    cv::namedWindow("Dessiner un cercle");
    cv::circle(
        img, 
        cv::Point(100, 100),
        65,
        0,
        3
        );   


    cv::putText(
        img,
        "Juste un gars chill",
        cv::Point(40, 600),
        cv::FONT_HERSHEY_SIMPLEX,
        2.0,
        255,
        2
        );  

    cv::imshow("Dessiner un cercle", img);

    cv::waitKey(0);

    return 0;
}