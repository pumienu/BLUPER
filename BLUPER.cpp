#include <iostream>
#include <vector>
using namespace std;

class Exp{
	private:
	    int n;
	    vector <int> s;
	public:
	    Exp(int N) : n(N), s(N + 1, 0) {}
	    void solve(int S) {
	        int sum = n * (n + 1)/2;
	        for (int i = n; i >= 1; --i){
	            if (sum - 2 * i >= S){
	                s[i] = 1;
	                sum -= 2 * i;
	            }
	        }
	        if (sum == S) {
	            if (s[1]) {
	                for (int i = 4; i <= n; ++i) {
	                    if (!s[1]) break;
	                    if (s[i]) {
	                        for (int j = 2; j <= i / 2; ++j) {
	                            if (s[j] == 0 && s[i + 1 - j] == 0) {
	                                s[j] = s[i + 1 - j] = 1;
	                                s[1] = s[i] = 0;
	                                break;
	                            }
	                        }
	                    }
	                }
	                if (s[1]) {
	                    cout << "Impossible" << endl;
	                    return;
	                }
	            }
	            cout << "1";
	            for (int i = 2; i <= n; ++i) {
	                cout << (s[i] == 1 ? '-' : '+') << i;
	            }
	        } else {
	            cout << "Impossible" << endl;
	        }
	    }
};
int main() {
    int N, S;
    cin >> N >> S;
    Exp exp(N);
    exp.solve(S);
    return 0;
}
