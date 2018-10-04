#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1("qweqwe"), str2="sdsd";
    str1=str2;
    cout<<str1+str2<<endl;
    cout<<str1.length()<<endl;
    cout<<str1.substr(1,2)<<endl;
    return 0;
}
