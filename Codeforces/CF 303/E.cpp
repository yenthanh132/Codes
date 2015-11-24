#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=207;

int n,m,start,finish,N,c[maxn][maxn],f[maxn][maxn];
int a[maxn],b[maxn],trace[maxn];
queue<int> myq;
int ans[maxn][maxn];

bool findpath(){
    reset(trace,0);
    myq = queue<int>();
    myq.push(start); trace[start]=-1;
    while(!myq.empty()){
        int u=myq.front(); myq.pop();
        for(int v=1; v<=N; ++v)
            if(c[u][v] > f[u][v] && trace[v]==0){
                trace[v] = u;
                myq.push(v);
                if(v==finish) return 1;
            }
    }
    return 0;
}

void incflow(){
    int delta = oo;
    int u,v;
    v=finish;
    do{
        u=trace[v];
        delta=min(delta,c[u][v]-f[u][v]);
        v=u;
    }while(v!=start);

    v=finish;
    do{
        u=trace[v];
        f[u][v]+=delta;
        f[v][u]-=delta;
        v=u;
    }while(v!=start);
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>m;
    int suma = 0, sumb = 0;
    for(int i=1; i<=n; ++i) cin>>a[i], suma+=a[i];
    for(int i=1; i<=n; ++i) cin>>b[i], sumb+=b[i];
    if(suma!=sumb){
        cout<<"NO"<<endl;
        return 0;
    }

    start = n*2+1;
    finish = n*2+2;
    N = n*2+2;
    int sum = 0;
    for(int i=1; i<=n; ++i){
        c[i][i+n] = a[i];

        if(b[i]<=a[i]){
            c[start][i]=a[i]-b[i];
            sum += c[start][i];
        }else
            c[i][finish]=b[i]-a[i];
    }
    for(int i=1; i<=m; ++i){
        int u,v;
        cin>>u>>v;
        c[u+n][v]=c[v+n][u]=oo;
    }

    while(findpath()) incflow();

    int res = 0;
    for(int i=1; i<=n; ++i) res+=f[start][i];
    if(res<sum){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i=1; i<=n; ++i){
            int left = a[i];
            for(int j=1; j<=n; ++j) if(i!=j){
                ans[i][j] = f[i+n][j];
                left -= ans[i][j];
            }
            ans[i][i] = left;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<n; ++j) cout<<ans[i][j]<<' ';
            cout<<ans[i][n]<<endl;
        }
    }
}

