#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
    // Load images
    cv::Mat img1 = cv::imread("boldt.jpg");
    cv::Mat img2 = cv::imread("rain.jpg");

    // Check if images are loaded successfully
    if (!img1.data || !img2.data) {
        std::cout << "Impossible de lire l'image !" << std::endl;
        return 0;
    }


    // Display original images
    cv::namedWindow("Image 1");
    cv::imshow("Image 1", img1);
    cv::namedWindow("Image 2");
    cv::imshow("Image 2", img2);

    // Blend images
    cv::Mat result;

    // cv::addWeighted est une fonction qui permet d'additionner  deux images en fonction de leur poids
    // il existeaussi la fonction cv::add qui permet d'additionner deux images sans prendre en compte le poids
    // cv::addWeighted(img1, alpha, img2, beta, gamma, result)
    // IL existe aussi la fonction cv::subtract qui permet de soustraire deux images
    // il eixiste aussi des fonctions qui prennent en inputt une seule image 
    //comme cv::square


    //cv::addWeighted(img1, 0.5, img2, 0.5, 0, result);
    result = 0.5 * img1 + 0.5 * img2;     // Equivalent to cv::addWeighted

    
    // Display result
    cv::namedWindow("Résultat");
    cv::imshow("Résultat", result);

    // Wait for a key press
    cv::waitKey(0);

    return 0;
}
