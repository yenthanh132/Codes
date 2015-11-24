
#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

pii p[maxn];
pii v[maxn];
int n,m;

bool cmp(const pii &a, const pii &b){
    return a.first*b.second < b.first*a.second;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].first,&p[i].second);
    sort(p+1,p+n+1);
    ll res=1ll*n*(n-1)*(n-2)/6;
    for(int i=1; i<n; ++i){
        m=0;
        for(int j=i+1; j<=n; ++j)
            v[++m]=pii(p[j].first-p[i].first, p[j].second-p[i].second);
        sort(v+1,v+m+1,cmp);

        for(int j=1; j<=m;){
            int j2=j;
            while(j2+1<=m && v[j2+1].first*v[j2].second==v[j2+1].second*v[j2].first) ++j2;
            int len=j2-j+1;
            res-=len*(len-1)/2;
            j=j2+1;
        }
    }
    cout<<res<<endl;
}

