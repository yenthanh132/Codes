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

int T,n,m,P;
double p;
struct node{int i; double x,y;};
vector<node> a[2];

bool mycmp(const node &a, const node &b){
    return a.i<b.i;
}

int main(){
//    freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d%d",&n,&m,&P);
        double p=1.0*P/100;
        int flag=1;
        a[flag].clear();
        FOR(i,1,m){
            node t;
            scanf("%d",&t.i);
            t.x=1; t.y=0;
            a[1].pb(t);
        }
        sort(a[1].begin(),a[1].end(),mycmp);
        while(n>1){
            flag=1-flag;
            a[flag].clear();
            for(int j=0; j<sz(a[1-flag]); j++)
                if(j<sz(a[1-flag])-1 && (a[1-flag][j].i+1)/2==(a[1-flag][j+1].i+1)/2){
                    node u=a[1-flag][j], v=a[1-flag][j+1];
                    node t;
                    t.i=(u.i+1)/2;
                    t.x=(u.x*v.x + u.x*v.y*p + u.y*v.x*p);
                    t.y=(u.x*v.y*(1-p) + u.y*v.x*(1-p) + u.y*v.y);
                    a[flag].pb(t);
                    j++;
                }else{
                    node u=a[1-flag][j];
                    node t;
                    t.i=(u.i+1)/2;
                    t.x=(u.x*p);
                    t.y=(u.x*(1-p) + u.y);
                    a[flag].pb(t);
                }
            n/=2;
        }
        printf("%0.12lf\n",a[flag][0].x*100);
    }
    return 0;
}


