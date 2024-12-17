#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <random>

void ColorReduce(cv::Mat img, int div=64){


    int nl= img.rows;

    // nombre de colonnes * nombre de canaux
    // nombre de canaux = 1 pour une image en niveaux de gris 
    // les canaux sont les composantes de couleur de l'image
    int nc= img.cols*img.channels();
    // parcourir l'image
    for(int j=0;j<nl;j++){

        // pointeur sur la ligne j
        uchar* data= img.ptr<uchar>(j);

        // parcourir chaque pixel de la ligne j
        for(int i=0;i<nc;i++){

            // diviser la valeur du pixel par div
            data[i]= data[i]/div*div+div/2;

            // ou bien 
            // *data corresponds à la valeur du pixel
            // diviser la valeur du pixel par div
                //*data++= *data/div*div+div/2;
        }
    }
}

// Version avec des pointeurs
void ColorReduceIo( const cv::Mat &img,
                    cv::Mat &result, 
                    int div=64)

{
    int nl = img.rows;
    int nc = img.cols ; 
    int nbchannels = img.channels();

    // le result .create crée une image de la même taille que img

    result.create(img.rows,img.cols,img.type());

    for (int j=0; j<nl; j++)
    {
        // pointeur sur la ligne j de l'image d'entrée
        const uchar* data_in = img.ptr<uchar>(j);

        // pointeur sur la ligne j de l'image de sortie
        uchar* data_out = result.ptr<uchar>(j);
        // parcourir chaque pixel de la ligne j
        for (int i=0; i<nc*nbchannels; i++)
        {
            // diviser la valeur du pixel par div
            data_out[i] = data_in[i]/div*div + div/2;
        }
    }

}
void ColorReduce6(cv::Mat img,int div=64){

    int nl= img.rows;
    int nc= img.cols*img.channels();
    
    // vérifier si l'image est continue
    // (c'est-à-dire s'il n'y a pas de pixels de remplissage)
    if(img.isContinuous()){
        // pas de pixels de remplissage
        // alors on peut traiter l'image comme un tableau unique
        nc= nc*nl;
        nl= 1;
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
void ColorReduce6(cv::Mat img,int div=64){

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

    cv::Mat img = cv::imread("boldt.jpg",1);
    cv::Mat imgClone = img.clone();
    ColorReduce(imgClone);
    cv::namedWindow("Image avec réduction de couleur");
    cv::imshow("Image avec réduction de couleur", imgClone);
    cv::waitKey(0);
    return 0;


}