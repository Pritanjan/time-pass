#include <iostream>
#include <queue>

using namespace std;

int main() {
	deque<int> d;
	
	d.push_front(1);
	d.push_back(2);
	
	
	cout << "FRONT " << d.front();  // 1
	cout << " BACK " << d.back();    // 2
	
    d.pop_front();
    cout << "FRONT " << d.front();  // 2
	cout << " BACK " << d.back();    // 2
	
	
	return 0;
}

// FRONT 1 BACK 2FRONT 2 BACK 2
