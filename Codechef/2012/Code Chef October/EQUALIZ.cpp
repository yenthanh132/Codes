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
vector< vector<int> > list;

bool isprime(int n){
    if(n==2 || n==3) return 1;
    if(n<2 || n%2==0 || n%3==0) return 0;
    int sn=int(sqrt(n)), k=0;
    do{
        k+=6;
        if(n%(k-1)==0 || n%(k+1)==0) break;
    }while(k-1<=sn);
    return (k-1>sn);
}

void getoutput(int start, int n){
    if(n==1) return;
    FORD(i,n,2) if(isprime(i) && n%i==0){
        REP(k,i) getoutput(k*(n/i)+start,n/i);
        FOR(j,1,n/i){
            vector<int> a; a.pb(i);
            REP(k,i) a.pb(k*(n/i)+start+j-1);
            list.pb(a);
        }
        break;
    }
}

void output(){
    printf("%d\n",sz(list));
    REP(i,sz(list)){
        vector<int> a=list[i];
        REP(j,sz(a)-1) printf("%d ",a[j]);
        printf("%d\n",a.back());
    }
}

int main(){
//    freopen("test.txt","r",stdin);
    int t,n;
    cin>>t;
    REP(index,t){
        int v;
        cin>>n; 
        FOR(i,1,n) cin>>v;
        list.clear();
        getoutput(1,n);
        output();
    }
    return 0;
}
        
