#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

vector< pair<int,char> > dances = vector<pair<int,char>>();
bool flag[100007];
int cnt;
int r,nn;
int meyakinkan = -1;
int y;
vector<int> listPermutation = vector<int>();

void generatePoints(int point, int cntPerm, char prevChar){
    int points = 0;
    if(cntPerm >= r){
        listPermutation.push_back(point);
    } else {
        for(int i = 0 ;i < nn; i++){
            if(flag[i])
                continue;

            if(cntPerm == 0){
                points += dances[i].first;
            } else {
                if(prevChar == 'P'){
                    points += dances[i].first * 2;
                } else if(prevChar == 'B'){
                    points += dances[i].first;
                } else if(prevChar == 'L'){
                    points += floor(dances[i].first/2);
                }else if (prevChar == 'Y'){
                    meyakinkan = cntPerm - 1;
                    points += dances[i].first;
                }

                if(meyakinkan != -1 && meyakinkan < cntPerm)
                    points += y;
            }

            flag[i] = true;
            generatePoints(point+points,cntPerm+1,dances[i].second);
            if(cntPerm == meyakinkan)
                meyakinkan = -1;
            points = 0;
            flag[i] = false;
        }
    }

}

int main()
{
    string x;

    getline(cin,x);

    int n,j;

    memset(flag,0,sizeof(flag));
    scanf("%d %d %d %d", &n, &r, &y, &j);
    nn = n;
    while(n--){
        int d;
        char t;
        cin>>d>>t;
        dances.emplace_back(d,t);
    }

    generatePoints(0,0,'X');
    int sz = listPermutation.size();

    bool breaked = false;
    sort(listPermutation.begin(), listPermutation.end());
    while(j--){
        cnt = 0;
        int xx;
        scanf("%d", &xx);
        if(listPermutation[sz-1] <= xx){
            cout<<0<<endl;
            continue;
        }
        for(int i = 0 ;i < sz ; i++){
            if(listPermutation[i] > xx) {
                cnt = i;
                breaked = true;
                break;
            }
        }

        if(!breaked)
            cnt = sz;

        cout<<sz-cnt<<endl;
        breaked = false;
    }

    return 0;
}
