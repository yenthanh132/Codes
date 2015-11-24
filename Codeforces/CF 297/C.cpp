#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int a[maxn],n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
    }
    ll res = 0;
    ll prev = 0;
    sort(a+1,a+n+1);
    for(int i=n; i>=1;){
        if(i>1 && a[i]-a[i-1]<=1){
            int len = a[i];
            if(a[i-1]<len) len=a[i-1];
            if(prev){
                res+=prev*len;
                prev=0;
            }else
                prev=len;
            i-=2;
        }else
            --i;
    }
    cout<<res<<endl;
}

