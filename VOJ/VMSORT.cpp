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

int k,n,res;
string s;
map<string,bool> namemap;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>k;
    res=0;
    FOR(i,1,k){
        cin>>n;
        FOR(j,1,n){
            cin>>s;
            if(namemap[s]==0){
                res++;
                namemap[s]=1;
            }
        }
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
