#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> numbers;
bool lines[100000] = {0};
int len,sz;
bool solved = false;
bool check(int offset1, int offset2){
    int cnt = 0;
    int cntCheck = 0;
    int i = 0;
    for(;i < sz; i++){
        if(!lines[i]) {
            cnt++;
            if(i == sz-1){
                if(cnt > offset2 || cnt < offset1)
                    return false;
                else
                    cntCheck++;
            }
        }
        else{
            int j = i;
            int ch = 1;
            while(numbers[j] == numbers[j-1]){
                j--;
                ch++;
                cnt--;
            }

            if(cnt > offset2 || cnt < offset1) {
                return false;
            }
            else {
                cntCheck++;
            }

            if(i == sz - 1) {
               cntCheck++;
            }

            cnt = ch;
        }
    }

    return cntCheck == len;
}

void solve(int index,int offset){

    if(solved) return;

    if(offset == 0) return;

    if(index >= sz){
        if(check(offset, offset+1)){
            int ii = 0;
            for(int i = 0 ; i < sz; i++){
                if(lines[i]){
                    if(ii) cout<<" ";
                    cout<<numbers[i];
                    ii++;
                }
            }
            cout<<endl;
            solved = true;
        }
        return;
    }

    lines[index+offset] = true;
    solve(index+offset, offset);
    lines[index+offset] = false;
    lines[index+offset+1] = true;
    solve(index+offset+1, offset);
    lines[index+offset+1] = false;

}

int main()
{
    int n;

    scanf("%d", &n);
    for(int i = 0 ;i < n ; i++){
        int x;
        scanf("%d",&x);
        numbers.push_back(x);
    }


    scanf("%d", &len);

    sort(numbers.begin(), numbers.end());

    sz = numbers.size();

//    for(int i =0 ;i < sz ; i++){
//        if(i) cout<<" ";
//        cout<<numbers[i];
//    }
//
//    cout<<endl;

    int offset = sz/len;

    solve(0,offset);
}
