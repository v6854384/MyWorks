include <iostream>

using namespace std;

int main()
{
    int i;
    char ch;
    while(cin>>ch, ch!='q')
        if(ch>='a' && ch<='z')
            {
                ch=(ch -'a' + 5)%26 +'a';
                cout<<"digit +5: "<< ch <<endl;
            }
        else
            cout<<"No digit"<<endl;

    return 0;
}
