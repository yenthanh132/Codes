#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;
vector<int> e[maxn];
int n,maxd[2][maxn],cnt[2][maxn],deg[maxn],par[maxn];
int length[maxn],val[maxn], maxval, maxLength;

void update(int &m1, int &c1, int &m2, int &c2, int v, int c){
    if(v<=0) return;
    if(v>m1){
        if(m2==m1) c2+=c1;
        else{
            m2=m1;
            c2=c1;
        }
        m1=v;
        c1=c;
    }else if(v==m1){
        c1+=c;
    }else if(v>m2){
        m2=v;
        c2=c;
    }else if(v==m2){
        c2+=c;
    }
}

void scan1(int u, int p){
    maxd[0][u]=0; cnt[0][u]=1; maxd[1][u]=-1; cnt[1][u]=0;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        scan1(v,u);
        update(maxd[0][u],cnt[0][u],maxd[1][u],cnt[1][u],maxd[0][v]+1,cnt[0][v]);
    }
}

void scan2(int u, int p, int m1, int c1){
    if(p>0){
//        cout<<p<<'-'<<u<<' '<<maxd[0][u]+m1<<' '<<cnt[0][u]*c1<<endl;
        par[u] = p;
        length[u] = maxd[0][u]+m1;
        if(maxLength < length[u]){
            maxLength = length[u];
            maxval = 0;
        }
        val[u] = cnt[0][u]*c1;

        if(maxLength == length[u]) maxval = max(maxval, val[u]);
    }
    update(maxd[0][u],cnt[0][u],maxd[1][u],cnt[1][u], m1,c1);

    int mx1=-1, cx1, mx2=-1, cx2;
    map<int,int> countCnt;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        update(mx1,cx1,mx2,cx2,maxd[0][v]+1,cnt[0][v]);
        countCnt[maxd[0][v]+1] += cnt[0][v];
    }
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        int newM1, newC1;
        newM1 = mx1;
        newC1 = countCnt[newM1];
        if(newM1 == maxd[0][v]+1)
            newC1 -= cnt[0][v];
        if(newC1==0){
            newM1 = mx2;
            newC1 = countCnt[newM1];
        }
        if(m1>newM1){
            newM1 = m1;
            newC1 = c1;
        }else if(m1==newM1){
            newC1 += c1;
        }
        scan2(v,u, newM1+1, newC1);
    }
}


int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int u=1; u<=n; ++u) e[u].clear();
        int u,v;
        for(int i=0; i<n-1; ++i){
            scanf("%d%d",&u,&v);
            e[u].pb(v);
            e[v].pb(u);
        }
        scan1(1,-1);
        maxval = 0;
        maxLength = 0;
        scan2(1,-1,0,1);
        reset(deg,0);

        int maxvalCnt = 0;
        for(int i=2; i<=n; ++i) if(length[i]==maxLength && val[i]==maxval) ++maxvalCnt;
        if(maxvalCnt<2){
            puts("NO");
            continue;
        }

        for(int i=2; i<=n; ++i) if(length[i]==maxLength && val[i]==maxval){
            int u=i, v=par[i];
            ++deg[u];
            ++deg[v];
        }

        bool ok=1;
        for(int i=1; i<=n; ++i){
            if(deg[i]>2){
                ok=0;
                break;
            }

        }
        if(ok) puts("YES");
        else puts("NO");

    }
}

