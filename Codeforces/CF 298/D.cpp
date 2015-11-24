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

vector<int> id[maxn];
int arr[maxn];
int n,m;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1,v; i<=n; ++i){
        scanf("%d",&v);
        id[v].pb(i);
    }
    m=0;
    int v = 0;
    while(1){
        while(v > 0 && id[v].empty()) v-=3;
        if(v<0 || (v==0 && id[v].empty())) break;
        arr[++m]=id[v].back();
        id[v].pop_back();
        ++v;
    }
    if(m<n){
        puts("Impossible");
    }else{
        puts("Possible");
        for(int i=1; i<=n; ++i) printf("%d ",arr[i]);
    }
}

