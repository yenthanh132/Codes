#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> iii;
typedef long long ll;

const int maxn=507;

struct box{
    int r,w,s,v;
    box(){}
    box(int _r, int _w, int _s, int _v){
        r=_r; w=_w; s=_s; v=_v;
    }
};
vector<box> b[maxn*2];

int n,S, f[maxn][maxn*2];

map<iii,int> dp;

int get(int state, int l, int r, int maxW){
    iii node = iii(pii(l,r),maxW);
    if(dp.count(node)) return dp[node];

    for(int i=l-1; i<=r; ++i) f[state][i]=0;
    for(int i=l; i<=r; ++i){
        f[state][i]=max(f[state][i],f[state][i-1]);
        for(int it=0; it<sz(b[i]); ++it){
            box &bb=b[i][it];
            if(bb.w <= maxW && bb.r<=r && (l<i || bb.r<r)){
                int new_maxW = min(maxW - bb.w, bb.s);
                f[state][bb.r] = max(f[state][bb.r], f[state][i] + bb.v + get(state+1,i,bb.r,new_maxW));
            }
        }
    }
    //cout<<l<<' '<<r<<' '<<maxW<<' '<<f[state][r]<<endl;
    dp[node]=f[state][r];
    return f[state][r];
}


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&S);
    int l,r,w,s,v;
    for(int i=1; i<=n; ++i){
        scanf("%d%d%d%d%d",&l,&r,&w,&s,&v);

        b[l].pb(box(r,w,s,v));
    }
    cout<<get(0,0,n*2,S)<<endl;
}

