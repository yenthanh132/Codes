#include <conio.h>
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

struct tile{
    int x1,y1,x2,y2;
}a[maxn];
int n,w,h;

bool overlap(const tile &t1, const tile &t2){
    if(max(t1.x1,t2.x1)<min(t1.x2,t2.x2) && max(t1.y1,t2.y1)<min(t1.y2,t2.y2)) return 1;
    return 0;
}

bool out(const tile &t){
    if(t.x1<0 || t.x2>w || t.y1<0 || t.y2>h) return 1;
    return 0;
}

int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&w,&h);   
        scanf("%d",&n);
        int area=0;
        FOR(i,1,n){
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
            area+=(a[i].x2-a[i].x1)*(a[i].y2-a[i].y1);
        }
        bool mark=0;
        FOR(i,1,n) FOR(j,i+1,n) if(overlap(a[i],a[j])){
            mark=1;
            break;
        }
        if(mark){
            puts("NONDISJOINT");
            continue;   
        }
        
        mark=0;
        FOR(i,1,n) if(out(a[i])){
            mark=1;
            break;
        }
        if(mark){
            puts("NONCONTAINED");
            continue;   
        }
        
        if(area!=w*h){
            puts("NONCOVERING");
            continue;
        }
        
        puts("OK");
    }
        
    //getch();
    return 0;
}
