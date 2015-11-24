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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);   
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n,a[101];
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int g=a[1];
    FOR(i,2,n) g=gcd(g,a[i]);
    FOR(i,1,n) a[i]/=g;
    if((a[n]-n)&1) cout<<"Alice"; else cout<<"Bob";
    //getch();
    return 0;
}
    
