#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

pii p[maxn];
int n,x[maxn],y[maxn],m,mys[maxn],last;

bool cmp(const pii &a, const pii &b){
    return a.first < b.first || (a.second > b.second && a.first == b.first);
}
set<pii> set1;

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll v1 = (x1-x2)*(y2-y3)*x3*y1;
    ll v2 = (x2-x3)*(y1-y2)*x1*y3;
    if(v1==v2) return 0;
    if(v1>v2) return 1;
    return -1;
}

int ccw(pii a, pii b, pii c){
    return ccw(a.first,a.second, b.first,b.second, c.first,c.second);
}

bool cmp2(const pii &a, const pii &b){
    int r = ccw(p[1],a,b);
    if(r==0) return a.first < b.first;
    return r<0;
}

int maxy[11111];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    reset(maxy,-1);
    for(int i=1; i<=n; ++i){
        scanf("%d%d",&x[i],&y[i]);
        maxy[x[i]]=max(maxy[x[i]],y[i]);
    }
    m=0;
    int cury=0;
    for(int i=10000; i>=0; --i) if(maxy[i]>cury){
        p[++m]=pii(i,maxy[i]);
        cury=maxy[i];
    }

    mys[last=1]=1;
    for(int i=2; i<=m; ++i){
        while(last >= 2 && ccw(p[mys[last-1]],p[mys[last]],p[i])<0) --last;
        mys[++last]=i;
    }

    while(last>1){
        int x1=p[mys[last]].first, y1=p[mys[last]].second;
        int x2=p[mys[last-1]].first, y2=p[mys[last-1]].second;
        if(x1 > x2 || (x1==x2 && y1<y2)){
            --last;
        }else{
            break;
        }
    }

    for(int i=1; i<=last; ++i) set1.insert(p[mys[i]]);

    for(int i=1; i<=n; ++i)
        if(set1.count(pii(x[i],y[i]))) printf("%d ",i);
}
