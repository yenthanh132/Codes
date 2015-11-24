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

int a[maxn],b[maxn],m,n,k;

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    if(a[m]>b[n]){
        puts("YES");
        return 0;
    }
    if(m>n) puts("YES");
    else{
        bool win=0;
        FOR(i,1,m) if(a[i]>b[n-m+i]){
            win=1;
            break;
        }
        if(win) puts("YES");
        else puts("NO");    
    }
    
    //getch();
    return 0;
}
        
