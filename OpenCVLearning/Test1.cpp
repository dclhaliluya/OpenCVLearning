#include <ostream>
#include "test1.h"
#include "test2.h"
using namespace std;

int main()
{
	char Imagepath[] = "C:\\Users\\dcl\\Pictures\\test\\image1.jpg";
	char Videopath[] = "C:\\Users\\dcl\\Videos\\test\\FlickAnimation.avi";

	/*cout << "加载一个图片" << endl;
	OpenAImage(Imagepath);
	cout << "加载一个AVI视频" << endl;
	OpenAVideo(Videopath);*/
	//AVIVideoUTrack(Videopath);
	IplImage* in = cvLoadImage(Imagepath);
	//SimpleChange(image);
	//IplImage* newImage = doPyrDown(image);
	//IplImage* newImage = doCanny(image,1,1,1);
	IplImage* img1 = doPyrDown(in, CV_GAUSSIAN_5x5);
	IplImage* img2 = doPyrDown(img1, CV_GAUSSIAN_5x5);
	IplImage* img3 = doCanny(img2, 10,100,3);

	ShowImage(img3);

	system("pause");
}


