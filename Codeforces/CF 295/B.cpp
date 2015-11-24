#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000009

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int n,ct[maxn],cb[maxn],x[maxn],y[maxn],alive[maxn];
vector<int> top[maxn],bot[maxn];
map<pii,int> points;
set<int> num;

bool canRemove(int i){
    if(ct[i]==0) return 1;
    for(int j=0; j<sz(top[i]); ++j){
        int k=top[i][j];
        if(alive[k] && cb[k]==1) return 0;
    }
    return 1;
}

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        scanf("%d%d",&x[i],&y[i]);
        points[pii(x[i],y[i])]=i;
    }
    for(int i=0; i<n; ++i){
        for(int xt=x[i]-1; xt<=x[i]+1; ++xt){
            int yt=y[i]+1;
            if(points.count(pii(xt,yt))){
                top[i].pb(points[pii(xt,yt)]);
                ct[i]++;
            }
            if(y[i]==0) continue;
            yt=y[i]-1;
            if(points.count(pii(xt,yt))){
                bot[i].pb(points[pii(xt,yt)]);
                ++cb[i];
            }
        }
    }
    reset(alive,1);
    for(int i=0; i<n; ++i) if(canRemove(i)) num.insert(i);
    ll res = 0;
    int pp=n-1;
    for(int i=0; i<n; ++i, --pp){
        int x;
        if(i%2==0){
            set<int>::iterator it=num.end();
            --it;
            x=*it;
            num.erase(x);
        }else{
            set<int>::iterator it=num.begin();
            x=*it;
            num.erase(x);
        }
        res = (res + x*mypow(n,pp))%oo;
        alive[x]=0;
        for(int j=0; j<sz(top[x]); ++j){
            int y=top[x][j];
            if(!alive[y]) continue;
            --cb[y];
            for(int k=0; k<sz(bot[y]); ++k){
                int z=bot[y][k];
                if(!alive[z]) continue;
                if(canRemove(z)) num.insert(z);
                else num.erase(z);
            }
        }
        for(int j=0; j<sz(bot[x]); ++j){
            int y=bot[x][j];
            if(!alive[y]) continue;
            --ct[y];
            if(canRemove(y)) num.insert(y);
            else num.erase(y);
        }

    }
    cout<<res<<endl;
}

