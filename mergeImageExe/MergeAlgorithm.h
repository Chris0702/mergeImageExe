#pragma once
#include <string>
#include <vector>
#include "Image.h"
#include <ctime>

using namespace std;
class MergeAlgorithm
{
public:
	MergeAlgorithm();
	MergeAlgorithm(vector<Image> mergeImageBase,Image mergeImageTarget,string savePath);
	void Exe();
	void test();

private:
	clock_t start, stop;
	double weights;
	string savePath;
	vector<RGB> mergeImageTargetRGB;
	vector<Image> mergeImageBase;
	Image mergeImageTarget;
	int bigImgWidth,bigImgHeight,smallImgWidth,smallImgHeight,widthCount,heightCount;
	void initImageSizeAll();
	void mergeImageOne(Image srcImg,int targetX,int targetY);
	void mergeImageAll();
	void makeUpMergeImageBase();
};