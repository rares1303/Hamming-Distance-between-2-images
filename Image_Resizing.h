#ifndef Image_Resizing_h
#define Image_Resizing_h


class Images {

public:

	cv::Mat image;
	cv::Mat image2;

	void resize_Images() {


		cv::Mat resized_down1, resized_down2;

		image = cv::imread("boy.jpg");
		image2 = cv::imread("boy2.jpg");

		if (image.size().width > image2.size().width && image.size().height > image2.size().height) {
			resize(image, resized_down1, cv::Size(image2.size().width, image2.size().height), cv::INTER_LINEAR);
			imwrite("Resized_Image1.png", resized_down1);
			imwrite("Image_2.png", image2);
		}
		else {
			resize(image2, resized_down2, cv::Size(image.size().width, image.size().height), cv::INTER_LINEAR);
			imwrite("Image_1.png", image);
			imwrite("Resized_Image2.png", resized_down2);
		}

	}

};

#endif /* Image_Filtering_h */
