#include <iostream>
#include <vector>
#include <string>

using namespace std;

int points[5] = {0,0,0,0,0};

vector<string> stringPoint = vector<string>();
void generatePoints(int team1, int team2, int n){
    if (team2 == n) {
        team1++;
        team2 = team1 + 1;
    }

    if(team1 < n && team2 < n) {
        points[team1] += 3;
        generatePoints(team1, team2 + 1,n);

        points[team1] -= 3;
        points[team1] += 1;
        points[team2] += 1;
        generatePoints(team1, team2+1,n);

        points[team1] -= 1;
        points[team2] -= 1;
        points[team2] += 3;
        generatePoints(team1,team2+1,n);
        points[team2] -= 3;
    } else {
        string s ="";
        for(int i = 0 ; i < n; i++){
            s += to_string(points[i]);
            if(i < n-1)
                s+=" ";
        }

        stringPoint.push_back(s);
    }
}

int main()
{
    int t,n;
    cin >> t;


    for(int i = 2; i <= 5; i++){
        generatePoints(0,1,i);
    }


    int sz = stringPoint.size();
    bool check = false;
    while(t--){
        cin>>n;
        stringPoint.clear();
        string s="";
        for(int i=0 ;i < n ; i++){
            string ss;
            cin>>ss;
            s+=ss;
            if(i < n - 1)
                s+=" ";
        }

        for(int i =0 ;i < sz; i++){
            if(s == stringPoint[i]){
                cout<<"YES\n";
                check = true;
                break;
            }
        }

        if(!check){
            cout<<"NO\n";
        }
        check = false;
    }
    return 0;
}

