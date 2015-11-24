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

const int maxn=130;

int m,n,a[maxn][maxn],s[maxn][maxn];
vector<ll> list[1<<16];

bool compare(int x1, int y1, int x2, int y2, int n){
    REP(i,n) REP(j,n) if(a[x1+i][y1+j]!=a[x2+i][y2+j]) return 0;
    return 1;   
}

int sum(int x, int y, int n){
    return s[x+n-1][y+n-1]-s[x-1][y+n-1]-s[x+n-1][y-1]+s[x-1][y-1];
}

void get(int i, int x, int y, int n, int &res1, int &res2){
    res1=res2=0;
    if(n==1){
        res1=res2=1;
        return;
    }
    int x2=x+n-1, y2=y+n-1;
    if(sum(x,y,n)==n*n || sum(x,y,n)==0){
        res1=res2=1;
        return;
    }
    int r1,r2,r3,r4,s1,s2,s3,s4;
    int v[5],xt[5],yt[5];
    get(i*4+1,x,y,n/2,r1,s1);
    get(i*4+2,x,y+n/2,n/2,r2,s2);
    get(i*4+3,x+n/2,y,n/2,r3,s3);
    get(i*4+4,x+n/2,y+n/2,n/2,r4,s4);
    res1=r1+r2+r3+r4;
    res2=s1+s2+s3+s4;
    v[1]=s1; v[2]=s2; v[3]=s3; v[4]=s4;
    xt[1]=x; yt[1]=y; xt[2]=x; yt[2]=y+n/2;
    xt[3]=x+n/2; yt[3]=y; xt[4]=x+n/2; yt[4]=y+n/2;
    res1++;
    res2++;
    FOR(i,1,3) FOR(j,i+1,4) if(sum(xt[i],yt[i],n/2)!=0 && sum(xt[i],yt[i],n/2)!=n*n/4 && v[i]==v[j] && sum(xt[i],yt[i],n/2)==sum(xt[j],yt[j],n/2) && compare(xt[i],yt[i],xt[j],yt[j],n/2))
        res2-=v[i];
    
}

char buf[maxn];
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    cin>>m>>n;
    while(m){
        reset(a,0); reset(s,0);
        
        FOR(i,1,m){
            scanf("%s",buf+1);
            FOR(j,1,n) a[i][j]=(buf[j]=='1');
        }
            
            
        int v=1;
        while(v<max(m,n)) v*=2;
        m=n=v;
        FOR(i,1,m) FOR(j,1,n) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        int res1=0,res2=0;
        get(1,1,1,v,res1,res2);
        cout<<res1<<' '<<res2<<endl;
        cin>>m>>n;
    }
    getch();
    return 0;
}
        
