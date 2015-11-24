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

int t,k,m,n;

int getbit(int m, int n){
        m--,n--;
        int v;
        v=min(m,n)/k;
        int bit1=(m+n)&1;
        int bit2=v&1;
    return bit1^bit2;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin>>t>>k;
    REP(index,t){
        cin>>m>>n;
        m--; n--;
        if (k != 1) {
            if (m < n) swap(m, n);
            if (n%(k+1) == k) puts("+");
            else {
                int t = n%(2*k+2);
                if ((t/(k+1))%2==(m+n)%2) puts("-");
                else puts("+");
            }
        }else{
            if (m%2==0 && n%2==0) puts("-"); else puts("+");
        }
    }
    return 0;
}
        
        
