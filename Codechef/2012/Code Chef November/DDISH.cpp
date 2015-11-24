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

ll gt[11];

ll P(int k, int n){
    return gt[n]/gt[n-k];
}

ll count(ll v){
    int a[20],cnt=0;
    while(v){
        a[++cnt]=v%10;
        v/=10;
    }
    ll res=0;
    FOR(i,1,min(cnt-1,10)) res+=P(i,10)-P(i-1,9);
    int check[10]; reset(check,0);
    int num=10;
    if(cnt<=10){
        reset(check,0);
        FORD(i,cnt,1){
            check[a[i]]++;
            int c=0;
            if(i<cnt && !check[0]) c++;
            FOR(j,1,a[i]-1) if(!check[j]) c++;
            res+=c*P(i-1,--num);
            if(check[a[i]]>1) break;
            if(i==1) res++;
            
        }
    }
    return res;
}

//#include <conio.h>

int main(){
    gt[0]=gt[1]=1;
    FOR(i,2,10) gt[i]=gt[i-1]*i;
    ll a,b;
    int T;
    scanf("%d",&T);
    REP(i,T){
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",count(b)-count(a-1));
    }
    
    return 0;
}
