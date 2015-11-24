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

int dem(int v){
    int c=0;
    while(v){
        if(v%10==4 || v%10==7) c++;
        v/=10;
    }
    return c;
}

#include <conio.h>
int main(){
    int f[11],m;
    reset(f,0);
    freopen("input.txt","r",stdin);
    cin>>m;
    FOR(i,1,m) f[dem(i)]++;
    int n=0;
    while(m){
        n++;
        m/=10;
    }
    FOR(i,0,n) cout<<i<<' '<<f[i]<<endl;
    getch();
    return 0;
}
