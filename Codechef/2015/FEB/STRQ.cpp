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

int n,q;
char st[maxn];
ll s[4][maxn],f[4][4][maxn];

int val(char ch){
    if(ch=='c') return 0;
    if(ch=='h') return 1;
    if(ch=='e') return 2;
    return 3;
}

ll get(char a, char b, int l, int r){
    int ia=val(a), ib=val(b);
    ll res = f[ia][ib][r]-f[ia][ib][l-1];
    res -= (s[ib][r]-s[ib][l-1])*s[ia][l-1];
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%s",st+1); n=strlen(st+1);
    for(int i=1; i<=n; ++i){
        for(int j=0; j<4; ++j){
            s[j][i]=s[j][i-1];
            for(int k=0; k<4; ++k)
                f[j][k][i]=f[j][k][i-1];
        }
        ++s[val(st[i])][i];
        for(int j=0; j<4; ++j)
            f[j][val(st[i])][i] += s[j][i];
    }
    scanf("%d",&q);
    char c1[5],c2[5];
    int l,r;
    for(int i=0; i<q; ++i){
        scanf("%s%s%d%d",c1,c2,&l,&r);
        printf("%lld\n",get(c1[0],c2[0],l,r));
    }
}

