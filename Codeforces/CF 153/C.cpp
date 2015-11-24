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

const int maxn=360360;

int d[maxn+7],k;
ll a,b;

int dis(int a, int b){
    d[a]=0;
    REP(i,a) d[i]=oo;
    FORD(i,a,b+1){
        if(d[i-1]>d[i]+1) d[i-1]=d[i]+1;
        FOR(x,2,k) if(i-i%x>=b && d[i-i%x]>d[i]+1) d[i-i%x]=d[i]+1;
    }
    return d[b];
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>a>>b>>k;
    ll posa=a/maxn, posb=b/maxn;
    ll res;
    if(posa==posb) res=dis(a%maxn,b%maxn);
    else res=dis(a%maxn,0) + (1 + dis(maxn-1,0))*(posa-posb-1) + 1 + dis(maxn-1,b%maxn);
    cout<<res<<endl;
    //getch();
    return 0;
}
        
        
        
