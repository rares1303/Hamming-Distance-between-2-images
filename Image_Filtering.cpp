//libraries
#include <stdio.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

//class for applying filters to every input image
class Filter_Image{
public:
    
    Mat SourceImage;
    Mat FilteredImage;
    string sourcePath;
    
    void apply_filters(){
        
        SourceImage = imread(sourcePath);
        
        //----------median blur
        medianBlur(SourceImage, FilteredImage, 7);
        imwrite("/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/MedianBlurImage1.jpeg", FilteredImage);
        
        //----------bilateral filter
        bilateralFilter(SourceImage, FilteredImage, 35, 35*2, 35/2);
        imwrite("/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/BilateralFilterImage1.jpeg", FilteredImage);
        
        //----------wiener filter
        Mat SourceImageGrayscale = imread(sourcePath, IMREAD_GRAYSCALE);
        const Size block = Size(5,5);
        double noiseVariance = 5000;
        
        int h = SourceImageGrayscale.rows;
        int w = SourceImageGrayscale.cols;

        FilteredImage = Mat1b(h, w);

        Mat1d means, sqrMeans, variances;
        Mat1d avgVarianceMat;

        boxFilter(SourceImageGrayscale, means, CV_64F, block, Point(-1, -1), true, BORDER_REPLICATE);
        sqrBoxFilter(SourceImageGrayscale, sqrMeans, CV_64F, block, Point(-1, -1), true, BORDER_REPLICATE);

        Mat1d means2 = means.mul(means);
        variances = sqrMeans - (means.mul(means));

        if (noiseVariance < 0){
            
            //estimating the noiseVariance
            reduce(variances, avgVarianceMat, 1, REDUCE_SUM, -1);
            reduce(avgVarianceMat, avgVarianceMat, 0, REDUCE_SUM, -1);
            noiseVariance = avgVarianceMat(0, 0) / (h * w);
            
        }
        
        int r, c;
        for (r = 0; r < h; ++r){
            // get row pointers
            uchar const * const sourceImageRow = SourceImage.ptr<uchar>(r);
            uchar * const filteredImageRow = FilteredImage.ptr<uchar>(r);
            double * const variancesRow = variances.ptr<double>(r);
            double * const meansRow = means.ptr<double>(r);
            for (c = 0; c < w; ++c) {
                filteredImageRow[c] = saturate_cast<uchar>(
                    meansRow[c] + max(0., variancesRow[c] - noiseVariance) / max(variancesRow[c], noiseVariance) * (sourceImageRow[c] - meansRow[c])
                );
            }
        }
        imwrite("/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/WienerFilterImage1.jpeg", FilteredImage);
    }
};

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
