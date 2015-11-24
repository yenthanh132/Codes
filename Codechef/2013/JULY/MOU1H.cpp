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
#define oo 1000000009

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

int n,SA[maxn],tSA[maxn],RA[maxn],tRA[maxn],cnt[maxn];
int h[maxn],a[maxn];
int LCP[maxn],PLCP[maxn],prev[maxn];

int fRA(int i){return (i<=n)?RA[i]:0;}

void sort(int k){
    int maxi=max(300,n);
    FOR(i,0,maxi) cnt[i]=0;
    FOR(i,1,n) cnt[fRA(SA[i]+k)]++;
    for(int i=0,sum=0,t; i<=maxi; ++i){
        t=cnt[i];
        cnt[i]=sum;
        sum+=t;
    }   
    FOR(i,1,n) tSA[++cnt[fRA(SA[i]+k)]]=SA[i];
    FOR(i,1,n) SA[i]=tSA[i];    
}

void constructSA(){
    int r;
    FOR(i,1,n) SA[i]=i, RA[i]=a[i];   
    for(int k=1; k<n; k<<=1){
        sort(k); sort(0);
        tRA[SA[1]]=r=1;
        FOR(i,2,n) 
            tRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && fRA(SA[i]+k)==fRA(SA[i-1]+k))?r:++r;
        FOR(i,1,n) RA[i]=tRA[i];
    }
    prev[SA[1]]=-1;
    FOR(i,2,n) prev[SA[i]]=SA[i-1];
    int l=0;
    FOR(i,1,n){
        if(prev[i]==-1){PLCP[i]=0; continue;}
        while(i+l<=n && prev[i]+l<=n && a[i+l]==a[prev[i]+l]) ++l;
        PLCP[i]=l;
        l=max(0,l-1);
    }
    FOR(i,1,n) LCP[i]=PLCP[SA[i]];
}

int count(){
    ll res=0;
    FOR(i,1,n) res=(res + (n-SA[i]+1)-LCP[i])%oo;
    return res%oo;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int t;
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d",&n);
        REP(i,n) scanf("%d",&h[i]); n--;
        FOR(i,1,n) a[i]=h[i]-h[i-1]+101;
        constructSA();
        printf("%d\n",count());
    }
    //getch();
    return 0;
}
