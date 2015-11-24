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

char str[maxn];
int s[maxn];
int m,l,r,n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%s",str+1);
    n=strlen(str+1);
    FOR(i,1,n){
        s[i]+=s[i-1];
        if(i<n && str[i]==str[i+1]) s[i]++;
    }
    scanf("%d",&m);
    REP(i,m){
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r-1]-s[l-1]);
    }
    //getch();
    return 0;
}
