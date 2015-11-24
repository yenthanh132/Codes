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

#include <conio.h>
string s[3];

pair<int,int> checkboard(){
    int XW=0,OW=0,cX,cO;
    REP(i,3){
        cX=cO=0;
        REP(j,3) if(s[i][j]=='X') cX++; else if(s[i][j]=='0') cO++;
        if(cX==3) XW++; else if(cO==3) OW++;
        cX=cO=0;
        REP(j,3) if(s[j][i]=='X') cX++; else if(s[j][i]=='0') cO++;
        if(cX==3) XW++; else if(cO==3) OW++;
    }
    cX=cO=0;
    REP(i,3) if(s[i][i]=='X') cX++; else if(s[i][i]=='0') cO++;
    if(cX==3) XW++; else if(cO==3) OW++;
    cX=cO=0;
    REP(i,3) if(s[i][2-i]=='X') cX++; else if(s[i][2-i]=='0') cO++;
    if(cX==3) XW++; else if(cO==3) OW++;
    return pii(XW,OW);
}
    
    
int main(){
    //freopen("test.txt","r",stdin);
    REP(i,3) cin>>s[i];
    int cX=0,cO=0;
    REP(i,3) REP(j,3) if(s[i][j]=='X') cX++; else if(s[i][j]=='0') cO++;
    pii chk=checkboard();
    if(cX<cO || cX>cO+1 || (chk.fi>0 && chk.se>0) || (chk.fi>0 && cX==cO) || (chk.se>0 && cX>cO)){
        cout<<"illegal\n";
        return 0;
    }
    if(chk.fi>0 || chk.se>0)
        if(chk.fi) cout<<"the first player won\n"; else cout<<"the second player won\n";
    else{
        if(cX+cO==9 && cX==cO+1) cout<<"draw\n";
        else if(cX==cO) cout<<"first\n";
        else if(cX==cO+1) cout<<"second\n";
        else cout<<"illegal\n";
    }
    //getch();
    return 0;
}
        
