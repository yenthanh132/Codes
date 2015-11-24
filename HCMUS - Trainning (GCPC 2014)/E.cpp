#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2000007;

int a[maxn],n,T,s[maxn],myq[maxn],first,last;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&n); for(int i=1; i<=n; ++i) scanf("%d",&a[i]),a[i+n]=a[i];
        s[0]=0;

        int res=0;
        myq[first=last=1]=0;
        for(int i=1; i<n*2; ++i){
            s[i]=s[i-1]+a[i];
            while(first<=last && myq[first]<i-n) ++first;
            res=max(res,s[i]-s[myq[first]]);
            while(first<=last && s[myq[last]]>=s[i]) --last;
            myq[++last]=i;
        }
        cout<<res<<endl;
    }
}

