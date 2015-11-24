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

ll gt[maxn];
int n,cnt[26];
char s[maxn];

ll mypow(ll base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",&s);
    n=strlen(s);
    for(int i=0; i<n; ++i) cnt[s[i]-'a']++;
    for(int i=0; i<26; ++i) if(cnt[i]&1){
        --cnt[i];
        break;
    }
    int total=0;
    for(int i=0; i<26; ++i) if(cnt[i]&1){
        puts("0");
        return 0;
    }else total+=cnt[i];

    total/=2;
    gt[0]=1;
    for(int i=1; i<=total; ++i) gt[i]=gt[i-1]*i%oo;
    ll res=gt[total];
    for(int i=0; i<26; ++i) if(cnt[i]) res=res*mypow(gt[cnt[i]/2],oo-2)%oo;
    cout<<res<<endl;
}

