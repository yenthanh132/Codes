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
const double eps=1e-6;

int x[maxn],y[maxn];
int n;
bool mark[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    int x0,y0;
    scanf("%d",&n);
    scanf("%d%d",&x0,&y0);
    reset(mark,1);
    for(int i=1; i<=n; ++i) scanf("%d%d",&x[i],&y[i]);
    int res=0;
    for(int i=1; i<=n; ++i) if(mark[i]){
        ++res;
        mark[i]=0;
        int vx1=x[i]-x0, vy1=y[i]-y0;
        for(int j=1; j<=n; ++j) if(mark[j]){
            int vx2=x[j]-x0, vy2=y[j]-y0;
            if(vx1*vy2==vx2*vy1){
                mark[j]=0;
            }
        }
    }
    cout<<res<<endl;
}

