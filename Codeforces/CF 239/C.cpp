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

int c[maxn*2][107],a[maxn],n,m;
int list[107][maxn];

struct ITNode{

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    
    reset(c,0);
    c[0][0]=1;
    FOR(i,1,111111){
        c[i][0]=1;
        FOR(j,1,100) c[i][j]=(c[i-1][j-1]+c[i-1][j])%oo;   
    }
    
    FOR(i,0,100)
        FOR(j,0,n) list[i][j]=c[j+i][i];   
        
    
    return 0;   
}
