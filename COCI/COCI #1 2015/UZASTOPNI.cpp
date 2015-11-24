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
vector<pii> mys[maxn];
vector<int> leftPart[111],rightPart[111];
int n,num[maxn];
int mark[111][111], idxMark;

void dfs(int u){
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        dfs(v);
    }
    for(int v=1; v<=100; ++v) leftPart[v].clear(), rightPart[v].clear();
    ++idxMark;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        for(int j=0; j<sz(mys[v]); ++j){
            int l=mys[v][j].first, r=mys[v][j].second;
            if(mark[l][r]==idxMark) continue;
            mark[l][r]=idxMark;
            leftPart[l].pb(r);
            rightPart[r].pb(l);
        }
    }
    int first=0, last=0;
    ++idxMark;
    mark[num[u]][num[u]] = idxMark;
    mys[u].pb(pii(num[u],num[u]));
    while(first<=last){
        int l=mys[u][first].first, r=mys[u][first].second; ++first;
        vector<int> &lstL = leftPart[r+1];
        for(int i=0; i<sz(lstL); ++i){
            int r2 = lstL[i];
            if(mark[l][r2]==idxMark) continue;
            mark[l][r2]=idxMark;
            mys[u].pb(pii(l,r2));
            ++last;
        }
        vector<int> &lstR = rightPart[l-1];
        for(int i=0; i<sz(lstR); ++i){
            int l2 = lstR[i];
            if(mark[l2][r]==idxMark) continue;
            mark[l2][r]=idxMark;
            mys[u].pb(pii(l2,r));
            ++last;
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&num[i]);

    int u,v;
    for(int i=0; i<n-1; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v);
    }

    reset(mark,0);
    idxMark=0;
    dfs(1);
    cout<<sz(mys[1])<<endl;
}

