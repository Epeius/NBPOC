#include <stdio.h>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utility.hpp>

using namespace cv; 
using namespace std;


int main(int argc, char** argv){
    const string dst_file = cv::tempfile(".png");
    try{
		Mat reference_image = imread(argv[1], IMREAD_GRAYSCALE );
		imwrite(dst_file, reference_image);
		remove(dst_file.c_str());
		
	}
	catch (cv::Exception){
		return 0;
	}
    
	return 0;
}
	
