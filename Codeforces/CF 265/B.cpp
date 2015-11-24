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

struct Point{
    ll x[4];
}p[10],res[10],q[10];

bool found;
ll len[10];
int cnt[4];

ll sqr(ll x){ return x*x; }

ll dis(Point p1, Point p2){
    ll d = 0;
    for(int i=1; i<=3; ++i) d += sqr(p1.x[i] - p2.x[i]);
    return d;
}

void dfs(int i){
    if(found) return;

    if(i>8){
        //checking
        for(int y=2; y<=8; ++y) len[y-1] = dis(p[1],p[y]);
        sort(len+1,len+8);
        int c = unique(len+1,len+8)-(len+1);
        if(c!=3 || len[2] != len[1]*2 || len[3] != len[1]*3 ) return;

        bool tmp;
        for(int x=2; x<=8; ++x){
            reset(cnt,0);
            for(int y=1; y<=8; ++y) if(y!=x){
                ll d = dis(p[x], p[y]);
                tmp = 0;
                for(int it=1; it<=3; ++it) if(d == len[it]){
                    ++cnt[it];
                    tmp = 1;
                    break;
                }
                if(!tmp) return;
            }
            if(cnt[1]!=3 || cnt[2]!=3 || cnt[3]!=1) return;
        }

        found = 1;
        for(int i=1; i<=8; ++i) res[i] = p[i];
        return;
    }

    q[i] = p[i];
    int num[4];
    for(int j=1; j<=3; ++j) num[j]=j;
    do{
        for(int j=1; j<=3; ++j) p[i].x[j] = q[i].x[num[j]];
        dfs(i+1);
    }while(next_permutation(num+1,num+4));
}

int main(){
    //freopen("input.txt","r",stdin);
    for(int i=1; i<=8; ++i) cin>>p[i].x[1]>>p[i].x[2]>>p[i].x[3];
    found = 0;
    dfs(2);
    if(found){
        cout<<"YES"<<endl;
        for(int i=1; i<=8; ++i) cout<<res[i].x[1]<<' '<<res[i].x[2]<<' '<<res[i].x[3]<<endl;
    }else
        cout<<"NO"<<endl;

    return 0;
}
