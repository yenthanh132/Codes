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

const int maxn=4007;
bool a[maxn][maxn];
int k,n,s,f,last[100];

void add(int u, int v){
    a[u][v]=a[v][u]=1;
}

void build(int len){
    int t1=s,t2=s;
    REP(i,len){
        int d1=++n, d2=++n;
        add(t1,d1); add(t1,d2);
        add(t2,d1); add(t2,d2);
        t1=d1; t2=d2;
    }
    add(t1,last[30-len]); add(t2,last[30-len]);
}

int main(){

    reset(a,0);
    s=1; f=2; n=2;
    FOR(i,1,30){
        add(n,n+1);
        last[i]=++n;
    }
    cin>>k;
    int len=0;
    while(k){
        if(k&1) build(len);
        k/=2;
        len++;
    }
    printf("%d\n",n);
    FOR(u,1,n){
        FOR(v,1,n) if(a[u][v]) putchar('Y'); else putchar('N');
        puts("");
    }
    return 0;
}
