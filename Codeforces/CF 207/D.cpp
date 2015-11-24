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

const int maxn=70007;
const int maxm=2200;

ll dp[2][maxm];
int n,s,first[maxn],m,r1[maxn],r2[maxn];
bool used[maxn];
pii a[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&s);
    FOR(i,1,n) scanf("%d",&a[i].fi), a[i].se=i;
    sort(a+1,a+n+1);
    s-=a[n].fi;
    n--;
    m=s/32+1;
    if(s<0){
        puts("-1");
        return 0;
    }
    
    reset(dp,0);
    reset(first,0);
    int flag=0;
    dp[flag][1]=1;
    FOR(i,1,n){
        flag^=1;
        FOR(j,1,m){
            dp[flag][j]=dp[1^flag][j];
            int r=j*32-1,l;
            if(r>=a[i].fi){
                ll mask,t;
                r=r-a[i].fi;   
                l=r-31;
                if(l>=0 && l/32+1==r/32+1) mask=dp[1^flag][l/32+1];
                else{
                    int id;
                    if(l<0) id=0; else id=l/32+1; 
                    ll mask2=(dp[1^flag][id]) | (dp[1^flag][id+1]<<32);
                    l=(l+32)%32;
                    r=l+31;
                    mask=(1ll<<(r+1)) - (1ll<<l);
                    mask&=mask2;
                    mask>>=l;
                }
                t=dp[flag][j] | mask;
                if(t!=dp[flag][j]){
                    REP(k,32) if( ((t>>k)&1)==1 && ((dp[flag][j]>>k)&1)==0){
                        first[(j-1)*32+k]=i;
                    }
                    dp[flag][j]=t;
                }    
            }
        }
    }
    
    if((dp[flag][m]>>(s%32))&1){
        n++;
        reset(used,0);
        while(s){
            used[first[s]]=1;
            s-=a[first[s]].fi;   
        }
        int p=-1;
        FOR(i,1,n)
            if(used[i]){
                r1[a[i].se]=a[i].fi;
                r2[a[i].se]=0;   
            }else{
                if(p==-1){
                    r1[a[i].se]=a[i].fi;
                    r2[a[i].se]=0;   
                }else{
                    r1[a[i].se]=a[i].fi-a[p].fi;
                    r2[a[i].se]=a[p].se;   
                }
                p=i;
            }
        FOR(i,1,n){
            printf("%d ",r1[i]);
            if(r2[i]==0) printf("0\n");
            else printf("1 %d\n",r2[i]);
            
        }
    }else puts("-1");
}
