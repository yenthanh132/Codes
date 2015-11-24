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

const int maxn=1000007;

int n,m;
char s[maxn],st[30];
char key[256];
bool mark[26];
string des,tmp,org;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        scanf("%s%s",s+1,st);
        REP(j,26) key[st[j]]=j+'a';
        reset(mark,1);
        org="";
        FOR(i,1,n) if(mark[s[i]-'a']){
            org+=s[i];
            mark[s[i]-'a']=0;
        }
        m=sz(org);
        des=org;
        tmp=des; REP(i,m) tmp[i]=key[tmp[i]];
        while(tmp!=org){
            if(tmp<des) des=tmp;
            REP(i,m) tmp[i]=key[tmp[i]];
        }        
        REP(j,m) key[org[j]]=des[j];
        FOR(i,1,n) s[i]=key[s[i]];
        puts(s+1);
    }
    //getch();
    return 0;
}
