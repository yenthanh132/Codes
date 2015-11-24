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

struct SimilarRatingGraph {

    int n;
    vector<int> x,y;

    bool songsong(int i, int j){
        return  1ll*(x[i+1]-x[i])*(y[j+1]-y[j]) == 1ll*(x[j+1]-x[j])*(y[i+1]-y[i]);
    }

    double len(int i){
        return hypot(x[i+1]-x[i],y[i+1]-y[i]);
    }

    bool equal(double a, double b){
        return abs(a-b)<1e-12;
    }

    double cal(int s0){
        double l1=0,l2=0;
        double res=0;
        for(int t0=s0+1; t0<n-1; ++t0)
            if(songsong(s0,t0)){
                ll vx1 = x[s0+1]-x[s0], vy1=y[s0+1]-y[s0];
                ll vx2 = x[t0+1]-x[t0], vy2=y[t0+1]-y[t0];
                l1=len(s0); l2=len(t0);
                for(int j=1; s0+j<n-1 && t0+j<n-1; ++j)
                    if(songsong(s0+j,t0+j) && vx1*(x[t0+j+1]-x[t0+j])==vx2*(x[s0+j+1]-x[s0+j]) && vy1*(y[t0+j+1]-y[t0+j])==vy2*(y[s0+j+1]-y[s0+j])){
                        l1+=len(s0+j);
                        l2+=len(t0+j);
                    }
                    else break;
                res=max(res,max(l1,l2));
            }
        return res;
    }

    double maxLength( vector <int> xx, vector <int> yy ) {
        x=xx; y=yy;
        n=sz(x);
        double res=0;
        for(int i=0; i<n-1; ++i) res=max(res,cal(i));
        return res;
    }

};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}

	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}

	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
		} else {
			verdict = "FAILED";
		}

		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;

		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl;
			std::cerr << "    Received: " << received << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int date[]                = {3, 4, 5, 450006, 900006};

			int rating[]              =  {15, 15, 15, 15, 15};
			double expected__         = 42.42640687119285;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int date[]                = {81,104,120,124,134,137};
			int rating[]              = {1866,2332,2510,2678,2876,3002};
			double expected__         = 168.04761230080004;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int date[]                = {10,11,13,15,19};
			int rating[]              = {10,14,15,23,25};
			double expected__         = 12.7183472062349;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int date[]                = {1,2,3,4};
			int rating[]              = {1700,1800,1750,1850};
			double expected__         = 100.00499987500625;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int date[]                = {1,2,3,4};
			int rating[]              = {1,4,9,16};
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int date[]                = {5,11,25,58,92,162,255,350,458,566,677,792,919,1051,1189,1331,1489,1673,1882,2093,2315,2541,2771,3012,3254,3524,3797,4087,4379,4675,4973,5278,5588,5904,6225,6550,6888,7249,7612,8018,8428,8847,9267,9688,10109,10530,10964,11407,11870,12340,12811,13288,13768,14249,14734,15242,15774,16306,16847,17400,17966,18533,19108,19692,20278,20871,21471,22074,22679,23297,23916,24553,25190,25829,26472,27135,27814,28497,29181,29865,30555,31272,31994,32729,33487,34246,35005,35764,36537,37326,38119,38913,39725,40538,41360,42185,43010,43840,44671,45509,46350,47205,48063,48932,49807,50691,51577,52464,53289,54119,54950,55788,56629,57484,58342,59211,60086,60970,61856,62743,63568,64398,65388};
			int rating[]              = {1505,1462,1436,1416,1463,1421,1411,1450,1497,1465,1423,1394,1391,1367,1358,1323,1310,1279,1268,1279,1311,1342,1359,1387,1414,1376,1424,1382,1373,1335,1359,1318,1275,1266,1227,1203,1168,1163,1184,1144,1169,1207,1250,1235,1209,1162,1124,1148,1168,1202,1190,1155,1179,1194,1195,1195,1203,1240,1218,1245,1220,1190,1208,1180,1182,1148,1139,1126,1152,1159,1147,1158,1112,1091,1101,1116,1123,1086,1126,1110,1128,1085,1132,1145,1135,1140,1117,1081,1120,1131,1081,1032,1071,1102,1071,1065,1068,1027,980,947,987,968,959,980,990,974,1003,996,999,958,911,878,918,899,890,911,921,905,934,927,930,889,844};
			double expected__         = 11940.179271014536;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int date[]                = ;
			int rating[]              = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int date[]                = ;
			int rating[]              = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int date[]                = ;
			int rating[]              = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = SimilarRatingGraph().maxLength(vector <int>(date, date + (sizeof date / sizeof date[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
