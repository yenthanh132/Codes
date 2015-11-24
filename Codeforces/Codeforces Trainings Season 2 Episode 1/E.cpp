#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string mode;
ll trid, item;
map<ll,bool> locked;
map<ll,bool> xLock;
map<ll,ll> lastID;


int main(){
    //freopen("input.txt","r",stdin);

    while(1){
        cin>>mode;
        if(mode=="#") break;
        cin>>trid>>item;
        if(locked[trid]){
            cout<<"IGNORED"<<endl;
            continue;
        }

        if(mode=="S"){
            if(lastID[item]!=trid){
                if(xLock[item]){
                    cout<<"DENIED"<<endl;
                    locked[trid]=1;
                }else{
                    if(lastID[item]==0) lastID[item]=trid;
                    else lastID[item]=-1; //2 or more
                    cout<<"GRANTED"<<endl;
                }
            }else{
                cout<<"GRANTED"<<endl;
            }
        }else{
            if(lastID[item]==0 || lastID[item]==trid){
                lastID[item]=trid;
                xLock[item]=1;
                cout<<"GRANTED"<<endl;
            }else{
                cout<<"DENIED"<<endl;
                locked[trid]=1;
            }
        }



    }
}
