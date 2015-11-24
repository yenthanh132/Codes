#include <cmath>
#include <iostream>
#include <conio.h>

using namespace std;

int count(int v){
    int i,res=0;
    i=2;
    while (i*2<=v){
        if (v % i == 0) while (v % i == 0) {v/=i; res++;}
        i++;
    }
    if (v>1) res++;
    return res;
}

bool isprime(int v){
    if (v==2 || v==3) return true;
    if (v<2 || v%2==0 || v%3==0) return false;
    int sqrt_n=int(sqrt(v)),k=0;
    do{
        k+=6;
        if (v%(k-1)==0 || v%(k+1)==0) break;
    }while (k-1>sqrt_n);
    return (k-1>sqrt_n);
}   

struct Underprimes{
    int howMany(int A, int B){
        int res=0;
        for(int i=A;i<=B;i++) if (isprime(count(i))) res++;
        return res;
    }
};
        
