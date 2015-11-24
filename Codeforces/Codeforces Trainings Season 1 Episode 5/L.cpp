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

int n,m,a[100];
string name,party[100];
map<string,int> mid;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    getline(cin,name);
    FOR(i,1,n){
        getline(cin,name);
        mid[name]=i;
        getline(cin,party[i]);
    }
    cin>>m;getline(cin,name);
    reset(a,0);
    FOR(j,1,m){
        getline(cin,name);
        a[mid[name]]++;
    }
    int maxv=a[1];
    FOR(i,2,n) maxv=max(maxv,a[i]);
    int c=0,u;
    FOR(i,1,n) if(maxv==a[i]){
        c++;
        u=i;
    }
    if(c>1){
        puts("tie");
    }else cout<<party[u]<<endl;
    
    //getch();
    return 0;
}
