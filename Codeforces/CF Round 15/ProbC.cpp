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

ll count2(ll len, ll pos1, ll pos2){
    return max(pos2-len/2,0ll)-max(pos1-1-len/2,0ll);
}

ll count1(ll len, ll pos, ll m){
    ll ans=((m-1)/len)*len/2, pos2=pos+(m-1)%len; if(pos2>len) pos2-=len;
    if(pos<=pos2) ans+=count2(len,pos,pos2); 
    else ans+=count2(len,1,pos2)+count2(len,pos,len);
    return ans;
}

ll sumxor(ll x, ll m){
    ll ans=0,num1,pos=0,len,pow2[60];
    pow2[0]=1; FOR(i,1,59) pow2[i]=pow2[i-1]*2;
    REP(p,60){
        int t=x%2;
        x/=2;
        if(t) pos|=pow2[p];
        len=pow2[p+1];
        num1=count1(len,pos+1,m);
        if(num1&1) ans|=pow2[p];
    }
    return ans;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n;
    ll res=0,x,m;
    scanf("%d",&n);
    REP(i,n){
        scanf("%I64d%I64d",&x,&m);
        res=res^sumxor(x,m);
    }
    if(res!=0) printf("tolik"); else printf("bolik");
    //getch();
    return 0;
}
