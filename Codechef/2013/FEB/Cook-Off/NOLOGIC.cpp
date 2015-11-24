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

bool mark[100];

int t,n;
char s[500];

int val(char ch){
    if('a'<=ch && ch<='z') return ch-'a';
    else if('A'<=ch && ch<='Z') return ch-'A';
    else return 26;
}

int main(){
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d\n",&t);
    REP(index,t){
        gets(s+1);
        n=strlen(s+1);
        reset(mark,1);
        FOR(i,1,n) mark[val(s[i])]=0;
        bool ok=0;
        REP(i,26) if(mark[i]){
            putchar('a'+i);
            ok=1;

        }
        if(!ok) putchar('~');
            
        putchar(10);
    }
    return 0;
}
