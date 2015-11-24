#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int T,n;
    char t[1005];
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%s",&n,t);
        int res = 0;
        int v=0;
        for(int i=0; i<=n; ++i){
            if(i > v){
                res += i-v;
                v=i;
            }
            v+=t[i]-'0';
        }
        printf("Case #%d: %d\n",tt,res);
    }
}

