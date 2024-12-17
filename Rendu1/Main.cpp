#include <opencv2/opencv.hpp>
#include <iostream>

// Fonction pour dessiner une ligne rouge
void DrawLine(cv::Mat& img, const cv::Mat& baseImg, int y) {
    if (y < 0 || y >= img.rows) {
        std::cout << "Coordonnée Y invalide !" << std::endl;
        return;
    }

    // Réinitialiser l'image avec sa couleur de base
    baseImg.copyTo(img);

    std::cout << "Ligne rouge à y: " << y << std::endl;

    // Dessiner la ligne rouge
    for (int x = 0; x < img.cols; x++) {
        std::cout << "niveau de gris: " << img.at<cv::Vec3b>(y, x) << std::endl;
        img.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 255);  // Rouge
    }

    // Afficher l'image mise à jour
    cv::Mat intensityProfile(300, img.cols, CV_8UC3, cv::Scalar(0, 0, 0));  // Fenêtre noire pour le graphe

    // Tracer les valeurs d'intensité
    for (int x = 1; x < img.cols; x++) {
        int intensity1 = baseImg.at<uchar>(y, x - 1);  // Intensité précédente
        int intensity2 = baseImg.at<uchar>(y, x);      // Intensité actuelle

        // Échelle verticale : inversée (300 -> 0 en haut)
        int y1 = 300 - (intensity1 * 300 / 255);
        int y2 = 300 - (intensity2 * 300 / 255);

        cv::line(intensityProfile, cv::Point(x - 1, y1), cv::Point(x, y2), cv::Scalar(255, 255, 255), 1);
    }

    // Afficher l'image mise à jour et le profil d'intensité
    cv::imshow("Image Original", img);
    cv::imshow("Profil d'intensité", intensityProfile);
}


// Fonction de rappel pour la souris
void onmouse(int event, int x, int y, int flags, void* param) {
    cv::Mat* images = reinterpret_cast<cv::Mat*>(param);
    cv::Mat& displayImage = images[0];  // Image affichée
    const cv::Mat& baseImage = images[1];  // Image de base (constante)

    if (event == cv::EVENT_LBUTTONDOWN) {
        DrawLine(displayImage, baseImage, y);
    }
}

int main() {
    // Charger l'image en niveaux de gris
    cv::Mat img = cv::imread("boldt.jpg", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cout << "Impossible de lire l'image !" << std::endl;
        return -1;
    }

    // Convertir en couleur pour permettre le dessin en rouge
    cv::Mat colorImage;
    cv::cvtColor(img, colorImage, cv::COLOR_GRAY2BGR);

    // Créer une copie pour affichage
    cv::Mat displayImage = colorImage.clone();
    cv::Mat images[2] = { displayImage, colorImage };  // Stocker les deux images

    // Configurer la fenêtre et le callback de la souris
    cv::namedWindow("Image Original");
    cv::setMouseCallback("Image Original", onmouse, reinterpret_cast<void*>(images));

    // Afficher l'image
    cv::imshow("Image Original", displayImage);
    cv::waitKey(0);

    return 0;
}
