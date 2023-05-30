#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

Mat c(Mat src)
{
    Mat dst;
    cvtColor(src, dst, COLOR_RGB2GRAY);// 改为灰度图
    medianBlur(dst, dst, 3);
    vector<Vec3f> circles;
    HoughCircles(dst, circles, HOUGH_GRADIENT, 1, 10, 100, 90, 1, 10000);// 霍夫圆检测
    // dp-累加分辨率大小-默认为1   两圆心之间最小距离   Canny边缘检测高阈值-低阈值自动为高阈值一半
    // 越大检测的圆越接近完美圆形   圆半径最小值   圆半径最大值
    for(int i=0; i<circles.size(); i++){
        Vec3f c = circles[i];
        circle(src,Point(c[0],c[1]),c[2],Scalar(0,255,255),3);
        cout << "x = " << c[0] << " y = " << c[1] << endl;
    }  
    return src;
}

// int main (int argc, char **argv)
// {
//     Mat src;
//     src = imread("1.jpg");
//     src = c(src);
//     imshow("效果图",src);
//     waitKey(0);
//     return 0;
// }