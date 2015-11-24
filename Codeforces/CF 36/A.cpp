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

int n;
char s[106];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    int p,p2,d;
    FOR(i,1,n) if(s[i]=='1'){
        p=i;
        break;
    }
    FOR(i,p+1,n) if(s[i]=='1'){
        p2=i;
        break;
    }
    d=p2-p; p=p2;
    bool ok=1;
    FOR(i,p2+1,n) if(s[i]=='1'){
        if(i-p!=d){
            ok=0;
            break;
        }else p=i;
    }
    if(ok) puts("YES"); else puts("NO");
    return 0;
}
