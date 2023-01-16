#ifndef Hamming_h
#define Hamming_h

class Hamming {
private:
	std::string base_image_filename = "image1.jpg";
	std::string locate_image_filename = "image2.jpg";
public:
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

		std::cout << "Keypoints Base Size:" << keypoints_base_image.size() << std::endl
			<< "Keypoints Locate Size:" << keypoints_locate_image.size() << std::endl
			<< "Matches Size:" << matches.size() << std::endl;

		std::cout << "First " << matches.size() << " Match Distance's:" << std::endl;
		for (int i = 0; i < matches.size(); i++)
		{
			std::cout << matches[i].distance << ", ";
		}
		std::cout << std::endl;

		cv::drawMatches(
			base_image, keypoints_base_image,
			locate_image, keypoints_locate_image,
			matches,
			output_image);

		cv::imshow("Matches", output_image);

		cv::imwrite("test.jpg", output_image);

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
