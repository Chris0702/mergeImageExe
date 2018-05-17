#include <string>
#include "MergeAlgorithm.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>

MergeAlgorithm::MergeAlgorithm(){
	
}

MergeAlgorithm::MergeAlgorithm(vector<Image> mergeImageBase,Image mergeImageTarget){
	this->mergeImageBase=mergeImageBase;
	this->mergeImageTarget=mergeImageTarget;
	widthCount=4;
	heightCount=6;
	bigImgWidth=800;
	bigImgHeight=1200;
	smallImgWidth=bigImgWidth/widthCount;
	smallImgHeight=bigImgHeight/heightCount;
	initImageSizeAll();
}

void MergeAlgorithm::initImageSizeAll() { 
	cout<<"initImageSizeAll\n";
	for(int i=0;i<mergeImageBase.size();i++){
		mergeImageBase[i].resize(smallImgWidth,smallImgHeight);
	}
	mergeImageTarget.resize(bigImgWidth,bigImgHeight);
}

void MergeAlgorithm::mergeImageOne(Image srcImg,int targetX,int targetY) { 
	cout<<"mergeImageOne\n";
	
}

void MergeAlgorithm::Exe() { 
	cout<<"exe\n";
	mergeImageTarget.info();
	vector<RGB> test = mergeImageTarget.getRGB();
	mergeImageTarget.setRGB(test);
	//mergeImageTarget.resize(500,600);
	mergeImageTarget.showImage();
}