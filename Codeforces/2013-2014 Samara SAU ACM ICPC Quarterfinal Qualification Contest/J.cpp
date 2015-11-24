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
int a[maxn],b[maxn],n;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
    int res=0;
    int last=0;
    for(int i=1; i<=n; ++i) if(a[i]>last){
        last=a[i];
        res=max(res,b[i]);
    }
    cout<<res<<endl;
}
