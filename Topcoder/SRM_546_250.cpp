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
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define sz(a) int(a.size())

using namespace std;

class ContestWinner {
public:
	int getWinner(vector <int>);
};

int ContestWinner::getWinner(vector <int> events) {
	int n=sz(events);
	int res=0,max=0;
	map<int,int> mymap;
	REP(i,n){
        mymap[events[i]]++;
	    if(max<mymap[events[i]]) max=mymap[events[i]], res=events[i];
    }
	return res;
}
