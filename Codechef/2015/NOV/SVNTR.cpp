#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=155;

ll a[maxn][maxn],s[maxn][maxn],arr[maxn];
int m,n,S;
int BIT[maxn];
void update(int i, int v){
    for( ; i; i-=i&(-i)) BIT[i] += v;
}

int get(int i, int n){
    int v=0;
    for( ; i<=n; i+=i&(-i)) v+=BIT[i];
    return v;
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&m,&n,&S);
        for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j){
            scanf("%lld",&a[i][j]);
            s[i][j]=a[i][j]+s[i-1][j];
        }
        ll res=0;
        for(int i=1; i<=m; ++i) for(int j=i; j<=m; ++j){
            vector<ll> lst;
            for(int k=1; k<=n; ++k){
                arr[k] = s[j][k]-s[i-1][k];
                arr[k] += arr[k-1];
                lst.pb(arr[k]);
            }
            lst.pb(0);
            sort(lst.begin(),lst.end());
            lst.resize(unique(lst.begin(),lst.end())-lst.begin());
            int idx=sz(lst);
            for(int i=1; i<=idx; ++i) BIT[i]=0;
            update(lower_bound(lst.begin(),lst.end(),0)-lst.begin()+1,1);
            ll sum=0;
            for(int k=1; k<=n; ++k){
                ll val = arr[k] - S;
                int pos = lower_bound(lst.begin(),lst.end(),val)-lst.begin()+1;
                res += get(pos, idx);
                update(lower_bound(lst.begin(),lst.end(),arr[k])-lst.begin()+1, 1);
            }
        }

        printf("%lld\n",res);
    }
}

