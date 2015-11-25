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

const int n=4;
const int k=3;

struct node{int a[10];};
struct classcmp{
    bool operator()(const node &a, const node &b){
        FOR(i,1,n) if(a.a[i]<b.a[i]) return 1; else if(a.a[i]>b.a[i]) return 0;
        return 0;
    }
};
set<node,classcmp> s[2];

#include <conio.h>
int main(){
    int flag=1;
    node a; a.a[0]=0;
    FOR(i,1,n) a.a[i]=i;
    s[1].insert(a);
    REP(i,k){
        flag=1-flag; s[flag].clear();
        for(set<node,classcmp>::iterator it=s[1-flag].begin(); it!=s[1-flag].end(); it++){
            a=*it;
            FOR(i,1,n-1){
                swap(a.a[i],a.a[i+1]);
                s[flag].insert(a);
                swap(a.a[i],a.a[i+1]);
            }
        }
    }
    cout<<sz(s[flag]);
    getch();
    return 0;
}
                
