#include <iostream>
#include <string>

using namespace std;

bool poiskSymb(string str, int start, int len, char symb)
{
//    for(int i=start;i<start+len;i++)
//        if(str[i]==symb)
//            return true;
    if (str.find(symb,start)<str.length() && str.find(symb,start))
        return true;
    else
        return false;

//    return str.find(symb,start)<str.length() && str.find(symb,start)<start+len ? true: false;
}

int main()
{
    string str;
    getline(cin, str);
    // Подсчитать количество чисел в строке
    int Count=0;
    bool fd=false; // Флаг передыдущей цифры
    for(auto s:str)
        if(!(s>='0' && s<='9'))
            fd=false;
        else
            if(!fd)
            {
                Count++;
                fd=true;
            }

    cout<<endl;

    cout<<poiskSymb(str,3, 10,'a'); // Поиск символа 'а' с третьей по десятую позицию

    return 0;
}
