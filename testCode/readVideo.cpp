#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
	
	// open the video file for reading
	VideoCapture cap("/media/seriger/Banshee/S01/Banshee.S01E06.HDTV.x264-2HD [eztv].avi"); 

	// if not success, exit program
	if ( !cap.isOpened() ){  
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	//start the video at 300ms
	//cap.set(CV_CAP_PROP_POS_MSEC, 300); 

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	 cout << "Frame per seconds : " << fps << endl;

	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	while(1) {
		Mat frame;

		// read a new frame from video
		bool bSuccess = cap.read(frame);

		//if not success, break loop
		if (!bSuccess) {
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		//show the frame in "MyVideo" window
		imshow("MyVideo", frame); 

		//wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		if(waitKey(30) == 27) {
			cout << "esc key is pressed by user" << endl; 
			break; 
		}
	}

	return 0;

}