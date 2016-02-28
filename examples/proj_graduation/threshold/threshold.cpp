/**********************************************************************
	Copyright (C) 2016 JLin Liu. All rights reserved.  
	                                                                 
	> File Name:		< threshold.cpp >
	> Author:		< JLin Liu >
	> Mail:			< Liu_JLin@outlook.com >
	> Created Time:		< 2016/02/27 >
	> Last Changed:  
	> Description:  
************************************************************************/ 
 
 
#include <iostream>
using namespace std;

//{{{ 定义一个类，用来处理单通道的灰度图像
class Histogram1D
{
	private:
		int histSize[1];//数量
		float hranges[2];//像素的最大值以及最小值
		const float*ranges[1];
		int channels[1];//一个通道
	public:
		Histogram1D
		{
			hitsiSize[0]= 256;
			hranges[0]= 0.0;
			hranges[1]= 255.0;
			ranges[0]= hranges;
			channels[0]= 0;
		}
}
//}}}
