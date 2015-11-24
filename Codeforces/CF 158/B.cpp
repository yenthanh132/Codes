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

const int dayinmonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int num(string s){
    int res=0;
    REP(i,sz(s)) if(s[i]<'0' || s[i]>'9') return -1; else res=res*10+s[i]-'0';
    return res;
}

bool correct(string s){
    if(s[2]!='-' || s[5]!='-') return 0;
    int day=num(s.substr(0,2));
    int month=num(s.substr(3,2));
    int year=num(s.substr(6,4));
    if(day==-1 || month==-1 || year==-1 || year<2013 || year>2015 || month<1 || month>12 || day<1 || day>dayinmonth[month]) return 0;
    return 1;
}

map<string,int> mm;
char s[100007];
int n;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%s",s+1);
    n=strlen(s+1);
    string st;
    FOR(i,1,n-9){
        st=string(s+i,s+i+10);
        if(correct(st)) mm[st]++;
    }
    string res;
    int best=0;
    for(map<string,int>::iterator it=mm.begin(); it!=mm.end(); it++)
        if(best<it->se){
            best=it->se;
            res=it->fi;
        }
    cout<<res<<endl;
    //getch();
    return 0;
}
