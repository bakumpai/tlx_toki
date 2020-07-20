#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int binarySearch(string * aa,int size, string val){
    int first = 0,
    last = size - 1,
    middle = (first + last) / 2,
    position = -1;

    bool found = false;

    while(!found && first <= last){
        middle = (first + last) / 2;
        if(aa[middle] == val){
            found = true;
            position = middle;
        }
        else if(strcmp(aa[middle].c_str(),val.c_str()) > 0)
            last = middle - 1;
        else
            first = middle + 1;
    }

    return position;
}


int main() {
    int n,m;
    //freopen("in.txt","r",stdin);
    cin>>n>>m;
    vector<string> ss(m);
    string * nameArr = new string[n];
    string * numbArr = new string[n];
    string s,x,y;

    for(int i = 0 ; i < n; i++){
        cin>>x>>y;
        nameArr[i] = x;
        numbArr[i] = y;
    }

    for(int j = 0 ; j < m ; j++){
        cin>>ss[j];
    }

    for(int i = 0 ; i < m ; i++){
        int pos = binarySearch(nameArr, n, ss[i]);
        if (pos == -1) {
            printf("%s\n", "NIHIL");
        }else{
            printf("%s\n",numbArr[pos].c_str());
        }
    }

    return 0;
}

