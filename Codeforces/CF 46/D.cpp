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

const int maxn=1007;

char s[maxn];
int n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",s+1);
    int c1=0, c2=0;
    FOR(i,1,n){
        if((i&1) != s[i]-'0') c1++;
        if((i&1) == s[i]-'0') c2++; 
    }
    cout<<min(c1,c2)<<endl;
    //getch();
    return 0;
}
