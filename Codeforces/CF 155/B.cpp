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

const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int n,val[1007];

int getid(int d, int m){
    int res=0;
    FOR(i,1,m-1) res+=day[i];
    return res+d+200;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    int d,m,p,t;
    reset(val,0);
    REP(i,n){
        scanf("%d%d%d%d",&m,&d,&p,&t);
        int pos=getid(d,m);
        FOR(x,pos-t,pos-1) val[x]+=p;
    }
    int res=0;
    FOR(i,1,1000) res=max(res,val[i]);
    printf("%d\n",res);
    return 0;
}
