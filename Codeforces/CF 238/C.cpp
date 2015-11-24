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

const int maxn=1007;

int a[maxn][maxn],n,q,res;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n){
        scanf("%d",&a[i][j]);
    }
    res=0;
    FOR(i,1,n) FOR(j,1,n) res=(res+a[i][j]*a[j][i])&1;
    
    scanf("%d",&q);
    int x,y;
    FOR(i,1,q){
        scanf("%d",&x);
        if(x==3){
            putchar(res+'0');   
        }else{
            scanf("%d",&y);
            res^=1; 
        }
    }   
    return 0;
}