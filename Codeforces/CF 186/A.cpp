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

string s;

#include <conio.h>

int main(){
    int n,v;
    cin>>s;
    n=atoi(s.c_str());
    FOR(i,sz(s)-2,sz(s)-1) if(i>=0 && s[i]!='-'){
        string st=s;
        st.erase(i,1);
        v=atoi(st.c_str());
        if(v>n) n=v;
    }
    cout<<n<<endl;
    //getch();
    return 0;
}
        
    
    
