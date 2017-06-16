#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <highgui.h>
#include "cv.h"
using namespace std;
using namespace cv;

void drawHistImg(const Mat &src, Mat &dst) {
	int histSize = 256;

	float scale = 0.01;	//scale factor for displaying purpose
	for (int i = 0; i<histSize; i++) {
		int intensity = static_cast<int>(src.at<float>(i)*scale);
		line(dst, Point(i, 255), Point(i, 255 - intensity), Scalar(0));	//for each histogram value, draw a intensity line
	}
}

int main(){
	int n;

	cout << "Select 1~3 to display the specified problem" << endl;
	cin >> n;
	if (n == 1)
	{
		//Exercise 1
		// Read input images
		Mat SrcImg1 = imread("Fig01_Slide10.tif", CV_LOAD_IMAGE_GRAYSCALE);
		// Create needed grayscale output image matrix
		Mat DstImgb = Mat(SrcImg1.rows, SrcImg1.cols, CV_8UC1);
		Mat DstImgc = Mat(SrcImg1.rows, SrcImg1.cols, CV_8UC1);
		Mat DstImgd = Mat(SrcImg1.rows, SrcImg1.cols, CV_8UC1);

		// Create a buffer to do the pixel manipulation, and scale the value to 0~1
		double buffer;

		// Copy each pixel of the source image to the output image
		for (int i = 0; i<SrcImg1.rows; ++i)
			for (int j = 0; j<SrcImg1.cols; ++j)
			{
				buffer = (double)SrcImg1.at<uchar>(i, j) / 255;
				DstImgb.at<uchar>(i, j) = (uchar)(pow(buffer, 0.6) * 255);	//fig(b) with £^ = 0.6
				DstImgc.at<uchar>(i, j) = (uchar)(pow(buffer, 0.4) * 255);	//fig(c) with £^ = 0.4
				DstImgd.at<uchar>(i, j) = (uchar)(pow(buffer, 0.3) * 255);	//fig(d) with £^ = 0.3
			}
		//show images
		imshow("Input Image", SrcImg1);
		imshow("Output1 Image", DstImgb);
		imshow("Output2 Image", DstImgc);
		imshow("Output3 Image", DstImgd);
		//write images
		imwrite("Fig01_06.tif", DstImgb);
		imwrite("Fig01_04.tif", DstImgc);
		imwrite("Fig01_03.tif", DstImgd);
	}
	else if (n == 2)
	{
		//Exercise 2
		// Read input images
		Mat SrcImg2 = imread("Fig02_Slide14.tif", CV_LOAD_IMAGE_GRAYSCALE);
		// Create needed grayscale output image matrix
		Mat DstImg1 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);
		Mat DstImg2 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);
		Mat DstImg3 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);
		Mat DstImg4 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);
		Mat DstImg5 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);
		Mat DstImg6 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);
		Mat DstImg7 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);
		Mat DstImg8 = Mat(SrcImg2.rows, SrcImg2.cols, CV_8UC1);

		// Create a buffer and variable to do the pixel manipulation
		uchar bitbuf;
		uchar isset = 0;;

		// Copy each pixel of the source image to the output image
		for (int i = 0; i<SrcImg2.rows; ++i)
			for (int j = 0; j<SrcImg2.cols; ++j)
			{
				bitbuf = SrcImg2.at<uchar>(i, j);		// copy the input value to buffer

														//check whether the 8-bit is set
				if (bitbuf & 128)
					DstImg8.at<uchar>(i, j) = 255;		//if set, assign the output pixel as white, otherwise, black		
				else
					DstImg8.at<uchar>(i, j) = 0;

				bitbuf <<= 1;							//shift left 1 bit so the 7-bit is now on the position of the 8-bit
				//check whether the 7-bit is set
				if (bitbuf & 128)
					DstImg7.at<uchar>(i, j) = 255;
				else
					DstImg7.at<uchar>(i, j) = 0;

				//check whether the 6-bit is set
				bitbuf <<= 1;
				if (bitbuf & 128)
					DstImg6.at<uchar>(i, j) = 255;
				else
					DstImg6.at<uchar>(i, j) = 0;

				//check whether the 5-bit is set
				bitbuf <<= 1;
				if (bitbuf & 128)
					DstImg5.at<uchar>(i, j) = 255;
				else
					DstImg5.at<uchar>(i, j) = 0;

				//check whether the 4-bit is set
				bitbuf <<= 1;
				if (bitbuf & 128)
					DstImg4.at<uchar>(i, j) = 255;
				else
					DstImg4.at<uchar>(i, j) = 0;

				//check whether the 3-bit is set
				bitbuf <<= 1;
				if (bitbuf & 128)
					DstImg3.at<uchar>(i, j) = 255;
				else
					DstImg3.at<uchar>(i, j) = 0;

				//check whether the 2-bit is set
				bitbuf <<= 1;
				if (bitbuf & 128)
					DstImg2.at<uchar>(i, j) = 255;
				else
					DstImg2.at<uchar>(i, j) = 0;

				//check whether the 1-bit is set
				bitbuf <<= 1;
				if (bitbuf & 128)
					DstImg1.at<uchar>(i, j) = 255;
				else
					DstImg1.at<uchar>(i, j) = 0;
			}
		//show images
		imshow("Input Image", SrcImg2);
		imshow("Output1 Image", DstImg1);
		imshow("Output2 Image", DstImg2);
		imshow("Output3 Image", DstImg3);
		imshow("Output4 Image", DstImg4);
		imshow("Output5 Image", DstImg5);
		imshow("Output6 Image", DstImg6);
		imshow("Output7 Image", DstImg7);
		imshow("Output8 Image", DstImg8);
		//write images
		imwrite("Fig02_1.tif", DstImg1);
		imwrite("Fig02_2.tif", DstImg2);
		imwrite("Fig02_3.tif", DstImg3);
		imwrite("Fig02_4.tif", DstImg4);
		imwrite("Fig02_5.tif", DstImg5);
		imwrite("Fig02_6.tif", DstImg6);
		imwrite("Fig02_7.tif", DstImg7);
		imwrite("Fig02_8.tif", DstImg8);
	}
	else if (n == 3)
	{
		//Exercise 3
		// Read input images
		Mat SrcImg3 = imread("Fig03_Slide23.tif", CV_LOAD_IMAGE_GRAYSCALE);
		// Create needed grayscale output image matrix
		Mat DstImgdark = Mat(SrcImg3.rows, SrcImg3.cols, CV_8UC1);
		Mat DstImglight = Mat(SrcImg3.rows, SrcImg3.cols, CV_8UC1);
		Mat DstImglow = Mat(SrcImg3.rows, SrcImg3.cols, CV_8UC1);

		// Create a buffer and variables to do the pixel manipulation
		uint16_t buffer;
		uchar min = 95;

		//declare some variables for computing histograme
		int histSize = 256;
		float range[] = { 0, 256 };
		const float* histRange = { range };
		
		// compute the low contrast image from textbook figure 3.16 for other two images
		for (int i = 0; i<SrcImg3.rows; ++i)
			for (int j = 0; j<SrcImg3.cols; ++j)
			{
				DstImglow.at<uchar>(i, j) = SrcImg3.at<uchar>(i, j)*0.2 + min;
			}

		//compute the dark image
		for (int i = 0; i<DstImglow.rows; ++i)
			for (int j = 0; j<DstImglow.cols; ++j)
			{
				DstImgdark.at<uchar>(i, j) = DstImglow.at<uchar>(i, j) - 87;
				DstImgdark.at<uchar>(i, j) *= 1.3;
			}
		//show the original dark image
		imshow("original dark", DstImgdark);

		//compute the light image
		for (int i = 0; i<DstImglow.rows; ++i)
			for (int j = 0; j<DstImglow.cols; ++j)
			{
				buffer = (DstImglow.at<uchar>(i, j)-min)*3 + 127;
				if (buffer > 255)
					buffer = 255;	//if value over the limit, compress it!
				DstImglight.at<uchar>(i, j) = (uchar)buffer;
			}
		//show the original light image
		imshow("original light", DstImglight);

		//write original images
		imwrite("original dark.tif", DstImgdark);
		imwrite("original light.tif", DstImglight);

		//declare histogram array, and some variables
		Mat darkImg, lightImg;
		uchar table[256];	//table for equalization
		float totalPixels = SrcImg3.cols*SrcImg3.rows, tmp = 0;
		//calculate the histograms of the two images
		calcHist(&DstImgdark, 1, 0, Mat(), darkImg, 1, &histSize, &histRange);
		calcHist(&DstImglight, 1, 0, Mat(), lightImg, 1, &histSize, &histRange);
		
		//compute the dark image equalization table
		for (int i = 0; i < histSize; i++)
		{
			tmp+=darkImg.at<float>(i);
			table[i] = (tmp / totalPixels) * 255;
		}

		//equalize the dark image
		for (int i = 0; i<DstImgdark.rows; ++i)
			for (int j = 0; j<DstImgdark.cols; ++j)
			{
				DstImgdark.at<uchar>(i, j) = table[DstImgdark.at<uchar>(i, j)];
			}

		//show the dark image after equalization and its histogram
		calcHist(&DstImgdark, 1, 0, Mat(), darkImg, 1, &histSize, &histRange);
		Mat showDarkHis(256, 256, CV_8UC1, Scalar(255));
		drawHistImg(darkImg, showDarkHis);
		imshow("dark after equalization", DstImgdark);
		imshow("dark equalization historgram", showDarkHis);

		//compute the light image equalization table
		tmp = 0;
		for (int i = 0; i < histSize; i++)
		{
			tmp += lightImg.at<float>(i);
			table[i] = (tmp / totalPixels) * 255;
		}

		//equalize the light image
		for (int i = 0; i<DstImglight.rows; ++i)
			for (int j = 0; j<DstImglight.cols; ++j)
			{
				DstImglight.at<uchar>(i, j) = table[DstImglight.at<uchar>(i, j)];
			}

		//show the light image after equalization and its histogram
		calcHist(&DstImglight, 1, 0, Mat(), lightImg, 1, &histSize, &histRange);
		Mat showLightHis(256, 256, CV_8UC1, Scalar(255));
		drawHistImg(lightImg, showLightHis);
		imshow("light after equalization", DstImglight);
		imshow("light equalization historgram", showLightHis);

		//write images after equalization and its histogram
		imwrite("equalized dark.tif", DstImgdark);
		imwrite("equalized light.tif", DstImglight);
		imwrite("dark equalization historgram.tif", showDarkHis);
		imwrite("light equalization historgram.tif", showLightHis);

	}
	waitKey(0);
	return 0;
}