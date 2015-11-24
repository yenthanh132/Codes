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

struct node{
    int v;
} IT[maxn*4];
int n;
struct edge{
    int l,r,c;
}a[maxn];
set<int> mys;

void update(int i, int l, int r, int p){
    if(p<l || p>r) return;
    if(l==r){
        IT[i].v=1;
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,p); update(i*2+1,mid+1,r,p);
    IT[i].v=IT[i*2].v+IT[i*2+1].v;
}

int get(int i, int l, int r, int s, int f){
    if(f<l || r<s) return 0;
    if(s<=l && r<=f) return IT[i].v;
    int mid=(l+r)/2;
    int res=get(i*2,l,mid,s,f)+get(i*2+1,mid+1,r,s,f);
    return res;
}   

bool cmp(const edge &a, const edge &b){
    return a.r<b.r;
}
 

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
    sort(a+1,a+n+1,cmp);
    int res=0;
    FOR(i,0,50000) mys.insert(i);
    FOR(i,1,n){
        int t=0;
        if(i>1) t=get(1,0,50000,a[i].l,a[i-1].r);
        REP(j,a[i].c-t){
            set<int>::iterator it=mys.upper_bound(a[i].r);   
            it--;
            update(1,0,50000,*it);
            res++;
            mys.erase(it);
        }
        
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
