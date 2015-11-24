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

int n,a[101],r1,c1,r2,c2;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>r1>>c1>>r2>>c2;
    int res=0,t,ans;
    t=r1;
    while(t!=r2){
        if(t<r2) t++; else t--;
        c1=min(c1,a[t]+1);
        res++;
    }
    res+=abs(c1-c2);
    
    FOR(i,1,n){
        ans=abs(r1-i);
        t=c1;
        int j=r1;
        while(j!=i){
            if(j<i) j++; else j--;
            t=min(t,a[j]+1);
        }
        ans+=abs(i-r2)+abs(t-c2);
        res=min(res,ans);
    }
    
    cout<<res<<endl;
    return 0;
}
    
