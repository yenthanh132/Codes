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

int n,v[maxn],cnt;
char s[maxn];

bool vowel(char s){
    return s=='A' || s=='E' || s=='O' || s=='U' || s=='I' || s=='Y';
}

int main(){
//    freopen("input.txt","r",stdin);
    cnt=0;
    scanf("%s",s+1); n=strlen(s+1);
    for(int i=1; i<=n; ++i)
        if(vowel(s[i])) v[++cnt]=min(i,n-i+1);
    sort(v+1,v+cnt+1);
    double res=0;
    int i=1;
    ll sum=0;
    for(int len=1; len<=n; ++len){
        if(len*2<=n){
            int val=len;
            while(i<=cnt && v[i]<=val) sum+=v[i++];
            ll x = sum + 1ll*(cnt-i+1)*val;
            res += 1.0*x/len;
        }else{
            int val=n-len+1;
            while(i>1 && v[i-1]>=val) sum-=v[--i];
            ll x = sum + 1ll*(cnt-i+1)*val;
            res += 1.0*x/len;
        }
    }
    printf("%0.6f\n",res);
}

