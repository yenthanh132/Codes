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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

const int maxn = 1007;

struct proc{string name,var[10]; int t;} a[maxn];
map<string,string> typevar1;
int n,m,k;

proc xuli(string &s){
    while(s.find(' ')!=string::npos) s.erase(s.find(' '),1);
    proc ans;
    ans.name=s.substr(0,s.find('('));
    s.erase(0,s.find('(')+1);
    ans.t=0;
    while(s.find(',')!=string::npos){
        ans.var[++ans.t]=s.substr(0,s.find(','));
        s.erase(0,s.find(',')+1);
    }
    ans.var[++ans.t]=s.substr(0,s.find(')'));
    return ans;
}

bool checkok(proc &a, proc &b){
    if(a.name!=b.name || a.t!=b.t) return false;
    string tvar;
    FOR(i,1,a.t){
        tvar=typevar1[b.var[i]];
        if(a.var[i]!="T" && tvar!=a.var[i]) return false;
    }
    return true;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    string st,st2;
    FOR(i,1,n){
        cin>>st;
        getline(cin,st);
        a[i]=xuli(st);
    }
    cin>>m;
    FOR(i,1,m){
        cin>>st>>st2;
        typevar1[st2]=st;
    }
    cin>>k;
    getline(cin,st);
    proc myproc;
    int res;
    FOR(i,1,k){
        getline(cin,st);
        myproc=xuli(st);
        res=0;
        FOR(j,1,n) if(checkok(a[j],myproc)) res++;
        cout<<res<<endl;
    }
    //getch();
    return 0;
}
