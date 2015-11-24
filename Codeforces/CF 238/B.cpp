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

int n;
bool mark[3007];
char a[3007];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    scanf("%s",a+1);
    reset(mark,1);
    mark[0]=0;
    FOR(i,1,n) if(a[i]=='L'){
        int j=i-1;
        while(mark[j] && a[j]!='R') --j;
        if(mark[j]){
            FOR(x,j,i) mark[x]=0;
            if((j-i+1)&1) mark[(i+j)/2]=1;   
        }else FOR(x,1,i) mark[x]=0;
    }
    FORD(i,n,1){
        if(!mark[i]) break;
        if(a[i]=='R'){
            FOR(j,i,n) mark[j]=0;
            break;   
        }
    }
    int res=0;
    FOR(i,1,n) res+=mark[i];
    
    cout<<res<<endl;
    
    return 0;
}
