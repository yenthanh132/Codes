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

#define maxn 101

int c[maxn];

bool mycmp(const int &a, const int &b){return(a>b);}

int main(){
    //freopen("test.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    FOR(i,1,n) cin>>c[i];
    sort(c+1,c+n+1,mycmp);
    ll res=0;
    int t=k,mul=1;
    FOR(i,1,n){
        res+=mul*c[i];
        t--;
        if(!t) t=k, mul++;
    }
    cout<<res<<endl;
    return 0;
}
