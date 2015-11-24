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

const int maxn=607;
const int n=4;
vector<string> list, list2[maxn];

bool check(string a, string b){
    string c=a;
    FOR(i,1,n){
        if(c==b) return 0;
        c=c+c[0];
        c.erase(0,1);   
    }   
    c=a;
    reverse(c.begin(),c.end());
    FOR(i,1,n){
        if(c==b) return 0;
        c=c+c[0];
        c.erase(0,1);   
    }   
    return 1;
}

bool ok(string s){
    REP(i,sz(list)) if(!check(list[i],s)){
        return 0;
        list2[i].pb(s);
    }
    return 1;   
}

#include <conio.h>
int main(){
    string s;
    REP(a,3){
        
        REP(b,3){
            
            REP(c,3){

                REP(d,3){
                    s=a+'a';
                    s+=b+'a';
                    s+=c+'a';
                    s+=d+'a';
                    if(ok(s)) list.pb(s);   
                }
            }
        }
    }
    cout<<sz(list)<<endl;
    REP(i,sz(list)){
        cout<<list[i]<<": ";
        REP(j,sz(list2[i])) cout<<list2[i][j]<<' ';
        cout<<endl;
    }
    
    getch();
}
