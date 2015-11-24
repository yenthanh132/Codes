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

const int maxn=107;
const int base=73471;

int next[maxn],n;
ll val[maxn],hashpw[maxn];
char s[maxn];

ll getv(int l, int r){
    if(l==0) return val[r];
    else return val[r]-val[l-1]*hashpw[r-l+1];
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gets(s); n=strlen(s);
    val[0]=s[0];
    FOR(i,1,n-1) val[i]=val[i-1]*base+s[i];
    hashpw[0]=1; FOR(i,1,n) hashpw[i]=hashpw[i-1]*base;
    FORD(len,n,1)
        FOR(i,0,n-len-1)
            FOR(j,i+1,n-len) 
                if(getv(i,i+len-1)==getv(j,j+len-1)){
                    cout<<len;
                    //getch();
                    return 0;
                }
    cout<<0;
    //getch();
    return 0;
}
               
            
