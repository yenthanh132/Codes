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
    int T,a,b,ma,mb;
    cin>>T;
    REP(i,T){
        cin>>a>>b>>ma>>mb;
        if(a==0 || ma==0) cout<<min(b,mb)<<endl;
        else if(b==0 || mb==0) cout<<min(a,ma)<<endl;
        else{
            if(a>b) swap(a,b), swap(ma,mb);
            if(a==b) cout<<a+b<<endl;
            else cout<<a+a+1+min(ll(b-a-1),ll(mb-1)*(a+1))<<endl;
        }
    }
    return 0;
}
        
