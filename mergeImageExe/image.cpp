#include "Image.h"
#include <iostream>


Image::Image(string imgPath){
	img= imread(imgPath);
}

void Image::showImage() { 
	namedWindow("Window");  
	imshow("Window",img);  
	//waitKey(0);  
}

void Image::test() { 
	cout<<"test";
}

