#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5000000;

int cnt[maxn+7],isprime[maxn+7];
int plist[maxn+7],n;
ll sum[maxn+7];

int main(){
//    freopen("input.txt","r",stdin);
    isprime[2]=1;
    for(int i=3; i<=maxn; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxn; i+=2) if(isprime[i])
        for(int j=1ll*i*i; j<=maxn; j+=2*i) isprime[j]=0;
    plist[n=1]=2;
    for(int i=3; i<=maxn; i+=2) if(isprime[i]) plist[++n]=i;

    cnt[0]=0;
    for(int i=1; i<=maxn; ++i){
        int v=i;
        cnt[i] = 0;
        for(int j=1; plist[j]*plist[j]<=v && v>1; ++j)
            while(v%plist[j]==0){
                v/=plist[j];
                ++cnt[i];
            }
        if(v>1) ++cnt[i];
        sum[i]=sum[i-1]+cnt[i];
    }

    int t,a,b;
    scanf("%d",&t);
    for(int i=0; i<t; ++i){
        scanf("%d%d",&a,&b);
        printf("%I64d\n",sum[a]-sum[b]);
    }
}

