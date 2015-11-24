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

const int maxn=100007;
char a[maxn];
int n;

int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    int j=0;
    FOR(i,1,n) if(a[i]=='0'){
        j=i;
        break;
    }
    if(j==0){
        FOR(i,1,n-1) putchar('1');
    }else{
        FOR(i,1,j-1) putchar(a[i]);
        FOR(i,j+1,n) putchar(a[i]);
    }
    puts("");
}
