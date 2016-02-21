#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){

	// open the video camera no. 0
	VideoCapture cap(0); 

	// if not success, exit program
	if (!cap.isOpened()){  
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	//get the width of frames of the video
	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	//get the height of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); 

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	//create a window called "MyVideo"
	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE);

	while (1){
		
		Mat frame;

		// read a new frame from video
		bool bSuccess = cap.read(frame); 

		//if not success, break loop
		if (!bSuccess) {
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		//show the frame in "MyVideo" window
		imshow("MyVideo", frame); 

		//wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		if (waitKey(30) == 27) {
			cout << "esc key is pressed by user" << endl;
			break; 
		}
	}
	return 0;

}