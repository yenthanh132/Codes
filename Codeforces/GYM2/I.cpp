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

const int maxn=107;

int n,m,deg[maxn],a[maxn];
int list[maxn],cnt,d[maxn];
ll dp[maxn];

void del(int i){
    cnt--;
    FOR(j,i,cnt) list[j]=list[j+1];
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    int u,v;
    reset(deg,0);
    FOR(i,1,m){
        cin>>u>>v;
        u++; v++;
        if(u>v) swap(u,v);
        deg[u]++;
    }
    cnt=n; FOR(i,1,n) list[i]=i;
    
    FOR(i,1,n){
        a[i]=list[deg[i]+1];
        del(deg[i]+1);
    }
    
    //FOR(i,1,n) cout<<a[i]<<' ';
    int minv=oo;
    ll res=0,t;
    FOR(i,1,n){
        if(a[i]<minv){
            reset(dp,0);
            reset(d,1);
            dp[i]=1;
            FOR(j,i+1,n){
                int maxv=0;
                dp[j]=0;
                FORD(z,j-1,i)
                    if(a[z]>maxv && a[z]<a[j]){
                        dp[j]+=dp[z];
                        d[z]=0;
                        maxv=a[z];
                    }
            }
            ll old=res;
            FOR(j,i,n) if(d[j]) res+=dp[j];            
            //cout<<i<<' '<<res-old<<endl;
        }
        minv=min(minv,a[i]);   
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
