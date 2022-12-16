//libraries
#include <stdio.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include "Image_Filtering.h"

using namespace std;

int main(){
    
    //first noisy image that needs the filters applied
    Filter_Image Image1;
    string sourcePath1 = "/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/NoisyImage1.jpeg";
    Image1.sourcePath = sourcePath1;
    Image1.apply_filters();
    
    /*
    //second noisy image that needs the filters applied
    Filter_Image Image2;
    string sourcePath2 = "/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/NoisyImage2.jpeg";
    Image2.sourcePath = sourcePath2;
    Image2.apply_filters();
    */
}
