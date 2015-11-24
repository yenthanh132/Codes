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
typedef pair<string, string> pss;

int T,n;
map<string,pss> m;
map<string,bool> degout;
vector<string> list;

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d\n",&T);
    string s1,s2,s3;
    int sum;
    REP(index,T){
        m.clear(); degout.clear(); list.clear(); sum=0;
        scanf("%d\n",&n);
        FOR(i,1,n-1){
            cin>>s1>>s2>>s3;
            //cout<<s1<<' '<<s2<<' '<<s3<<endl;
            m[s1]=pss(s2,s3);
            degout[s2]=1;
            list.pb(s1);
            s3.erase(sz(s3)-1,1);
            sum+=atoi(s3.c_str());
        }
        REP(i,n) if(degout[list[i]]==0){
            s1=list[i];
            break;
        }
        while(m.find(s1)!=m.end()){
            pss t=m[s1];
            printf("%s %s %s\n",s1.c_str(),t.fi.c_str(),t.se.c_str());
            s1=t.fi;
        }
        printf("%d$\n",sum);
    }
    getch();        
    return 0;
}
