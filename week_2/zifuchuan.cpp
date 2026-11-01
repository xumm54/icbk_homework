#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
    string line;
    getline(cin,line);
    stringstream ss(line);
    string word;
    vector<string> words;
    while (ss>>word)
    {
        words.push_back(word);
    }
    cout <<"输入的单词个数为："<<words.size()<<endl;
    cout <<"逆序输出：";
    for (int i=words.size()-1;i>=0;i--)
    {
        cout <<words[i]<<" "; 
    }
    cout << endl;
    return 0;
}