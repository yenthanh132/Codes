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

string m,s;
int t;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t>>m;
    REP(index,t){
        cin>>s;
        REP(j,sz(s)){
            if(s[j]=='_') cout<<' ';
            else if(s[j]=='.' || s[j]==',' || s[j]=='?' || s[j]=='!') cout<<s[j];
            else if(s[j]>='a') printf("%c",m[s[j]-'a']);
            else printf("%c",m[s[j]-'A']-'a'+'A');
        }
        cout<<endl;
    }
    return 0;
}
                
