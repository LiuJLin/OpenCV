/**********************************************************************
	Copyright (C) 2016 JLin Liu. All rights reserved.  
	                                                                 
	> File Name:		< hellovideo.cpp >
	> Author:		< JLin Liu >
	> Mail:			< Liu_JLin@outlook.com >
	> Created Time:		< 2016/02/27 >
	> Last Changed:  
	> Description:  
************************************************************************/ 
 
 
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <vector>
#include <stdio.h>
using namespace cv;
using namespace std;


int main(int ac, char** av) 
{
        int n = 0;
        char filename[200];
	char file2name[200];
        string window_name = "video | q or esc to quit";
        string window2_name = "video2 | q or esc to quit";
        cout << "press space to save a picture. q or esc to quit" << endl;
        namedWindow(window_name, CV_WINDOW_KEEPRATIO); //resizable window;
	namedWindow(window2_name, CV_WINDOW_KEEPRATIO);

	VideoCapture cap(0);	//open the appointed camera. 0 >> default; 1 >> other
	if(!cap.isOpened())	//check if succeeded
		return -1;

	Mat frame;   //采集到的实时图像画面
	Mat video;   //处理后的图像画面
//	namedWindow("video",1);
	for(;;)
	{
		cap >> frame;
	    	if (frame.empty())
                	break;
//{{{   退出程序或保存图像
            	char key = (char)waitKey(5); //delay N millis, usually long enough to display and capture input
            	switch (key) 
	    	{
        		case 'q':
        		case 'Q':
        		case 27: //escape key	
					return 0;
				
        		case ' ': //Save an image
            			sprintf(filename,"filename%.3d.jpg",n);
				sprintf(file2name,"file2name%.3d.jpg",n++);
            			imwrite(filename,frame);
				imwrite(file2name,video);
            			cout << "Saved " << filename << " and " << file2name << endl;
            			break;
        		default:
            			break;
            	}
//}}}


//{{{  图像的简单处理
		cvtColor(frame, video, CV_BGR2GRAY);	
			//转换图片的色彩空间，本语句将frame的RGB通道转换为单通道，即灰度图片，输出为video
			//c++: void cvtColor(InputArray src, OutputArray dst, int code, int dstCn=0)
			//Parameters:
			//	src >> input image: 8-bit unsigned, 16-bit unsigned (CV_16UC...), or single-precision floating-point(单精度浮点型)。在opencv中实际上是BGR，在标准的色彩图片中，第一个字节为8-bit蓝色部分，第二是绿色，第三是红色，紧接着时下一个像素（BGR）.
			//	dst >> output image of the same size and depth as src.
			//	code >> color space conversion code
			//		RGB  <->  GRAY :CV_BGR2GRAY, CV_RGB2GRAY, CV_GRAY2BGR, CV_GRAY2RGB
			//		还有许多其他转换，详见手册Page283.
			//	dstCn >> number of channels in the destination image; if the parameter is 0, the number of the channels is derived automatically from src and code
		GaussianBlur(video, video, Size(7,7), 1.5, 1.5);
			//Blurs an image using a Gaussian filter. 用高斯滤波器模糊处理图片
			//c++: void GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=BORDER_DEFAULT)
			//Parameters:(详见Page257)
			//	src >> input image; the image can have any number of channels, which are processed independently, but the depth shude be CV_8U, CV_16U,CV_16S,CV_32F or CV_64F.
			//	dst >> output image of the same size and type as src.
			//	ksize >> Gaussian kernel size. ksize.width and ksize.height can differ but they both must be positive and odd. Or,they can be zero's and then they are computed from sigma*.
			//	sigmaX >> Gaussion kernel standard deviation(偏差，误差) in X direction
			//	sigmaY >> Gaussion kernel standard deviation in Y direction; 
		Canny(video, video, 0, 30, 3);
			//用canny算法检测图像的边缘
			//c++: void Canny(InputArray image, OutputArray edges, double threshold1, double threshold2, int apertureSize=3, bool L2gradient=false )
			//Parameters:
			//	image >> 单通道8-bit输入图像
			//	edges >> 输出边缘图，大小和类型与输入图像一致
			//	threshold1 >> 第一个临界值  first threshold for the hysteresis procedure
			//	threshold2 >> 第二各临界值  （类似于磁滞现象的上下阈值？）
			//	apertureSize >> aperture size for the Sobel() operator???
//}}}
//{{{  处理前后的图像显示
		imshow(window2_name, video);
            	imshow(window_name, frame);
//}}}
//		if(waitKey(30) >= 0) break;
	}
	return 0;
}
