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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

#define maxn 100007
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s;
    getline(cin,s);
    while(s.find(" ")!=string::npos) s.erase(s.find(" "));
    int n=s.length();
    vector<int> a[26];
    REP(i,n) a[int(s[i]-'a')].pb(i);
    int pos=0;
    FORD(i,25,0) if(!a[i].empty()){
        int l=0, r=sz(a[i])-1, res=sz(a[i]),mid;
        while(l<=r){
            mid=(l+r)/2;
            if(pos<=a[i][mid]) res=mid, r=mid-1; else l=mid+1;
        }
        FOR(j,1,sz(a[i])-res) printf("%c",'a'+i);
        pos=max(pos,a[i][sz(a[i])-1]+1);
    }
    printf("\n");
    //getch();
    return 0;
}
    
        
        
        
