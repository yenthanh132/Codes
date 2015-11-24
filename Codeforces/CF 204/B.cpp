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

const int maxn=3007;

int n,a[maxn];

/*
double res;


void duyet(double v, int m){
    bool ok=1;
    FOR(i,1,n) if(a[i]!=i) ok=0;
    if(ok){
        res+=v*(m-1);
        return;   
    }
    if(m>32) return;
    if(m&1){
        FOR(i,1,n-1){
            swap(a[i],a[i+1]);
            duyet(v/(n-1),m+1);
            swap(a[i],a[i+1]);
        }   
    }else{
        int c1,c2=0;
        FOR(i,1,n-1)
            if(a[i]>a[i+1]) c1++;
            else c2++;
        if(c2==0){
            FOR(i,1,n-1){
                swap(a[i],a[i+1]);
                duyet(v/(n-1),m+1);
                swap(a[i],a[i+1]); 
            }
        }else{
            FOR(i,1,n-1){
                swap(a[i],a[i+1]);
                if(a[i+1]>a[i]) duyet(0.5*v/c1,m+1);
                else duyet(0.5*v/c2,m+1);
                swap(a[i],a[i+1]);   
            }
        }
    }
}*/

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int c=0;
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1) FOR(j,i+1,n) if(a[i]>a[j]) c++;
    if(c&1) cout<<max(c*2-1,0)<<".000000"<<endl;
    else cout<<max(c,0)<<".000000"<<endl;
    //getch();
    return 0;
}
    
