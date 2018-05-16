#pragma once
#include <string>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include "opencv2/opencv.hpp"

using namespace cv;

using namespace std;
class Image
{
	Mat img;
public:
	Image();
	Image(string);
	void resize(int width,int height);
	void showImage();
	void info();

};