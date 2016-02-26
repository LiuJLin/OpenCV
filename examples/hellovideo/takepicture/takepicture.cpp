/*********************************************************************
	Copyright (C) 2016 JLin Liu. All rights reserved.  
	                                                                 
	> File Name:		< hellovideo.cpp >
	> Author:		< JLin Liu >
	> Mail:			< Liu_JLin@outlook.com >
	> Created Time:		< 2016/02/26 >
	> Last Changed:  
	> Description:  	from Opencv/Documents/opencv2reman Page9
				opencv调用摄像头采集图像，
				VideoCapture 的用法
************************************************************************/ 
 
 
#include <iostream>

#include <cv.h>
//#include <highgui.h>
//#include<core/core.hpp>
//#include<imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

//#define NAME_cpp " Flip_Image "
using namespace cv;  
using namespace std; 

//int process(Mat& frame)
//{
			
//	return 0;
//}


int main( int argc, char** argv )
{
	VideoCapture cap(1);                  //VideoCapture cap(0)调用电脑默认摄像头；VideoCapture cap(1)调用外部usb摄像头
	if(!cap.isOpened()) return -1;

	Mat frame, edges;
	namedWindow("edges",1);
	
	cout << "press space to save a picture. q or esc to quit" << endl;
	//namedWindow(window_name, CV_WINDOW_KEEPRATIO);
	
	for(;;)
	{
		int n = 0;
		char filename[200];  //用以存储各帧图像
		char C2filename[200];//用以存储处理后的图像

		char key = (char)waitKey(5);
		cap >> frame;
	//{{{ 模糊和边缘处理
		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
	//	Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
	//}}}
	//{{{ 获取图片
		imshow("frame", frame);
		if (frame.empty())
		{	cout << "No frame!" << endl;
			break;
		}
		switch (key)
		{
			case 'q':
			case 'Q':
			case 27:return 0;
			case ' ':
				sprintf(filename,"filename%.3d.jpg",n++);
				sprintf(C2filename,"C2filename%.3d.jpg",n);
				imwrite(filename,frame);
				imwrite(C2filename,edges);
				cout << "Saved " << filename << " and " << C2filename << endl;
				break;
			default:
				break;
		}
	//}}}
	//	if(waitKey(30) >= 0) break;
	}

	return 0;
}
