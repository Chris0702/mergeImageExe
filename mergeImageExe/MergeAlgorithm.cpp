#include <string>
#include "MergeAlgorithm.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>

MergeAlgorithm::MergeAlgorithm(){

}

MergeAlgorithm::MergeAlgorithm(vector<Image> mergeImageBase,Image mergeImageTarget,string savePath){
	this->mergeImageBase=mergeImageBase;
	this->mergeImageTarget=mergeImageTarget;
	this->savePath=savePath;
	widthCount=10;
	heightCount=10;
	bigImgWidth=400;
	bigImgHeight=600;
	weights=0.7;
	smallImgWidth=bigImgWidth/widthCount;
	smallImgHeight=bigImgHeight/heightCount;
	initImageSizeAll();
}

void MergeAlgorithm::initImageSizeAll() { 
	for(int i=0;i<mergeImageBase.size();i++){
		mergeImageBase[i].resize(smallImgWidth,smallImgHeight);
	}
	mergeImageTarget.resize(bigImgWidth,bigImgHeight);
}

void MergeAlgorithm::makeUpMergeImageBase(){
	int needBaseCount = widthCount*heightCount;
	int newBaseIndex=0;
	while(mergeImageBase.size()>needBaseCount){
		mergeImageBase.pop_back();
	}
	while(mergeImageBase.size()<needBaseCount){
		Image newBase = mergeImageBase[newBaseIndex%needBaseCount];
		mergeImageBase.push_back(newBase);
		newBaseIndex++;
	}
}

void MergeAlgorithm::mergeImageOne(Image srcImg,int offsetX,int offsetY) { 
	vector<RGB> srcImgRGB=srcImg.getRGB();
	for(int srcIndex=0;srcIndex<srcImgRGB.size();srcIndex++){
		for(int targetIndex=0;targetIndex<mergeImageTargetRGB.size();targetIndex++){
			if(srcImgRGB[srcIndex].x+offsetX==mergeImageTargetRGB[targetIndex].x&&srcImgRGB[srcIndex].y+offsetY==mergeImageTargetRGB[targetIndex].y){
				mergeImageTargetRGB[targetIndex].b=mergeImageTargetRGB[targetIndex].b*weights+srcImgRGB[srcIndex].b*(1-weights);
				mergeImageTargetRGB[targetIndex].g=mergeImageTargetRGB[targetIndex].g*weights+srcImgRGB[srcIndex].g*(1-weights);
				mergeImageTargetRGB[targetIndex].r=mergeImageTargetRGB[targetIndex].r*weights+srcImgRGB[srcIndex].r*(1-weights);
				targetIndex=mergeImageTargetRGB.size();
			}
		}
	}
	

}

void MergeAlgorithm::mergeImageAll() { 
	cout<<"開始合併\n";
	int baseIndex=0;
	for(int offsetX=0;offsetX<bigImgHeight;offsetX+=smallImgHeight){
		for(int offsetY=0;offsetY<bigImgWidth;offsetY+=smallImgWidth){
			mergeImageOne(mergeImageBase[baseIndex],offsetX,offsetY);
			baseIndex++;
			cout<<"總共"<<widthCount*heightCount<<"個，目前完成了: "<<baseIndex<<" 個\n";
		}
	}
}

void MergeAlgorithm::Exe() { 
	start = clock(); //開始時間
	//mergeImageTarget.info();
	mergeImageTargetRGB = mergeImageTarget.getRGB();
	makeUpMergeImageBase();
	mergeImageAll();
	mergeImageTarget.setRGB(mergeImageTargetRGB);
	stop = clock(); //結束時間
	cout << double(stop - start) / CLOCKS_PER_SEC <<endl;
	mergeImageTarget.saveImage(savePath);
	//mergeImageTarget.showImage();
}