/*------------------------------------------------------------------------------------------*\
   This file contains material supporting chapter 4 of the cookbook:  
   Computer Vision Programming using the OpenCV Library. 
   by Robert Laganiere, Packt Publishing, 2011.

   This program is free software; permission is hereby granted to use, copy, modify, 
   and distribute this source code, or portions thereof, for any purpose, without fee, 
   subject to the restriction that the copyright notice may not be removed 
   or altered from any source or altered source distribution. 
   The software is released on an as-is basis and without any warranties of any kind. 
   In particular, the software is not guaranteed to be fault-tolerant or free from failure. 
   The author disclaims all warranties with regard to this software, any use, 
   and any consequent failure, is purely the responsibility of the user.
 
   Copyright (C) 2010-2011 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
using namespace cv;
#include "cv.h"
#include "highgui.h"
#include "histogram.h"

int main()
{
//{{{	读取输入图片   // Read input image
	char* imageName = argv[1];
	
	Mat iamge;
	image = imread( imageName );

	if( argc != 2 )
	{
		cout << NAME_cpp << "usage: ./ExecutableFileName ImageName " << endl;
		return -1;
	}
	else if( !image.data )
	{
		cout << "No image data." << endl;
		return -1;
	}
//	Mat image= imread("../group.jpg",0);
//	if (!image.data)
//		return 0; 
//}}}

//{{{   显示图片 // Display the image
	namedWindow("Image");
	imshow("Image",image);
//}}}

//{{{  	创建一个Histogram1D实例 
	// The histogram object
	Histogram1D h;
//}}}

//{{{   计算直方图// Compute the histogram
	MatND histo= h.getHistogram(image);
//}}}

//{{{   遍历所有的容器// Loop over each bin
	for (int i=0; i<256; i++) 
		cout << "Value " << i << " = " << histo.at<float>(i) << endl;  
//}}}

//{{{   将直方图以图片形式显示// Display a histogram as an image
	namedWindow("Histogram");
	imshow("Histogram",h.getHistogramImage(image));
//}}}

//{{{   通过在流通域进行阈值转换生成一个二值化图片，保存并显示// creating a binary image by thresholding at the valley
	Mat thresholded;
	threshold(image,thresholded,60,255,THRESH_BINARY);
 
	// Display the thresholded image
	namedWindow("Binary Image");
	imshow("Binary Image",thresholded);
	imwrite("binary.bmp",thresholded);
//}}}

//{{{ 	均衡化（补偿）图片，并显示// Equalize the image
	Mat eq= h.equalize(image);

	// Show the result
	namedWindow("Equalized Image");
	imshow("Equalized Image",eq);
//}}}

//{{{ 	显示均衡化后的图片的的直方图// Show the new histogram
	namedWindow("Equalized Histogram");
	imshow("Equalized Histogram",h.getHistogramImage(eq));
//}}}

//{{{	忽略像素值少于5的容器来伸缩图片// Stretch the image ignoring bins with less than 5 pixels
	Mat str= h.stretch(image,5);

	// Show the result
	namedWindow("Stretched Image");
	imshow("Stretched Image",str);
//}}}

//{{{	显示伸缩后图片的直方图// Show the new histogram
	namedWindow("Stretched Histogram");
	imshow("Stretched Histogram",h.getHistogramImage(str));
//}}}

//{{{	生成翻转图片// Create an image inversion table
	uchar lookup[256];
	
	for (int i=0; i<256; i++) {
		
		lookup[i]= 255-i;
	}
//}}}

//{{{ 	应用查找表并显示翻转图片// Apply lookup and display negative image
	namedWindow("Negative image");
	imshow("Negative image",h.applyLookUp(image,lookup));
//}}}
	waitKey();
	return 0;
}

