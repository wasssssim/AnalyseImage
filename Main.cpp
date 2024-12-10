#include <opencv2/opencv.hpp>      // Fonctions principales d'OpenCV
#include <opencv2/highgui.hpp>    // Contient imshow et waitKey
#include <opencv2/imgcodecs.hpp>  // Contient imread et imwrite
#include <opencv2/imgproc.hpp>    // Contient les fonctions de traitement d'image
#include <iostream>

int main() {
    // Afficher la version d'OpenCV
    std::cout << "Version d'OpenCV : " << CV_VERSION << std::endl;

    // Charger une image
    cv::Mat image = cv::imread("log.jpg");
    if (image.empty()) {
        std::cerr << "Erreur : Impossible de charger l'image !" << std::endl;
        return -1;
    }

    // Afficher des informations sur l'image
    std::cout << "Dimensions de l'image : " << image.cols << "x" << image.rows << std::endl;
    std::cout << "Nombre de canaux : " << image.channels() << std::endl;

    // Afficher l'image originale
    cv::imshow("Image originale", image);

    // Convertir l'image en niveaux de gris
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::imshow("Image en niveaux de gris", grayImage);

    // Appliquer un flou gaussien
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(15, 15), 0);
    cv::imshow("Image floutée", blurredImage);

    // Appliquer une détection de contours avec Canny
    cv::Mat edges;
    cv::Canny(blurredImage, edges, 50, 150);
    cv::imshow("Contours détectés", edges);

    // Sauvegarder les résultats
    cv::imwrite("output_gray.jpg", grayImage);
    cv::imwrite("output_blurred.jpg", blurredImage);
    cv::imwrite("output_edges.jpg", edges);
    std::cout << "Images transformées sauvegardées : output_gray.jpg, output_blurred.jpg, output_edges.jpg" << std::endl;

    // Attendre une touche avant de quitter
    cv::waitKey(0);
    return 0;
}
