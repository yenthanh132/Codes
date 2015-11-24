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

bool isprime(int n){
    if(n==2 || n==3) return 1;
    if(n<2 || n%2==0 || n%3==0) return 0;
    int sn=int(sqrt(n)),k=0;
    do{
        k+=6;
        if(n%(k-1)==0 || n%(k+1)==0) break;
    }while(k-1<=sn);
    return (k-1>sn);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> list;
    FOR(i,2,n) if(isprime(i)) list.pb(i);
    REP(i,sz(list)){
        bool ok=0;
        REP(j,sz(list)-1){
            if(list[j]+list[j+1]+1==list[i]) ok=1;
            if(list[j]+list[j+1]+1>=list[i]) break;
        }
        if(ok) k--;
        if(k==0) break;
    }
    if(k) cout<<"NO"; else cout<<"YES";
    //system("pause");
    return 0;
}
        
