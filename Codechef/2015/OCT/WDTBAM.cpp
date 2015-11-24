#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;

char s1[maxn],s2[maxn];
int n,T,w[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s%s",s1+1,s2+1);
        int c=0;
        for(int i=1; i<=n; ++i) c+=(s1[i]==s2[i]);
        for(int i=0; i<=n; ++i) scanf("%d",&w[i]);
        int res=0;
        if(c==0) res=w[0];
        else if(c==n) res=w[n];
        else{
            for(int v=0; v<=c; ++v) res=max(res,w[v]);
        }
        printf("%d\n",res);
    }
}

