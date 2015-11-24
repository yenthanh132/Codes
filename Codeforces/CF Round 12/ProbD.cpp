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

const int maxn=500001;

struct node{int b,i,r;} a[maxn];
map<int,int> val;
int BIT[maxn],n,listi[maxn],m,res;

bool mycmp(const node &a, const node &b){
    if(a.b>b.b) return 1; else if(a.b<b.b) return 0;
    if(a.i<b.i) return 1; else if(a.i>b.i) return 0;
    if(a.r<b.r) return 1; else return 0;
}

void update(int u, int v){
    while(u>0){
        BIT[u]=max(BIT[u],v);
        u&=u-1;
    }
}

int get(int u){
    int v=0;
    while(u<=m){
        v=max(v,BIT[u]);
        u+=(u&(-u));
    }
    return v;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i].b);
    FOR(i,1,n) scanf("%d",&a[i].i), listi[i]=a[i].i;
    FOR(i,1,n) scanf("%d",&a[i].r);
    
    sort(a+1,a+n+1,mycmp);
    sort(listi+1,listi+n+1);
    reset(BIT,0);
    m=0;
    FOR(i,1,n) if(val.find(listi[i])==val.end()) val[listi[i]]=++m;
    FOR(i,1,n) a[i].i=val[a[i].i];
    
    res=0;
    FOR(i,1,n){
        if(get(a[i].i+1)>a[i].r) res++;
        update(a[i].i,a[i].r);
    }
    printf("%d",res);
    //getch();
    return 0;
}
