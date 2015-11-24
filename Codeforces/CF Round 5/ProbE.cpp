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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1000007;

#include <conio.h>
int main(){
    int n, maxv, pos, a[maxn], b[maxn],l[maxn],r[maxn],equalr[maxn];
    ll res;
    stack<int> mystack;
    //freopen("Test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) if(maxv<a[i]) maxv=a[i], pos=i;
    FOR(i,1,n) if(pos+i-1<=n) b[i]=a[pos+i-1]; else b[i]=a[pos+i-1-n];
    
    mystack=stack<int>(); b[0]=oo; mystack.push(0);
    FOR(i,1,n){
        while(b[mystack.top()]<=b[i]) mystack.pop();
        l[i]=mystack.top();
        mystack.push(i);
    }
    mystack=stack<int>(); b[n+1]=b[1]; mystack.push(n+1);
    FORD(i,n,1){
        while(b[mystack.top()]<b[i]) mystack.pop();
        r[i]=mystack.top();
        mystack.push(i);
        equalr[i]=0;
        if(b[i]==b[r[i]]){
            equalr[i]=equalr[r[i]]+1;
            r[i]=r[r[i]];
        }
    }
    
    res=0;
    FOR(i,1,n){
        if(b[i]==maxv) res+=equalr[i]-1; else res+=equalr[i];
        if(b[i]!=maxv)
            if(l[i]!=1 || r[i]!=n+1) res+=2; else res+=1;
    }        
    
    printf("%I64d\n",res);
    //getch();
    return 0;
}
    
