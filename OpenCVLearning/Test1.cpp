#include <ostream>
#include "test1.h"
#include "test2.h"
using namespace std;

int main()
{
	char Imagepath[] = "C:\\Users\\dcl\\Pictures\\test\\image1.jpg";
	char Videopath[] = "C:\\Users\\dcl\\Videos\\test\\FlickAnimation.avi";

	/*cout << "����һ��ͼƬ" << endl;
	OpenAImage(Imagepath);
	cout << "����һ��AVI��Ƶ" << endl;
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


