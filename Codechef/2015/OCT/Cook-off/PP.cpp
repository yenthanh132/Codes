#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

const int base=73471;
const int base2=2;
const int maxn=2000007;

ll pw[maxn],vl[maxn],vr[maxn];
ll pw2[maxn],vl2[maxn],vr2[maxn];
char s[maxn];
int pos[maxn],n,len[maxn];
map<pll,int> cnt;

pll getL(int l, int r){
    return pll(vl[r] - vl[l-1]*pw[r-l+1], (vl2[r] - vl2[l-1]*pw2[r-l+1]%oo + oo)%oo);
}

pll getR(int l, int r){
    return pll(vr[l] - vr[r+1]*pw[r-l+1], (vr2[l] - vr2[r+1]*pw2[r-l+1]%oo + oo)%oo);
}

int main(){
    pw[0]=1;
    for(int i=1; i<=2000000; ++i) pw[i]=pw[i-1]*base;
    pw2[0]=1;
    for(int i=1; i<=2000000; ++i) pw2[i]=pw2[i-1]*base2%oo;

//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int it=1;
        int total=0;
        for(int i=1; i<=n; ++i){
            scanf("%s",s+it);
            pos[i] = it;
            len[i] = strlen(s+it);
            it += len[i];
            total += len[i];
        }
        vl[0]=0;
        for(int i=1; i<=total; ++i) vl[i]=vl[i-1]*base + s[i];
        vr[total+1]=0;
        for(int i=total; i>=1; --i) vr[i]=vr[i+1]*base + s[i];

        vl2[0]=0;
        for(int i=1; i<=total; ++i) vl2[i]=(vl2[i-1]*base2 + s[i])%oo;
        vr2[total+1]=0;
        for(int i=total; i>=1; --i) vr2[i]=(vr2[i+1]*base2 + s[i])%oo;

        cnt.clear();
        ll res=0;
        for(int i=1; i<=n; ++i) ++cnt[getR(pos[i],pos[i]+len[i]-1)];
        for(int i=1; i<=n; ++i){
            --cnt[getR(pos[i], pos[i]+len[i]-1)];

            for(int j=0; j<len[i]-1; ++j){
                pll v=getL(pos[i],pos[i]+j);
                int rx=pos[i]+len[i]-1;
                int lx=pos[i]+j+1;
                if(getL(lx,rx)==getR(lx,rx))
                    res += cnt[v];
            }

            for(int j=0; j<len[i]-1; ++j){
                pll v=getL(pos[i]+len[i]-j-1,pos[i]+len[i]-1);
                int rx=pos[i]+len[i]-j-2;
                int lx=pos[i];
                if(getL(lx,rx)==getR(lx,rx))
                    res += cnt[v];
            }

            res += cnt[getL(pos[i],pos[i]+len[i]-1)];
            ++cnt[getR(pos[i], pos[i]+len[i]-1)];
        }




        printf("%lld\n",res);
    }
}

