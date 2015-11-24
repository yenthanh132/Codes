#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct BedroomFloor{
    long numberOfSticks(int x1, int y1, int x2, int y2){
        int p[6]; fill_n(p,6,0);
        
