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
const int base=73471;

bool isprime[maxv];
int list[80000],n,x,y,c,d[20];           
ll res;
                
#include <conio.h>
int main(){
    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isprime[j]=0;
    list[n=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) list[++n]=i;
    
    freopen("test.txt","r",stdin);
    int test;
    scanf("%d",&test);
    FOR(i,1,test){
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        res=y+2;
        FOR(i,2,x){
            int v=i,cnt;
            c=0;
            for(int j=1; j<=n && list[j]*list[j]<=v; j++) if(v%list[j]==0){
                d[c++]=list[j];
                while(v%list[j]==0) v/=list[j];
            }
            if(v>1) d[c++]=v;
            
            FOR(i,1,(1<<c)-1){
                v=1; cnt=0;
                REP(j,c) if((i>>j)&1) v*=d[j],cnt++;
                if(cnt&1) res+=y-y/v; else res-=y-y/v;
            }
        }
        printf("Case %d: %lld\n",i,res);
                
    }
    
    getch();
    return 0;
}
