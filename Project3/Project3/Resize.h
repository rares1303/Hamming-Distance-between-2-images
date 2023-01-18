#pragma once
#ifndef Image_Resizing_h
#define Image_Resizing_h
#include<opencv2/opencv.hpp>

class Images {

public:
	int k;
	cv::Mat image;
	cv::Mat image2;

	void resize_Images(std::string img1, std::string img2) {


		cv::Mat resized_down1, resized_down2;

		image = cv::imread(img1);
		image2 = cv::imread(img2);

		if (image.size().width > image2.size().width && image.size().height > image2.size().height) {
			resize(image, resized_down1, cv::Size(image2.size().width, image2.size().height), cv::INTER_LINEAR);
			imwrite("C:\\pooProg\\Resized_Image1.png", resized_down1);
			imwrite("C:\\pooProg\\Image_2.png", image2);
			this->k = 0;
		}
		else {
			resize(image2, resized_down2, cv::Size(image.size().width, image.size().height), cv::INTER_LINEAR);
			imwrite("C:\\pooProg\\Image_1.png", image);
			imwrite("C:\\pooProg\\Resized_Image2.png", resized_down2);
			this->k = 1;
		}

	}

};

#endif /* Image_Filtering_h */
