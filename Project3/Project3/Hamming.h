#pragma once
#ifndef Hamming_h
#define Hamming_h
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>

class Hamming {
private:
	
	std::string base_image_filename;
	std::string locate_image_filename;
public:
	std::string print = "";
	Hamming(std::string img1, std::string img2) {
		base_image_filename = img1;
		locate_image_filename=img2;
	}
	void master() {
		/* Orb Stuff */

// Load Base and Locate image
		cv::Mat base_image = cv::imread(base_image_filename, cv::IMREAD_GRAYSCALE);
		cv::Mat locate_image = cv::imread(locate_image_filename, cv::IMREAD_GRAYSCALE);

		// Initiate ORB Detector Class within pointer.
		cv::Ptr<cv::FeatureDetector> detector = cv::ORB::create();

		// Finding key points.
		std::vector< cv::KeyPoint > keypoints_base_image;
		std::vector< cv::KeyPoint > keypoints_locate_image;

		// Find keypoints.
		detector->detect(base_image, keypoints_base_image);
		detector->detect(locate_image, keypoints_locate_image);

		detector.release();

		// Find descriptors.

		cv::Mat descriptors_base_image;
		cv::Mat descriptors_locate_image;

		cv::Ptr<cv::DescriptorExtractor> extractor = cv::ORB::create();

		extractor->compute(base_image, keypoints_base_image, descriptors_base_image);
		extractor->compute(locate_image, keypoints_locate_image, descriptors_locate_image);

		extractor.release();

		// Create Brute-Force Matcher. Hamming distance 
		cv::BFMatcher brute_force_matcher = cv::BFMatcher(cv::NORM_HAMMING, true);


		// Vector where matches will be stored.
		std::vector< cv::DMatch > matches;

		// Find matches and store in matches vector.
		brute_force_matcher.match((const cv::OutputArray)descriptors_base_image, (const cv::OutputArray)descriptors_locate_image, matches);

		// Sort them in order of their distance. The less distance, the better.
		sort_matches_increasing(matches);

		if (matches.size() > 20)
		{
			matches.resize(20);
		}

		cv::Mat output_image;

		this->print="Keypoints Base Size:" +std::to_string(keypoints_base_image.size()) + "\n" +"Keypoints Locate Size:" + std::to_string(keypoints_locate_image.size()) +"\n"+"Matches Size:" +std::to_string(matches.size()) + "\n";

		this->print+= "First " + std::to_string(matches.size()) + " Match Distance's:" + "\n";
		for (int i = 0; i < matches.size(); i++)
		{
			this->print += std::to_string(matches[i].distance) + ", ";
			if (i % 5 == 0 && i!=0)print += "\n";
		}

		cv::drawMatches(
			base_image, keypoints_base_image,
			locate_image, keypoints_locate_image,
			matches,
			output_image);

		

		cv::imwrite("pooProg\\test.jpg", output_image);

		cv::waitKey(0);
	}

	void sort_matches_increasing(std::vector< cv::DMatch >& matches) {
		for (int i = 0; i < matches.size(); i++)
		{
			for (int j = 0; j < matches.size() - 1; j++)
			{
				if (matches[j].distance > matches[j + 1].distance)
				{
					auto temp = matches[j];
					matches[j] = matches[j + 1];
					matches[j + 1] = temp;
				}
			}
		}
	}
};
#endif

