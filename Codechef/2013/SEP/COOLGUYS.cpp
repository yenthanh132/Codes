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

int count(int n){
    if(n==1) return 1;
    int res=1;
    for(int i=2; i*i<=n; ++i) if(n%i==0){
        int t=1;
        while(n%i==0){
            n/=i;
            t++;
        }
        res*=t;
    }
    if(n>1) res*=2;
    return res;
}
 
int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
} 
        
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int sum=0;
    FOR(i,1,100){
        sum+=count(i);
        cout<<i<<": "<<count(i)<<' '<<sum<<endl;
        //int v=gcd(sum,i*i);
        //cout<<sum/v<<"/"<<i*i/v<<endl;
    }
    getch();
    return 0;
}
