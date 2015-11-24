#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> iii;
const int maxn=400007;

int e,s,n,m,f[maxn],N;
vector<int> pos[4];
pii d[maxn];
vector<iii> edge[maxn];
bool free1[maxn];
set<iii> mys;

int getId(int i, int j){
    int r=0;
    for(int i0=0; i0<i; ++i0) r+=sz(pos[i0]);
    r+=j;
    return r;
}

bool cmp(const int &a, const int &b){
    return f[a]>f[b];
}

map<int,pii> ans;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&e,&s,&n,&m);
    for(int i=1; i<=n; ++i){
        int t,x;
        scanf("%d%d",&t,&x);
        if(x<e) pos[t].pb(x);
    }
    for(int i=1; i<=m; ++i){
        int x;
        scanf("%d",&x);
        f[i]=x;
        if(x<e) pos[0].pb(x);
    }
    pos[3].pb(e);
    for(int t=0; t<=3; ++t) sort(pos[t].begin(),pos[t].end());

    for(int i=1; i<=3; ++i){
        for(int j=0; j<sz(pos[i]); ++j){
            int p=pos[i][j];
            int u=getId(i,j);
            bool found=0;

            for(int k=i; k<=3; ++k){
                int it=lower_bound(pos[k].begin(),pos[k].end(),p+1)-pos[k].begin();
                if(it>=sz(pos[k])) continue;

                int p2=pos[k][it];
                if(p<p2 && p+s>=p2){
                    int x=0,y=0;
                    if(i==1) x+=p2-p; else if(i==2) y+=p2-p;
                    int v=getId(k,it);
                    edge[u].pb(iii(pii(x,y),v));
                    found=1;
                }
            }

            if(found) continue;

            for(int k=i-1; k>=1; --k){
                int it=upper_bound(pos[k].begin(),pos[k].end(),p+s)-pos[k].begin();
                if(it==0) continue;
                --it;
                int p2=pos[k][it];
                if(p<p2 && p+s>=p2){
                    int x=0, y=0;
                    if(i==2){
                        y+=s;
                        x-=s-(p2-p);
                    }else if(i==3){
                        if(k==2) y-=s-(p2-p);
                        else x-=s-(p2-p);
                    }
                    int v=getId(k,it);
                    edge[u].pb(iii(pii(x,y),v));
                    break;
                }
            }
        }
    }

    for(int j=0; j<sz(pos[0]); ++j){
        int p=pos[0][j];
        int u=getId(0,j);
        bool found=0;
        for(int k=3; k<=3; ++k){
            int it=lower_bound(pos[k].begin(),pos[k].end(),p+1)-pos[k].begin();
            if(it>=sz(pos[k])) continue;

            int p2=pos[k][it];
            if(p<p2 && p+s>=p2){
                int x=0,y=0;
                int v=getId(k,it);
                edge[u].pb(iii(pii(x,y),v));
                found=1;
            }
        }

        if(found) continue;

        for(int k=2; k>=1; --k){
            int it=upper_bound(pos[k].begin(),pos[k].end(),p+s)-pos[k].begin();
            if(it==0) continue;
            --it;
            int p2=pos[k][it];
            if(p<p2 && p+s>=p2){
                int x=0, y=0;

                if(k==2) y-=s-(p2-p);
                else x-=s-(p2-p);

                int v=getId(k,it);
                edge[u].pb(iii(pii(x,y),v));
                break;
            }
        }
    }

    N=0;
    for(int i=0; i<=3; ++i) N==sz(pos[i]);

    d[N-1] = pii(0,0);
    int it[4];
    for(int i=0; i<=3; ++i) it[i]=sz(pos[i])-1;
    it[3]--;

    while(it[0]>=0 || it[1]>=0 || it[2]>=0 || it[3]>=0){
        int maxY=-1,i=-1,v2=-1;
        for(int v=0; v<=3; ++v)
            if(it[v]>=0 && (v2==-1 || maxY < pos[v][it[v]])){
                maxY = pos[v][it[v]];
                i=getId(v,it[v]);
                v2=v;
            }
        --it[v2];

        d[i]=pii(oo,oo);
        for(int j=0; j<sz(edge[i]); ++j){
            int v=edge[i][j].second;
            if(d[v].first!=oo){
                pii tmp = pii(d[v].first+edge[i][j].first.first,d[v].second+edge[i][j].first.second);
                if(d[i] > tmp){
                    d[i] = tmp;
                }
            }
        }
    }



    for(int i=0; i<sz(pos[0]); ++i){
        int p=pos[0][i];
        int u=getId(0,i);
        if(d[u].first!=oo)
            ans[p] = d[u];
    }

    for(int i=1; i<=m; ++i)
        if(ans.count(f[i])){
            pii t=ans[f[i]];
            printf("%I64d %I64d\n",t.first,t.second);
        }else{
            puts("-1 -1");
        }


}

