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

string s[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool compare(string s, string t){
    if(sz(s)!=sz(t)) return 0;
    for(int i=0; i<sz(s); ++i) if(s[i]!='.' && t[i]!='.' && s[i]!=t[i]) return 0;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    string t;
    int n;
    cin>>n>>t;
    for(int i=0; i<8; ++i) if(compare(t,s[i])){
        cout<<s[i]<<endl;
        return 0;
    }
    return 0;
}
