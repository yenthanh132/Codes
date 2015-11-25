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

int main(){
    //freopen("test.txt","r",stdin);
    string s,ss,res2;
    double res1,f;
    bool ok;
    int t,i,j;
    getline(cin,s);
    while(s[0]!='?'){
        t=i=0;
        res1=0; res2=""; ok=true;
        while(i<s.length() && s[i]==' ') i++;
        while(i<s.length()){
            j=i;
            while(j<s.length()-1 && s[j+1]!=' ') j++;
            ss=s.substr(i,j-i+1);
            if(ss[0]=='-' || ('0'<=ss[0] && ss[0]<='9')){
                if(t==2){ok=false; break;}
                f=atof(ss.c_str());
                t=1; res1=res1+f;
            }else{
                if(t==1){ok=false; break;}
                t=2; res2=res2+ss;
            }
            i=j+1; while(i<s.length() && s[i]==' ') i++;
        }
        if(ok)
            if(t==1) printf("%0.6f\n",res1); else printf("%s\n",res2.c_str());
        else printf("Error!\n");
        
        getline(cin,s);
    }
    
    return 0;
}
