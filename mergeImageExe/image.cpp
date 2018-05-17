#include "Image.h"
#include <iostream>

using namespace cv;

Image::Image(){
	img= imread("");
	savePath = "";
	orgPath="";
}


Image::Image(string imgPath){
	img= imread(imgPath);
	savePath = "";
	orgPath=imgPath;
}

void Image::resize(int width,int height) {
	Size dsize = Size(width,height);
	Mat tmp = Mat(dsize,CV_32S);
	cv::resize(img, tmp,dsize);
	img=tmp;
}

vector<RGB> Image::getRGB() { 
	vector<RGB> result;
	for (int i = 0; i < img.rows; i++)
	{
		uchar* pt = img.ptr<uchar>(i);
		for (int j = 0, k = 0; j < img.cols; j++)
		{
			RGB rgb;
			rgb.b=pt[k];
			rgb.g=pt[k+1];
			rgb.r=pt[k+2];
			rgb.x=i;
			rgb.y=j;
			result.push_back(rgb);
			k = k + 3;
		}
	}
	return result;
}

void Image::setRGB(vector<RGB> RGBVector) {
	int vectorIndex=0;
	if(RGBVector.size()<=0){
		return;
	}
	for (int i = 0; i < img.rows; i++)
	{
		uchar* pt = img.ptr<uchar>(i);
		for (int j = 0, k = 0; j < img.cols; j++)
		{
			if(vectorIndex<RGBVector.size())
			{
				pt[k] = RGBVector[vectorIndex].b;    // blue通道
				pt[k + 1] = RGBVector[vectorIndex].g;  // green通道
				pt[k + 2] = RGBVector[vectorIndex].r;  // red通道
				vectorIndex++;
			}
			k = k + 3;
		}
	}
}

void Image::showImage() { 
	namedWindow("Window");  
	imshow("Window",img);  
	waitKey(0);  
}

void Image::setSavePath(string savePath) { 
	this->savePath=savePath;
}

void Image::saveImage(string savePath) { 
	imwrite( savePath, img );
}

void Image::saveImage() { 
	imwrite( savePath, img );
}

void Image::info() { 
	cout<<"========cols=========\n";
	cout<<img.cols<<"\n";
	cout<<"========rows=========\n";
	cout<<img.rows<<"\n";
	cout<<"========step=========\n";
	cout<<img.step<<"\n";
	cout<<"========elemSize=========\n";
	cout<<img.elemSize()<<"\n";
	cout<<"========channels=========\n";
	cout<<img.channels()<<"\n";
	cout<<"========total=========\n";
	cout<<img.total()<<"\n";
}

