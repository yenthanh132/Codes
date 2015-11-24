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

const int maxn=10007;

struct edge{
    int x,y,c;
} e[maxn];
int lab[maxn],n,m,c;
bool free1[maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

bool cmp1(const edge &a, const edge &b){
    return a.c>b.c;   
}
bool cmp2(const edge &a, const edge &b){
    return a.c<b.c;   
}

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d%d",&n,&m,&c);
        FOR(i,1,n) lab[i]=-1;   
        
        FOR(i,1,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].c);
        sort(e+1,e+m+1,cmp1);
        FOR(i,1,m) free1[i]=1;
        int t=0;
        FOR(i,1,m){
            int r1=getroot(e[i].x);
            int r2=getroot(e[i].y);
            if(r1!=r2){
                dsu(r1,r2);
                free1[i]=0;
                t++;
            }
        }
        
        int mt=0;
        FOR(i,1,m) if(free1[i]) e[++mt]=e[i];
        m=mt;
        sort(e+1,e+m+1,cmp2);
        int r1=0,p=1,r2=0,r3=0;
        
        REP(step,n-1-t){
            if(p<=m && e[p].c<=c){
                r3+=e[p].c;
                r2++;
                p++;
            }else{
                r3+=c;
                r1++;
            }
        }
        cout<<r1<<' '<<r2<<' '<<r3<<endl;
    }
       
    //getch();
    return 0;
}
