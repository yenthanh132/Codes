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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool f[1<<15];
int T, n, a[15];

bool check(int i){
    int t=0;
    REP(j,n) if((i>>j)&1){
        if(t>a[j]) return false;
        t=a[j];
    }
    return true;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    cin>>T;
    REP(index,T){
        cin>>n;
        REP(i,n) cin>>a[i];
        REP(i,1<<n)
            if(check(i)) f[i]=false;
            else{
                f[i]=false;
                REP(j,n) if(((i>>j)&1) && !f[i-(1<<j)]){f[i]=true; break;}
            }
        if(f[(1<<n)-1]) puts("Alice"); else puts("Bob");
    }
    
    //getch();
    return 0;
}
