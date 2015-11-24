#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int n,m,cnt,q;
vector<pii> clist[maxn];
map<int,int> mid;
pii query[maxn];

int lab[maxn];

int res[maxn];

map<pii,int> fcnt;
vector<int> ulist;

int get(int u){
    if(lab[u]<0) return u;
    lab[u]=get(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v,color;
    cnt=0;
    for(int i=0; i<m; ++i){
        scanf("%d%d%d",&u,&v,&color);
        if(mid[color]==0) mid[color]=++cnt;
        clist[mid[color]].pb(pii(u,v));
    }
    reset(lab,-1);

    scanf("%d",&q);
    for(int i=1; i<=q; ++i){
        scanf("%d%d",&query[i].first,&query[i].second);
        if(query[i].first>query[i].second)
            swap(query[i].first,query[i].second);
        if(fcnt.count(query[i])==0) fcnt[query[i]]=0;
    }

    for(int i=1; i<=cnt; ++i){
        for(int j=0; j<sz(clist[i]); ++j){
            int u=clist[i][j].first, v=clist[i][j].second;
            int r1=get(u), r2=get(v);
            if(r1!=r2) dsu(r1,r2);
        }

        if(sz(clist[i])>200){
            for(int x=1; x<=q; ++x){
                int u=query[x].first, v=query[x].second;
                if(get(u)==get(v)) ++res[x];
            }
            reset(lab,-1);
        }else{

            ulist.clear();
            for(int j=0; j<sz(clist[i]); ++j){
                ulist.pb(clist[i][j].first);
                ulist.pb(clist[i][j].second);
            }
            sort(ulist.begin(),ulist.end());
            ulist.resize(unique(ulist.begin(),ulist.end())-ulist.begin());

            for(int j=0; j<sz(ulist); ++j){//<=400
                int u=ulist[j];
                for(int j2=j+1; j2<sz(ulist); ++j2){
                    int v=ulist[j2];
                    if(get(u)==get(v) && fcnt.count(pii(u,v))) ++fcnt[pii(u,v)];
                }
            }

            for(int j=0; j<sz(clist[i]); ++j){
                int u=clist[i][j].first, v=clist[i][j].second;
                lab[u]=-1;
                lab[v]=-1;
            }
        }


    }

    for(int i=1; i<=q; ++i){
        printf("%d\n",res[i] + fcnt[query[i]]);
    }
}

