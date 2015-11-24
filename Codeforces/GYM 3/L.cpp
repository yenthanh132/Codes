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

int f[100007];

int count(int v){
    int c=0;
    while(v){
        c+=v%2;
        v/=2;
    }
    return c;
}

int a[100],n;
ll C[100][100];
bool mark[100];

ll dfs(int x, int y){
    if(x<y || y<0) return 0;
    if(x==0 && y==0) return 1;
    if(a[x]==1)
        return C[x-1][y]+dfs(x-1,y-1);   
    else return dfs(x-1,y);       
}

ll dem(ll v, int num){
    ll t=v;
    n=0;
    while(t){
        a[++n]=t%2;
        t/=2;
    }
    if(n<num) return 0;
    return dfs(n,num); 
}

ll cal(ll v, int k){
    if(k==1){
        int c=0;
        ll t=1;
        while(t<=v){
            c++;
            t*=2;
        }
        return c;
    }
    ll res=0;
    reset(mark,0);
    FOR(i,1,60) if(f[i]==k-1 && !mark[i]){
        res+=dem(v,i);
        mark[i]=1;
    }
    return res;
}

void init(){
    C[0][0]=1;
    FOR(i,1,60){
        C[i][0]=1;
        FOR(j,1,i) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    f[1]=1;
    FOR(i,2,100000) f[i]=f[count(i)]+1;
}
           

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    init();
    ll a,b;
    int k;
    cin>>a>>b>>k;
    while(a!=0){
        k++;
        if(k==1){
            if(a==1) cout<<1<<endl;
            else cout<<0<<endl;
        }else{
            if(a==1) a++;
            cout<<cal(b,k)-cal(a-1,k)<<endl;
        }
        cin>>a>>b>>k;
    }
    //getch();
    return 0;
}
    
