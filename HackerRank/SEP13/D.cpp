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

int n,a[100007],v[2];
map<int,int> cnt[2];
ll res;

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    res=0;
    cnt[0][0]=1;
    cnt[1][0]=1;
    FORD(i,n-1,1){
        int x=i&1;
        int t=a[i+1]-a[i];
        v[x]^=t;
        res+=cnt[x][v[x]];
        res+=cnt[!x][v[!x]^a[i]];
        cnt[x][v[x]]++;
        
    }
    cout<<1ll*n*(n-1)/2-res<<endl;
    
    //getch();
    return 0;
}
    
