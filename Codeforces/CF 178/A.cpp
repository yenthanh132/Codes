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

int n,a[maxn],m;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>m;
    int x,y;
    FOR(i,1,m){
        cin>>x>>y;
        if(x>1) a[x-1]+=y-1;
        if(x<n) a[x+1]+=a[x]-y;
        a[x]=0;
    }
    FOR(i,1,n) cout<<a[i]<<endl;
    //getch();
    return 0;
}
