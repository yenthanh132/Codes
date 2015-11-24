#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;


const int maxn=100007;

int n,a[maxn],k;

ll dp[2][maxn];
struct line{
    ll a, b;
}lst[maxn];
int cnt,caret;

bool cover(line &l1, line &l2, line &l3){
    return (l2.b-l1.b)*(l3.a-l2.a) <= (l2.b-l3.b)*(l1.a-l2.a);
}

void pushEdge(ll a, ll b){
    line newL;
    newL.a = a;
    newL.b = b;
    while(cnt>1 && cover(newL, lst[cnt-1], lst[cnt])) --cnt;

    lst[++cnt]=newL;
    caret = min(caret, cnt);
}

ll getCost(int i){
    while(caret < cnt && lst[caret].a*i + lst[caret].b >= lst[caret+1].a*i + lst[caret+1].b) ++caret;
    return lst[caret].a*i + lst[caret].b;
}

int main(){

//    freopen("input.txt","r",stdin);

    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    dp[0][1] = 1ll*a[1]*k*k;
    for(int i=2; i<=n; ++i) dp[0][i]=-1;
    int flag=0;
    ll res = oo;
    for(int i=2; i<=min(k,220); ++i){
        flag^=1;
        cnt=0; caret=1;
        for(int j=1; j<=n; ++j){
            if(cnt>0)
                dp[flag][j] = 1ll*a[j]*k*k + 1ll*j*j + getCost(j);
            else
                dp[flag][j] = -1;
            if(dp[flag^1][j]!=-1) pushEdge(-2*j,dp[flag^1][j]+1ll*j*j);
        }
        res = min(res, dp[flag][n]);
    }
    cout<<res<<endl;
}

