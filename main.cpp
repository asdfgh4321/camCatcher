#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
	VideoCapture cap(0);
	//if not able to open cam.
	if (!cap.isOpened() ){
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	namedWindow("Cam catch",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    	while(1)
    	{
	        Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess){
                        cout << "Cannot read the frame from video file" << endl;
			break;
		}

		imshow("MyVideo", frame); //show the frame in "MyVideo" window

		//wait for 'anykey' to be pressed. If 'anykey is pressed, break loop
		if(waitKey(30) > 0){
			cout << "anykey pressed by user" << endl;
			break; 
		}
	}

	return 0;

}
