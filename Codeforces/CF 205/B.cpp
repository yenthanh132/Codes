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

int n,a[207],ans[207],b[207];
bool mark[207];
vector<int> list;
vector<int> l[3];
set<int> mys[2];

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n*2){
        cin>>a[i];
        list.pb(a[i]);
    }
    sort(list.begin(),list.end());
    list.resize(unique(list.begin(),list.end())-list.begin());
    int len=sz(list);
    REP(i,len) if(i<len/2) b[list[i]]=1; else b[list[i]]=2;
    reset(mark,1);
    FOR(i,1,n*2){
        if(b[a[i]]){
            l[b[a[i]]-1].pb(i);   
            b[a[i]]=0;
            mark[i]=0;
        }
    }
    FOR(i,1,n*2) if(mark[i]) 
        if(sz(l[0])<n) l[0].pb(i); 
        else l[1].pb(i);

    REP(i,2){
        REP(j,sz(l[i])){
            mys[i].insert(a[l[i][j]]);
            ans[l[i][j]]=i+1;
        }
    }
    cout<<sz(mys[0])*sz(mys[1])<<endl;
    FOR(i,1,n*2) cout<<ans[i]<<' ';
    
    
    getch();
    return 0;
}
        
    
