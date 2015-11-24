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
typedef pair<int, pii> iii;
const int maxn=36;

map<string,int> cstr;
bool firstwin;
map<string,iii> save;

int getpoint(string s){
    int maxv=0,sumv=0;
    REP(i,sz(s)){
        sumv+=s[i]-'a'+1;
        maxv=max(maxv,s[i]-'a'+1);
    }
    return sumv*maxv+cstr[s];
}

void update(bool &win, int &a, int &b, bool win0, int a0, int b0){
    if(win<win0){
        win=win0;
        a=a0;
        b=b0;
    }else if(win==win0 && a<a0){
        a=a0;
        b=b0;
    }else if(win==win0 && a==a0 && b>b0) b=b0;
}

void dfs(string s, bool &win, int &a, int &b){
    if(save.count(s)){
        win=save[s].fi;
        a=save[s].se.fi;
        b=save[s].se.se;
        return;
    }
    bool win0;
    int a0,b0;
    a=b=win=0;
    string st;
    REP(k,26){
        st=char(k+'a')+s;
        if(cstr.find(st)!=cstr.end()){
            dfs(st,win0,a0,b0);
            update(win,a,b,1^win0,b0+getpoint(st),a0);
        }
        st=s+char(k+'a');
        if(cstr.find(st)!=cstr.end()){
            dfs(st,win0,a0,b0);
            update(win,a,b,1^win0,b0+getpoint(st),a0);
        }
    }
    save[s]=iii(win,pii(a,b));
}
    

int n;

#include <conio.h>
int main(){
    string s;
    
    //freopen("test.txt","r",stdin);
    cin>>n;
    set<string> mys;
    REP(i,n){
        cin>>s;
        mys.clear();
        REP(i,sz(s)) FOR(j,1,sz(s)-i) mys.insert(s.substr(i,j));
        for(set<string>::iterator it=mys.begin(); it!=mys.end(); ++it)
            cstr[*it]++;
            
    }
    bool win;
    int a,b;
    dfs("",win,a,b);
    if(win) puts("First"); else puts("Second");
    printf("%d %d\n",a,b);
    
    //getch();
    return 0;
}
    
    
    
