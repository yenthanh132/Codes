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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

#define maxn 100007
#define base 1000000009

ll gt[maxn];

ll pow(ll u, int n){
    if(n==1) return u;
    ll t=pow(u,n/2);
    if(n%2) return((t*t*u)%base); else return((t*t)%base);
}

ll tohop(int k, int n){
    ll res=gt[n];
    res=(res*pow(gt[k],base-2))%base;
    res=(res*pow(gt[n-k],base-2))%base;
    return res;
}

void init(){
    gt[0]=1;
    FOR(i,1,10000) gt[i]=(gt[i-1]*i)%base;
}

int n,m,a[maxn],s;
vector<int> list;
map<int> mymap;

int main(){
    freopen("test.txt","r",stdin);
    m=0;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",a+i);
        if(mymap.find(a[i])=mymap.end()){
            mymap[a[i]]=0;
            list.pb(a[i]);
        }
        mymap[a[i]]++;
    }
    scanf("%d",&q);
    FOR(i,1,q){
        scanf("%d",&s);
        ll res=0;
        REP(j,m){
            
            
