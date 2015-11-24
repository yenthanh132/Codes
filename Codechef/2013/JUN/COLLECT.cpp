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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;
const int maxv=3000000;
const int dmod=3046201;

int n,IT[maxn*4],q,x,y;
char buf[10];
ll gt[maxv+1];

//IT implementation
void update(int i, int l, int r, int p, int v){
    if(p<l || p>r) return;
    if(l==r){
        IT[i]=v;
        return;
    }
    int mid=(l+r)>>1;
    update(i*2,l,mid,p,v); update(i*2+1,mid+1,r,p,v);
    IT[i]=IT[i*2]+IT[i*2+1];
}

int resIT;

void get(int i, int l, int r, int s, int f){
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        resIT+=IT[i];
        return;
    }
    int mid=(l+r)>>1;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
}

void change(int i, int v){
    update(1,1,n,i,v);
}

int sum(int i, int j){
    resIT=0;
    get(1,1,n,i,j);
    return resIT;
}   
//=================================================

ll mypow(ll v0, int n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=t*t%dmod;
    if(n&1) return t*v0%dmod; else return t;
}

void init(){
    gt[0]=1;
    FOR(i,1,maxv) gt[i]=gt[i-1]*i%dmod;
}

int main(){
    int s,len,v,k;
    ll res,den;
    
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    init();
    reset(IT,0);
    FOR(i,1,n){
        scanf("%d",&v);
        change(i,v);
    }
    
    scanf("%d",&q);

    REP(t,q){
        scanf("%s%d%d",buf,&x,&y);
        if(buf[0]=='c') change(x,y);
        else{
            s=sum(x,y);
            len=y-x+1;
            v=s/len; k=s%len;
            den=mypow(gt[v],len-k)*mypow(gt[v+1],k)%dmod;
            res=gt[s]*mypow(den,dmod-2)%dmod;
            res=res*gt[len]%dmod;
            res=res*mypow(gt[k],dmod-2)%dmod * mypow(gt[len-k],dmod-2)%dmod;
            printf("%lld\n",res);
        }
    }
    //getch();
    return 0;
}
