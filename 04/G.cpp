#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int direct[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool flag[1000][1000];
bool flag2[1000][1000];
int arr[1000][1000];
int m,n;
int cnt = 0;

void dfs(int start, int i, int j, int arry[][1000], bool flagy[][1000]){
    if(!flagy[i][j] && arry[i][j] == start){
        cnt++;
        flagy[i][j] = true;
        for (auto &k : direct) {
            int x = i + k[0];
            int y = j + k[1];

            if(x >= 0 && x < m  && y >= 0 && y < n){
                dfs(start,x,y, arry, flagy);
            }
        }
    }
}

void dfsKosong(int start, int i, int j){
    if(!flag[i][j] && arr[i][j] == start){
        arr[i][j] = 0;
        flag[i][j] = true;
        for (auto &k : direct) {
            int x = i + k[0];
            int y = j + k[1];

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

    int arr2[1000][1000];
    memset(arr,0, sizeof(arr));
    memset(flag2,false, sizeof(flag2));
    memset(flag, false,sizeof(flag));
    for(int i =0 ;i < m; i++){
        for(int j = 0; j < n ;j++) {
            scanf("%d", &arr[i][j]);
            arr2[i][j] = arr[i][j];
        }
    }

    int max = 0;
    int result = 0;

    for(int i = 0 ;i < m ; i++){
        for(int j = 0; j < n ; j++){
            result = 0;
            dfs(arr[i][j],i,j,arr,flag);
            if(cnt > 1) {
                cnt = cnt * (cnt - 1);
                result += cnt;
                cnt = 0;
                memset(flag, 0, sizeof(flag));
                dfsKosong(arr[i][j], i, j);
                for (int i1 = m - 1; i1 >= 0; i1--) {
                    for (int j1 = n - 1; j1 >= 0; j1--) {
                        dfsRuntuh(i1, j1);
                    }
                }
            }
            cnt = 0;
            for(int ii = 0 ;ii < m ; ii++){
                    for(int jj = 0 ;jj < n; jj++){
                        if(arr[ii][jj] != 0 && !flag2[ii][jj]) {
                            dfs(arr[ii][jj], ii, jj, arr, flag2);
                            cnt = cnt * (cnt - 1);
                            result += cnt;
                            if (max < result) {
                                max = result;
                            }
                            result -= cnt;
                            cnt = 0;
                        }
                    }
            }

            //result = 0;

            memset(flag2,0,sizeof(flag2));
            for(int iii = 0 ;iii < m ; iii++){
                for(int jjj =0 ;jjj < n ; jjj++){
                    arr[iii][jjj] = arr2[iii][jjj];
                }
            }

        }
    }

    cout<<max<<endl;

    return 0;
}
