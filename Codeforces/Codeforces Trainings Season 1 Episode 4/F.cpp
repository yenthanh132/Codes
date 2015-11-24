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
const int maxn=57;

string s1[maxn],s2[maxn],s3[maxn];
vector<string> l1,l2;
map<pss,string> data;
int n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    cin>>T;
    REP(tt,T){
        cin>>n;
        l1.clear(); l2.clear();
        data.clear();
        FOR(i,1,n){
            cin>>s1[i]>>s2[i]>>s3[i];
            l1.pb(s1[i]); l2.pb(s2[i]);
            data[pss(s1[i],s2[i])]=s3[i];
        }
        sort(l1.begin(),l1.end()); sort(l2.begin(),l2.end());
        l1.resize(unique(l1.begin(),l1.end())-l1.begin());
        l2.resize(unique(l2.begin(),l2.end())-l2.begin());
        REP(j,sz(l2)+1) cout<<"+---"; cout<<"+"<<endl;
        cout<<"|   "; 
        REP(j,sz(l2)){
            cout<<"|";
            cout<<l2[j];
            REP(z,3-sz(l2[j])) cout<<" ";
        };
        cout<<"|"<<endl;
        REP(i,sz(l1)){
            REP(j,sz(l2)+1) cout<<"+---"; cout<<"+"<<endl;
            cout<<"|"; 
            cout<<l1[i];
            REP(z,3-sz(l1[i])) cout<<" ";
            REP(j,sz(l2)){
                cout<<"|";
                string st="";
                if(data.find(pss(l1[i],l2[j]))!=data.end()) st=data[pss(l1[i],l2[j])];
                cout<<st;
                REP(z,3-sz(st)) cout<<" ";
            };
            cout<<"|"<<endl;
        }
        REP(j,sz(l2)+1) cout<<"+---"; cout<<"+"<<endl;
    }
            
    //getch();
    return 0;   
}
