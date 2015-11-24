#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

pii a[111111];
int n,d;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);

    int l=1, r=1;
    ll total=a[1].second;
    ll res=total;
    while(r<=n){
        if(a[r].first - a[l].first < d){
            res=max(res,total);
            total += a[++r].second;
        }else{
            total -= a[l++].second;
        }
    }
    cout<<res<<endl;
}

