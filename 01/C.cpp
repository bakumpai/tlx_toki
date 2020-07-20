#include<iostream>

using namespace std;

int main()
{

    string s;
    cin >> s;
    int n;
    bool c;
    scanf("%d", &n);
    string b;
    while(n--)
    {
       cin>>b;
       c = true;


       if(s[0] == '*'){
          int j = 0;
          for(int i = s.length()-1;i > 0 ;i--)
          {
            if(s[i] != b[b.length()-1-j]){
              c = false;
              break;
            }
            j++;
          }
       } else if(s[s.length()-1] == '*')
       {
          for(int i = s.length()-2; i >= 0; i--)
          {
            if(s[i] != b[i]){
              c = false;
              break;
            }
          }
       } else if(s[0] != '*' && s[s.length()-1] != '*') {
          int sv=0;
          for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '*'){
              sv = i;
              break;
            }
          }

          for(int i = 0 ; i < sv; i++)
          {
            if(s[i] != b[i]){
              c = false;
              break;
            }
          }

          int j = 0;
          for(int i = s.length()-1; i > sv; i--)
          {
            if(s[i] != b[b.length()-1-j] || i > b.length()){
              c = false;
              break;
            }
            j++;
          }
       }

       if (c) printf("%s\n", b.c_str());
    }
    return 0;
}
