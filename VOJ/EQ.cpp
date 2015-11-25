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

int test,n,p;
priority_queue<ll,vector<ll>,greater<ll> > q;
ll t,k,res;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d",&n,&p);
        res=0;
        while(!q.empty()) q.pop();
        FOR(i,1,p){
            scanf("%lld%lld",&t,&k);
            if(sz(q)==n){
                ll mint=q.top(); q.pop();
                if(mint>=t) res+=mint-t+1;
                t=max(t,mint+1);
            }
            q.push(t+5+k-1);
            res+=5+k;
        }
        printf("%lld\n",res);
    }
    //getch();
    return 0;
}
            
                
