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

int a[maxn],n,k,cnt;
ll l,bit[2][maxn];
vector<int> lst;
map<int,int> mm;

void update(ll *bit, int i, ll v){
    for( ; i<=cnt; i+=i&(-i)) bit[i] = (bit[i] + v)%oo;
}

ll get(ll *bit, int i){
    ll res=0;
    for( ; i; i-=i&(-i)) res = (res + bit[i])%oo;
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%I64d%d",&n,&l,&k);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        mm[a[i]]=0;
    }
    cnt=0;
    for(map<int,int>::iterator it=mm.begin(); it!=mm.end(); ++it) it->second = ++cnt;
    for(int i=1; i<=n; ++i) a[i] = mm[a[i]];
    update(bit[0],1,1);
    int flag=0;
    ll res=0;
    for(int len=1; len<=k; ++len){
        flag ^=1;
        for(int v=1; v<=cnt; ++v) bit[flag][v] = 0;
        for(int i=1; i<=n; ++i){
            ll val = get(bit[flag^1],a[i]);
            update(bit[flag], a[i], val);
            ll mul = (l-1)/n+1;
            if(i > (l-1)%n+1) --mul;
            mul = mul - len + 1;
            if(mul < 0) mul = 0;
            mul %= oo;
            res = (res + val * mul)%oo;
        }
    }

    cout<<res<<endl;
}

