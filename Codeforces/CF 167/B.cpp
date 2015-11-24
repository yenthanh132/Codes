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

const int maxn=200007;

int n,m,dem[maxn];
ll gt[maxn];
struct node{int x,y;} a[maxn];

int mpow2(int n){
    if(n==0) return 1;
    ll t=mpow2(n/2);
    t=(t*t)%m;
    if(n&1) return (t*2)%m; else return t;
}

bool cmp(const node &a, const node &b){
    return a.x<b.x || (a.x==b.x && (a.y<b.y));
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&a[i].x);
        a[i].y=i;
    }
    FOR(i,1,n){
        scanf("%d",&a[i+n].x);
        a[i+n].y=i;
    }
    scanf("%d",&m);
    n*=2;
    sort(a+1,a+n+1,cmp);
    gt[0]=1; dem[0]=0;
    FOR(i,1,n){
        int v=i;
        dem[i]=dem[i-1];
        while(v%2==0){
            v/=2;
            dem[i]++;
        }
        gt[i]=(gt[i-1]*v)%m;
    }
    
    ll res=1;
    
    for(int i=1,j,cnt; i<=n;){
        j=i;
        while(j<n && a[j+1].x==a[i].x) j++;
        cnt=0;
        FOR(x,i,j-1) if(a[x].y==a[x+1].y) cnt++;
        res=(res*gt[j-i+1])%m;
        res=(res*mpow2(dem[j-i+1]-cnt))%m;
        i=j+1;
    }
    
    printf("%I64d\n",res);
    
    return 0;
}
    
