#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <unistd.h>
                 
using namespace std;
using namespace cv;

int main(int argc, char * argv[]){
        Mat m;
        for(int i = 0; i < argc; i++){
                if(string(argv[i]) == "-f" || string(argv[i]) == "--feed" ){
                       
                VideoCapture cap("rtsp://192.168.0.100/axis-media/media.amp");
                
                if(!cap.isOpened()){
                        cout << "Unable to get camera";
                        return -1;
                }
                
                m.release();
                cap.read(m);   
                }

        }
}
