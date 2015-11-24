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

const int maxn=507;

bool isprime[maxn];
int test,m,n,v[maxn][maxn],list[maxn],cnt;
char a[maxn][maxn];

//#include <conio.h>
int main(){
    
    isprime[2]=1;
    for(int i=3; i<=500; i+=2) isprime[i]=1;
    for(int i=3; i*i<=500; i+=2) if(isprime[i])
        for(int j=i*i; j<=500; j+=i*2) isprime[j]=0;
    list[cnt=1]=2;
    for(int i=3; i<=500; i+=2) if(isprime[i]) list[++cnt]=i;
     
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    REP(tt,test){
        scanf("%d%d",&m,&n);
        FOR(i,1,m) scanf("%s",a[i]+1);
        FOR(x,1,m) FOR(y,1,n) v[x][y]=oo;
        FOR(x,1,m){
            int t=0;
            FOR(y,1,n) 
                if(a[x][y]=='^')
                    v[x][y]=min(v[x][y],t++);
                else
                    v[x][y]=t=0;
            
            t=0;
            FORD(y,n,1)
                if(a[x][y]=='^')
                    v[x][y]=min(v[x][y],t++);
                else
                    v[x][y]=t=0;
        }
        
        FOR(y,1,n){
            int t=0;
            FOR(x,1,m) 
                if(a[x][y]=='^')
                    v[x][y]=min(v[x][y],t++);
                else
                    v[x][y]=t=0;
            
            t=0;
            FORD(x,m,1)
                if(a[x][y]=='^')
                    v[x][y]=min(v[x][y],t++);
                else
                    v[x][y]=t=0;
        }       
        
        int res=0;
        FOR(x,1,m) FOR(y,1,n) if(v[x][y]>=2){
            int l=1,r=cnt,mid,pos=1;
            while(l<=r){
                mid=(l+r)/2;
                if(list[mid]<=v[x][y]){
                    pos=mid;
                    l=mid+1;
                }else r=mid-1;
            }   
            res+=pos;
        }
        
        printf("%d\n",res); 
    }
    //getch();
    return 0;
}
        
