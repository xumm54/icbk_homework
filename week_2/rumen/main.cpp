#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
    Mat pic=imread("../test1.jpg");
    if(pic.empty())
    {cout<<"图片读取失败"<<endl;
    return -1;}
    Mat gray;
    cvtColor(pic,gray,COLOR_BGR2GRAY);
    Mat two;
    threshold(gray,two,127,255,THRESH_BINARY);
    int no_gray=countNonZero(gray);
    int no_two=countNonZero(two);
    cout<<"灰度图像非零像素点个数为："<<no_gray<<endl;
    cout<<"二值图像非零像素点个数为："<<no_two<<endl;
    imwrite("../two_result.jpg",two);
    cout<<"二值图像已保存为two_result.jpg"<<endl;
    imshow("原图",pic);
    imshow("灰度图",gray);
    imshow("二值图",two);
    //进阶1：ROI裁剪
    Rect rect(100,100,200,200);
    Mat roi=pic(rect);
    imwrite("../roi_result.jpg",roi);
    cout<<"ROI裁剪图像已保存为roi_result.jpg"<<endl;
    //进阶2：图像缩放
    Mat resize_pic;
    resize(pic,resize_pic,Size(320,240));
    imwrite("../resize_result.jpg",resize_pic);
    cout<<"缩放图像已保存为resize_result.jpg"<<endl;
    //进阶3：颜色筛选
    Mat hsv_pic;
    cvtColor(pic,hsv_pic,COLOR_BGR2HSV);
    imwrite("../hsv_result.jpg",hsv_pic);
    Mat mask;
    Scalar lower_red(0,120,80);
    Scalar upper_red(10,255,255);
    inRange(hsv_pic,lower_red,upper_red,mask);
    imwrite("../mask_result.jpg",mask);
    cout<<"掩膜图像已保存为mask_result.jpg"<<endl;
    waitKey(0);
    destroyAllWindows();
    return 0;
}