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

struct node{node *next[2];} *root;

void newnode(node *&a){
    a=new node;
    a->next[0]=a->next[1]=NULL;
}
int n;

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    newnode(root);
    node *p;
    int v;
    FOR(i,1,n){
        scanf("%d",&v);
        p=root;
        
        REP(j,20){
            int t=(v>>j)&1;
            if(p->next[t]==NULL) newnode(p->next[t]);
            p=p->next[t];
        }
    }
    
    int res=0;
    REP(i,1<<20){
        p=root;
        bool ok=1;
        REP(j,20){
            int t=(i>>j)&1;
            if(p->next[t]==NULL){
                ok=0;
                break;
            }
            p=p->next[t];
        }
        if(ok) res++, cout<<i<<endl;
    }
    
    cout<<res<<endl;
    getch();
    return 0;
}
        
