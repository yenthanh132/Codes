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

void printbuf(char ch, int n){
    REP(i,n) printf("%c",ch);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    vector<string> s;
    int maxlen=0;
    bool left=true;
    string st;
    while(getline(cin,st)){
        s.pb(st);
        maxlen=max(maxlen,int(st.length()));
    }
    printbuf('*',maxlen+2); printf("\n");
    REP(i,sz(s)){
        int len=s[i].length(),l,r;
        l=(maxlen-len)/2; r=maxlen-len-l;
        if(l!=r && !s.empty())
            if(left) left=0;
            else{
                left=1;
                l++; r--;
            }
        printf("*"); printbuf(' ',l); printf("%s",s[i].c_str()); printbuf(' ',r); printf("*\n");
    }
    printbuf('*',maxlen+2);
    //getch();
    return 0;
}
        
