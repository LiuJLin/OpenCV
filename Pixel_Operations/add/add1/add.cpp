/****************************************************************
	Description:
	> 图像算术
	> 图像以矩阵形式存储，因此可以做加减乘除运算
	> 在此，我们将两个图像相加结合

	cv::add
	> c[i] = a[i] + b[i];
	  cv::add(imageA,imageB,resultC);
	> c[i] = a[i] + k;
	  cv::add(imageA,cv::Scalar(k),resultC);
	> c[i] = k1*a[i] + k2*b[i] + k3;
	  cv::addWeighted(imageA,k1,imageB,k2,k3,resultC);
	> c[i] = a[i] + b[i]
	  cv::scaleAdd(imageA,k,imageB,resultC);
	
*****************************************************************/

#include <cv.h>
#include <highgui.h>

//#include<opencv2/core/core.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//#include<opencv2/highgui/highgui.hpp>

using namespace cv;  // 避免每次都要输入cv::，因此在程序开始加入本语句


int main( int argc, char** argv )
{
	char* imageName1 = argv[1];
	char* imageName2 = argv[2];

	Mat image1;
	Mat image2;
	Mat add;

	image1 = imread( imageName1 );  //载入图片
	image2 = imread( imageName2 );  //载入图片

	if( argc != 3 )//参数输入错误提示
	{
		printf( "add usage: ./executable_file_name Image1_fullname Image2_fullname \n ");
		return -1;
	}
	else if( !(image1.data || image2.data) )//载入图片失败
	{
		printf(" No image data. \n ");
		return -1;
	}
	
	addWeighted( image1, 0.7, image2, 0.8, 0, add );         // 1: input image
						 // 2: output image	
	std::cout << "rows: " << add.rows << "cols: " << add.cols << "\n" ;
	imwrite( "./add_image.jpg", add );
	// imwrite( "destination_direction/Name_gray_image", gray_image)
	// -> 1st parameter: my destination_direction/Name_gray_image, as which I want to save the gray_image 
	// -> 2nd parameter: the converted image, gray_image

	namedWindow( imageName1, CV_WINDOW_AUTOSIZE );// Create a window for display
	namedWindow( imageName2, CV_WINDOW_AUTOSIZE );// Create a window for display
	namedWindow( "add_image", CV_WINDOW_AUTOSIZE );

	imshow( imageName1, image1 );// Show our image inside it
	imshow( imageName2, image2 );// Show our image inside it
	imshow( "add_image", add );

	waitKey(0); // Wait for a keystroke in the window
	//In order to display the window until the user presses a key, we use the waitkey function whose the only parameter is how long should it wait for a user input.
	// 0 : forever
	// About waitKey() ?????

	return 0;
}
