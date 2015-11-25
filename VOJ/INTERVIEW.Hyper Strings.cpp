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

const int maxn=101;

map<ll,int> mymap[11];
map<ll,int>::iterator it;
string s[maxn];
int n,m,val[maxn],sub[11],add[11],f[maxn];
bool free1[maxn];
ll pow11[11];

void makemap(){
    FOR(i,1,10) mymap[i].clear();
    mymap[0][0]=1;
    FOR(len,1,10)
        FOR(i,1,n) if (free1[i] && s[i].length()<=len){
            int pos=len-s[i].length();
            for(it=mymap[pos].begin(); it!=mymap[pos].end(); it++) if(it->fi%11<s[i][0]-'a'+1)
                mymap[len][it->fi*pow11[s[i].length()]+val[i]]++;
        }
}

#include <conio.h>
int main(){
    pow11[0]=1; FOR(i,1,10) pow11[i]=pow11[i-1]*11;
    freopen("test.txt","r",stdin);
    cin>>n>>m;
    FOR(i,1,n){
        cin>>s[i];
        val[i]=0;
        REP(j,s[i].length()) val[i]=val[i]*11+s[i][j]-'a'+1;
    }
    reset(free1,true);
    makemap();
    FOR(i,1,n) if(mymap[s[i].length()][val[i]]>1) free1[i]=false;
    makemap();
    reset(add,0);
    FOR(i,1,n) if (free1[i]) add[s[i].length()]++;
    reset(sub,0);
    FOR(len,1,10)
        for(it=mymap[len].begin(); it!=mymap[len].end(); it++)
            sub[len]+=it->se-1;
    f[0]=1;
    FOR(i,1,m) FOR(j,1,10) if(i>=j) f[i]=(f[i]+(ll)f[i-j]*(add[j]-sub[j]))%oo;
    int res=0;
    FOR(i,0,m) res=(res+f[i])%oo;
    cout<<res<<endl;
    getch();
    return 0;
}
    
