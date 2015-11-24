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

char a[107];
int n;

#include <conio.h>
int main(){
    gets(a+1);
    n=strlen(a+1);
    ll res=1,p=1,num=0;       
    REP(i,n-1) res=res*2 %oo;
    FORD(i,n,1){
        if(a[i]=='1') num=(num+p)%oo;
        p=p*2%oo;
    }
    cout<<res*num%oo<<endl;
    //getch();
}

