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

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s;
    cin>>s;
    while(s.find("WUB")!=string::npos){
        int p=s.find("WUB");
        s.erase(p+1,2);
        s[p]=' ';
    }
    while(s.find("  ")!=string::npos) s.erase(s.find("  "),1);
    while(!s.empty() && s[0]==' ') s.erase(0,1);
    while(!s.empty() && s[sz(s)-1]==' ') s.erase(sz(s)-1,1);
    cout<<s<<endl;
    //getch();
    return 0;
}
