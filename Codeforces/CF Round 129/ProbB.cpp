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

int n;
map<int,pii> a;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int x,y;
    scanf("%d",&n);
    pii t;
    REP(i,n){
        scanf("%d%d",&x,&y);
        if(a.find(x)==a.end()) a[x]=pii(1,0);
        else{
            t=a[x];
            t.fi++;
            a[x]=t;
        }
        if(y==x) continue;
        if(a.find(y)==a.end()) a[y]=pii(0,1);
        else{
            t=a[y];
            t.se++;
            a[y]=t;
        }
    }
    map<int,pii>::iterator it;
    int res=oo,m=(n+1)/2;
    for(it=a.begin(); it!=a.end(); it++){
        if(it->se.fi>=m) res=0;
        else if(it->se.fi+it->se.se>=m){
            x=it->se.fi;
            res=min(res,m-x);
        }
    }
    if(res==oo) printf("-1\n"); else printf("%d\n",res);
    //getch();
    return 0;
}
