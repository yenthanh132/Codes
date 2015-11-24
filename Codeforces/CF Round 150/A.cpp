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

int a[maxn],n;
vector<int> bit[30],arr;
vector<int> list;
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) REP(j,20) if((a[i]>>j)&1) bit[j].pb(i);
    
    vector<int>::iterator it;
    FOR(i,1,n){
        arr.clear();
        int v=a[i];
        REP(j,20) if(((v>>j)&1)==0){
            it=lower_bound(bit[j].begin(),bit[j].end(),i+1);
            if(it!=bit[j].end()) arr.pb(*it);
            v|=(1<<j);
        }
        sort(arr.begin(),arr.end());
        v=a[i]; list.pb(v);
        REP(j,sz(arr)){
            v|=a[arr[j]];
            list.pb(v);
        }
    }
    
    sort(list.begin(),list.end());
    cout<<unique(list.begin(),list.end())-list.begin()<<endl;
    //getch();
    return 0;
}
        
        
    
