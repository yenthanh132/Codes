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

int a[107],b[107];
int n;

bool check(){
    int s1=0,s2=0;
    FOR(i,1,n){
        s1+=a[i];
        s2+=b[i];
    }
    return s1%2==0 && s2%2==0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i]>>b[i];
    if(check()) puts("0");
    else{
        bool ok=0;
        FOR(i,1,n){
            swap(a[i],b[i]);
            if(check()){
                ok=1;
                break;
            }
            swap(a[i],b[i]);   
        }   
        if(ok) puts("1");
        else puts("-1");
    }
    //getch();
}
