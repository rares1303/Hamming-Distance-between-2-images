// let's start with including libraries 
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

class Images {

public: 
	
	Mat image;
	Mat image2;

	void resize_Images(){
	

		Mat resized_down1, resized_down2;

		image = imread("boy.jpg");
		image2 = imread("boy2.jpg");

		if (image.size().width > image2.size().width && image.size().height > image2.size().height) {
			resize(image, resized_down1, Size(image2.size().width, image2.size().height), INTER_LINEAR);
			imshow("Resized Image 1", resized_down1);
			waitKey();
			imshow("Image 2", image2);
			waitKey();
		}
		else {
			resize(image2, resized_down2, Size(image.size().width, image.size().height), INTER_LINEAR);
			imshow("Image 1", image);
			waitKey();
			imshow("Resized Image 2", resized_down2);
			waitKey();
		}

	}

};

int main()
{
	// Read the image using imread function
	Images image;
	
	image.resize_Images();
	

	destroyAllWindows();
	return 0;
}