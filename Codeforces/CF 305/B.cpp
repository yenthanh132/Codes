#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;
int a[maxn],n,mys[maxn],last,Left[maxn],Right[maxn],bit[maxn];

void update(int i, int v){
    for(;i; i-=i&(-i)) bit[i]=max(bit[i],v);
}

int get(int i){
    int v=0;
    for(;i<=n; i+=i&(-i)) v=max(v, bit[i]);
    return v;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];

    int last=0;
    for(int i=1; i<=n; ++i){
        while(last>0 && a[mys[last]]>=a[i]) --last;
        if(last==0) Left[i]=0; else Left[i]=mys[last];
        mys[++last]=i;
    }
    last=0;
    for(int i=n; i>=1; --i){
        while(last>0 && a[mys[last]]>=a[i]) --last;
        if(last==0) Right[i]=n+1; else Right[i]=mys[last];
        mys[++last]=i;
    }

    for(int i=1; i<=n; ++i){
        int len=Right[i]-Left[i]-1;
        update(len, a[i]);
    }

    for(int i=1; i<=n; ++i) cout<<get(i)<<' ';
    cout<<endl;

}

