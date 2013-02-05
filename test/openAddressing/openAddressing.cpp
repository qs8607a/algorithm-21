#include <iostream>
#include <vector>


using namespace std;

class openAddressing
{
public:
	openAddressing():store(new int[m]), m(20), n(19){	
		for(int i = 0; i < m; i++){
			store[i] = -1;
		}
	}

	int insert(const int &val)
	{
		for(int i = 0; i < n; i++){
			int key = get_key(val, i);
			if(store[key] == -1){
				store[key] = val;	
				return key;
			}
		}
		return -1;
	}
	int search(const int &val)
	{
		for(int i = 0; i < n; i++){
			int key = get_key(val, i);
			if(store[key] == val){
				return key;
			}
		}
		return -1;
	}
	int del(const int &val)
	{
		int key;
		key = search(val);
		if(key < 0)
			return -1;
		else{
			store[key] = -1;
			return 0;
		}
	}
	virtual std::ostream& debug(std::ostream& out){
		for(int i = 0; i < m; i++){
			out << store[i] << " ";
		}
		out << std::endl;
		return out;
	}
private:
	int get_key(int val, int i){
		return (val + i)%n;
	}
	int *store;
	const int m;
	const int n;
};



int main()
{
	openAddressing a;
	a.insert(2);
	a.insert(100);
	a.insert(29);
	a.insert(33);
	a.insert(71);
	a.debug(cout);	
	a.del(29);
	a.debug(cout);
return 0;
}
