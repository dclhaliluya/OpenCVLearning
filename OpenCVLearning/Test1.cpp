#include <ostream>
#include <opencv2/opencv.hpp>
#include <Windows.h>
using namespace cv;
using namespace std;


void OpenAImage(char * path)
{
	IplImage* img = cvLoadImage(path);
	cvNamedWindow("第一个opencv程序", CV_WINDOW_AUTOSIZE);
	cvShowImage("第一个opencv程序", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("第一个opencv程序");
	/*
	1、cvLoadImage 将图像文件加载至内存
	2、cvNamedWindow 是高层调用接口，用于在屏幕创建一个窗口，第一个参数指定窗口的标题，
	第二参数指定窗口的属性（设置为0时窗口大小不会因图像大小而改变，CV_WINDOW_AUTOSIZE则根据图像大小自动缩放）
	3、cvShowImage在创建好的窗口中显示图像；第一个参数确定在哪个	已存在的窗口中显示图像，窗口会重新绘制
	4、cvWaitKey使程序暂停


	*/
}
void OpenAVideo(char *path)
{
	cvNamedWindow("打开一个视频",CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(path);
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("打开一个视频", frame);
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("打开一个视频");
}
int main()
{
	char Imagepath[] = "C:\\Users\\dcl\\Pictures\\test\\image1.jpg";
	char Videopath[] = "C:\\Users\\dcl\\Videos\\test\\FlickAnimation.avi";
	cout << "加载一个图片" << endl;
	OpenAImage(Imagepath);
	cout << "加载一个AVI视频" << endl;
	OpenAVideo(Videopath);
	system("pause");
}


