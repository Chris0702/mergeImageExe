#pragma once
#include <string>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include "opencv2/opencv.hpp"
#include <vector>

using namespace cv;
using namespace std;

struct RGB{
	int r;
	int g;
	int b;
	int x;
	int y;
};

class Image
{
	Mat img;
	
public:
	Image();
	Image(string);
	void resize(int width,int height);
	void showImage();
	vector<RGB> getRGB();
	void setRGB(vector<RGB>);
	void info();

};