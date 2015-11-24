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

string s[10007];
int t,n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>t;
    REP(tt,t){
        cin>>n;
        FOR(i,1,n) cin>>s[i];
        sort(s+1,s+n+1);
        bool ok=1;
        FOR(i,1,n-1){
            int len=min(sz(s[i]),sz(s[i+1]));
            if(s[i].substr(0,len)==s[i+1].substr(0,len)){
                ok=0;
                break;   
            }   
        }   
        if(ok) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    //getch();
    return 0;
}
