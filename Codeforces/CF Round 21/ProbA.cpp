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

bool okc(char ch){
    return ('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z') || ('0'<=ch && ch<='9') || ch=='_';
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    bool ok=1;
    string s,st;
    getline(cin,s);
    if(s.find("@")==string::npos) ok=0;
    else{
        st=s.substr(0,s.find("@"));
        s.erase(0,s.find("@")+1);
        if(sz(st)==0 || sz(st)>16) ok=0;
        else REP(i,sz(st)) if(!okc(st[i])) ok=0;
    }
    if(s.find("/")!=string::npos){
        st=s.substr(0,s.find("/"));
        s.erase(0,s.find("/")+1);
        if(sz(s)==0) ok=0;
    }else{
        st=s;
        s="";
    }
    int c=0;
    bool dot=0;
    if(sz(st)==0 || sz(st)>32) ok=0;
    REP(i,sz(st)) 
        if(okc(st[i])){
            c++;
            if(c>16) ok=0;
        }
        else if(st[i]=='.'){
            if(c==0) ok=0;
            c=0, dot=1;
        }else ok=0;
    if(c==0) ok=0;
    if(sz(s)>16) ok=0;
    else REP(i,sz(s)) if(!okc(s[i])) ok=0;
    if(ok) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    //getch();
    return 0;
}
