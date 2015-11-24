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

const int maxn=5000007;
const int base=73471;

ll hashpw[maxn],val1[maxn],val2[maxn],res;
char s[maxn];
int f[maxn];

ll getval1(int l, int r){
    return (val1[r]-val1[l-1]*hashpw[r-l+1]);
}

ll getval2(int l, int r){
    return (val2[l]-val2[r+1]*hashpw[r-l+1]);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gets(s);
    int n=strlen(s);
    hashpw[0]=1; val1[0]=0; val2[n+1]=0;
    FOR(i,1,n){
        val1[i]=val1[i-1]*base+int(s[i-1]);
        hashpw[i]=hashpw[i-1]*base;
    }
    FORD(i,n,1) val2[i]=val2[i+1]*base+int(s[i-1]);
    res=1; f[1]=1;
    int j;
    FOR(i,2,n)
        if(getval1(1,i/2)==getval2(i-i/2+1,i)) f[i]=f[i/2]+1, res+=f[i];
        else f[i]=0;
    cout<<res;
    //getch();
    return 0;
}
        
    
