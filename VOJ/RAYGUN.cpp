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

const int maxv=1000000;

ll m,n,res;
bool isprime[maxv];
int cnt,p[80000],c0,c1,p0[310000],p1[310000];

//#include <conio.h>
int main(){
    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=i*2) isprime[j]=0;
    p[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) p[++cnt]=i;

    c0=c1=0;
    FOR(i,2,maxv){
        int v=i,v2=1,d=0;
        bool ok=1;
        for(int j=1;p[j]*p[j]<=v;j++){
            if(v%(p[j]*p[j])==0){
                ok=0;
                break;
            }
            if(v%p[j]==0){
                d++;
                v2*=p[j];
                v/=p[j];
            }
        }
        if(!ok) continue;
        if(v>1) v2*=v, d++;
        if(d&1) p1[c1++]=v2; else p0[c0++]=v2;
    }   
    
    sort(p0,p0+c0); sort(p1,p1+c1);
        
    //freopen("test.txt","r",stdin);
    int test;
    scanf("%d",&test);
    FOR(tt,1,test){
        scanf("%lld%lld",&m,&n);
        if(m>n) swap(m,n);
        res=m*n;    
        REP(i,c1){
            if(p1[i]>m) break;
            res-=(m/p1[i])*(n/p1[i]);
        }
        REP(i,c0){
            if(p0[i]>m) break;
            res+=(m/p0[i])*(n/p0[i]);
        }
        if(m==0 && n==0) res=-2;
        else if(m==0) res=-1;
        printf("Case %d: %lld\n",tt,res+2);
    }
    
    //getch();
    return 0;
}
