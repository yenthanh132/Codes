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

const int maxn=107;

int a[maxn],n,s;

int count(int v){
    int res=0;
    while(v>0){
        res++;
        v/=10;   
    }
    return res;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    int tt=0;
    while(n){
        FORD(i,n,0) cin>>a[i];
        cin>>s;
        int res=1,res2;
        res2=((s==1 || n%2==0)?1:-1)*a[n];
        FORD(i,n-1,1){
            if(a[i]!=0) res+=2+count(a[i])+1;  
            else res+=2;
            res2+=((s==1 || i%2==0)?1:-1)*a[i];      
        }
        if(a[0]!=0){
            res+=count(a[0])+1;
            res2+=a[0];
        }
        printf("Polynomial %d: %d %d\n",++tt,res2,res+1);
        cin>>n;
    }
    //getch();
    return 0;
}
    
