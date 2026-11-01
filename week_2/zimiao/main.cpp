#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("../test.jpg");
    if (src.empty())
    {
        cout << "图片读取失败,检查test.jpg是否在当前文件夹" << endl;
        return -1;
    }
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);
    Scalar lower_red = Scalar(0, 120, 80);
    Scalar upper_red = Scalar(10, 255, 255);
    Mat mask;
    inRange(hsv, lower_red, upper_red, mask);
    imwrite("../mask.jpg", mask);
    cout << "掩码图 mask.jpg 保存成功" << endl;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(mask, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    Mat result = src.clone();
    for (int i = 0; i < contours.size(); i++)
    {
        Rect box = boundingRect(contours[i]);
        int area = box.width * box.height;
        if (area < 80)
            continue;
        rectangle(result, box, Scalar(0,0,255), 2);
    }
    imwrite("../aim_result.jpg", result);
    cout << "自瞄结果图 aim_result.jpg 保存成功" << endl;
    imshow("原图", src);
    imshow("mask掩码", mask);
    imshow("识别结果", result);
    waitKey(0);
    destroyAllWindows();

    return 0;
}