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

int sum[maxn][3];
char s[maxn];
int n,q;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%s",s+1);
    n=strlen(s+1);
    reset(sum,0);
    FOR(i,1,n){
        REP(j,3){
            sum[i][j]=sum[i-1][j];
            if(j==s[i]-'x') sum[i][j]++;
        }           
    }
    
    scanf("%d",&q);
    int l,r,t[10];
    REP(i,q){
        scanf("%d%d",&l,&r);
        REP(j,3) t[j]=sum[r][j]-sum[l-1][j];
        sort(t,t+3);
        if(r-l+1<3 || t[2]-t[0]<=1) puts("YES");
        else puts("NO");
    }
}

