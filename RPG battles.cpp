#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxp=107;
const int maxn=1007;

double f[maxn][maxp][8];
int n,p,p1[maxn],p2[maxn],t1[maxn],t2[maxn],w1[maxn],w2[maxn];
int pow2[8];
double val(int p1, int p2, int t1, int t2, int p){
    if(p>p2) return t2;
    return t1 + (1.0*(p-p1)/(p2-p1))*(t2-t1);
}

int main(){
    //freopen("input.txt","r",stdin);
    pow2[0]=1;
    for(int i=1; i<=7; ++i) pow2[i]=pow2[i-1]*2;

    while(scanf("%d%d",&n,&p),n>0){
        for(int i=1; i<=n; ++i) scanf("%d%d%d%d%d%d",&p1[i],&p2[i],&t1[i],&t2[i],&w1[i],&w2[i]);
        for(int i=0; i<=n; ++i) for(int j=0; j<=100; ++j) for(int k=0; k<=7; ++k) f[i][j][k]=oo;
        f[0][p][0]=0;
        double res=oo;
        for(int i=1; i<=n; ++i) for(int j=0; j<=100; ++j) for(int k=0; k<=7; ++k)
            if(f[i-1][j][k]<oo){
                for(int v=0; v<=k; ++v)
                    if(j*pow2[v]>=p1[i]){
                        int newj = min(100,j*pow2[v]+w1[i]);
                        int newk = min(7,k-v + w2[i]);
                        f[i][newj][newk]=min(f[i][newj][newk], f[i-1][j][k] + val(p1[i],p2[i],t1[i],t2[i],j*pow2[v]));
                        if(i==n) res=min(res,f[i][newj][newk]);
                    }
            }
        if(res<oo) printf("%.2lf\n",res);
        else puts("Impossible");
    }
}

