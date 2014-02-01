#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <unistd.h>
                 
using namespace std;
using namespace cv;


int xcoor, ycoor;

//size of the crosshairs
int stroke;

//draws the crosshairs
void drawCrossHairs(Mat m);

//

int main(int argc, char * argv[]){
        
        Mat m;
        namedWindow("Crosshaired Image", 0);

        for(int i = 0; i < argc; i++){
                if(string(argv[i]) == "-f" || string(argv[i]) == "--feed" ){
                       
                VideoCapture cap("rtsp://192.168.0.100/axis-media/media.amp");
                
                if(!cap.isOpened()){
                        cout << "Unable to get camera";
                        return -1;
                }
                
                m.release();
                cap.read(m);   
                
                }else if(string(argv[i]) == "-d" ||string(argv[i]) == "--file"){
                       
                        m = imread(argv[i + 1]);
                
                }else if(string(argv[i]) == "-x" || string(argv[i]) == "--xcoordinate" ){
                        
                        xcoor = atoi(string(argv[i + 1]).c_str());
                
                }else if(string(argv[i]) == "-y" || string(argv[i]) == "--ycoordinate" ){
 
                        ycoor = atoi(string(argv[i + 1]).c_str());

                }else if(string(argv[i]) == "-s" ||string(argv[i]) == "--stroke"){
                 
                        stroke = atoi(String(argv[i + 1]).c_str());

                }else if(string(argv[i]) == "--help"){
                        
                        cout << "-r || --feed \t\t\t Grabs image from camera feed" << endl;
                        cout << "-d || --file \t\t\t Grabs image from file <filename>" << endl;
                        cout << "-x || --xcoordinate \t\t\t Sets the x coordinate" << endl;
                        cout << "-y || --ycoordinate \t\t\t Sets the y coordinate" << endl;       
                }
        }
        
        drawCrossHairs(m);
        
        imshow("Crosshaired Image", m);
        waitKey(0);
}

void drawCrossHairs(Mat m){

        //horizontal line
        line(m, Point(0, ycoor), Point(m.cols, ycoor), Scalar(24, 34, 243), stroke, 8, 0);
        
        //vertical line
        line(m, Point(xcoor, 0), Point(xcoor, m.rows), Scalar(100, 80, 200), stroke, 8, 0);
}
