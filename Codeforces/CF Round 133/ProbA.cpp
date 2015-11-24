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

int cal(int a, int b, int c){
    if(a==1 && b==1) return c;
    if(a==0) return 0;
    if(a==1 && b>2) return (a+b+c-3)*2+cal(1,b-2,c-2);
    else return (a+b+c-3)*2+cal(a-1,b-1,c-1);
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b) swap(a,b);
    if(a>c) swap(a,c);
    if(b>c) swap(b,c);
    cout<<cal(a,b,c)<<endl;
    
    //system("pause");
    return 0;
}
