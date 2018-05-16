#pragma once
#include <string>
#include <vector>

using namespace std;
class TextProcess
{
public:
	TextProcess();
	void test();
	string wchar_t2String(wchar_t*);
	string getDirnamePath(char*);
	string getDirnamePath(string);
	vector<string> getSplitStr(char*);
};