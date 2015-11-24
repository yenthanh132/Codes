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

#include <conio.h>

const int maxn=1000007;
int a[maxn];

int main(){
    int n,N;
    cin>>n;
    N=n;
    
    int p=1;
    while(p*2<=n) p*=2;
    
    while(n>0){
        FOR(v,p,n){
            a[v]=p-(v-p+1);
            a[p-(v-p+1)]=v;
        }
        n=p-(n-p+1)-1;
        while(p && p>n) p/=2;
    }
    
    ll res=0;
    FOR(i,0,N)
        res+=i^a[i];
    printf("%I64d\n",res);
    FOR(i,0,N) printf("%d ",a[i]);
    
    //getch();
    return 0;
}
    
