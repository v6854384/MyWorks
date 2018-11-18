#include<iostream>
int main (int argc,char*argv [])
{
   cout « "count=" <<argc-1<< endl;
   for (int i=1 ; i<argc; i++)
   {
      cout << "argv ["<<i<<"]=" << argv [i] << endl;
   }
}
