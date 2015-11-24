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

int n,v;
char a[maxn];

#include <conio.h>
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    int i,j,res=0;
    i=1;
    bool doub;
    while(i<=n){
        while(i<=n && a[i]=='0') i++;
        if(i>n) break;
        j=i;
        if(i<n && a[i+1]=='1') doub=1; else doub=0;
        while(1){
            if(j<n && a[j+1]=='1'){
                j++;
            }else if(doub && j+2<=n && a[j+2]=='1'){
                j+=2;
            }else break;
        }
        int c=0;
        FOR(x,i,j) if(a[x]=='0') c++;
        if(i==j) res++;
        else res+=2 + c;
        i=j+1;
    }
    cout<<res<<endl;
    //getch();
}
        
