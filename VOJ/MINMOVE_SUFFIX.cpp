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

const int maxn=200000;
const int base=73471;

int SA[maxn],tmpSA[maxn],RA[maxn],tmpRA[maxn],c[maxn];
char T[maxn];
int n,N,res;
ll val[maxn],hashpw;

int getRA(int v){
    if(v<=N) return RA[v]; else return 0;
}

void countingsort(int k){
    int maxv=max(300,N);
    reset(c,0);
    FOR(i,1,N) c[getRA(SA[i]+k)]++;
    int i,sum,t;
    for(i=sum=0; i<=maxv; i++){
        t=c[i];
        c[i]=sum;
        sum+=t;
    }
    FOR(i,1,N) tmpSA[++c[getRA(SA[i]+k)]]=SA[i];
    FOR(i,1,N) SA[i]=tmpSA[i];
}
    
void constructSA(){
    int r;
    FOR(i,1,N) RA[i]=T[i]-'.', SA[i]=i;
    for(int len=1; len<N; len<<=1){
        countingsort(len);
        countingsort(0);
        tmpRA[SA[1]]=r=1;
        FOR(i,2,N) if(getRA(SA[i])==getRA(SA[i-1]) && getRA(SA[i]+len)==getRA(SA[i-1]+len))
            tmpRA[SA[i]]=r;
        else tmpRA[SA[i]]=++r;
        FOR(i,1,N) RA[i]=tmpRA[i];
    }
}    

//#include <conio.h>
int main(){
    ll hashv;
    bool first=1;
    
    //freopen("test.txt","r",stdin);
    
    scanf("%s",T+1);
    n=strlen(T+1);
    N=n*2;
    FOR(i,n+1,N) T[i]=T[i-n];
    val[0]=0; hashpw=1;
    FOR(i,1,n) hashpw*=base;
    FOR(i,1,N) val[i]=val[i-1]*base+T[i];
    constructSA();
    T[N+1]='\0';
    FOR(i,1,N) if(SA[i]<=n){
        if(first){
            hashv=val[SA[i]+n-1]-val[SA[i]-1]*hashpw;
            first=0;
            res=SA[i];
        }else
            if(val[SA[i]+n-1]-val[SA[i]-1]*hashpw == hashv)
                res=min(res,SA[i]);
            else break;
    }
    printf("%d\n",res-1);
    
    //getch();
    return 0;
}
