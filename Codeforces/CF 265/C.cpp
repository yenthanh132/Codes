#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

struct Number{
    ll val, len;
    Number(){}
    Number(ll a, ll b):val(a), len(b){}
}val[maxn],res[10];

int n,m;

int num[maxn];
string sub[maxn];

char s[maxn],buf[maxn];
int jump[maxn][10], pos[10];
bool free1[maxn];

ll pow10(ll n){
    if(n==0) return 1;
    ll t=pow10(n/2);
    t=t*t%oo;
    if(n&1) return t*10%oo;
    return t;
}

Number calc(int i, int v){
    if(jump[i][v]==-1) return Number(v,1);

    int idx = jump[i][v];
    if(!free1[idx]) return val[idx];
    free1[idx] = 0;
    Number &ans = val[idx];
    string &s = sub[idx];
    int slen = sz(s);
    ans.val = ans.len = 0;
    for(int j=slen-1; j>=0; --j){
        Number tmp = calc(idx,s[j]-'0');
        ans.val = ( ans.val + tmp.val * pow10(ans.len) ) %oo;
        ans.len = ( ans.len + tmp.len ) % (oo-1);
    }
    return ans;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1); n=strlen(s+1);
    scanf("%d",&m);
    for(int i=1; i<=m; ++i){
        scanf("%s",buf);
        sub[i] = string(buf, buf + strlen(buf));
        num[i] = sub[i][0]-'0';
        sub[i].erase(0,3);
    }
    reset(pos,-1);
    for(int i=m; i>=0; --i){
        for(int v=0; v<10; ++v) jump[i][v]=pos[v];
        if(i>0) pos[num[i]] = i;
    }

    reset(free1,1);
    for(int v = 0; v<10; ++v) res[v] = calc(0,v);
    Number ans;
    ans.len = ans.val = 0;
    for(int j=n; j>=1; --j){
        Number tmp = res[s[j]-'0'];
        ans.val = ( ans.val + tmp.val * pow10(ans.len) ) %oo;
        ans.len = ( ans.len + tmp.len ) % (oo-1);
    }

    cout<<ans.val<<endl;

    return 0;
}
