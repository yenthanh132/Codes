#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;
int n,T;
char s[maxn];

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int mm[1<<26];
vector<int> lst;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1); n=strlen(s+1);
        mm[0]=1;
        lst.clear(); lst.pb(0);
        int state=0;
        ll cnt=0;
        for(int i=1; i<=n; ++i){
            int v=s[i]-'a';
            state^=(1<<v);
            cnt += mm[state];
            for(int x=0; x<26; ++x)
                cnt += mm[state^(1<<x)];
            ++mm[state];
            lst.pb(state);
        }
        for(int i=0; i<sz(lst); ++i) mm[lst[i]]=0;

        ll den=1ll*n*(n+1)/2;
        ll g=gcd(cnt,den);
        cnt/=g; den/=g;
        printf("%lld/%lld\n",cnt,den);
    }
}

