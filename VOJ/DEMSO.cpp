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

const int maxn=20;

ll dp[maxn][11][2][maxn],a,b;
int d[maxn],n,D,k;

ll value(int pos, int last, bool less, int cnt){
    if(pos==0) return (last!=10 && cnt<=k);
    ll &res=dp[pos][last][less][cnt];
    if(res!=-1) return res;
    res=0;
    FOR(x,0,9) if(less || d[pos]>=x)
        res+=value(pos-1, (last==10 && x==0)?10:x, less || x<d[pos], cnt + ((last!=10 && abs(last-x)<=D)?1:0));
    return res;
}
    
ll count(ll v){
    if(v==0) return 0;
    for(d[1]=n=0; v; v/=10) d[++n]=v%10;
    reset(dp,-1);
    return value(n,10,0,0);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>a>>b>>D>>k;
    cout<<count(b)-count(a-1)<<endl;
    //getch();
    return 0;
}
