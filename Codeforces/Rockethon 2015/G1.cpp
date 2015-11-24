#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

int n,p[5][maxn],k;
double res;

void calc(){
    double t=0;
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(p[k][i]>p[k][j]) t+=1;
    res+=t;
}

void duyet(int i){
    if(i>k){
        calc();
        return;
    }
    for(int x=1; x<=n; ++x) for(int y=x; y<=n; ++y){
        for(int j=1; j<=n; ++j) p[i][j]=p[i-1][j];
        for(int l=x, r=y; l<=r; ++l, --r) swap(p[i][l],p[i][r]);
        duyet(i+1);
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    res=0;
    cin>>n>>k;
    for(int i=1; i<=n; ++i) cin>>p[0][i];
    duyet(1);
    for(int r=0; r<k; ++r) res/=(n*(n+1)/2);
    printf("%0.12lf\n",res);
}
