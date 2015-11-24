#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

multiset<pii> px,py;
int n,k;

pii inv(pii p){
    swap(p.first,p.second);
    return p;
}

pii getMin(multiset<pii> &s){
    return *s.begin();
}

pii getMax(multiset<pii> &s){
    multiset<pii>::iterator it=s.end();
    return *(--it);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        px.insert(pii(x1+x2,y1+y2));
        py.insert(pii(y1+y2,x1+x2));
    }
    ll res=-1;
    for(int l=0; l<=k; ++l) for(int r=0; l+r<=k; ++r) for(int t=0; l+r+t<=k; ++t) for(int b=0; l+r+t+b<=k; ++b){
        vector<pii> buf;
        multiset<pii>::iterator it;
        for(int i=0; i<l; ++i){
            pii p = *px.begin(); px.erase(px.begin());
            buf.pb(p);
            py.erase(py.find(inv(p)));
        }
        for(int i=0; i<r; ++i){
            it=px.end();
            pii p = *(--it); px.erase(it);
            buf.pb(p);
            py.erase(py.find(inv(p)));
        }
        for(int i=0; i<t; ++i){
            pii p=*py.begin(); py.erase(py.begin());
            buf.pb(inv(p));
            px.erase(px.find(inv(p)));
        }
        for(int i=0; i<b; ++i){
            it=py.end();
            pii p = *(--it); py.erase(it);
            buf.pb(inv(p));
            px.erase(px.find(inv(p)));
        }

        ll W = getMax(px).first - getMin(px).first;
        ll H = getMax(py).first - getMin(py).first;
        W/=2; H/=2;
        W = max(W,1ll); H = max(H,1ll);
        if(res==-1 || res > W*H) res=W*H;
        for(int i=0; i<sz(buf); ++i){
            px.insert(buf[i]);
            py.insert(inv(buf[i]));
        }
    }

    cout<<res<<endl;

}

