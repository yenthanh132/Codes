#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,k,res,d;

int main(){
//    freopen("input.txt","r",stdin);
    res=0;
    scanf("%d%d",&n,&k);
    int m,v;
    d=0;
    for(int i=1; i<=k; ++i){
        scanf("%d",&m);
        bool found1=0;
        for(int j=1; j<=m; ++j){
            scanf("%d",&v);
            if(j==1 && v==1) found1=1;
            if(!found1 || v!=j){
                if(j>1) ++res;
            }
            else d++;
        }
    }
    res += n-d;
    printf("%d\n",res);

}

