#include <string>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

using namespace std;
class Image
{
	Mat img;
public:
	Image(string);
	void showImage();
	void test();

};