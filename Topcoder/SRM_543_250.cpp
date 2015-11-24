#include <string>
#include <cmath>

using namespace std;

struct EllysTSP{
    
    int getMax(string places){
        int v=0,c=0;
        for(int i=0;i<places.size();i++) if (places[i]=='V') v++; else c++;
        return (min(v,c)*2+1);
    };
};

