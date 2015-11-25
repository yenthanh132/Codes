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

string s;
vector<int> a;

ll ans(int s, int f){
    if(s>=f) return 1;
    stack<int> mys;
    int res,posmid=-1,cnt=0;
    FOR(i,s,f) if(a[i]==1) mys.push(i);
    else if(a[i]==2 && sz(mys)==1){
        posmid=i;
    }else if(a[i]==3){
        if(sz(mys)==1) cnt++;
        mys.pop();
    }
    if(cnt>1){
        res=1;
        FOR(i,s,f) if(a[i]==1) mys.push(i);
        else if(a[i]==3){
            if(sz(mys)==1) res*=ans(mys.top(),i);
            mys.pop();
        }
        return res;
    }else{
        if(posmid!=-1) return ans(s+1,posmid-1)+ans(posmid+1,f-1);
        else return ans(s+1,f-1)+1;
    }
}           

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>s;
    while(s!="ENDPROGRAM"){
        if(s=="IF") a.pb(1);
        else if(s=="ELSE") a.pb(2);
        else if(s=="END_IF") a.pb(3);
        cin>>s;
    }
    cout<<ans(0,sz(a)-1)<<endl;   
    //getch();
    return 0; 
}
            
    
