#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int direct[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool flag[1000][1000];
int arr[1000][1000];
int m,n;
int cnt = 0;
void dfs(int start, int i, int j){
    if(!flag[i][j] && arr[i][j] == start){
        cnt++;
        flag[i][j] = true;
        for(int k = 0 ; k < 4 ; k++){
            int x = i + direct[k][0];
            int y = j + direct[k][1];

            if(x >= 0 && x < m  && y >= 0 && y < n){
                dfs(start,x,y);
            }
        }
    }
}

int main()
{

    cin>>m>>n;

    memset(arr,0, sizeof(arr));
    memset(flag,false, sizeof(flag));
    for(int i =0 ;i < m; i++){
        for(int j = 0; j < n ;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int max = -200000000;

    for(int i=0 ;i < m; i++){
        for(int j =0 ;j < n; j++){
            dfs(arr[i][j],i,j);
            cnt = cnt * (cnt-1);
            if(max < cnt) max = cnt;
            cnt = 0;
        }
    }



    cout<<max<<endl;

    return 0;
}
