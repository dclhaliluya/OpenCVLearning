#pragma once

#include "include.h"
using namespace cv;



int		g_slider_position = 0;	//��������λ��
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
	cvNamedWindow("��ӹ���������Ƶ", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture(path);
	int frames = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
	);
	if (frames != 0)
	{
		cvCreateTrackbar(
			"Position",
			"��ӹ���������Ƶ",
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
		cvShowImage("��ӹ���������Ƶ", frame);
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("��ӹ���������Ƶ");
	/*
	1��cvCreateTrackbar()������һ��������������ͨ�����ò���ȷ�������������ڵĴ���
	2��cvSetCaptureProperty()��cvGetCaptureProperty() ���ף���Щ���������������ã����ѯ��
	CvCapture����ĸ������ԡ���������CV_CAP_PROP_POS_FRAMES��ʾ������֡�������ö���λ�ã�
	���������ͨ����Ƶ���ȱ��������ö���λ�ã�����ͨ��AVI_RATO����FRAMESʵ��
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
	1��cvLoadImage ��ͼ���ļ��������ڴ�
	2��cvNamedWindow �Ǹ߲���ýӿڣ���������Ļ����һ�����ڣ���һ������ָ�����ڵı��⣬
	�ڶ�����ָ�����ڵ����ԣ�����Ϊ0ʱ���ڴ�С������ͼ���С���ı䣬
	CV_WINDOW_AUTOSIZE�����ͼ���С�Զ����ţ�
	3��cvShowImage�ڴ����õĴ�������ʾͼ�񣻵�һ������ȷ�����ĸ�	�Ѵ��ڵĴ�������ʾͼ�񣬴��ڻ����»���
	4��cvWaitKeyʹ������ͣ
	5��cvReleaseImage��������ص��ڴ��ͼ���ļ�������������ͷ�Ϊ��ͼ���ļ���������ڴ�
	6��cvDestoryWindow������ʾ����
	*/
}
void OpenAVideo(char *path)
{
	cvNamedWindow("��һ����Ƶ", CV_WINDOW_AUTOSIZE);
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
	/*
	1��cvCreateFileCapture()ͨ����������ȷ��Ҫ��ȡ��AVI��Ƶ������һ��CvCapture�ṹ��ָ��
	2��CvCapture�ṹ�������й���Ҫ�����AVI��Ƶ��������Ϣ
	3��cvQueryFrame() ��������һ֡��Ƶ�ļ������ڴ棨ʵ�����������CvCapture�ṹ��
	4��
	*/
}