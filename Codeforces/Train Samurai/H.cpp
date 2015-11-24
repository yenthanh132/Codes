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

int n,m,a[maxn],b[maxn];
vector<int> num;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
    int l=1, r=oo, mid, minv=oo;
    while(l<=r){
        mid=(l+r)/2;
        ll val=0;
        for(int i=1; i<=n; ++i) if(a[i]>=mid) val += (a[i]-mid)/b[i] + 1;
        if(val < m){
            minv=mid;
            r=mid-1;
        }else l = mid+1;
    }

    ll res = 0;
    for(int i=1; i<=n; ++i) if(a[i]>=minv){
        ll cnt=(a[i]-minv)/b[i]+1;
        res += a[i] * cnt - cnt*(cnt-1)*b[i]/2;
        m-=cnt;
        if(minv > 1){
            int val = a[i] - cnt * b[i];
            val=max(val,1);
            num.pb(val);
        }
    }else if(a[i]>=minv-1) num.pb(a[i]);

    sort(num.begin(), num.end(), greater<int>());
    for(int i=0; i<sz(num); ++i){
        if(m==0) break;
        if(num[i]==1){
            res+=m;
            m=0;
            break;
        }
        res+=num[i];
        --m;
    }
    res+=m;

    cout<<res<<endl;
}

