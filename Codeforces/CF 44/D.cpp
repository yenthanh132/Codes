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

map<vector<int>, int> mymap;
int n,m,n1,n2,v[20];
string s1[20],s2[20];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>m;
    n1=n/2;
    n2=n-n1;
    REP(i,m){
        cin>>s2[i]>>v[i];
        s1[i]=s2[i].substr(0,n1);
        s2[i].erase(0,n1);
        reverse(s1[i].begin(),s1[i].end());
        reverse(s2[i].begin(),s2[i].end());
    }
    vector<int> tmp;
    REP(id,1<<n1){
        tmp.clear();
        REP(i,m){
            int val=0;
            REP(j,n1) if(((id>>j)&1)==s1[i][j]-'0') val++;
            tmp.pb(v[i]-val);
        }
        mymap[tmp]++;
    }
    
    ll res=0;
    REP(id,1<<n2){
        tmp.clear();
        REP(i,m){
            int val=0;
            REP(j,n2) if(((id>>j)&1)==s2[i][j]-'0') val++;
            tmp.pb(val);
        }
        if(mymap.find(tmp)!=mymap.end()) res+=mymap[tmp];
    }
    
    cout<<res<<endl;
    
    //getch();
    return 0;
}
    
