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
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define REPD(i,a) for(int i=(a)-1; i>=0; i--)
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

int test,k,n;
string s,st;
bool ok;

int round(int v){
    if(v<0) return n-1;
    else if(v>=n) return 0;
    else return v;    
}

void duyet(int root){
    ok=true;
    s=st;
    if(s[0]!='?' && s[0]!=char(root+48)){
        ok=false;
        return;
    }
    REP(j,n){
        if(s[j]!='?' && (s[round(j-1)]==s[j] || s[round(j+1)]==s[j])) { ok=false; break;}
        if(s[j]!='?') continue;
        int x;
        for(x=0; x<k; x++) if(j>0 || x==root) if(s[round(j-1)]!=char(x+48) && s[round(j+1)]!=char(x+48)) break;
        if(x==k){ok=false; break;}
        s[j]=char(x+48);
    }
}

int main(){
    //freopen("test.txt","r",stdin);
    
    scanf("%d\n",&test);
    REP(i,test){
        scanf("%d\n",&k);
        getline(cin,s);
        while(s.find(" ")!=string::npos) s.erase(s.find(" "),1);
        n=sz(s);
        ok=true;
        if(n==1){
            if (s[0]=='?' )cout<<0<<endl; else cout<<s<<endl;
            continue;
        }
        ok=false;
        st=s;
        REP(x,k){
            duyet(x);
            if(ok) break;
        }
        if (ok) cout<<s<<endl; else cout<<"NO"<<endl;
    }   

    return 0;
}         
