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

int a[107],b[107],n,m;

bool check(int v){
    bool found=0;
    FOR(i,1,n) if(a[i]>v) return 0;
    else if(a[i]*2<=v) found=1;
    return found;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,m) cin>>b[i];
    int minv=b[1];
    FOR(i,2,m) minv=min(minv,b[i]);
    int res=-1;
    FOR(i,1,minv-1) if(check(i)){
        res=i;
        break;
    }
    cout<<res<<endl;
    //getch();
}
