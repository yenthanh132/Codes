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

const int maxn=107;

int n,test;
char s[maxn];

vector<int> list,num[maxn];

vector<int> f(char *s){
    int len=strlen(s);
    int x=0,y;
    vector<int> list;
    while(x<len){
        y=x;
        while(y+1<len && s[y+1]==s[x]) ++y;
        num[sz(list)].pb(y-x+1);
        list.pb(s[x]-'a');        
        x=y+1;
    }
    return list;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    
    scanf("%d",&test);
    FOR(tt,1,test){
        printf("Case #%d: ",tt);
        FOR(i,0,100) num[i].clear();
        
        scanf("%d",&n);
        scanf("%s",s);        
        list=f(s);
        bool ok=1;
        FOR(i,2,n){
            scanf("%s",s);
            vector<int> tmp=f(s);
            if(tmp!=list) ok=0;
        }
        
        if(!ok) puts("Fegla Won");
        else{
            int res=0,mid;
            REP(i,sz(list)){
                sort(num[i].begin(),num[i].end());
                mid=num[i][n/2];
                REP(j,sz(num[i])) res+=abs(mid-num[i][j]);
            }
            printf("%d\n",res);
        }
        
    }     
    return 0;   
}
