#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>
#include <unistd.h>
#include <vector>                 

using namespace std;
using namespace cv;

struct CrossHair{
        int xcoor, ycoor;
};

//vector that stores all of the configuration files
vector<CrossHair> crosshairs;

//size of the crosshairs
int stroke;

//draws the crosshairs
void drawCrossHairs(Mat m);

//reads in cross hairs and pus them into the vector array
void readInCrossHairs(){
        
}

CrossHair initCH;

int main(int argc, char * argv[]){   

        //the configuration file for the coordinates
        ifstream file;
        file.open("coordinate_config.txt");
        
        CrossHair crosshair;

        string word;

        while(file >> word >> crosshair.xcoor >> word >> word >> crosshair.ycoor){ 
                cout << "X: " << crosshair.xcoor << " Y: " << crosshair.ycoor << endl;
                crosshairs.push_back(crosshair);
        }

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
                        
                        initCH.xcoor = atoi(string(argv[i + 1]).c_str());
                
                }else if(string(argv[i]) == "-y" || string(argv[i]) == "--ycoordinate" ){
 
                        initCH.ycoor = atoi(string(argv[i + 1]).c_str());

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
        
        file.close();
}

void drawCrossHairs(Mat m){

        //horizontal line
        line(m, Point(0, initCH.ycoor), Point(m.cols, initCH.ycoor), Scalar(24, 34, 243), stroke, 8, 0);
        
        //vertical line
        line(m, Point(initCH.xcoor, 0), Point(initCH.xcoor, m.rows), Scalar(100, 80, 200), stroke, 8, 0);

}
