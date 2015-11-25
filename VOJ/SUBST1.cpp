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

const int maxn=50007;

int n,SA[maxn],tmpRA[maxn],tmpSA[maxn],RA[maxn],c[maxn],PLCP[maxn],prev[maxn];
char T[maxn];
ll res;

int fRA(int v){
    if(v<n) return RA[v]; else return 0;
}

void sort(int k){
    reset(c,0);
    REP(i,n) c[fRA(SA[i]+k)]++;
    int t,sum,i,maxi=max(300,n);
    for(i=sum=0; i<=maxi; i++){
        t=c[i];
        c[i]=sum;
        sum+=t;
    }
    REP(i,n) tmpSA[c[fRA(SA[i]+k)]++]=SA[i];
    REP(i,n) SA[i]=tmpSA[i];
}

void constructSA(){
    int r;
    REP(i,n) SA[i]=i, RA[i]=T[i];
    for(int k=1; k<n; k<<=1){
        sort(k); sort(0);
        tmpRA[SA[0]]=r=1;
        FOR(i,1,n-1)
            tmpRA[SA[i]]=((RA[SA[i]]==RA[SA[i-1]] && fRA(SA[i]+k)==fRA(SA[i-1]+k))?r:++r);
        REP(i,n) RA[i]=tmpRA[i];
    }
}

//#include <conio.h>
int main(){
    int test,l;
    //freopen("test.txt","r",stdin);
    
    scanf("%d",&test);
    REP(index,test){
        scanf("%s",T);
        n=strlen(T);
        constructSA();
        l=0;
        prev[SA[0]]=-1;
        FOR(i,1,n-1) prev[SA[i]]=SA[i-1];
        REP(i,n){
            if(prev[i]==-1){PLCP[i]=0; continue;}
            while(i+l<n && prev[i]+l<n && T[i+l]==T[prev[i]+l]) l++;
            PLCP[i]=l;
            l=max(l-1,0);
        }
        res=0;
        REP(i,n) res+=n-i-PLCP[i];
        printf("%lld\n",res);
    }
    
    //getch();
    return 0;
}
