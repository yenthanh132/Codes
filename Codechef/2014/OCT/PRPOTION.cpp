#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int cal(int v, int x){
    int c=0;
    while(v>x){
        v/=2;
        ++c;
    }
    return c;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t,rc,gc,bc,m,R,G,B,v;
    cin>>t;
    while(t--){
        cin>>rc>>gc>>bc>>m;
        R=G=B=0;
        for(int i=0; i<rc; ++i){ cin>>v; R=max(R,v); }
        for(int i=0; i<gc; ++i){ cin>>v; G=max(G,v); }
        for(int i=0; i<bc; ++i){ cin>>v; B=max(B,v); }
        int l=0, r=oo, mid, res;
        while(l<=r){
            mid=(l+r)/2;
            if(cal(R,mid) + cal(G,mid) + cal(B,mid) <= m){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        cout<<res<<endl;
    }
}

