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

const int maxn = 400007;

int n,a[maxn],w;
deque<int> minl,maxl;

//#include <conio.h>
int main(){
    scanf("%d%d",&n,&w);
    FOR(i,1,n)scanf("%d",a+i);
    FOR(i,1,w-1){
        while(!minl.empty() && a[minl.back()]>=a[i]) minl.pop_back();
        while(!maxl.empty() && a[maxl.back()]<=a[i]) maxl.pop_back();
        minl.push_back(i); maxl.push_back(i);
    }
    int res=0;
    FOR(i,w,n){        
        while(!minl.empty() && i-minl.front()>=w) minl.pop_front();
        while(!maxl.empty() && i-maxl.front()>=w) maxl.pop_front();
        while(!minl.empty() && a[minl.back()]>=a[i]) minl.pop_back();
        while(!maxl.empty() && a[maxl.back()]<=a[i]) maxl.pop_back();
        minl.push_back(i); maxl.push_back(i);
        if(a[maxl.front()]-a[minl.front()]+1==w) res++;
    }
    printf("%d\n",res);
    //getch();
    return 0;
}
