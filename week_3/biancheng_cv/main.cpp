#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
int main()
{
    Mat src=imread("../test3.jpg");
    if(src.empty())
    {
        cout<<"图片读取失败"<<endl;
        return -1;
}
Mat hsv,mask;
cvtColor(src,hsv,COLOR_BGR2HSV);
inRange(hsv,Scalar(105,120,120),Scalar(125,255,255),mask);
GaussianBlur(mask,mask,Size(3,3),0);
Mat kernel=getStructuringElement(MORPH_RECT,Size(5,5));
morphologyEx(mask,mask,MORPH_CLOSE,kernel);
imwrite("二值化结果图.jpg",mask);
vector<vector<Point>> contours;
findContours(mask,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
vector<RotatedRect>lights;
Mat result=src.clone();
for(size_t i=0;i<contours.size();i++)
{
    double area=contourArea(contours[i]);
    if(area<10||area>2000)
        continue;
    RotatedRect light=minAreaRect(contours[i]);
    float width=light.size.width;
    float height=light.size.height;
    if(width>height)
        {
            swap(width,height);
        light.angle+=90.0f;
        }
        float ratio=height/width;
        if(ratio<1.5||ratio>15.0)continue;
        if(abs(light.angle)>45.0)continue;
        lights.push_back(light);
        Point2f points[4];
        light.points(points);
        for(int j=0;j<4;j++)
        {
            line(result,points[j],points[(j+1)%4],Scalar(0,255,255),2);
        }
    }
    Mat result_img=src.clone();
    bool is_found=false;
    for(size_t i=0;i<lights.size();i++)
    {
        for(size_t j=i+1;j<lights.size();j++)
        {
            if(abs(lights[i].angle-lights[j].angle)>20.0f)continue;
            if(abs(lights[i].center.y-lights[j].center.y)>45.0f)continue;
            float distance=norm(lights[i].center-lights[j].center);
            if(distance<25.0f||distance>250.0f)continue;
            float dx=abs(lights[i].center.x-lights[j].center.x);
            float dy=abs(lights[i].center.y-lights[j].center.y);
            if(dx<dy)continue;
            Point2f center=(lights[i].center+lights[j].center)/2.0f;
            float armor_width=distance;
            float armor_height=max(lights[i].size.height,lights[j].size.height);
            int x=center.x-armor_width/2.0f;
            int y=center.y-armor_height/2.0f;
            Rect armor_rect(x,y,armor_width,armor_height);
            armor_rect&=Rect(0,0,src.cols,src.rows);
            Mat armor_roi=src(armor_rect).clone();
            imwrite("装甲板ROI.jpg",armor_roi);
            rectangle(result_img,armor_rect,Scalar(0,0,255),2);
            is_found=true;
            break;
        }    
        if(is_found)break;
    }
        imwrite("灯条候选画框图.jpg",result);
        imwrite("灯条配对画框图.jpg",result_img);
        waitKey(0);
        return 0;
}
