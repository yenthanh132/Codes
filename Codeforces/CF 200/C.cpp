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

const int maxn=100007;

int n,m;
ll h[maxn],p[maxn];

bool check(ll time){
    int x=1,old_x;
    FOR(i,1,n){
        if(x>m) return 1;   
        if(p[x]<=h[i]){
            if(h[i]-p[x]>time) return 0;
            old_x=x;
            while(x<=m && h[i]>=p[x]) x++;
            if(old_x!=x){
                while(x<=m && p[x]-p[old_x] + min(p[x]-h[i],h[i]-p[old_x])<=time) x++;
            }
        }else{
            while(x<=m && p[x]-h[i]<=time) x++;   
        }
    }
    return (x>m);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%I64d",&h[i]);
    FOR(i,1,m) scanf("%I64d",&p[i]);
    ll l,r,mid,res;
    r=res=20000000000ll;
    l=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    
    cout<<res<<endl;
    
    //getch();
    return 0;
}
