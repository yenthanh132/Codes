#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10000007;
int n,k,q;
int a,b,c,d,e,f,r,s,t,m,A[maxn];
int L1,La,Lc,Lm,D1,Da,Dc,Dm;
int val[maxn],myq[maxn],first,last;

int getmin(int l, int r){
    return min(val[l], val[r-k+1]);
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>k>>q;
    cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>A[1];
    cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
    int t2=t;
    for(int x=2; x<=n; ++x){
        t2=1ll*t2*t%s;
        if(t2<=r){
            A[x]=(1ll*a*A[x-1]%m*A[x-1] + 1ll*b*A[x-1] + c)%m;
        }else{
            A[x]=(1ll*d*A[x-1]%m*A[x-1] + 1ll*e*A[x-1] + f)%m;
        }
    }

    first=1; last=0;
    for(int i=1; i<=n; ++i){
        while(first<=last && i-myq[first]+1 > k) ++first;
        while(first<=last && A[myq[last]]>=A[i]) --last;
        myq[++last]=i;
        if(i>=k) val[i-k+1]=A[myq[first]];
    }

    ll res1=0,res2=1;
    for(int i=1; i<=q; ++i){
        L1 = (1ll*La*L1 + Lc)%Lm;
        D1 = (1ll*Da*D1 + Dc)%Dm;
        int L = L1+1;
        int R = min(L+k-1+D1,n);
        int v=getmin(L,R);
        res1+=v;
        res2=res2*v%oo;
    }
    cout<<res1<<' '<<res2<<endl;

}

