#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]){
	// Start a capture section.
	cv::VideoCapture cap;
	// Check that the capture is on!
	if(!cap.open(0)){
		std::cerr << "Couldn't open capture." << std::endl;
		return 1;
	}

	while(1){

		// Create a frame.
		cv::Mat frame;
		
		// check if the frame is empty or not!
		if(!cap.read(frame)){
			std::cerr << "The frame is Empty! Mother fucker." << std::endl;
			break;
		}

		if(!cv::imwrite("/home/mejan/Pictures/test.jpg", frame)){
			std::cerr << "Couldn't fatch frame." << std::endl;
			break;
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			break;
		}
	}

	cap.release();
	return 0;	
}