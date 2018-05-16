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
	mergeImageTarget.resize(500,600);
	mergeImageTarget.showImage();
}