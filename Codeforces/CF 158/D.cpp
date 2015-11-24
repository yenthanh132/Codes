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

struct mycmp{
    bool operator()(const pii a, const pii b){
        return a.fi<b.fi;
    }
};

priority_queue<pii,vector<pii>,mycmp> s1,s2;
int n;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int c,v;
    FOR(i,1,n){
        scanf("%d%d",&c,&v);
        if(c==0) s1.push(pii(v,i)); else s2.push(pii(v,i));
    }
    REP(index,n-1){
        pii a=s1.top(), b=s2.top();
        if(a.fi < b.fi || (a.fi==b.fi && sz(s1)>sz(s2))){
            printf("%d %d %d\n",a.se,b.se,a.fi);
            s1.pop();
            s2.pop();
            b.fi-=a.fi;
            s2.push(b);
        }else{
            printf("%d %d %d\n",a.se,b.se,b.fi);
            s1.pop();
            s2.pop();
            a.fi-=b.fi;
            s1.push(a);
        }
    }
    
    //getch();
    return 0;
    
}           
