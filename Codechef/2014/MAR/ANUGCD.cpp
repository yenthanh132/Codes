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

const int maxn=100007;

int a[maxn],n,m,*IT[maxn],*IT2[maxn];
bool isprime[maxn];
int pl[maxn],cnt;
vector<int> list[maxn];
vector<pii> q[maxn];

void initIT(int v, int i, int l, int r){
    if(l==r){
        IT[v][i]=a[list[v][l]];
        IT2[v][i]=1;
        return;
    }      
    int mid=(l+r)/2;
    initIT(v,i*2,l,mid); initIT(v,i*2+1,mid+1,r);
    IT[v][i]=max(IT[v][i*2],IT[v][i*2+1]);
    IT2[v][i]=0;
    if(IT[v][i]==IT[v][i*2]) IT2[v][i]+=IT2[v][i*2];
    if(IT[v][i]==IT[v][i*2+1]) IT2[v][i]+=IT2[v][i*2+1];
}

int maxIT, cntIT, res1, res2;

void update_max(int &v, int &c, int v0, int c0){
    if(v0>v){
        v=v0;
        c=c0;
    }else if(v0==v) c+=c0;   
}

void getIT(int v, int i, int l, int r, int s, int f){
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        update_max(maxIT,cntIT,IT[v][i],IT2[v][i]);
        return;
    }
    int mid=(l+r)/2;
    getIT(v,i*2,l,mid,s,f); getIT(v,i*2+1,mid+1,r,s,f);    
}

int get_left(int v, int p){
    int l=0, r=sz(list[v])-1, mid, res = r+1;
    while(l<=r){
        mid=(l+r)/2;
        if(p<=list[v][mid]){
            res=mid;
            r=mid-1;   
        }else l=mid+1;
    }
    return res;
}

int get_right(int v, int p){
    int l=0, r=sz(list[v])-1, mid, res=l-1;
    while(l<=r){
        mid=(l+r)/2;
        if(list[v][mid]<=p){
            res=mid;
            l=mid+1;   
        }else r=mid-1;
    }   
    return res;
}

void find_solution(int val, int x, int y){
    int x0,y0;
    x0 = get_left(val,x);
    y0 = get_right(val,y);
    if(x0<=y0){
        maxIT=-1;
        getIT(val,1,0,sz(list[val])-1,x0,y0);   
        if(maxIT>res1){
            res1=maxIT;
            res2=cntIT;   
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    isprime[2]=1;
    for(int i=3; i<=100000; i+=2) isprime[i]=1;
    for(int i=3; i*i<=100000; i+=2) if(isprime[i])
        for(int j=i*i; j<=100000; j+=2*i) isprime[j]=0;
    pl[cnt=1]=2;
    for(int i=3; i<=100000; i+=2) if(isprime[i]) pl[++cnt]=i;
    
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d",&a[i]);
        int v=a[i];
        for(int j=1; pl[j]*pl[j]<=v; ++j) if(v%pl[j]==0){
            list[pl[j]].pb(i);
            int t=pl[j];
            while(v%t==0) v/=t;
        }   
        if(v>1) list[v].pb(i);
    }
    FOR(i,1,cnt){
        int v=pl[i];
        if(sz(list[v])>0){
            int k=sz(list[v]);
            IT[v]=new int[k*4+1];
            IT2[v]=new int[k*4+1];
            initIT(v,1,0,k-1);
        }   
    }
        
    
    int g,x,y;
    
    REP(r,m){
        scanf("%d%d%d",&g,&x,&y);
        if(g==1){
            puts("-1 -1");
            continue;
        }
        res1=res2=-1;
        for(int i=1; pl[i]*pl[i]<=g; ++i) if(g%pl[i]==0){
            int v=pl[i];
            find_solution(v,x,y);
            while(g%v==0) g/=v;
        }
        if(g>1) find_solution(g,x,y);
        printf("%d %d\n",res1,res2);
    } 
    
    return 0;
}
