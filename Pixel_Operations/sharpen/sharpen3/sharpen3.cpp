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

using namespace cv;  // 避免每次都要输入cv::，因此在程序开始加入本语句
using namespace std;  // 避免每次都要输入std::，因此在程序开始加入本语句

// {{{ colorReduce
void me_sharpen( Mat &image, Mat &result )
{
	result = image.clone();//为避免对原图像进行更改，因此先克隆图像，以下的操作也是对克隆得到的图像
//	result.create(image.size(),image.type());	
	for( int j = 1; j < result.rows-1; j++ )  // 
	{
		//const uchar* previous = image.ptr<const uchar>(j-1);
		//const uchar* current = image.ptr<const uchar>(j);
		//const uchar* next = image.ptr<const uchar>(j+1);
		uchar* output = result.ptr<uchar>(j);
		for(int i=1; i < result.cols-1; i++)
		{
			//*output++ = saturate_cast<uchar>(5*current[i]-current[i-1]-current[i+1]-previous[i]-next[i]);
			for(int k=0; k < 3; k++ )
				result.at<Vec3b>(j,i)[k] = saturate_cast<uchar>(5*image.at<Vec3b>(j,i)[k]-image.at<Vec3b>(j,i-1)[k]-image.at<Vec3b>(j,i+1)[k]-image.at<Vec3b>(j-1,i)[k]-image.at<Vec3b>(j+1,i)[k]);
//			if( (i%10) == 0 )
//				cout<< "i=" << i << "\n";
		}
	}
	result.row(0).setTo(Scalar(0));
	result.row(result.rows-1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(result.cols-1).setTo(Scalar(0));
};
// }}}

int main( int argc, char** argv )
{
	char* imageName = argv[1];

	Mat image;
	Mat sharpen;

	image = imread( imageName );  //载入图片

	if( argc != 2 )//参数输入错误提示
	{
		printf( "sharpen usage: ./executable_file_name Image_fullname \n ");
		return -1;
	}
	else if( !image.data )//载入图片失败
	{
		printf(" No image data. \n ");
		return -1;
	}
	
	me_sharpen( image, sharpen );         // 1: input image
						 // 2: output image	
	std::cout << "rows: " << image.rows << "cols: " << image.cols << endl;
	imwrite( "./sharpen.png", sharpen );
	// imwrite( "destination_direction/Name_gray_image", gray_image)
	// -> 1st parameter: my destination_direction/Name_gray_image, as which I want to save the gray_image 
	// -> 2nd parameter: the converted image, gray_image

	namedWindow( imageName, CV_WINDOW_AUTOSIZE );// Create a window for display
	namedWindow( "sharpen", CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );// Show our image inside it
	imshow( "sharpen", sharpen );

	waitKey(0); // Wait for a keystroke in the window
	//In order to display the window until the user presses a key, we use the waitkey function whose the only parameter is how long should it wait for a user input.
	// 0 : forever
	// About waitKey() ?????

	return 0;
}
