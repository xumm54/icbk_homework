#include <iostream>
using namespace std;
class MyClass
{
public:
void fun (int gr[],int n)
{
int min=0;
for(int i=1;i<n;i++)
{
if(gr[i]<gr[min]){
min=i;
}
}
int sh=gr[min];
gr[min]=gr[n-1];
gr[n-1]=sh;
}
};
int main ()
{
    int n;
    int gr[100];
    cout <<"请输入数组长度";
    cin >> n;
    cout <<"请输入数组元素";
    for (int i=0;i<n;i++)   
 {
    cin >> gr[i];
    }
MyClass obj;
cout <<"交换前：";
for (int i=0;i<n;i++)
{
    cout << gr[i] <<" ";
}
cout << endl;
obj.fun(gr,n);
cout << "交换后：";
for(int i=0;i<n;i++)
{
    cout << gr[i] <<" ";
}
cout << endl;
return 0;
}