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
	int x;//height
	int y;//width
};

class Image
{
	Mat img;
	string savePath;
	string orgPath;

public:
	Image();
	Image(string);
	void resize(int width,int height);
	void showImage();
	void saveImage();
	void saveImage(string);
	vector<RGB> getRGB();
	void setRGB(vector<RGB>);
	void info();
	void setSavePath(string);

};