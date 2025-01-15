# AnalyseImage
Analyse d'image en c++
# Compilation
g++ -o test_opencv Main.cpp     -I/usr/local/include/opencv4     -L/usr/local/lib     -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
# Compilation Video 12
 g++ Compare.cpp ColorDetector.cpp -o Compare -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui