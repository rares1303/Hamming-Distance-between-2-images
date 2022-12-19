#include<opencv2/opencv.hpp>
#include<iostream>
#include "Image_Resizing.h"

using namespace std;
using namespace cv;


int main()
{

	Images image;
	
	image.resize_Images();
	

	destroyAllWindows();
	return 0;
}