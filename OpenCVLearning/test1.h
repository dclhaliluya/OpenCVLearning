#pragma once

#include "include.h"
using namespace cv;



int		g_slider_position = 0;	//滚动条的位置
CvCapture* g_capture = NULL;


void onTrackBarSlider(int pos)
{
	cvSetCaptureProperty(
		g_capture,
		CV_CAP_PROP_POS_FRAMES,
		pos
	);
}

void AVIVideoUTrack(char *path)
{
	cvNamedWindow("添加滚动条的视频", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture(path);
	int frames = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
	);
	if (frames != 0)
	{
		cvCreateTrackbar(
			"Position",
			"添加滚动条的视频",
			&g_slider_position,
			frames,
			onTrackBarSlider
		);
	}
	IplImage *frame;
	while (1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame) break;
		cvShowImage("添加滚动条的视频", frame);
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("添加滚动条的视频");
	/*
	1、cvCreateTrackbar()来创建一个滚动条，并且通过设置参数确定滚动条所属于的窗口
	2、cvSetCaptureProperty()和cvGetCaptureProperty() 配套，这些函数允许我们设置（或查询）
	CvCapture对象的各种属性。本函数中CV_CAP_PROP_POS_FRAMES表示我们以帧数来设置读入位置，
	如果我们想通过视频长度比例来设置读入位置，可以通过AVI_RATO代替FRAMES实现
	*/
}

void OpenAImage(char * path)
{
	IplImage* img = cvLoadImage(path);
	cvNamedWindow("A Image", CV_WINDOW_AUTOSIZE);
	cvShowImage("A Image", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("A Image");
	/*
	1、cvLoadImage 将图像文件加载至内存
	2、cvNamedWindow 是高层调用接口，用于在屏幕创建一个窗口，第一个参数指定窗口的标题，
	第二参数指定窗口的属性（设置为0时窗口大小不会因图像大小而改变，
	CV_WINDOW_AUTOSIZE则根据图像大小自动缩放）
	3、cvShowImage在创建好的窗口中显示图像；第一个参数确定在哪个	已存在的窗口中显示图像，窗口会重新绘制
	4、cvWaitKey使程序暂停
	5、cvReleaseImage：用完加载到内存的图像文件，这个函数就释放为该图像文件所分配的内存
	6、cvDestoryWindow销毁显示窗口
	*/
}
void OpenAVideo(char *path)
{
	cvNamedWindow("打开一个视频", CV_WINDOW_AUTOSIZE);
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
	/*
	1、cvCreateFileCapture()通过参数设置确定要读取的AVI视频，返回一个CvCapture结构的指针
	2、CvCapture结构包含所有关于要读入的AVI视频的所有信息
	3、cvQueryFrame() 用来将下一帧视频文件载入内存（实际是填充或更新CvCapture结构）
	4、
	*/
}