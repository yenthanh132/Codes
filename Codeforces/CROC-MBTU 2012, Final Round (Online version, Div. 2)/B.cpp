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

string process(string s){
    int p=-1,c=0;
    if(s.find("::")!=string::npos){
        REP(i,sz(s)) if(s[i]==':'){
            if(i-p>1) c++;
            p=i;
        }
        if(p<sz(s)-1) c++;
        string st="";
        REP(i,8-c){
            st+=':';
            REP(j,4) st+='0';
        }
        st+=':';
        s.replace(s.find("::"),2,st);
        //cout<<"- "<<st<<endl;
        if(s[0]==':') s.erase(0,1);
        if(s[sz(s)-1]==':') s.erase(sz(s)-1,1);
    }
    p=sz(s);
    REPD(i,sz(s))
        if(s[i]==':'){
            REP(j,5-(p-i)) s.insert(i+1,"0");
            p=i;
        }
    REP(j,4-p) s.insert(0,"0");
    return s;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n;
    string s;
    cin>>n;
    REP(i,n){
        cin>>s;
        cout<<process(s)<<endl;
    }
    //getch();
    return 0;
}
