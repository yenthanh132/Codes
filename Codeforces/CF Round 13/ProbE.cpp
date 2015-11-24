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

const int maxn=100007;

int n,m,a[maxn],next[maxn],val[maxn],block;

void init(){
    block=int(sqrt(n));
    int j,r;
    REPD(i,n){
        j=i+a[i]; r=min((i/block+1)*block-1,n-1);
        if(j<=r) next[i]=next[j], val[i]=val[j]+1;
        else next[i]=j, val[i]=1;
    }
}

void update(int pos, int v){
    int l,r,j;
    l=(pos/block)*block,r=min(l+block-1,n-1);
    a[pos]=v;
    FORD(i,pos,l){
        j=i+a[i];
        if(j<=r) next[i]=next[j], val[i]=val[j]+1;
        else next[i]=j, val[i]=1;
    }
}

pii get(int pos){
    int v=0, last;
    while(pos<n){
        last=pos;
        v=v+val[pos];
        pos=next[pos];
    }
    while(last+a[last]<n) last+=a[last];
    return(pii(last+1,v));
}

#include <conio.h>
        
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    REP(i,n) scanf("%d",a+i);
    init();
    int k,x,y;
    REP(i,m){
        scanf("%d",&k);
        if(k==0){
            scanf("%d%d",&x,&y);
            update(x-1,y);
        }else{
            scanf("%d",&x);
            pii r=get(x-1);
            printf("%d %d\n",r.fi,r.se);
        }
    }
    //getch();
    return 0;
}
