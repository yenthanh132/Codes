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

int main(){
    int m,n;
    cin>>m>>n; 
    if(n>(m+1)*2 || n<m-1) puts("-1");
    else{
        if(n<m){
            printf("0");
            m--;   
        }
        while(m || n){
            if(n>m && n>1){
                printf("11");
                n-=2;
            }else{
                printf("1");
                n--;   
            }   
            if(m>0){
                printf("0");
                m--;   
            }
        }
    }
    //cout<<endl;
   // system("pause");
}
