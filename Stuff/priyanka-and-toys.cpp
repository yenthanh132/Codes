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

int a[maxn],n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int res = 0;
    int i=1;
    while(i<=n){
        ++res;
        int v=a[i];
        while(i<=n && a[i]<=v+4) ++i;
    }
    printf("%d\n",res);
}

