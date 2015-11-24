#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


const int base = 73471;
int n;
deque<int> a,b;
set<pll> mys;
vector<int> lst;

ll myhash(deque<int> &a){
    ll res = 0;
    for(int i=0; i<sz(a); ++i) res=res*base+a[i];
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;

    int k,v;
    cin>>k;
    for(int i=0; i<k; ++i){
        cin>>v;
        a.pb(v);
        lst.pb(v);
    }
    cin>>k;
    for(int i=0; i<k; ++i){
        cin>>v;
        b.pb(v);
        lst.pb(v);
    }
    sort(lst.begin(),lst.end());

    mys.insert(pll(myhash(a),myhash(b)));
    for(int i=1; ; ++i){
        int va = a.front(); a.pop_front();
        int vb = b.front(); b.pop_front();
        if(va>vb){
            a.pb(vb);
            a.pb(va);
        }else{
            b.pb(va);
            b.pb(vb);
        }
        if(sz(a)==0){
            cout<<i<<' '<<2<<endl;
            return 0;
        }else if(sz(b)==0){
            cout<<i<<' '<<1<<endl;
            return 0;
        }
//        for(int i=0; i<sz(a); ++i) cout<<a[i]<<' '; cout<<" | "; for(int i=0; i<sz(b); ++i) cout<<b[i]<<' '; cout<<endl;

        ll vhash = myhash(a);
        ll vhash2 = myhash(b);

        if(mys.count(pll(vhash,vhash2))){

            cout<<-1<<endl;
            return 0;
        }


        mys.insert(pll(vhash,vhash2));
    }
}

