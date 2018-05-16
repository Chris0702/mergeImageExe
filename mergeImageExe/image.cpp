#include "Image.h"
#include <iostream>

using namespace cv;

Image::Image(){
	img= imread("");
}


Image::Image(string imgPath){
	img= imread(imgPath);
}

void Image::resize(int width,int height) {
	Size dsize = Size(width,height);
	Mat tmp = Mat(dsize,CV_32S);
	cv::resize(img, tmp,dsize);
	img=tmp;
}

void Image::showImage() { 
	namedWindow("Window");  
	imshow("Window",img);  
	waitKey(0);  
}

void Image::info() { 
	//int a = img.col;
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
	//img.
	
}

