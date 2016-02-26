/*****************************************************************
	Description:
	-> 指针遍历图像
	-> 例：减少图像中的颜色数目
	-> 较例1中的区别在于，这里我们使用cv::Mat的create成员函数，它可以根据新的尺寸和数据类型对一个矩阵进行重新分配。
           如果新指定的尺寸和数据类型与原有的一样，create函数会直接返回，并不会对该实例作任何更改。
*****************************************************************/

#include <cv.h>
#include <highgui.h>

#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

#define NAME	colorReduce
#define n  	6    //(0~7)
#define mask	uchar( 0xFF << n )
#define divn	pow(2,n)

using namespace cv;  // 避免每次都要输入cv::，因此在程序开始加入本语句

// {{{ colorReduce
void colorReduce( Mat &image, Mat &result, int div )
{
	result = image.clone();//为避免对原图像进行更改，因此先克隆图像，以下的操作也是对克隆得到的图像

	int nu_row = result.rows; // 行数
	int nu_pixel = result.cols*result.channels();// 每行的像素值数 = 列数（宽度） × 通道数
	int j; // row count
	int i; // colume  count
	
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
	Mat s_colorReduce;

	int nu_row = image.rows; // 行数
	int nu_pixel = image.cols*image.channels();// 每行的像素值数 = 列数（宽度） × 通道数
	int j; // row count
	int i; // colume  count

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
	
	colorReduce( image, s_colorReduce, divn );
	s_colorReduce.create( image.rows, image.cols, image.type() );//  _____.creat()
	
	for(j=0; j<nu_row; j++)  // 每行
	{
		const uchar* data_in = image.ptr<uchar>(j);
	     	uchar* data_out = s_colorReduce.ptr<uchar>(j);
		for( i=0; i < nu_pixel; i++ )  // 第j行的各像素值
		{
			data_out[i] = (data_in[i] & mask) + divn/2;//对每个像素值的处理，在此采用位处理方法，效率高
		
		}
	}

	imwrite( "./s_colorReduce.jpg", s_colorReduce );
	// imwrite( "destination_direction/Name_gray_image", gray_image)
	// -> 1st parameter:" my destination_direction/Name_image", as which I want to save the output_image 
	// -> 2nd parameter: the converted image

	namedWindow( imageName, CV_WINDOW_AUTOSIZE );// Create a window for display
	namedWindow( "s_colorReduce", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );// Show our image inside it
	imshow( "s_colorReduce", s_colorReduce );

	waitKey(0); // Wait for a keystroke in the window
	//In order to display the window until the user presses a key, we use the waitkey function whose the only parameter is how long should it wait for a user input.  
	// 0 : forever 
	// About waitKey() ?????

	return 0;
}
