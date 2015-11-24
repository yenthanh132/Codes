#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

map<int,int> mx,my;
map<int,ll> cvx, cvy;
map<pii,int> a;
ll n,cx,cy;
int k,q;

ll intersect;

void updateX(int v, int val){
    if(v==0) return;
    intersect -= cvx[v] * cvy[v];
    cvx[v] += val;
    intersect += cvx[v] * cvy[v];
}

void updateY(int v, int val){
    if(v==0) return;
    intersect -= cvx[v] * cvy[v];
    cvy[v] += val;
    intersect += cvx[v] * cvy[v];;
}

void xorPoint(int x, int y, int v){
    updateX(mx[x], -1);
    mx[x] ^= v;
    updateX(mx[x], 1);
    if(mx[x] == v){
        ++cx;
    }else if(mx[x] == 0){
        --cx;
    }

    updateY(my[y],-1);
    my[y] ^= v;
    updateY(my[y],1);

    if(my[y] == v){
        ++cy;
    }else if(my[y] == 0){
        --cy;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%lld%d%d",&n,&k,&q);
    cx=cy=0;
    intersect=0;
    for(int i=1; i<=k; ++i){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        xorPoint(x,y,v);
        a[pii(x,y)]=v;
    }

    for(int i=1; i<=q; ++i){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int v=a[pii(x1,y1)];
        xorPoint(x1,y1,v);
        a[pii(x2,y2)]=v;
        a[pii(x1,y1)]=0;
        xorPoint(x2,y2,v);

        ll res = n*(cx+cy) - cx*cy - intersect;
        printf("%lld\n",res);
    }
}

