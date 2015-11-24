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

int n,w,a[maxn],b[maxn],pre[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&w);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=1; i<=w; ++i) scanf("%d",&b[i]);
    if(w==1) printf("%d\n",n);
    else{
        for(int i=1; i<n; ++i) a[i]-=a[i+1];
        for(int i=1; i<w; ++i) b[i]-=b[i+1];
        pre[1]=0;
        --w; --n;
        int res=0;
        for(int i=1,j=0; i<=w; ){
            while(j>0 && b[j]!=b[i]) j=pre[j];
            ++i; ++j;
            if(b[j]==b[i]) pre[i]=pre[j]; else pre[i]=j;
        }
        for(int i=1,j=1; i<=n; ){
            while(j>0 && b[j]!=a[i]) j=pre[j];
            ++i; ++j;
            if(j>w){
                j=pre[j];
                ++res;
            }
        }
        printf("%d\n",res);
    }
}

