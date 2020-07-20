#include <iostream>
#include <vector>
using namespace std;

int abs(int a){
    if(a < 0){
        return a*-1;
    }

    return a;
}
int main() {
    int n,i,j,k;
    vector<int> jj,kk;
    cin >> n >> k;

    for(i = 0 ; i < n ; i++){
        cin>>j;
        jj.push_back(j);
        kk.push_back(abs(k - j));
    }

    int min = kk[0], index = 0;
    for(int i = 1 ; i < n ; i++){
        if((min > kk[i]) || (min == kk[i] && jj[index] > jj[i]) ){
            min = kk[i];
            index = i;
        }
    }

    cout<<jj[index]<<endl;
    return 0;
}
