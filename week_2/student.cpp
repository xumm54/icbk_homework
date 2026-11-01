#include <iostream>
#include <string>
using namespace std;
class Student
{
    private:
    string name;
    string id;
    int* scores;
    int numScores;
    public:
    Student(string n,string i,int* s,int num)
    {
        name=n;
        id=i;
        numScores=num;
        scores=new int[numScores];
        for(int j=0;j<numScores;j++)
        {
            scores[j]=s[j];
        }
    }
    Student(const Student& other)
    {
        name=other.name;
        id=other.id;
        numScores=other.numScores;
        scores=new int[numScores];
        for(int j=0;j<numScores;j++)
        {
            scores[j]=other.scores[j];
        }

    }
    ~Student()
    {
        delete[] scores;
        scores=nullptr;
    }
    void print()
    {
        cout<<"姓名："<<name<<" "<<"学号："<<id<<" "<<numScores<<"门成绩：";
        for(int j=0;j<numScores;j++)
        {
            cout<<scores[j]<<" ";
        }
        cout<<endl;
    }
    void fix(int a,int b)
    {
        if(a>=1 && a<= numScores)
        {
            scores[a-1]=b;
        }
        else
        {
            cout<<"成绩序号错误"<<endl;
        }
    }
};
int main()
{
    int arr[]={85,90,78};
    Student stu1("张三","2025001",arr,3);
    Student stu2=stu1;
    cout<<"修改前："<<endl;
    cout<<"stu1:";
    stu1.print();
    cout<<endl;
    cout<<"stu2:";
    stu2.print();
    cout<<endl;
    cout<<"修改后："<<endl;
    stu1.fix(1,60);
    cout<<"stu1:";
    stu1.print();
    cout<<endl;
    cout<<"stu2:";
    stu2.print();
    cout<<endl;
    return 0;
}