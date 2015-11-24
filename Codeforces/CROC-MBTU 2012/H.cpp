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

const int maxn= 5007;
int n,q,BIT[maxn][maxn];
char s[maxn];

void update(int l, int r){
    for(int i=l; i<=n; i+=i&(-i))
        for(int j=r; j<=n; j+=j&(-j))
            BIT[i][j]++;
}

int get(int l, int r){
    int res=0;
    for(int i=l; i>0; i-=i&(-i))
        for(int j=r; j>0; j-=j&(-j))
            res+=BIT[i][j];
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    gets(s);
    n=strlen(s);
    scanf("%d",&q);
    FOR(i,1,n)
        FOR(j,0,min(i-1,n-i)){
            if(s[i-j-1]!=s[i+j-1]) break;
            update(i-j,i+j);
        }
    FOR(i,1,n-1) if(s[i-1]==s[i])
        FOR(j,0,min(i-1,n-i-1)){
            if(s[i-j-1]!=s[i+j]) break;
            update(i-j,i+j+1);
        }
        
    int x,y;
    FOR(i,1,q){
        scanf("%d%d",&x,&y);
        printf("%d\n",get(y,y)-get(x-1,y));
    }
    
    //getch();
    return 0;
}
