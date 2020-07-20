#include <iostream>

using namespace std;

int main()
{
    string s,ss,sss;
    cin>>s;
    cin>>ss;

    bool res = 0;


    for(int i = 0 ; i < s.length();i++)
    {
      for(int j = 0 ; j < s.length();j++)
      {
         if(j != i) sss+=s[j];
      }
      if(sss == ss){
        res = 1;
        break;
      }
      sss="";
    }

    if(res){
      printf("Tentu saja bisa!\n");
    } else {
      printf("Wah, tidak bisa :(\n");
    }
}
