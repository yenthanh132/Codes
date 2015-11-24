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
int d,m,y,a[5],p[5],l[5];
bool ok;

int daymonth(int m,int y){
    if(m==2) if(y%4==0) return 29; else return 28;
    else return dayinmonth[m];
}

void check(){
    if(l[2]>12 || l[2]<1) return;
    if(l[1]<1 || l[1]>daymonth(l[2],l[3])) return;
    if(y-l[3]>18) ok=1;
    else if(y-l[3]==18){
        if(m>l[2]) ok=1;
        else if(m==l[2]) ok=(d>=l[1]);
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s;
    cin>>s;
    d=(s[0]-'0')*10+s[1]-'0';
    m=(s[3]-'0')*10+s[4]-'0';
    y=(s[6]-'0')*10+s[7]-'0';
    cin>>s;
    a[1]=(s[0]-'0')*10+s[1]-'0';
    a[2]=(s[3]-'0')*10+s[4]-'0';
    a[3]=(s[6]-'0')*10+s[7]-'0';
    FOR(i,1,3) p[i]=i;
    ok=0;
    do{
        FOR(i,1,3) l[i]=a[p[i]];
        check();
    }while(next_permutation(p+1,p+4));
    if(ok) puts("YES"); else puts("NO");
    //getch();
    return 0;
}
