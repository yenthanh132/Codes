#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxlen = 2000007;
ll n,len,x;
char s[maxlen],ch[10];
int k,sum[26];
vector<int> pos[26];

int dem(int v, int l, int r){
    if(l>r) return 0;
    return upper_bound(pos[v].begin(), pos[v].end(),r) - lower_bound(pos[v].begin(),pos[v].end(),l);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld",&n);
    scanf("%s",s+1); len=strlen(s+1);
    reset(sum,0);
    for(int i=1; i<=len; ++i) sum[s[i]-'A']++;
    for(int i=1; i<=len*2; ++i){
        int j=i;
        if(j>len) j-=len;
        pos[s[j]-'A'].pb(i);
    }
    scanf("%d",&k);
    for(int i=0; i<k; ++i){
        scanf("%lld%s",&x,ch);
        int v=ch[0]-'A';

        ll res = sum[v] * (x/len);

        ll A=x, B=x-1;
        if(A%2==0) A/=2; else B/=2;
        A%=len; B%=len;
        ll pos = (A*B%len) + 1;
        x%=len;
        res += dem(v, pos, pos+x-1);

        printf("%lld\n",res);
    }
}

