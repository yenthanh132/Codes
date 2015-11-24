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

const int maxn=1<<20;

int a[maxn],IT[maxn];
int n,N,m;

void init(int i, int l, int r){
    if(l==r){
        IT[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    int len=r-l+1,p=0;
    while(len>1){
        p++;
        len/=2;   
    }
    if(p&1) IT[i]=IT[i*2] | IT[i*2+1];
    else IT[i] = IT[i*2] ^ IT[i*2+1];
}
    
int cal(int i, int l, int r, int p, int v){
    if(p<l || p>r) return IT[i];
    if(l==r){
        IT[i]=v;
        return v;
    }
    int mid=(l+r)/2;
    int len=r-l+1, q=0;
    while(len>1){
        q++;
        len/=2;   
    }
    int v1=cal(i*2,l,mid,p,v), v2=cal(i*2+1,mid+1,r,p,v);
    if(q&1) IT[i]= v1 | v2; else IT[i]=v1^v2;
    return IT[i];
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    N=1<<n;
    REP(i,N) scanf("%d",&a[i]);
    init(1,0,N-1);
    int p,v;
    REP(i,m){
        scanf("%d%d",&p,&v);
        printf("%d\n",cal(1,0,N-1,p-1,v));
    }
    //getch();
    return 0;
}
    
