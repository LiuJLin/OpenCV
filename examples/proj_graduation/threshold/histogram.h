#if !defined HISTOGRAM
#define HISTOGRAM

#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>

class Histogram1D {

  private:

	int histSize[1];
	float hranges[2];
	const float* ranges[1];
	int channels[1];

  public:

	Histogram1D() 
//{{{   准备 1D 直方图的参数
	{
		// Prepare arguments for 1D histogram
		histSize[0]= 256;
		hranges[0]= 0.0;
		hranges[1]= 255.0;
		ranges[0]= hranges; 
		channels[0]= 0; // by default, we look at channel 0
	}
//}}}

	void setChannel(int c) 
//{{{	为直方图设置通道值，默认为0通道
	// Sets the channel on which histogram will be calculated.
	// By default it is channel 0.
	{

		channels[0]= c;
	}
//}}}

	int getChannel() 
//{{{	获取当前通道值
	// Gets the channel used.
	{
		return channels[0];
	}
//}}}

	void setRange(float minValue, float maxValue) 
//{{{	为像素值设置范围，默认为[0,255]
	// Sets the range for the pixel values.
	// By default it is [0,255]
	{

		hranges[0]= minValue;
		hranges[1]= maxValue;
	}
//}}}

	float getMinValue() 
//{{{	获取最小的像素值
	// Gets the min pixel value.
	{
		return hranges[0];
	}
//}}}

	float getMaxValue() 
//{{{	获取最大的像素值
	// Gets the max pixel value.
	{
		return hranges[1];
	}
//}}}

	void setNBins(int nbins) 
//{{{	为直方图设置容器数量
	// Sets the number of bins in histogram.
	// By default it is 256.
	{
		histSize[0]= nbins;
	}
//}}}

	int getNBins() 
//{{{	获取直方图的容器数量值
	// Gets the number of bins in histogram.
	{
		return histSize[0];
	}
//}}}

	cv::MatND getHistogram(const cv::Mat &image) 
//{{{	// 计算 1D 直方图 Computes the 1D histogram.
	{
		cv::MatND hist;

		// 计算直方图 Compute histogram
		cv::calcHist(&image, 
			1,			// histogram of 1 image only
			channels,	// the channel used
			cv::Mat(),	// no mask is used
			hist,		// the resulting histogram
			1,			// it is a 1D histogram
			histSize,	// number of bins
			ranges		// pixel value range
		);

		return hist;
	}
//}}}
	cv::Mat getHistogramImage(const cv::Mat &image)
//{{{	计算 1D 直方图 并返回图
	// Computes the 1D histogram and returns an image of it.
	{

		// Compute histogram first
		cv::MatND hist= getHistogram(image);

		// Get min and max bin values
		double maxVal=0;
		double minVal=0;
		cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);

		// Image on which to display histogram
		cv::Mat histImg(histSize[0], histSize[0], CV_8U,cv::Scalar(255));

		// set highest point at 90% of nbins
		int hpt = static_cast<int>(0.9*histSize[0]);

		// Draw vertical line for each bin 
		for( int h = 0; h < histSize[0]; h++ ) {

			float binVal = hist.at<float>(h);
			int intensity = static_cast<int>(binVal*hpt/maxVal);
			cv::line(histImg,cv::Point(h,histSize[0]),cv::Point(h,histSize[0]-intensity),cv::Scalar::all(0));
		}

		return histImg;
	}
//}}}
	cv::Mat equalize(const cv::Mat &image) 
//{{{ 	直方图的均衡化
	// Equalizes the source image.
	{

		cv::Mat result;
		cv::equalizeHist(image,result);

		return result;
	}
//}}}
	cv::Mat stretch(const cv::Mat &image, int minValue=0) 
//{{{   拉伸图像
	// Stretches the source image.
	{

		// Compute histogram first
		cv::MatND hist= getHistogram(image);

		// find left extremity of the histogram
		int imin= 0;
		for( ; imin < histSize[0]; imin++ ) {
			std::cout<<hist.at<float>(imin)<<std::endl;
			if (hist.at<float>(imin) > minValue)
				break;
		}
		
		// find right extremity of the histogram
		int imax= histSize[0]-1;
		for( ; imax >= 0; imax-- ) {

			if (hist.at<float>(imax) > minValue)
				break;
		}

		// Create lookup table
		int dims[1]={256};
		cv::MatND lookup(1,dims,CV_8U);

		for (int i=0; i<256; i++) {
		
			if (i < imin) lookup.at<uchar>(i)= 0;
			else if (i > imax) lookup.at<uchar>(i)= 255;
			else lookup.at<uchar>(i)= static_cast<uchar>(255.0*(i-imin)/(imax-imin)+0.5);
		}

		// Apply lookup table
		cv::Mat result;
		result= applyLookUp(image,lookup);

		return result;
	}
//}}}
	cv::Mat applyLookUp(const cv::Mat& image, const cv::MatND& lookup) 
//{{{	应用查找表转换原始图像为一个单通道图像
	// Applies a lookup table transforming an input image into a 1-channel image
	{

		// Set output image (always 1-channel)
		cv::Mat result(image.rows,image.cols,CV_8U);
		cv::Mat_<uchar>::iterator itr= result.begin<uchar>();

		// Iterates over the input image
		cv::Mat_<uchar>::const_iterator it= image.begin<uchar>();
		cv::Mat_<uchar>::const_iterator itend= image.end<uchar>();

		// Applies lookup to each pixel
		for ( ; it!= itend; ++it, ++itr) {

			*itr= lookup.at<uchar>(*it);
		}

		return result;
	}
//}}}
};


#endif
