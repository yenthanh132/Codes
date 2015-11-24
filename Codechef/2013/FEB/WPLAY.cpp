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

const int base=73471;

int d,r,c,t,n;
char s[20],arr[20];
bool valid[1<<16],dp[1<<16];
set<ll> mys;

ll hash(char *s, int n){
    sort(s,s+n);
    ll res=0;
    REP(i,n) res=res*base+s[i];
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&d);
    ll vhash;
    FOR(i,1,d){
        scanf("%s",s);
        vhash=hash(s,strlen(s));
        mys.insert(vhash);
    }
    scanf("%d%d",&r,&c);
    n=r*c;
    scanf("%d",&t);
    int len,e,f;
    REP(index,t){
        REP(i,r) scanf("%s",arr+i*c);
        REP(id,1<<n){
            len=0;
            REP(j,n) if((id>>j)&1) s[len++]=arr[j];
            vhash=hash(s,len);
            valid[id]=(mys.find(vhash)!=mys.end());
            dp[id]=0;
        }
        REP(id,1<<n) if(!dp[id]){
            e=((1<<n)-1)^id;
            f=e;
            while(f){
                if(valid[f]) dp[id|f]=1;
                f=e&(f-1);
            }
        }
        if(dp[(1<<n)-1]) puts("Alice"); else puts("Bob");
    }
    //getch();
    return 0;
}
