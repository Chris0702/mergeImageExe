#pragma once
#include <string>
#include <vector>
#include "Image.h"

using namespace std;
class MergeAlgorithm
{
public:
	MergeAlgorithm();
	MergeAlgorithm(vector<Image> mergeImageBase,Image mergeImageTarget);
	void Exe();
	void test();

private:
	vector<Image> mergeImageBase;
	Image mergeImageTarget;
	
};