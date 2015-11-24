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

int a[maxn];
int n,q;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&q);
    a[0]=0;
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        a[i] = a[i-1] + (a[i]&1);
    }

    int l,r;
    for(int i=0; i<q; ++i){
        scanf("%d%d",&l,&r);
        if((a[r]-a[l-1])&1) puts("Odd");
        else puts("Even");
    }

}

