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

int n,a[maxn],pos[maxn],m;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1,it=0; i<=n; ++i){
        scanf("%d",&a[i]);
        for(int j=0; j<a[i]; ++j) pos[++it]=i;
    }
    scanf("%d",&m);
    for(int i=0; i<m; ++i){
        int x;
        scanf("%d",&x);
        printf("%d\n",pos[x]);
    }
}

