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

const int maxn=1000007;

const int maxv=100000;

char name[maxn][20];
int n,val[maxn],last,BIT[maxv+7];

void update(int pos, int v){
    for(int i=pos; i<=maxv; i+=i&(-i)) BIT[i]+=v;
}

int get(int pos){
    int res=0;
    for(int i=pos; i>0; i-=i&(-i)) res+=BIT[i];
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    last=0;
    int c,minv,v;
    FOR(i,1,n){
        scanf("%d",&v);
        if(v==-1){
            c=0;
            while(get(val[last]-1)){
                c++;
                update(val[last],-1);
                last--;
            }
            printf("%d %s\n",c,name[last]);
            update(val[last],-1);
            last--;
        }else{
            val[++last]=v;
            scanf("%s",name[last]);
            if(v>0) update(v,1); else last--;
        }
    }
    //getch();
    return 0;
}
