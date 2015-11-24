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

const int maxn=107;
int s[maxn];
int a[maxn][maxn];
int n,s1,s2,b[maxn],c;


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    c=0; s1=s2=0;
    FOR(i,1,n){
        scanf("%d",&s[i]);
        FOR(j,1,s[i]) scanf("%d",&a[i][j]);
        if(s[i]&1) b[++c]=a[i][(s[i]+1)/2];
        FOR(j,1,s[i]/2) s1+=a[i][j];
        FOR(j,s[i]-s[i]/2+1,s[i]) s2+=a[i][j];
    }
    sort(b+1,b+c+1,greater<int>());
    FOR(i,1,c) if(i&1) s1+=b[i]; else s2+=b[i];
    cout<<s1<<' '<<s2<<endl;
    return 0;
}
