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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int x,n;

int getmax(int x){
    int s=x; x-=2;
    while(x>0){
        s+=x*2;
        x-=2;
    }
    return s;
}

int getval(int x){
    if(x%2==0) return getmax(x/2-1)*4;
    else return getmax(x);
}



#include <conio.h>
int main(){
    //FOR(i,1,20) cout<<i<<": "<<getval(i)<<endl;
    cin>>x;
    FOR(i,1,100){
        int v=getval(i);
        if(v<x) continue;
        if((v-x)%4==0 || (i%2==1 && (v-x-1)%4==0)){
            cout<<i<<endl;
            exit(0);
        }
        if(i&1){
            FOR(j,1,(i+1)/4){
                int vv=v-j*2-1;
                if(vv<x) break;
                if((vv-x)%4==0){
                    cout<<i<<endl;
                    exit(0);
                }
            }
            FOR(j,1,((i+1)/2-1)/2){
                int vv=v-j*2;
                if(vv<x) break;
                if((vv-x)%4==0){
                    cout<<i<<endl;
                    exit(0);
                }
            }
        }
    }
    getch();      
    return 0;
}
