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
typedef pair<string,string> pss;
typedef pair<string,pss> psss;

const int maxn = 60;

int n;
string a[maxn];
set<psss> list[maxn];

bool match(string &s1, string &s2){return(s1[0]==s2[0] || s1[1]==s2[1]);}

psss mp(string &s1, string &s2, string &s3){
    return psss(s1,pss(s2,s3));
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    if(n==1 || (n==2 && match(a[1],a[2])) || (n==3 && match(a[1],a[3]) && match(a[2],a[3]))){cout<<"YES"; return 0;}
    if(n<4){ cout<<"NO"; return 0; }
    list[n-3].insert(mp(a[n-2],a[n-1],a[n]));
    string s1,s2,s3;
    set<psss>::iterator it;
    psss t;
    FORD(i,n-3,1)
        for(it=list[i].begin(); it!=list[i].end(); it++){
            t=*it; s1=t.fi; s2=t.se.fi; s3=t.se.se;
            if(s3=="  "){
                t.fi=a[i]; t.se.fi=s1; t.se.se=s2;
                if(list[i-1].find(t)==list[i-1].end()) list[i-1].insert(t);
                continue;
            }
            if(match(a[i],s3)){
                t.fi=s3; t.se.fi=s1; t.se.se=s2;
                if(list[i-1].find(t)==list[i-1].end()) list[i-1].insert(t);
            }
            if(match(s2,s3)){
                t.fi=a[i]; t.se.fi=s1; t.se.se=s3;
                if(list[i-1].find(t)==list[i-1].end()) list[i-1].insert(t);
            }
        }
    for(it=list[0].begin(); it!=list[0].end(); it++){
        t=*it; s1=t.fi; s2=t.se.fi; s3=t.se.se;
        if(match(s1,s3) && match(s2,s3)){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    //getch();
    return 0;
}
            
    
