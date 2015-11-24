#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=30007;
const int maxk=666;
int f[maxn][maxk];
int c[maxn],pos[maxn],cnt,lst[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=0,v; i<n; ++i){
        scanf("%d",&v);
        ++c[v];
    }
    cnt=0;
    for(int v=max(1,d-300); v<=min(30000,d+300); ++v){
        ++cnt;
        pos[v]=cnt;
        lst[cnt]=v;
    }
    reset(f,-1);

    int res=0;
    f[d][pos[d]]=c[d];
    for(int i=d; i<=30000; ++i)
        for(int j=1; j<=cnt; ++j) if(f[i][j]!=-1){
            int v=lst[j];
            res=max(res,f[i][j]);
            for(int x=v-1; x<=v+1; ++x) if(x>0 && i+x<=30000){
                f[i+x][pos[x]] = max(f[i+x][pos[x]], f[i][j] + c[i+x]);
            }
        }

    cout<<res<<endl;
}

