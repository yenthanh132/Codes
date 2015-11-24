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

int main(){
    //freopen("test.txt","r",stdin);
    int t,n;
    bool deg[1000];
    char ch;
    cin>>t;
    REP(i,t){
        cin>>n;
        reset(deg,0);
        REP(j,n){
            cin>>ch;
            if(ch=='1'){
                deg[j]=1;
                if(j>0) deg[j-1]=1;
                if(j<n-1) deg[j+1]=1;
            }
        }
        int res=0;
        REP(j,n) if(!deg[j]) res++;
        cout<<res<<endl;
    }
    return 0;
}
        
