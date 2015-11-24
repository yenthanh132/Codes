#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

int n,x[maxn],y[maxn],T;
set<pii> mys;

void rotate(int x1, int y1, int x2, int y2, int sign, int &X, int &Y){
    x2-=x1; y2-=y1;
    X=x1-sign*y2;
    Y=y1+sign*x2;
}

bool found(int x, int y){
    return mys.find(pii(x,y))!=mys.end();
}

int main(){
//    freopen("input.txt","r",stdin);
//    scanf("%d",&T);
//    while(T--){
        scanf("%d",&n);
        mys.clear();
        for(int i=1; i<=n; ++i){
            scanf("%d%d",&x[i],&y[i]);
            mys.insert(pii(x[i],y[i]));
        }
        if(n<=1) printf("%d\n",4-n);
        else{
            int res = 2;
            for(int i=1; i<n; ++i) for(int j=i+1; j<=n; ++j){
                for(int v=-1; v<=1; v+=2){
                    int x2,y2,x3,y3;
                    rotate(x[i],y[i],x[j],y[j],v,x2,y2);
                    rotate(x[j],y[j],x[i],y[i],-v,x3,y3);
                    bool f1=found(x2,y2), f2=found(x3,y3);
                    if(f1 && f2) res=min(res,0);
                    else if(f1 || f2) res=min(res,1);
                }
            }
            printf("%d\n",res);
        }
//    }
}

