// mergeImageExe.cpp : Defines the entry point for the console application.
//
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string> 
#include "TextProcess.h"
#include "Image.h"
#include "MergeAlgorithm.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace std;

vector<string> getMergeImageBasePath(string dirname,char* localStr){
	TextProcess textProcess =TextProcess();
	vector<string> mergeImageBasePath=textProcess.getSplitStr(localStr);
	for(int i=0;i<mergeImageBasePath.size();i++){
		mergeImageBasePath[i]=dirname+"\\"+mergeImageBasePath[i];
	}
	return mergeImageBasePath;
}

vector<Image> getMergeImageBase(vector<string> mergeImageBasePath){
	vector<Image> mergeImageBase;
	for(int i=0;i<mergeImageBasePath.size();i++){
		Image item = Image(mergeImageBasePath[i]);
		mergeImageBase.push_back(item);
	}
	return mergeImageBase;
}

int main(int argc, char* argv[])
{
	if(argc<=1){
		cout<<"沒給參數";
		return 0;
	}
	cout<<"argv\n";
	cout<<argv<<"\n";
	cout<<"argc\n";
	cout<<argc<<"\n";
	TextProcess textProcess;
	textProcess.test();
	string dirname=textProcess.getDirnamePath(argv[0]);
	string mergeImageDir=textProcess.getDirnamePath(dirname)+"\\client";
	string mergeImageTargetPath(argv[2]);
	mergeImageTargetPath=mergeImageDir+"\\"+mergeImageTargetPath;
	vector<string> mergeImageBasePath = getMergeImageBasePath(mergeImageDir,argv[1]);
	Image mergeImageTarget = Image(mergeImageTargetPath);
	vector<Image> mergeImageBase=getMergeImageBase(mergeImageBasePath);
	MergeAlgorithm mergeAlgorithm(mergeImageBase,mergeImageTarget);
	mergeAlgorithm.Exe();
	

	system("pause");
	return 0;
}

