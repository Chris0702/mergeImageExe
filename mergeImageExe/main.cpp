// mergeImageExe.cpp : Defines the entry point for the console application.
//


#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string> 
#include "TextProcess.h"
#include "Image.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace std;

int main(int argc, char* argv[])
{
	TextProcess textProcess =TextProcess();
	textProcess.test();
	//Image image = Image("D:/chris-work/mergeImageExe/image/test.png");
	//image.showImage();
	vector<string> mergeImageBase;
	string mergeImageTarget="";
	cout<<"argv\n";
	cout<<argv<<"\n";
	cout<<"argc\n";
	cout<<argc<<"\n";
	
	if(argc>1){
		mergeImageBase=textProcess.getSplitStr(argv[1]);
		string tmp(argv[2]);
		mergeImageTarget=tmp;
	}
	
	for(int i=0;i<argc;i++){
		cout<<i<<"\n";
		cout<<argv[i]<<"\n";



	}
	
	/*
	if(argc>1){
	wcout<<argv[1];
	wcout<<argv[2];
	}
	*/
	//waitKey(0); 

	/*
	string mergeBaseStr = textProcess.wchar_t2String(argv[1]);
	string mergeTargetStr = textProcess.wchar_t2String(argv[2]);
	cout<<mergeBaseStr<<"\n";
	cout<<mergeTargetStr<<"\n";
	waitKey(0); 
	*/


	/*
	for(int i=0;i<argc;i++){
		cout<<i<<"\n";
		wcout<<argv[i]<<"\n";
		cout<<textProcess.wchar_t2String(argv[i])<<"\n";
	}
	*/

	system("pause");
	return 0;
}

