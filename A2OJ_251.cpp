#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;
const int dmod=123456789;
int a[maxn],n;

int C[maxn*2][maxn];

int main(){
    C[0][0]=1;
    for(int i=1; i<=20000; ++i){
        C[i][0]=1;
        for(int j=1; j<=i && j<=10000; ++j){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=dmod) C[i][j]-=dmod;
        }
    }
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        int l=0, r=a[1];
        for(int i=2; i<=n; ++i){
            if(a[i]>a[i-1]) l+=a[i]-a[i-1], r+=a[i]-a[i-1];
            else{
                r-=a[i-1]-a[i];
                if(l>r) break;
            }
        }
        int len=r-l;
        int res=0;
        for(int t=0; t<=len; ++t){
            res += C[n-1+t][t];
            if(res >= dmod) res-=dmod;
        }
        cout<<res<<endl;
    }
}

