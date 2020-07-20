#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int direct[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int directRuntuh[2][2] = {{1,0},{-1,0}};
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

void dfsKosong(int start, int i, int j){
    if(!flag[i][j] && arr[i][j] == start){
        arr[i][j] = 0;
        flag[i][j] = true;
        for(int k = 0 ; k < 4 ; k++){
            int x = i + direct[k][0];
            int y = j + direct[k][1];

            if(x >= 0 && x < m  && y >= 0 && y < n){
                dfsKosong(start,x,y);
            }
        }
    }
}

void dfsRuntuh(int i, int j){
    if(!flag[i][j] && arr[i][j] == 0){
        flag[i][j] = true;
        int x = i + 1;
        if(x >= 0 && x < m){
            dfsRuntuh(x,j);
        }
    } else {
        while(arr[i+1][j] == 0 && i+1 < m){
            arr[i+1][j] = arr[i][j];
            arr[i][j] = 0;
            i++;
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
    int ii = 0, jj = 0;
    for(int i=0 ;i < m; i++){
        for(int j =0 ;j < n; j++){
            dfs(arr[i][j],i,j);
            cnt = cnt * (cnt-1);
            if(max < cnt) {
                max = cnt;
                ii = i;
                jj = j;
            }
            cnt = 0;
        }
    }

    memset(flag,0,sizeof(flag));
    dfsKosong(arr[ii][jj],ii,jj);

    for(int i = m ;i >= 0 ; i--){
        for(int j =n ; j >= 0 ; j--){
            dfsRuntuh(i,j);
        }
    }

    memset(flag,0,sizeof(flag));
    for(int i =0 ;i < m ;i++){
        for(int j = 0 ;j < n ;j++){
            if (j > 0) cout<<" ";
            if(arr[i][j] == 0) cout<<".";
            else cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}

