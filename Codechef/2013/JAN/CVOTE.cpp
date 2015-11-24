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

map<string,int> vote, vote2;
int n,m,best;
string s;
map<string,string> country;
char buf[20],buf2[20];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%s%s",buf,buf2);
        country[string(buf)]=string(buf2);
    }
    FOR(i,1,m){
        scanf("%s",buf);
        vote[string(buf)]++;
        vote2[country[string(buf)]]++;
    }
    best=0;
    for(map<string,int>::iterator it=vote2.begin(); it!=vote2.end(); it++)
        if(it->se > best || (it->se == best && it->fi < s)){
            best=it->se;
            s=it->fi;
        }
    cout<<s<<endl;
    
    best=0;
    for(map<string,int>::iterator it=vote.begin(); it!=vote.end(); it++)
        if(it->se > best || (it->se == best && it->fi < s)){
            best=it->se;
            s=it->fi;
        }
    cout<<s<<endl;
    
    return 0;
}
