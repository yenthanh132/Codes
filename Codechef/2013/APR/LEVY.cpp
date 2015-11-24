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

bool isprime(int n){
    if(n==2 || n==3) return 1;
    if(n<2 || n%2==0 || n%3==0) return 0;
    int k=0,sn=int(sqrt(n));
    do{
        k+=6;
        if(n%(k-1)==0 || n%(k+1)==0) break;
    }while(k-1<=sn);
    return k-1>sn;
}

int ans[10007],t,n,c,list[10007];

int main(){
    list[c=1]=2;
    for(int i=3; i<=10000; i+=2) if(isprime(i)) list[++c]=i;
    for(int i=6; i<=10000; i++){
        int x=1, y=c;
        while(x<=c){
            while(y>0 && list[x]+2*list[y]>i) y--;
            if(y==0) break;
            if(list[x]+2*list[y]==i) ans[i]++;
            x++;
        }
    }
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
        
