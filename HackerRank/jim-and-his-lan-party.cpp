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

int x[maxn],y[maxn],q,sq,res[maxn];
int n,m,c[maxn];
vector<int> pos[maxn],query[maxn];
int lab[350][maxn],vt[maxn],cnt,f[maxn];
vector<int> ds;

int getroot(int *lab, int u){
    if(lab[u]<0) return u;
    return (lab[u]=getroot(lab,lab[u]));
}

void dsu(int *lab, int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

void save(int i){
    ++cnt;
    for(int u=1; u<=n; ++u) lab[cnt][u]=f[u];
    vt[cnt]=i;
}

bool check(int *lab, int c){
    int r=getroot(lab,pos[c][0]);
    for(int i=1; i<sz(pos[c]); ++i)
        if(r!=getroot(lab,pos[c][i])) return 0;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1; i<=n; ++i){
        scanf("%d",&c[i]);
        pos[c[i]].pb(i);
    }

    cnt=0;
    for(int i=1; i<=n; ++i) f[i]=-1;
    sq=int(sqrt(q));
    save(0);
    for(int i=1; i<=q; ++i){
        scanf("%d%d",&x[i],&y[i]);
        int r1=getroot(f,x[i]), r2=getroot(f,y[i]);
        if(r1!=r2) dsu(f,r1,r2);
        if(sq > 0 && i%sq==0) save(i);
    }

    if(sq>0 && q%sq>0) save(q);
    for(int c=1; c<=m; ++c){
        int i;
        for(i=1; i<=cnt; ++i) if(check(lab[i],c)) break;
        if(i==1) res[c]=0;
        else if(i>cnt) res[c]=-1;
        else query[i-1].pb(c);
    }

    for(int i=1; i<=cnt; ++i){
        ds.clear();
        for(int j=0; j<sz(query[i]); ++j) ds.pb(query[i][j]);
        bool found=0;
        for(int j=0; j<sz(ds); ++j) if(ds[j]!=-1){ found=1; break; }
        for(int z=vt[i]+1; found; ++z){
            int r1=getroot(lab[i],x[z]), r2=getroot(lab[i],y[z]);
            if(r1!=r2) dsu(lab[i],r1,r2);
            for(int j=0; j<sz(ds); ++j) if(ds[j]!=-1)
                if(check(lab[i],ds[j])){
                    res[ds[j]]=z;
                    ds[j]=-1;
                }

            found = 0;
            for(int j=0; j<sz(ds); ++j) if(ds[j]!=-1){ found=1; break; }
        }
    }

    for(int i=1; i<=m; ++i) printf("%d\n",res[i]);
    return 0;
}

