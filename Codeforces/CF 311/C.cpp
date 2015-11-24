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

int total,n;
pii a[maxn];
multiset<int> mys;
vector<int> tmp;

int getmax(){
    multiset<int>::iterator it=mys.end();
    int res=*(--it);
    mys.erase(it);
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i].first);
    total=0;
    for(int i=1; i<=n; ++i) scanf("%d",&a[i].second), total+=a[i].second;

    sort(a+1,a+n+1);
    int res=oo;

    int i=1;
    while(i<=n){
        int j=i;
        while(j+1<=n && a[j+1].first==a[i].first) ++j;
        int val=0;
        for(int x=i; x<=j; ++x) val+=a[x].second;
        int len=j-i+1;
        tmp.clear();
        for(int x=1; x<=len-1 && !mys.empty(); ++x){
            int y = getmax();
            tmp.pb(y);
            val+=y;
        }
        res=min(res,total-val);
        for(int x=0; x<sz(tmp); ++x) mys.insert(tmp[x]);

        for(int x=i; x<=j; ++x) mys.insert(a[x].second);

        i=j+1;
    }
    cout<<res<<endl;

    return 0;
}

