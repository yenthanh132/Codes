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

int myq[maxn],d[maxn],s[maxn];
int n;
vector<pii> res;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int first=1,last=0;
    for(int i=0; i<n; ++i){
        scanf("%d%d",&d[i],&s[i]);
        if(d[i]==1) myq[++last]=i;
    }
    while(first<=last){
        int x=myq[first++];
        if(d[x]!=1) continue;
        int y=s[x];
        res.pb(pii(x,y));
        s[y]^=x;
        --d[y];
        if(d[y]==1) myq[++last]=y;
    }
    printf("%d\n",sz(res));
    for(int i=0; i<sz(res); ++i) printf("%d %d\n",res[i].first,res[i].second);
}
