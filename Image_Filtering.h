#ifndef Image_Filtering_h
#define Image_Filtering_h

class Filter_Image{
public:
    
    cv::Mat SourceImage;
    cv::Mat FilteredImage;
    cv::String sourcePath;
    
    void apply_filters(){
        
        //----------image import from sourcePath
        SourceImage = cv::imread(sourcePath);
        
        //----------median blur
        medianBlur(SourceImage, FilteredImage, 7);
        imwrite("/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/MedianBlurImage1.jpeg", FilteredImage);
        
        //----------bilateral filter
        bilateralFilter(SourceImage, FilteredImage, 37, 37*2, 37/2);
        imwrite("/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/BilateralFilterImage1.jpeg", FilteredImage);
        
        //----------wiener filter
        cv::Mat SourceImageGrayscale = imread(sourcePath, cv::IMREAD_GRAYSCALE);
        const cv::Size block = cv::Size(6,6);
        double noiseVariance = 6000;
        
        int h = SourceImageGrayscale.rows;
        int w = SourceImageGrayscale.cols;

        FilteredImage = cv::Mat1b(h, w);

        cv::Mat1d means, sqrMeans, variances;
        cv::Mat1d avgVarianceMat;

        boxFilter(SourceImageGrayscale, means, CV_64F, block, cv::Point(-1, -1), true, cv::BORDER_REPLICATE);
        sqrBoxFilter(SourceImageGrayscale, sqrMeans, CV_64F, block, cv::Point(-1, -1), true, cv::BORDER_REPLICATE);

        cv::Mat1d means2 = means.mul(means);
        variances = sqrMeans - (means.mul(means));

        if (noiseVariance < 0){
            
            //estimating the noiseVariance
            reduce(variances, avgVarianceMat, 1, cv::REDUCE_SUM, -1);
            reduce(avgVarianceMat, avgVarianceMat, 0, cv::REDUCE_SUM, -1);
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
                filteredImageRow[c] = cv::saturate_cast<uchar>(
                    meansRow[c] + cv::max(0., variancesRow[c] - noiseVariance) / cv::max(variancesRow[c], noiseVariance) * (sourceImageRow[c] - meansRow[c])
                );
            }
        }
        imwrite("/Users/mihnea/Documents/XCODE/WienerFilter/WienerFilter/WienerFilterImage1.jpeg", FilteredImage);
    }
};

#endif /* Image_Filtering_h */
