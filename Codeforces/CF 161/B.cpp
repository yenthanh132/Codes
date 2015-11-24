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
    int n,k,a[100];
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    if(k>n) cout<<-1<<endl;
    else if(k==0){
        if(a[n]<1000000000) cout<<1000000000<<' '<<1000000000<<endl;
        else cout<<-1<<endl;   
    }else{
        k=n-k+1;
        if(k==1 || a[k]!=a[k-1]) cout<<a[k]<<' '<<a[k]<<endl; else cout<<-1<<endl;
    }
    return 0;
}
