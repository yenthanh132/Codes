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

struct team{int win,lose,p;};

map<string,team> mymap;
vector<pair<string,team> > list;
vector<string> namelist;
int n;

bool mycmp(const pair<string,team> &a, const pair<string,team> &b){
    int v=a.se.p-b.se.p;
    if(v>0) return 1; else if(v<0) return 0;
    v=a.se.win-a.se.lose-(b.se.win-b.se.lose);
    if(v>0) return 1; else if(v<0) return 0;
    v=a.se.win-b.se.win;
    if(v>0) return 1; else return 0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    string s,n1,n2;
    int w,l;
    REP(i,n){
        cin>>s;
        mymap[s].win=mymap[s].lose=mymap[s].p=0;
    }
    REP(i,n*(n-1)/2){
        cin>>s;
        n1=s.substr(0,s.find("-"));
        s.erase(0,s.find("-")+1);
        n2=s;
        cin>>s;
        w=atoi(s.substr(0,s.find(":")).c_str());
        s.erase(0,s.find(":")+1);
        l=atoi(s.c_str());
        if(w<l) swap(w,l), swap(n1,n2);
        mymap[n1].win+=w; mymap[n1].lose+=l;
        mymap[n2].win+=l; mymap[n2].lose+=w;
        if(w>l) mymap[n1].p+=3; else{mymap[n1].p++; mymap[n2].p++;}
    }
    map<string,team>::iterator it;
    for(it=mymap.begin(); it!=mymap.end(); it++) list.pb(*it);
    sort(list.begin(),list.end(),mycmp);
    REP(i,n/2) namelist.pb(list[i].fi);
    sort(namelist.begin(),namelist.end());
    REP(i,sz(namelist)) cout<<namelist[i]<<endl;
    //getch();
    return 0;
}
