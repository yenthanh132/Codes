#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000009

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

struct bucket{
    char ch;
    int pos;
}a[maxn];
int n,m,T;
char buf[10];

bool cmp(const bucket &a, const bucket &b){
    return a.pos < b.pos;
}

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; ++i) scanf("%s%d",buf,&a[i].pos), a[i].ch=buf[0];
        sort(a+1,a+m+1,cmp);
        ll res = 1;
        for(int i=1; i<m; ++i) if(a[i+1].ch != a[i].ch) res = res * (a[i+1].pos - a[i].pos) %oo;

        printf("%lld\n",res);
    }

    return 0;
}

