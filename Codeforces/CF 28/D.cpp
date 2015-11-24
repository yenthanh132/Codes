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

int n,cnt;
struct node{
    int v,c,l,r,id;
    node(int v1, int v2, int v3, int v4, int v5){
        v=v1;
        c=v2;
        l=v3;
        r=v4;
        id=v5;
    }
};

map<int,int> mm;
int trace[maxn*3],pos[maxn*3];
vector<node> list[maxn];
int best;
vector<int> rlist;


void process(int id){
    int t,maxv=0,d;
    mm.clear();
    REP(i,sz(list[id]))
        if(list[id][i].l==0){
            t=list[id][i].v;
            if(mm[list[id][i].c]<t){
                mm[list[id][i].c]=t;
                pos[list[id][i].c]=i;
                trace[i]=-1;
                if(list[id][i].r==0 && maxv<t){
                    maxv=t;
                    d=i;
                }
            }
        }else if(mm[list[id][i].l]>0){
            t=mm[list[id][i].l]+list[id][i].v;
            if(mm[list[id][i].l+list[id][i].c]<t){
                mm[list[id][i].l+list[id][i].c]=t;
                pos[list[id][i].l+list[id][i].c]=i;
                trace[i]=pos[list[id][i].l];
                if(list[id][i].r==0 && maxv<t){
                    maxv=t;
                    d=i;
                }
            }
        }
    if(best<maxv){
        best=maxv;
        rlist.clear();
        while(d!=-1){
            rlist.pb(list[id][d].id);
            d=trace[d];
        }
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int v,c,l,r;
    cnt=0;
    FOR(i,1,n){
        scanf("%d%d%d%d",&v,&c,&l,&r);
        if(mm[c+l+r]==0) mm[c+l+r]=++cnt;
        list[mm[c+l+r]].pb(node(v,c,l,r,i));
    }
    best=0;
    FOR(i,1,cnt) process(i);
    printf("%d\n",sz(rlist));       
    REPD(i,sz(rlist)) printf("%d ",rlist[i]);
    puts("");
    //getch();
    return 0;
}
