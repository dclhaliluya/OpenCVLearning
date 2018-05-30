#pragma once
#include "include.h"
void SimpleChange(IplImage* image)
//载入一个图像并进行平滑处理
{
	cvNamedWindow("一个简单的图形变换-in");
	cvNamedWindow("一个简单的图形变换-out");

	cvShowImage("一个简单的图形变换-in", image);

	IplImage* out = cvCreateImage(
		cvGetSize(image),
		IPL_DEPTH_8U,
		3
	);
	/*
		1、cvCreateImage()自主创建一个图像，第一个参数是一个CvSize结构,这个结构可以由
			cvGetSize(image)获得，说明当前图像结构的大小；第二个参数告诉我们各个通道每个
			像素点的数据类型；最后一个参数说明了通道的总数
			
	*/
	cvSmooth(image, out, CV_GAUSSIAN, 3, 3);
	cvShowImage("一个简单的图形变换-out" ,out);

	cvReleaseImage(&out);
	cvWaitKey(0);
	cvDestroyWindow("一个简单的图形变换-in");
	cvDestroyWindow("一个简单的图形变换-out");
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