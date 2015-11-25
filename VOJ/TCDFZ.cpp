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

int mpow(int v, int n){
    int ans=v;
    REP(i,n%4) ans=ans*v;
    return(ans%10);
}

//#include <conio.h>
int main(){
    int n,ans=1;
    cin>>n;
    while(n){
        FOR(i,2,9) if(i!=5)
            if(i<=n%10) ans=(ans*mpow(i,n/10+1))%10; else ans=(ans*mpow(i,n/10))%10;
        int k=n/5;
        REP(i,k%4){
            if(ans==2 || ans==6) ans=ans+10;
            ans/=2;
        }
        n/=5;
    }
    cout<<ans;
    //getch();
    
    return 0;
}
