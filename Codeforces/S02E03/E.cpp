#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1006;
int N,B,W,H;
int p[maxn],a[maxn][maxn];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>N>>B>>H>>W;
    for(int i=1; i<=H; ++i){
        cin>>p[i];
        for(int j=1; j<=W; ++j) cin>>a[i][j];
    }
    int res = oo;
    for(int j=1; j<=W; ++j) for(int i=1; i<=H; ++i)
        if(a[i][j]>=N)
            res=min(res,N*p[i]);
    if(res>B) cout<<"stay home";
    else cout<<res;

    return 0;
}

