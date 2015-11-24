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

int m[maxn],w[maxn],s[maxn],n;

bool check(int c){
    int v=0,v2=0;
    for(int i=1; i<=n; ++i) v+=min(m[i],s[i]);
    if(v<c) return 0;
    for(int i=1; i<=n; ++i){
        int woman = s[i]-m[i];
        if(woman<0) woman = 0;
        if(woman>w[i]) woman = w[i];
        v2+=woman;
        int man = min(s[i],m[i]);
        if(man > v-c) man = v-c;
        if(man > w[i]-woman) man=w[i]-woman;
        v2 += man;
        v -= man;
    }
    return v2>=c && v>=c;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>m[i]>>w[i]>>s[i];
    int l=1, r=oo, mid, res=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<res<<endl;
}

