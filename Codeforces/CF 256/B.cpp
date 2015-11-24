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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int c[26],d[26];
string s1,s2;

int main(){
    //freopen("input.txt","r",stdin);
    reset(c,0); reset(d,0);
    cin>>s1>>s2;
    for(int i=0; i<sz(s1); ++i) ++c[s1[i]-'a'];
    for(int i=0; i<sz(s2); ++i) ++d[s2[i]-'a'];
    int state = 1;
    for(int i=0; i<26; ++i){
        if(d[i]<c[i]) state=0;
        else if(d[i]>c[i]){
            state=-1;
            break;
        }
    }
    if(state==1) puts("array");
    else if(state==-1) puts("need tree");
    else{
        int j=0;
        for(int i=0; i<sz(s1); ++i){
            if(j<sz(s2) && s2[j]==s1[i]) ++j;
        }
        if(j>=sz(s2)) puts("automaton");
        else puts("both");
    }
}
