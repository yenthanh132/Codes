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

const int maxn=1000007;

char s[maxn];
int n,k,a[maxn],last;
ll sum[maxn],mys[maxn];

int find(ll vsum){
    int l=1,r=last,mid,pos=mys[last];
    while(l<=r){
        mid=(l+r)/2;
        if(sum[mys[mid]]<=vsum){
            r=mid-1;
            pos=mys[mid];
        }else l=mid+1;
    }
    return pos;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%s",&k,s+1);
    n=strlen(s+1);
    FOR(i,1,n) if(s[i]=='1') a[i]=3; else a[i]=-2;
    mys[last=1]=n+1;
    ll res=0;
    FORD(i,n,1){
        sum[i]=sum[i+1]+a[i];
        int pos=find(sum[i]);
        if(sum[i]>=sum[pos]) res=max(res,1ll*pos-i);
        if(sum[i]<sum[mys[last]]) mys[++last]=i;             
    }
    if(k>1){
        if(sum[1]>=0){
            FORD(i,n,1){
                ll vsum=sum[i]+sum[1]*(k-1);
                int pos=find(vsum);
                if(vsum>=sum[pos]) res=max(res,(n-i+1) + 1ll*n*(k-2) + pos-1);
            }   
        }else{
            FORD(i,n,1){
                int l=0, r=k-2, mid, kt=0;
                while(l<=r){
                    mid=(l+r)/2;
                    if(sum[i] + sum[1]*(mid+1) >= sum[mys[last]]){
                        kt=mid;
                        l=mid+1;
                    }else r=mid-1;
                }
                ll vsum=sum[i]+sum[1]*(kt+1);
                int pos=find(vsum);
                if(vsum>=sum[pos]) res=max(res,(n-i+1) + 1ll*n*kt + pos-1);
            }   
        }
    }
              
    cout<<res<<endl;
    
    //getch();
    return 0;
}
        
        
