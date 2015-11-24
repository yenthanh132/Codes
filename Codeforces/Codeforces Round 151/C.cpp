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
typedef pair<int, ll> pil;

struct classcmp{
    bool operator()(const pil &a, const pil &b)
    {return a.fi<b.fi;};
};

set< pil ,classcmp> s[2];
int n,a[50],k;
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    REP(i,n) scanf("%d",a+i);
    set<pair<int,ll> >::iterator it;
    REP(i,n){
        s[i&1].clear();
        for(it=s[1-i&1].begin(); it!=s[1-i&1].end(); it++){
            if(sz(s[i&1])<k) s[i&1].insert(pil(it->fi+a[i], it->se + (1ll<<i)));
            if(sz(s[i&1])<k) s[i&1].insert(*it);
        }
        if(sz(s[i&1])<k) s[i&1].insert(pil(a[i],1ll<<i));
    }
    for(it=s[1-n&1].begin(); it!=s[1-n&1].end(); it++){
        int c=0;
        REP(i,n) if((it->se >> i)&1) c++;
        //cout<<it->fi<<' '<<it->se<<' ';
        printf("%d ",c);
        REP(i,n) if((it->se >> i)&1) printf("%d ",a[i]);
        puts("");
    }
    //getch();
    return 0;
}
            
        
