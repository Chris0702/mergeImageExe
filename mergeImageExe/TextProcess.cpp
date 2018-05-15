#include <string>
#include "TextProcess.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string> 

TextProcess::TextProcess(){
}

void TextProcess::test() { 
	cout<<"test";
}

string TextProcess::wchar_t2String(wchar_t* txt) { 
	wstring ws(txt);
	// your new String
	string str(ws.begin(), ws.end());
	return str;
}

vector<string> TextProcess::getSplitStr(char* txt) { 
	vector<string> result;
	string txtStr(txt);
	string tmp = "";
	for(int i=0;i<txtStr.length();i++){
		//cout<<"str i \n";
		//cout<<txtStr[i]<<" \n";
		if(txtStr[i]==','){
			result.push_back(tmp);
			tmp="";
		}else{
			tmp =tmp+txtStr[i];
		}
	}
	if(txtStr.length()>0){
		result.push_back(tmp);
	}
	return result;

}