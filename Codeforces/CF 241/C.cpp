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

const int maxn=1007;

int n,k;
struct request{
    int p,c,i;
}a[maxn];
int r[maxn];
int res;
vector<pii> list;

bool cmp(const request &a, const request &b){
    return a.c>b.c;   
}

int main(){
    ios::sync_with_stdio(0);
    
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>n;
    FOR(i,1,n){
        cin>>a[i].p>>a[i].c;
        a[i].i=i;   
    }
    cin>>k;
    FOR(i,1,k) cin>>r[i];
    
    res=0;
    sort(a+1,a+n+1,cmp);
    FOR(i,1,n){
        int u=-1;
        FOR(j,1,k) if(r[j]>=a[i].p && (u==-1 || r[j]<r[u])) u=j;
        if(u!=-1){
            res+=a[i].c;
            list.pb(pii(a[i].i,u));   
            r[u]=0;
        }
    }
    
    cout<<sz(list)<<' '<<res<<endl;
    REP(i,sz(list)) cout<<list[i].fi<<' '<<list[i].se<<endl;
    
    return 0;
}
    
