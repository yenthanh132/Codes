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


int a[maxn],n,m,cost[maxn],id[maxn],k[maxn];
vector<int> ds[maxn];

bool cmp(const int &a, const int &b){
    return cost[a]<cost[b];
}

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&m);
    int v;
    for(int i=0; i<n; ++i){
        scanf("%d%d",&k[i],&cost[i]);
        for(int j=0; j<k[i]; ++j){
            scanf("%d",&v);
            ds[i].pb(v);
        }
    }

    bool ok=1;
    for(int i=0; i<n; ++i) id[i]=i;
    sort(id,id+n,cmp);

    reset(a,-1);
    for(int it=0; it<n; ++it){
        int i=id[it];
        bool found=0;
        for(int j=0; j<k[i]; ++j){
            v=ds[i][j];
            if(a[v]==-1 || a[v]==cost[i]){
                a[v]=cost[i];
                found=1;
            }
        }
        if(!found){
            ok=0;
            break;
        }
    }

    if(!ok) puts("Poor memory");
    else{
        puts("Good memory");
        for(int i=1; i<=m; ++i) if(a[i]==-1) a[i]=1;
        for(int i=1; i<=m; ++i) printf("%d ",a[i]);
    }
}

