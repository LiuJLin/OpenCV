/*****************************************************************
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

	int nu_row = result.rows; // 行数
	int nu_pixel = result.cols*result.channels();// 每行的像素值数 = 列数（宽度） × 通道数
	int j; // row count
	int i; // colume  count
	
	if(image.isContinuous())  //cv::Mat 的一个成员函数 isContinuous 可以判断这幅图像是否对行进行了填补，若返回值为真，则无填补，是连续的。
	{
		nu_pixel = nu_row*nu_pixel;
		nu_row = 1;
	}
	//对于连续图像，本循环只执行一次，即相当于只有内层循环
	for(j=0; j<nu_row; j++)  // 每行
	{
		uchar* data = result.ptr<uchar>(j);  // 第j行的首地址,ptr 函数可以得到图像任一行的首地址
		for( i=0; i < nu_pixel; i++ )  // 第j行的各像素值
		{
			data[i] =( data[i] & mask ) + div/2;//对每个像素值的处理，在此采用位处理方法，效率高
			//也可作：data[i] = data[i]/div*div+div/2;
			//	  *data++ = *data/div*div + div/2;
			//	  data[i] = data[i] - data[i]%daiv + div/2;  因为需要存取每个像素两次，因此运算方式较慢
		
		}
	}
}
// }}}

int main( int argc, char** argv )
{
	char* imageName = argv[1];

	Mat image;
	Mat colorReduce;

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
	
	me_colorReduce( image, colorReduce, divn );         // 1: input image
		               				    // 2: output image	

	imwrite( "./colorReduce.jpg", colorReduce );
	// imwrite( "destination_direction/Name_gray_image", gray_image)
	// -> 1st parameter: my destination_direction/Name_gray_image, as which I want to save the gray_image 
	// -> 2nd parameter: the converted image, gray_image

	namedWindow( imageName, CV_WINDOW_AUTOSIZE );// Create a window for display
	namedWindow( "colorReduce", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );// Show our image inside it
	imshow( "colorReduce", colorReduce );

	waitKey(0); // Wait for a keystroke in the window
	//In order to display the window until the user presses a key, we use the waitkey function whose the only parameter is how long should it wait for a user input.
	// 0 : forever
	// About waitKey() ?????

	return 0;
}
