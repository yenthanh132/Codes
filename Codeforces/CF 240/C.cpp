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

int a[maxn+1],n,m,N,b[maxn+1];
ll s[22],val[22],val2[22];

void merge(int l, int r){
    int mid=(l+r)/2;
    int x=l, y=mid+1, p=l;
    while(p<=r){
        if( y>r || (x<=mid && a[x]<=a[y])) b[p++]=a[x++];
        else b[p++]=a[y++];           
    }   
    FOR(i,l,r) a[i]=b[i];
}

void sort(int l, int r, int level){
    if(level==0) return;  
    int mid=(l+r)/2;
    sort(l,mid,level-1); sort(mid+1,r,level-1);
    int x=l;
    FOR(y,mid+1,r){
        while(x<=mid && a[x]<=a[y]) ++x;
        val[level]+=mid-x+1; 
    }
    x=l-1;
    FOR(y,mid+1,r){
        while(x+1<=mid && a[x+1]<a[y]) ++x;
        val2[level]+=x-l+1;
    }
    merge(l,r);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d",&n); N=1<<n;
    FOR(i,1,N) scanf("%d",&a[i]);
    
    reset(val,0); reset(val2,0);
    sort(1,N,n);
    FOR(i,1,n) s[i]=val[i]+val2[i];
    
    scanf("%d",&m);
    int x;
    REP(i,m){
        ll res=0;
        scanf("%d",&x);
        FOR(j,1,x) val[j]=s[j]-val[j];   
        FOR(j,1,n) res+=val[j];
        printf("%I64d\n",res);
    }
    
    return 0;
}
