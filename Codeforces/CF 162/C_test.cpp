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
#define oo 100000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

int n,c[maxn],v[maxn],q,a,b;
ll dp[maxn],max1,id1,max2,id2,res,res2;

void update(ll &max1, ll &id1, ll &max2, ll &id2, ll v, ll id){
    if(v>max1){
        if(id!=id1){
            max2=max1;
            id2=id1;
        }
        max1=v;
        id1=id;
    }else if(v>max2 && id!=id1){
        max2=v;
        id2=id;
    }
}

void update2(ll &max1, ll &id1, ll &max2, ll &id2, ll v, ll id){
    if(v>max1){
        if(id!=id1){
            max2=max1;
            id2=id1;
        }
        max1=v;
        id1=id;
    }else if(v>max2){
        max2=v;
        id2=id;
    }
}

void sinhtest(){
    freopen("test.txt","w",stdout);
    cout<<10<<' '<<10<<endl;
    FOR(i,1,10) cout<< rand()%(5-(-5)+1)-5<<' '; cout<<endl;
    FOR(i,1,10) cout<<rand()%10+1<<' '; cout<<endl;
    FOR(i,1,10) cout<<rand()%(5-(-5)+1)-5<<' '<<rand()%(5-(-5)+1)-5<<endl;
}

#include <conio.h>
int main(){
    srand(time(NULL));
    sinhtest();
while(1){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&v[i]);
    FOR(i,1,n) scanf("%d",&c[i]);
    FOR(index,1,q){
        scanf("%d%d",&a,&b);
        max1=max2=id1=id2=-oo;
        res=0;
        FOR(i,1,n) dp[i]=-oo;
        ll val1,val2,best;
        FOR(i,1,n){
            val1=dp[c[i]];
            if(max1>-oo && id1!=c[i]) val2=max1;
            else if(max2>-oo && id2!=c[i]) val2=max2;
            else val2=-oo;
            val2=max(val2,0ll);
            best=max(val1 + 1ll*v[i]*a, val2+1ll*v[i]*b);
            update(max1,id1,max2,id2,best,c[i]);
            dp[c[i]]=max(dp[c[i]],best);
            res=max(res,best);
        }
        
        max1=max2=id1=id2=-oo;
        res2=0;
        FOR(i,1,n) dp[i]=-oo;
        FOR(i,1,n){
            val1=dp[c[i]];
            if(max1>-oo && id1!=c[i]) val2=max1;
            else if(max2>-oo && id2!=c[i]) val2=max2;
            else val2=-oo;
            val2=max(val2,0ll);
            best=max(val1 + 1ll*v[i]*a, val2+1ll*v[i]*b);
            update2(max1,id1,max2,id2,best,c[i]);
            dp[c[i]]=max(dp[c[i]],best);
            res2=max(res2,best);
        }
        if(res!=res2){
            return 0;
        }
    }
    fclose(stdin);
    sinhtest();
}
    return 0;
}
        
                       
