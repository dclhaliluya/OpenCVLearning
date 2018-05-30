#include <ostream>
#include <opencv2/opencv.hpp>
#include <Windows.h>
using namespace cv;
using namespace std;


void OpenAImage(char * path)
{
	IplImage* img = cvLoadImage(path);
	cvNamedWindow("��һ��opencv����", CV_WINDOW_AUTOSIZE);
	cvShowImage("��һ��opencv����", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("��һ��opencv����");
	/*
	1��cvLoadImage ��ͼ���ļ��������ڴ�
	2��cvNamedWindow �Ǹ߲���ýӿڣ���������Ļ����һ�����ڣ���һ������ָ�����ڵı��⣬
	�ڶ�����ָ�����ڵ����ԣ�����Ϊ0ʱ���ڴ�С������ͼ���С���ı䣬CV_WINDOW_AUTOSIZE�����ͼ���С�Զ����ţ�
	3��cvShowImage�ڴ����õĴ�������ʾͼ�񣻵�һ������ȷ�����ĸ�	�Ѵ��ڵĴ�������ʾͼ�񣬴��ڻ����»���
	4��cvWaitKeyʹ������ͣ


	*/
}
void OpenAVideo(char *path)
{
	cvNamedWindow("��һ����Ƶ",CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(path);
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("��һ����Ƶ", frame);
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("��һ����Ƶ");
}
int main()
{
	char Imagepath[] = "C:\\Users\\dcl\\Pictures\\test\\image1.jpg";
	char Videopath[] = "C:\\Users\\dcl\\Videos\\test\\FlickAnimation.avi";
	cout << "����һ��ͼƬ" << endl;
	OpenAImage(Imagepath);
	cout << "����һ��AVI��Ƶ" << endl;
	OpenAVideo(Videopath);
	system("pause");
}


