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

const int maxn=10007;

int t,n,m,a[maxn],c[26],c2[26],Left[maxn],Right[maxn];
char s[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int t;
    scanf("%d",&t);
    REP(tt,t){
        scanf("%s",s+1);
        n=strlen(s+1);
        s[++n]='#';
        m=0;
        reset(c,0); reset(c2,0);
        FOR(i,1,n)
            if(s[i]!='#') c[s[i]-'a']++, c2[s[i]-'a']++;
            else{
                int maxv=0;   
                REP(j,26) maxv=max(maxv,c[j]);
                a[++m]=maxv;
                maxv=0;   
                REP(j,26) maxv=max(maxv,c2[j]);
                Left[m]=maxv;
                reset(c,0);
            }
        reset(c2,0);
        int m2=m;
        FORD(i,n-1,1) 
            if(s[i]!='#') c2[s[i]-'a']++;
            else{
                int maxv=0;   
                REP(j,26) maxv=max(maxv,c2[j]);
                Right[m2--]=maxv;   
            }
        
        int res=0;
        FOR(i,1,m-3) if(Left[i] && a[i+1] && a[i+2] && Right[i+3])
            res=max(res,Left[i] + a[i+1] + a[i+2] + Right[i+3] + 3);
         
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
        
