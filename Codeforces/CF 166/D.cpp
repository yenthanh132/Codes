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
typedef pair<ll, ll> pll;

const int maxn=1507;
const ll base=73471;
const ll base2=100007;

char s[maxn],buf[30];
int n,k,res,sum[maxn];
ll val[maxn],hashpw[maxn],val2[maxn],hashpw2[maxn];
vector<pll> list;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%s",buf);
    scanf("%d",&k);
    
    hashpw[0]=hashpw2[0]=1; val[0]=val2[0]=0; sum[0]=0;
    FOR(i,1,n){
        val[i]=val[i-1]*base+s[i];
        hashpw[i]=hashpw[i-1]*base;
        val2[i]=val2[i-1]*base2+s[i];
        hashpw2[i]=hashpw2[i-1]*base2;
        sum[i]=sum[i-1]+(buf[s[i]-'a']=='0');
    }
    FOR(i,1,n) FOR(j,i,n) if(sum[j]-sum[i-1]<=k)
        list.pb(pll(val[j]-val[i-1]*hashpw[j-i+1], val2[j]-val2[i-1]*hashpw2[j-i+1]));
    sort(list.begin(),list.end());
    list.resize(unique(list.begin(),list.end())-list.begin());
    printf("%d\n",sz(list));
    //getch();
    return 0;
}
    
