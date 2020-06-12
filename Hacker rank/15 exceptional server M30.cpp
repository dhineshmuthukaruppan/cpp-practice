#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
        // vector<int> test; 
        // cout << test.max_size(); 
        // if(A > test.max_size()){
        //     cout << "Not enough Memory" << endl; 
        // }else{
            try{
                int answer; 
                answer = Server::compute(A, B); 
                cout << answer << endl; 
            }catch(exception &e){
                string temp = e.what();  
                if(temp.compare("std::bad_alloc") == 0){
                    cout << "Not enough memory" << endl;       
                }else{
                    cout << "Exception: " << e.what() << endl;
                }
                
            }catch(int &a){
                cout << "Other Exception" << endl;    
            }catch(...){
                cout << "Not enough memory" << endl;   
            }
        // }




	}
	cout << Server::getLoad() << endl;
	return 0;
}