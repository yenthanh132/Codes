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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int d[256][256];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    char ch;
    int x=128, y=128,c=0;
    reset(d,0);
    d[x][y]=++c;
    while(cin>>ch){
        if(ch=='U') y++;
        else if(ch=='D') y--;
        else if(ch=='L') x--;
        else x++;
        if(d[x][y]){
            puts("BUG\n");
            return 0;
        }
        d[x][y]=++c;
        REP(k,4){
            int xt=x+dx[k], yt=y+dy[k];
            if(d[xt][yt]!=0 && d[xt][yt]+1<d[x][y]){
                puts("BUG\n");
                return 0;
            }
        }
    }
    puts("OK\n");
    //getch();
    return 0;
}
