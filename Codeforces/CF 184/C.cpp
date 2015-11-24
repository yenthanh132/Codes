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

multiset<int> mys;
int n,a[maxn],m;
ll res;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int v;
    FOR(i,1,n){
        scanf("%d",&v);
        mys.insert(v);
    }
    
    m=0;
    while(!mys.empty()){
        int u=*mys.begin();
        mys.erase(mys.begin());
        v=1;
        while(!mys.empty() && *mys.begin()==u){
            mys.erase(mys.begin());
            v++;
        }
        if(v&1) a[++m]=u;
        v/=2;
        while(v){
            u++;
            if(v&1) mys.insert(u);
            v/=2;
        }
    }
    cout<<a[m]-m+1<<endl;
    //getch();
    return 0;
}
        
    
