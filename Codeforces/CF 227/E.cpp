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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=1000007;

bool mark[maxn];
int a[maxn],pos[maxn],n,k,bit[maxn];
set<int> s1,s2;
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    reset(mark,1);
    FOR(i,1,n) scanf("%d",&a[i]), pos[a[i]]=i;
    FOR(i,1,k){
        int v;
        scanf("%d",&v);
        mark[v]=0;
    }
    ll res=0;
    s1.insert(0); s1.insert(n+1);
    s2.insert(0); s2.insert(-n-1);
    FOR(v,1,n){
        if(!mark[v]){
            s1.insert(pos[v]);
            s2.insert(-pos[v]);
        }else{
            int p=pos[v];
            int r=*s1.lower_bound(p);
            int l=-*s2.lower_bound(-p);
            int len=r-l-1;
            for(int i=r-1; i; i-=i&(-i)) len-=bit[i];
            for(int i=l; i; i-=i&(-i)) len+=bit[i];
            for(int i=p; i<=n; i+=i&(-i)) bit[i]++;
            res+=len;
        }
    }

    cout<<res<<endl;
    return 0;
}

