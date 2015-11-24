#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

int a[maxn],n,b[maxn];
int m,p[maxn*2];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    m=0;
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=1, j; i<=n; ){
        j=i;
        while(j+1<=n && a[j+1]==a[i]) ++j;
        if(j-i+1>1 || i==1 || j==n){
            if(i!=1) p[m++]=i;
            if(j!=n) p[m++]=j;
        }
        i=j+1;
    }
    int res=0;
    for(int i=0; i<m; i+=2){
        int x=p[i], y=p[i+1];
        if(a[x] == a[y]){
            res = max(res, (y-x)/2);
            for(int j=x+1; j<y; ++j) a[j]=a[x];
        }else{
            res = max(res, (y-x+1)/2-1);
            int c=(y-x+1)/2-1;
            for(int i=x+1; i<y; ++i){
                if(i-x<=c) a[i]=a[x];
                else a[i]=a[y];
            }
        }
    }
    printf("%d\n",res);
    for(int i=1; i<=n; ++i) printf("%d ",a[i]);
}

