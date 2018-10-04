#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    const int MAXLEN=100;
    char str[MAXLEN];
    char *strD=new char[MAXLEN];
    string strS;

//    getline(cin,strS);
    cin.getline(str,MAXLEN);

    int Count;
    for(Count=0;str[Count]!='\0';Count++);
    cout<<Count<<endl;
    cout<<strlen(str)<<endl;
    Count=0;
//    for(int i=0;str[i]!='\0';i++)
    for(int i=0;i<strlen(str);i++)
        if(str[i]>='0' && str[i]<='9')
            Count++;
    cout<<Count<<endl;
    if(strlen(str)>=4)
        str[strlen(str)-4]='\0';
    cout<<str<<endl;
    return 0;
}
