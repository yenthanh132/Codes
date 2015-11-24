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

const int dx[8]={-2,-1,1,2,2,1,-1,-2};
const int dy[8]={1,2,2,1,-1,-2,-2,-1};

bool have[10][10];
bool mark[10][10];

#include <conio.h>
int main(){
    string s;
    int x1,y1,x2,y2;
    cin>>s;
    x1=s[0]-'a'+1;
    y1=s[1]-'0';
    cin>>s;
    x2=s[0]-'a'+1;
    y2=s[1]-'0';
    reset(mark,0);
    reset(have,0);
    have[x1][y1]=1; have[x2][y2]=1;
    FOR(i,1,8){
        mark[i][y1]=1;
        mark[x1][i]=1;
    }
    REP(k,8){
        int xt=x2+dx[k];
        int yt=y2+dy[k];
        if(xt>=1 && xt<=8 && yt>=1 && yt<=8) mark[xt][yt]=1;
    }
    
    int c=0;
    bool ok;
    FOR(x,1,8) FOR(y,1,8) if(!mark[x][y] && !have[x][y]){
        ok=1;
        REP(k,8){
            int xt=x+dx[k];
            int yt=y+dy[k];
            if(xt>=1 && xt<=8 && yt>=1 && yt<=8 && have[xt][yt]){
                ok=0;
                break;
         
            }
        }
        if(ok) c++;
    }
    cout<<c<<endl;
    
    //getch();
    return 0;
}
