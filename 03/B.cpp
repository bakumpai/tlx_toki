#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m,k,xx,yy,f,calc;
    cin>>n>>m>>k;

    vector<vector<int>> a(n);
    vector<int> x(m);
    vector<int> x1(3);
    vector<vector<int>> kk;
    int arrow[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            cin>>f;
            x[j] = f;
        }
        a[i]=x;
    }

    calc = 0;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++) {
            for(int o = 0 ; o < 4 ; o++){
                if(i+arrow[o][0] > - 1 && i+arrow[o][0] < n && j+arrow[o][1] < m && j+arrow[o][1] > -1) {
                    if(calc == 0){calc = a[i + arrow[o][0]][j + arrow[o][1]];}else {
                        calc *= a[i + arrow[o][0]][j + arrow[o][1]];
                    }
                }
            }
            x1[0] = i+1;
            x1[1] = j+1;
            x1[2] = calc;
            calc = 0;
            kk.push_back(x1);
        }
    }


    vector<vector<int>> res(1);

    res[0] = {0,0,0};
    int dup = 0;
    for(int i = 0 ; i < kk.size() ; i++){
        if(kk[i][2] == k){
            res[0] = kk[i];
        }
    }

    for (int i = 0; i < kk.size(); i++) {
        if(kk[i][2] == k && kk[i][1] <= res[0][1]) {
            res[0] = kk[i];
        }
    }

        for (int i = 0; i < kk.size(); i++) {
            if(kk[i][2] == k && kk[i][0] < res[0][0] && kk[i][1] <= res[0][1]) {
                res[0] = kk[i];
            }
        }



    cout<<res[0][0]<<" "<<res[0][1]<<endl;
    return 0;
}
