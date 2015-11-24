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

string text, crib;
int test,n,s,m;

string shift(string txt, int s){
    REP(i,sz(txt)) txt[i]=(txt[i]-'A'-s+26)%26+'A';
    return txt;   
}

bool check(int s, int m){
    string txt=shift(text,s);
    string txt2="",st;
    while(sz(txt)>m){
        st=txt.substr(0,m);
        txt.erase(0,m);
        reverse(st.begin(),st.end());
        txt2+=st;
    }
    reverse(txt.begin(),txt.end());
    txt2+=txt;
    return txt2.find(crib)!=-1;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>test;
    REP(tt,test){
        cin>>n;    
        text="";
        string st;
        while(n>0){
            cin>>st;
            text+=st;
            n-=sz(st);
        }
        cin>>crib;
        
        s=-1;
        FOR(x,1,25){
            if(s!=-1) break;
            FOR(y,5,20) if(check(x,y)){
                s=x;
                m=y;
                break;
            }
        }
        if(s!=-1) cout<<s<<' '<<m<<endl;
        else cout<<"Crib is not encrypted."<<endl;
    }
    
    //getch();
    return 0;
}
