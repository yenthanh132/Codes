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
//    freopen("input.txt","r",stdin);
    int T,n,s1,s2;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        s1=s2=0;
        for(int i=0; i<n; ++i){
            int v;
            scanf("%d",&v);
            if(v>0) s1+=v-1;
            s2+=v;
        }
        if(s1<100 && s2>=100) puts("YES");
        else puts("NO");
    }
}

