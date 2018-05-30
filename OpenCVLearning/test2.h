#pragma once
#include "include.h"
void SimpleChange(IplImage* image)
//����һ��ͼ�񲢽���ƽ������
{
	cvNamedWindow("һ���򵥵�ͼ�α任-in");
	cvNamedWindow("һ���򵥵�ͼ�α任-out");

	cvShowImage("һ���򵥵�ͼ�α任-in", image);

	IplImage* out = cvCreateImage(
		cvGetSize(image),
		IPL_DEPTH_8U,
		3
	);
	/*
		1��cvCreateImage()��������һ��ͼ�񣬵�һ��������һ��CvSize�ṹ,����ṹ������
			cvGetSize(image)��ã�˵����ǰͼ��ṹ�Ĵ�С���ڶ��������������Ǹ���ͨ��ÿ��
			���ص���������ͣ����һ������˵����ͨ��������
			
	*/
	cvSmooth(image, out, CV_GAUSSIAN, 3, 3);
	cvShowImage("һ���򵥵�ͼ�α任-out" ,out);

	cvReleaseImage(&out);
	cvWaitKey(0);
	cvDestroyWindow("һ���򵥵�ͼ�α任-in");
	cvDestroyWindow("һ���򵥵�ͼ�α任-out");
}

void ShowImage(IplImage* image)
{
	cvNamedWindow("A Image", CV_WINDOW_AUTOSIZE);
	cvShowImage("A Image", image);
	cvWaitKey(0);
	cvReleaseImage(&image);
	cvDestroyWindow("A Image");
}

IplImage* doPyrDown(
	IplImage* in, 
	int filter = CV_GAUSSIAN_5x5
){
	assert(in->width % 2 == 0 && in->height % 2 == 0);

	IplImage* out = cvCreateImage(
		cvSize(in->width / 2, in->height / 2),
		in->depth,
		in->nChannels
	);
	cvPyrDown(in, out);
	return (out);

}

IplImage* doCanny(
	IplImage* in ,
	double  lowThresh,
	double	highThresh,
	double	aperture
) {
	if (in->nChannels != 1)
		return(0);
	IplImage* out = cvCreateImage(
		cvGetSize(in),
		IPL_DEPTH_8U,
		1
	);
	cvCanny(in, out, lowThresh, highThresh, aperture);
	return (out);
}