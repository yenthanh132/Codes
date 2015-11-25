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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=200007;

int n,x[maxn],xlist[maxn],cnt,xc;
struct ITnode{
    int maxv,t;
}IT[maxn*4];

struct node{
    int y,x1,x2;
    bool open;
    bool operator<(const node &b)const{
        return y<b.y;
    }
}list[maxn];

void lazy_update(int i, int l, int r){
    if(!IT[i].t) return;
    if(l+1<r){
        IT[i*2].t+=IT[i].t;
        IT[i*2+1].t+=IT[i].t;
    }
    IT[i].maxv+=IT[i].t;
    IT[i].t=0;
}

void update(int i, int l, int r, int x1, int x2, int v){
    lazy_update(i,l,r);
    if(x2<=xlist[l] || x1>=xlist[r] || l>=r) return;
    if(x1<=xlist[l] && xlist[r]<=x2){
        IT[i].t=v;
        lazy_update(i,l,r);
        return;
    }
    int mid=(l+r)>>1;
    update(i*2,l,mid,x1,x2,v);
    update(i*2+1,mid,r,x1,x2,v);
    IT[i].maxv=max(IT[i*2].maxv,IT[i*2+1].maxv);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int k;
    read(n);
    cnt=xc=0;
    FOR(i,1,n){
        read(k);
        FOR(j,1,k) read(x[j]);
        x[k+1]=x[1];
        for(int j=2; j<=k; j+=2){
            xlist[++xc]=x[j-1];
            if(x[j-1]<x[j+1]){        
                list[++cnt].y=x[j];
                list[cnt].x1=x[j-1];
                list[cnt].x2=x[j+1];
                list[cnt].open=1;
            }else{
                list[++cnt].y=x[j];
                list[cnt].x1=x[j+1];
                list[cnt].x2=x[j-1];
                list[cnt].open=0;
            }
        }
    }
    sort(xlist+1,xlist+xc+1);
    xc=unique(xlist+1,xlist+xc+1)-xlist-1;
    sort(list+1,list+cnt+1);
    int res=0;
    FOR(i,1,cnt){
        if(list[i].open) update(1,1,xc,list[i].x1,list[i].x2,1);
        else update(1,1,xc,list[i].x1,list[i].x2,-1);
        res=max(res,IT[1].maxv);
    }
    printf("%d\n",res);
    //getch();
    return 0;
}
    
