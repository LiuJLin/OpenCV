/*********************************************************************
	Copyright (C) 2016 JLin Liu. All rights reserved.  
	                                                                 
	> File Name:		< hellovideo.cpp >
	> Author:		< JLin Liu >
	> Mail:			< Liu_JLin@outlook.com >
	> Created Time:		< 2016/02/26 >
	> Last Changed:  
	> Description:  	A simple example from Opencv/Documents/opencv2reman Page9
				opencv调用摄像头采集图像，
				VideoCapture 的用法
************************************************************************/ 
 
 
#include <iostream>

#include <cv.h>
//#include <highgui.h>
//#include<core/core.hpp>
//#include<imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;  
//using namespace std; 


int main( int argc, char** argv )
{
	VideoCapture cap(1);                  //VideoCapture cap(0)调用电脑默认摄像头；VideoCapture cap(1)调用外部usb摄像头
	if(!cap.isOpened()) return -1;

	Mat frame, edges;
	namedWindow("edges",1);
	for(;;)
	{
		cap >> frame;
		cvtColor(frame, edges, CV_BGR2GRAY);//Converts an image from one color space to another，这里将frame转换为单通道的edges
	//	GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);//模糊处理
		Canny(edges, edges, 0, 30, 3);//canny算子，边缘处理
		imshow("edges", edges);
		if(waitKey(30) >= 0) break;
		
	}
	return 0;
}
