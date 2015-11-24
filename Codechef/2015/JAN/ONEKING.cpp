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

pii a[maxn*2];
int n,T,m,lst[maxn],c;
bool live[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) live[i]=1;
        int l,r;
        m=0;
        for(int i=1; i<=n; ++i){
            scanf("%d%d",&l,&r);
            a[++m]=pii(l,-i);
            a[++m]=pii(r,i);
        }
        sort(a+1,a+m+1);
        int res = 0; c=0;
        for(int i=1; i<=m; ++i)
            if(a[i].second < 0)
                lst[++c]=-a[i].second;
            else if(live[a[i].second]){
                while(c) live[lst[c--]]=0;
                ++res;
            }
        printf("%d\n",res);
    }
}

