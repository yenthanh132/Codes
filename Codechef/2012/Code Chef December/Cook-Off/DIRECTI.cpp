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

int t,n;
char a[100][100], m[100],buf[100];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    REP(index,t){
        scanf("%d",&n);
        FOR(i,1,n){
            scanf("%s",buf);
            m[i]=buf[0];
            scanf("%s",buf);
            gets(a[i]);
        }
        FORD(i,n,1){
            if(i==n) printf("Begin"); 
            else if(m[i+1]=='L') printf("Right"); else printf("Left");
            printf(" on%s\n",a[i]);
        }
        puts("");
    }
    return 0;
}
        
