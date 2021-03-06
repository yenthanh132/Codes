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

#include <conio.h>



int main(){
    int t,n;
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d",&n);
        string s="",st;
        int v=n;
        while(sz(s)<=6 && v){
            int t=v;  
            st="";          
            while(t){
                st+=char(t%10);
                t/=10;
            }
            s+=st;
            v--;
        }
        double x=0,mul=1;
        REP(i,sz(s)){
            x+=mul*s[i];
            mul=mul/10;
        }
        printf("%0.6lf\n",x*0.45);
    }
    getch();
}
