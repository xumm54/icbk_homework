#include <opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat pic=imread("test1.jpg");
    if(pic.empty())
    {
        cout<<"图片读取失败"<<endl;
    return -1;
    }
    Mat hsv;
    cvtColor(pic,hsv,COLOR_BGR2HSV);
    vector<Mat> ab;
    split(hsv,ab);
    Mat H=ab[0];
    Mat S=ab[1];
    Mat V=ab[2];
    imshow("原图BGR",pic);
    imshow("H色相",H);
    imshow("S饱和度",S);
    imshow("V明度",V);
    waitKey(0);
    destroyAllWindows();
    return 0;
}