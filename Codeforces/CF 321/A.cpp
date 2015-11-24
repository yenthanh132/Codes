#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,a[111111];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
    }
    int v=1,res=1;
    for(int i=2; i<=n; ++i){
        if(a[i]>=a[i-1]) ++v;
        else v=1;
        res=max(res,v);
    }
    printf("%d\n",res);
}

