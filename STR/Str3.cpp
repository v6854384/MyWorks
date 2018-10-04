#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    const int MAXLEN=100;
    char str[MAXLEN];
    int k;
    cin>>k;
    getchar();
    cin.getline(str,MAXLEN);
    string Str(str);

//    for(int i=0;str[i]!='\0';i++)
//        if(str[i]>='a' && str[i]<='z')
//            str[i]=(str[i]-'a'+k)%26+'a';
//        else
//            if(str[i]>='A' && str[i]<='Z')
//                str[i]=(str[i]-'A'+k)%26+'A';

//    for(char *ui=str;*ui!='\0'; ui++)
//        if(*ui>='a' && *ui<='z')
//            *ui=(*ui-'a'+k)%26+'a';
//        else
//            if(*ui>='A' && *ui<='Z')
//                *ui=(*ui-'A'+k)%26+'A';
//    cout<<str;

    Str[0]='s';
    for(auto ii=Str.begin(); ii!=Str.end();ii++)
        if(*ii>='a' && *ii<='z')
            *ii=(*ii-'a'+k)%26+'a';
        else
            if(*ii>='A' && *ii<='Z')
                *ii=(*ii-'A'+k)%26+'A';
    cout<<Str;

// Еще один более короткий способ описания итератора
//    for(auto &ii: Str)
//        if(ii>='a' && ii<='z')
//            ii=(ii-'a'+k)%26+'a';
//        else
//            if(ii>='A' && ii<='Z')
//                ii=(ii-'A'+k)%26+'A';
//    cout<<Str;

    return 0;
}
