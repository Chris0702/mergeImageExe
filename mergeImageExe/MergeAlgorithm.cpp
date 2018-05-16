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
}

void MergeAlgorithm::Exe() { 
	cout<<"exe";
	mergeImageTarget.info();
	vector<RGB> test = mergeImageTarget.getRGB();
	mergeImageTarget.setRGB(test);
	//mergeImageTarget.resize(500,600);
	mergeImageTarget.showImage();
}