#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll dp[13][1<<13];
int x[222],y[222],qx[222],qy[222],qz[222],n,m,q;

bool checkLCA(int leftMask, int rightMask, int r){
    for(int i=0; i<q; ++i){
        if((leftMask>>qx[i]&1) && (rightMask>>qy[i]&1) && r!=qz[i]) return 0;
        if((leftMask>>qy[i]&1) && (rightMask>>qx[i]&1) && r!=qz[i]) return 0;
    }
    for(int i=0; i<m; ++i){
        if((leftMask>>x[i]&1) && y[i]!=r && (rightMask>>y[i]&1)) return 0;
        if((leftMask>>y[i]&1) && x[i]!=r && (rightMask>>x[i]&1)) return 0;
    }
    return 1;
}

bool checkEdge(int u, int v, int subMask){
    for(int i=0; i<m; ++i){
        if(x[i]==u && (subMask>>y[i]&1) && y[i]!=v) return 0;
        if(y[i]==u && (subMask>>x[i]&1) && x[i]!=v) return 0;
    }
    return 1;
}

ll get(int r, int mask){
    if(dp[r][mask]!=-1) return dp[r][mask];
    ll &res = dp[r][mask]; res = 0;
    int maskWithoutR = mask - (1<<r);
    int lastBit = maskWithoutR & (-maskWithoutR);
    int mask0 = mask - lastBit;
    for(int mask2 = mask0; mask2; mask2 = (mask2-1)&mask0){
        int leftMask = mask2 | lastBit;
        int rightMask = mask ^ leftMask;
        if(leftMask >> r & 1) continue; // r must in right mask
        if(!checkLCA(leftMask, rightMask, r)) continue;
        for(int v=0; v<n; ++v) if(leftMask>>v&1){
            if(!checkEdge(r,v,leftMask)) continue;
            res += get(r,rightMask)*get(v,leftMask);
        }
        if(mask2 == 0) break;
    }

    int leftMask = lastBit;
    int rightMask = mask ^ leftMask;
    int v=0;
    while(!(lastBit>>v&1)) ++v;
    if((rightMask>>r&1) && checkLCA(leftMask, rightMask, r) && checkEdge(r,v,leftMask))
        res += get(r,rightMask)*get(v,leftMask);

    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    bool ok=1;
    reset(dp,-1);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0; i<m; ++i){
        scanf("%d%d",&x[i],&y[i]);
        --x[i]; --y[i];
    }
    for(int i=0; i<q; ++i){
        scanf("%d%d%d",&qx[i],&qy[i],&qz[i]);
        --qx[i]; --qy[i]; --qz[i];
        if(qx[i]==qy[i] && qx[i]!=qz[i]) ok=0;
    }
    for(int i=0; i<n; ++i) dp[i][1<<i]=1;
    cout<<get(0,(1<<n)-1)*ok<<endl;
}

