#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n;
pii a[100007];

bool cmp(const pii &a, const pii &b){
    return a.second - a.first < b.second - b.first;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i].second);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i].first);
    sort(a+1,a+n+1,cmp);
    ll sum=0;
    bool found=0;
    for(int i=1; i<=n; ++i){
        sum+=a[i].first;
        if(a[i].second<=sum){
            found=1;
            break;
        }
    }
    if(found) cout<<"Redemption"<<endl;
    else cout<<"Dire victory"<<endl;
}

