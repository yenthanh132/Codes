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

int n,a[maxn],s1[maxn],s2[maxn],m;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n){
        s1[i]=s1[i-1]; s2[i]=s2[i-1];
        if(i<n && a[i]>a[i+1]) s1[i]++;
        if(i<n && a[i]<a[i+1]) s2[i]++;
    }
    int u,v,l,r,mid,p;
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        l=u; r=v;
        p=u;
        while(l<=r){
            mid=(l+r)/2;
            if(s1[mid-1]-s1[u-1]==0){
                p=mid;
                l=mid+1;
            }else r=mid-1;
        }
        if(s2[v-1]-s2[p-1]==0) puts("Yes"); else puts("No");
    }
    
    return 0;
}    
    
