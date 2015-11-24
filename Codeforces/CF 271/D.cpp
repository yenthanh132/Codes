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

int n,k;
ll s[maxn],f[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    f[0]=1;
    s[0]=1;
    for(int i=1; i<=100000; ++i){
        f[i]=f[i-1];
        if(i>=k) f[i]=(f[i]+f[i-k])%oo;
        s[i]=s[i-1]+f[i]; s[i]%=oo;
    }
    int a,b;
    for(int i=1; i<=n; ++i){
        scanf("%d%d",&a,&b);
        printf("%I64d\n",(s[b]-s[a-1]+oo)%oo);
    }
}

