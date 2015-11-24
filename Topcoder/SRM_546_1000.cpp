#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define reset(a,b) memset(a,b,sizeof(a))

using namespace std;

class FavouriteDigits {
public:
	long long findNext(long long, int, int, int, int);
};

long long getnum(string s, int n, int pos, int digit1, int count1, int digit2, int count2){
    if(s[pos]=='9') return -1;
    if (digit1>digit2) swap(digit1,digit2), swap(count1,count2);
    FOR(i,0,pos-1) if(int(s[i])-48==digit1) count1--; else if(int(s[i])-48==digit2) count2--;
    if(pos>0 && digit1==0) count1++;
    count1=max(count1,0); count2=max(count2,0);
    //cout<<pos<<" "<<count1<<" "<<count2<<endl;
    if(pos<n){
        if(n-pos==count1+count2){
            if(count1>0 && int(s[pos])-48<digit1) s[pos]=char(digit1+48);
            else if(count2>0 && int(s[pos])-48<digit2) s[pos]=char(digit2+48);
            else return -1;
        }else s[pos]++;
        if(int(s[pos])-48==digit1) count1--; else if(int(s[pos])-48==digit2) count2--;
    }
  
    FORD(i,n-1,pos+1){
        if (count2>0) s[i]=char(digit2+48), count2--; 
        else if(count1>0) s[i]=char(digit1+48), count1--;
        else s[i]='0';
    }
    //cout<<pos<<" "<<s<<" "<<digit1<<" "<<count1<<" "<<digit2<<" "<<count2<<endl;
    if(count1>0 || count2>0) return -1;
    long long res=0;
    FOR(i,0,n-1) res=res*10+int(s[i])-48;
    return res;
    
}
    

long long FavouriteDigits::findNext(long long N, int digit1, int count1, int digit2, int count2) {
	stringstream ss;
	ss<<N;
	string s=ss.str();
	int n=s.length();
	if(count1+count2>n){
        long long res=0;
        if(digit1>digit2) swap(digit1,digit2), swap(count1,count2);
        if(digit1==0)
            if(count2>0) res=res*10+digit2, count2--;
            else res=res*10+1;
        REP(i,count1) res=res*10+digit1;
        REP(i,count2) res=res*10+digit2;
        return res;
    }else{
        long long res=-1;
        s='0'+s;
        n++;
        FOR(i,0,n){
            long long t=getnum(s,n,i,digit1,count1,digit2,count2);
            if(t!=-1)
                if(res==-1 || res>t) res=t;
        }
        if(res!=-1) return res;
    }   
}
