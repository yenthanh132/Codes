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

const int maxn=5007;

set<int> mys;
int g[maxn];
bool mark[maxn];

int n;
char s[maxn];

bool check(int i){
    return s[i-1]==s[i+1];
}

void init(){
    g[0]=0;
    g[1]=1;
    g[2]=1;
    FOR(i,3,5000){
        mys.clear();
        mys.insert(g[i-2]);
        FOR(j,0,i-3) mys.insert(g[i-j-3]^g[j]);
        for(g[i]=0; mys.find(g[i])!=mys.end(); g[i]++);
    }
}

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    gets(s+1);
    n=strlen(s+1);
    int val=0;
    int i=2;
    init();
    reset(mark,0);
    while(i<n)
        if(check(i)){
            mark[i]=1;
            int j=i;
            while(j<n-1 && check(j+1)){
                j++;
                mark[j]=1;
            }
            val^=g[j-i+1];
            i=j+1;
        }else 
            i++;
    
    if(val==0) puts("Second");
    else{
        puts("First");
        int pos=-1;
        bool tmp[3];
        FOR(i,1,n) if(mark[i]){
            val=0;
            REP(z,3){
                tmp[z]=mark[i-1+z];
                mark[i-1+z]=0;
            }
            int x=2,y;
            while(x<n)
                if(mark[x]){
                    y=x;
                    while(y<n-1 && mark[y+1]) y++;
                    val^=g[y-x+1];
                    x=y+1;
                }
                else x++;
            if(val==0){
                pos=i;    
                break;
            }
            REP(z,3){
                mark[i-1+z]=tmp[z];
            }
        }
        printf("%d\n",pos);
    }
    
    //getch();
    return 0;
}
