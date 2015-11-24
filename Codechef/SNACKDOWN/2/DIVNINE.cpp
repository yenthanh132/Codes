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

int n,sum;
char s[maxn];
int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1); n=strlen(s+1);
        sum=0;
        int devS=0;
        int incS=0;
        for(int i=1; i<=n; ++i){
            int v=s[i]-'0';
            sum+=v;
            if(i==1) devS+=v-1; else devS+=v;
            incS+=9-v;
        }
        int res = oo;
        if(devS >= sum%9 || n==1) res=min(res,sum%9);
        if(incS >= 9-sum%9) res=min(res,9-sum%9);
        printf("%d\n",res);
    }
}

