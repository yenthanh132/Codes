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

bool win[3][3];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    string s;
    int a[3];
    REP(i,3){
        cin>>s;
        if(s=="scissors") a[i]=0;
        else if(s=="paper") a[i]=1;
        else a[i]=2;
    }
    win[0][1]=1;
    win[1][2]=1;
    win[2][0]=1;
    int x=-1;
    REP(i,3){
        int c=0;
        REP(j,3) if(win[a[i]][a[j]]) c++;
        if(c==2){
            x=i;
            break;
        }
    }
    if(x==-1) puts("?");
    else if(x==0) puts("F");
    else if(x==1) puts("M");
    else puts("S");
    
    //getch();
    return 0;
}
