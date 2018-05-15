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