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

const int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
const int maxn= 5000007;

int toint(string s){
    return atoi(s.c_str());
}

int a[maxn],cnt;
char s[maxn][25],buf[maxn],buf2[maxn],buf3[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n,m,month,day,hh,mm,ss;
    scanf("%d %d\n",&n,&m);    
    cnt=0;
    while(scanf("%s %s",buf,buf2)!=EOF){
        sscanf(buf,"2012-%d-%d",&month,&day);
        sscanf(buf2,"%d:%d:%d:",&hh,&mm,&ss);
        month--; day--;
        FOR(i,1,month) day+=days[i];
        a[++cnt]=ss + mm*60 + hh*60*60 + day*60*60*24;
        
        if(cnt>=m && a[cnt]-a[cnt-m+1]+1<=n){
            buf2[8]=0;
            printf("%s %s\n",buf,buf2);
            //getch();
            return 0;
        }
        gets(buf);
    }
    puts("-1");
    //getch();
    return 0;
}
    
