#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

const int maxn=100007;

int n,s[maxn],q,cnt;
int f[20][maxn],lg2[maxn];
map<int,int> id;
vector<int> pos[maxn];

int get(int l, int r){
    int len=r-l+1;
    int d=lg2[len];
    return gcd(f[d][l],f[d][r-(1<<d)+1]);
}



int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    cnt=0;
    for(int i=1; i<=n; ++i){
        scanf("%d",&s[i]);
        f[0][i]=s[i];
        if(id[s[i]]==0) id[s[i]]=++cnt;
        pos[id[s[i]]].pb(i);
    }
    for(int j=1; j<20; ++j)
        for(int i=1; i<=n-(1<<j)+1; ++i)
            f[j][i]=gcd(f[j-1][i], f[j-1][i+(1<<(j-1))]);
    for(int i=1,j=0; i<=n; ++i){
        while((1<<(j+1))<=i) ++j;
        lg2[i]=j;
    }

    scanf("%d",&q);
    int l,r;
    for(int i=0; i<q; ++i){
        scanf("%d%d",&l,&r);
        int val=get(l,r);
        int xid=id[val];
        int res = r-l+1;
        if(xid!=0){
            int cc = upper_bound(pos[xid].begin(),pos[xid].end(),r) - lower_bound(pos[xid].begin(), pos[xid].end(),l);
            res -= cc;
        }
        printf("%d\n",res);
    }
}

