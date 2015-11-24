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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=300007;

int n,a[maxn],l,r;
map<int,int> Right;
ll s[maxn],res;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    res=-oo;
    s[0]=0;
    FOR(i,1,n){
        scanf("%d",&a[i]);
        Right[a[i]]=i;
        s[i]=s[i-1];
        if(a[i]>0) s[i]+=a[i];
    }
    l=r=-1;
    ll val;
    FOR(i,1,n-1){
        int p=Right[a[i]];
        if(p>i){
            val=s[p-1]-s[i] + a[i]*2; 
            if(val>res){
                res=val;
                l=i;
                r=p;
            }
        }
    }
    
    vector<int> list;
    FOR(i,1,l-1) list.pb(i);
    FOR(i,l+1,r-1) if(a[i]<0) list.pb(i);
    FOR(i,r+1,n) list.pb(i);
    printf("%I64d %d\n",res,sz(list));
    REP(i,sz(list)) printf("%d ",list[i]);
    
    //getch();
    return 0;
}
            
        
    
    
    
        
    
