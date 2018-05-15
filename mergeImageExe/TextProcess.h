#include <string>
#include <vector>

using namespace std;
class TextProcess
{
public:
	TextProcess();
	void test();
	string wchar_t2String(wchar_t*);
	vector<string> getSplitStr(char*);
};