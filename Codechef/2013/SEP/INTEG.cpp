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

const int maxn=100007;

ll n,a[maxn],res,sum,x;;


//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>x;
    sort(a+1,a+n+1);
    res=oo;
    sum=0;
    a[++n]=oo;
    FOR(i,1,n){
        res=min(res,sum+x*max(-a[i],0ll)-1ll*max(-a[i],0ll)*(i-1));
        if(a[i]>=0) break;
        sum-=a[i];
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
