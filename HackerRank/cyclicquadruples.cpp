#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll l[4],r[4];
int T;

ll calc(int mask){
    ll minv=-oo, maxv=oo;
    ll res = 1;
    for(int i=0; i<4; ++i)
        if(mask>>i&1){
            minv = max(minv, l[i]);
            maxv = min(maxv, r[i]);
        }else{
            res = res * (r[i]-l[i]+1)%oo;
        }
    if(minv>maxv) return 0;
    if(mask) res = res * (maxv-minv+1)%oo;
    return res;

}

int cntbit(int v){
    int r = 0;
    while(v){
        r+=v&1;
        v/=2;
    }
    return r;
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--){
        for(int i=0; i<4; ++i) cin>>l[i]>>r[i];
        ll res = calc(0);
        for(int i=0; i<16; ++i)
            if(cntbit(i)==2) res -= calc(i);
            else if(cntbit(i)==3) res += 2*calc(i);
            else if(cntbit(i)==4) res -= 4*calc(i);
        cout<<res<<endl;
    }
}

