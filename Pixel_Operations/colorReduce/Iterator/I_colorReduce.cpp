/****************************************************************
	Description:
	-> 指针遍历图像
	-> 例：减少图像中的颜色数目
*****************************************************************/

#include <cv.h>
#include <highgui.h>

//#include<opencv2/core/core.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//#include<opencv2/highgui/highgui.hpp>

#define NAME_cpp   colorReduce
#define mask  uchar( 0xFF << 6 )
#define divn 64
using namespace cv;  // 避免每次都要输入cv::，因此在程序开始加入本语句

// {{{ colorReduce
void me_colorReduce( Mat &image, Mat &result, int div )
{
	result = image.clone();//为避免对原图像进行更改，因此先克隆图像，以下的操作也是对克隆得到的图像
	
	cv::Mat_<cv::Vec3b>::iterator it = result.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::iterator itend = result.end<cv::Vec3b>();

	for(; it != itend; it+=5 )  // it 变化量改变产生的效果也会随之改变
	{
		(*it)[0] = ((*it)[0] & mask) + divn/2;
		(*it)[1] = ((*it)[1] & mask) + divn/2;
		(*it)[2] = ((*it)[2] & mask) + divn/2;
	}
}
// }}}

int main( int argc, char** argv )
{
	char* imageName = argv[1];

	Mat image;
	Mat I_colorReduce;

	image = imread( imageName );  //载入图片

	if( argc != 2 )//参数输入错误提示
	{
		printf( "colorReduce usage: ./executable_file_name Image_fullname \n ");
		return -1;
	}
	else if( !image.data )//载入图片失败
	{
		printf(" No image data. \n ");
		return -1;
	}
	
	me_colorReduce( image, I_colorReduce, divn );         // 1: input image
						 // 2: output image	

	imwrite( "./colorReduce.jpg", I_colorReduce );
	// imwrite( "destination_direction/Name_gray_image", gray_image)
	// -> 1st parameter: my destination_direction/Name_gray_image, as which I want to save the gray_image 
	// -> 2nd parameter: the converted image, gray_image

	namedWindow( imageName, CV_WINDOW_AUTOSIZE );// Create a window for display
	namedWindow( "I_colorReduce", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );// Show our image inside it
	imshow( "I_colorReduce", I_colorReduce );

	waitKey(0); // Wait for a keystroke in the window
	//In order to display the window until the user presses a key, we use the waitkey function whose the only parameter is how long should it wait for a user input.
	// 0 : forever
	// About waitKey() ?????

	return 0;
}
