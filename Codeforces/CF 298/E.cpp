#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

int a[maxn],n,m;
int c[maxn],d[maxn],ok;
ll res,sum;

void inc(int i){
    ++d[i];
    if(d[i]==c[i]) ++ok;
    if(d[i]==c[i]+1) --ok;
}

void dec(int i){
    --d[i];
    if(d[i]==c[i]) ++ok;
    if(d[i]==c[i]-1) --ok;
}

ll dis(int i, int j){
    return abs(a[i]-a[j]);
}

ll go(int &pos, int &dir){
    int prev = pos;
    pos += dir;
    if(pos > n){
        pos = n-1;
        dir = -1;
    }
    if(pos < 1){
        pos = 2;
        dir = 1;
    }
    return dis(prev,pos);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    scanf("%d",&m);
    reset(c,0);
    for(int i=0,v; i<m; ++i){
        scanf("%d",&v);
        ++c[v];
    }

    ok=0;
    reset(d,0);
    for(int v=1; v<=n; ++v) if(c[v]==0) ++ok;

    res = -1;
    sum = 0;
    int pos = 1, dir = 1;
    for(int i=1; i<=m; ++i){
        inc(pos);
        if(i<m) sum += go(pos,dir);
    }

    dir *= -1;
    int pos2 = 1, dir2 = 1;
    for(int i=1, j=n*2; i<=n*2; ++i, --j){
        if(ok==n){
            if(res!=-1 && res!=sum){
                cout<<-1<<endl;
                return 0;
            }
            res=sum;
        }
        dec(pos);
        sum += go(pos2, dir2) - go(pos, dir);
        inc(pos2);
    }

    cout<<res<<endl;
}

