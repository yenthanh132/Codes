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

multiset<int> mys;

int ans[maxn],n,m,a[maxn],list[maxn];

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);   
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int v,p,c,p2;
    FOR(i,1,n){
        scanf("%d",&v);
        mys.insert(v);
    }
    c=p=0;
    FORD(i,n,1){
        multiset<int>::iterator it = mys.lower_bound(m-a[i]-1);
        if(it!=mys.end() && *it>m-a[i]-1 && it==mys.begin() )
            list[++p]=a[i];
        else{
            if(it==mys.end() || *it>m-a[i]-1) it--;
            ans[++c]=(a[i]+*it)%m;
            mys.erase(it);
        }
    }
    for( multiset<int>::iterator it = mys.begin(); it!=mys.end(); it++)
        ans[++c]=(*it+list[p--])%m;
    sort(ans+1,ans+n+1);
    FORD(i,n,1) printf("%d ",ans[i]);
    //getch();
    return 0;
}
        
            
       
