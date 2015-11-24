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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int mark[111],n,m,k,minv[111],maxv[111];
int free1[111];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    reset(mark,0);
    cin>>m>>k;
    int v,d;
    REP(i,k){
        cin>>v;
        mark[v]=1;   
    }
    cin>>n;
    string st;
    FOR(i,1,n){
        cin>>st;   
        cin>>d;
        int c0=0,val=0;
        minv[i]=maxv[i]=0;
        reset(free1,1);
        REP(j,d){
            cin>>v;
            if(v!=0 && mark[v]) ++val;
            else if(v==0) c0++;
            free1[v]=0;
        }
        minv[i]=maxv[i]=val;
        int c1=0,c2=0;
        FOR(v,1,m) if(free1[v])
            if(mark[v]) ++c2;
            else ++c1;
        if(c0>c1) minv[i]+=c0-c1;
        maxv[i]+=min(c0,c2);
    }
    FOR(i,1,n){
        bool check=1;
        FOR(j,1,n) if(j!=i && minv[i]<maxv[j]) check=0;
        if(check){
            puts("0");
            continue;
        }
        check=0;
        FOR(j,1,n) if(j!=i && maxv[i]<minv[j]) check=1;
        if(check){
            puts("1");
            continue;   
        }
        puts("2");
    }
    
    return 0;
}

