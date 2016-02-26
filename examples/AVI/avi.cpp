/**********************************************************************
	Copyright (C) 2016 JLin Liu. All rights reserved.  
	                                                                 
	> File Name:		< avi.cpp >
	> Author:		< JLin Liu >
	> Mail:			< Liu_JLin@outlook.com >
	> Created Time:		< 2016/02/20 >
	> Last Changed:  
	> Description:  
************************************************************************/ 
 
 
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
	namedWindow( "example2", CV_WINDOW_AUTOSIZE );
	capture* capture = createFileCapture( argv[1] );
	iplImage* frame;
	while(1)
	{
		frame =	queryFrame( capture );
		if( !frame ) break;
		showImage( "example2", frame );
		char c = waitKey(33);
		if( c == 27 ) break;
	}
	releaseCapture( &capture );
	destroyWindow( "examples2" );
}
 
