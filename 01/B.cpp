#include <iostream>

using namespace std;

bool board[21][9];
int r,c;
int ci;

void reset(int i)
{
    for(int j = 0 ; j < c; j++){
      board[i][j] = 0;
    }
}


bool check(){
  bool stat = true, ret = false;
  for(int i = 0 ; i < r; i++){
    for(int j = 0 ; j < c; j++)
    {
      if(!board[i][j]) stat = false;
    }
    if(stat){
      reset(i);
      ret = true;
      ci = i;
    }
    stat = true;
  }
  return ret;
}

void dfs(int i, int j){
    if(i+1 < r && board[i+1][j] == 0){
      board[i][j] = 0;
      dfs(i+1,j);
    } else if(!board[i][j]) {
      board[i][j] = 1;
    }
}

int main()
{

  scanf("%d %d", &r, &c);

  for(int i = 0 ;i < r; i++)
  {
    string s;
    cin>>s;
    for(int j = 0 ; j < c ; j++)
    {
      if(s[j] == '1')
        board[i][j] = 1;
      else
        board[i][j] = 0;
    }
  }

  while(check()){
    for(int i = ci ;i >= 0; i--)
    {
      for(int j = 0 ; j < c; j++)
      {
        if(board[i][j]){
          dfs(i,j);
      }
      }
    }
  }

  for(int i = 0 ;i < r; i++)
  {
    for(int j = 0 ;j < c; j++)
    {
      printf("%d", board[i][j]);
    }
      printf("\n");
  }
}
