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
int n,c1;
char s[maxn],t[maxn];

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",s+1);
    c1=0;
    FOR(i,1,n) if(s[i]=='T') c1++;
    FOR(i,1,c1) t[i]='T';
    FOR(i,c1+1,n) t[i]='H';
    int res=oo;
    REP(step,n){
        int cnt=0;
        FOR(j,1,n) if(t[j]!=s[j]) cnt++;
        res=min(res,cnt/2);
        FOR(i,0,n-1) s[i]=s[i+1];
        s[n]=s[0];           
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
