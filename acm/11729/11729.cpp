#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Job{
	int j, b;
	bool operator < (const Job &x) const {
		return j > x.j;	
	}
};
int main()
{
	int curr = 1;
	int count;
	int j, b;
	vector<Job> store;
	while( scanf("%d", &count) == 1 && count){
		int circle = count;
		while(circle--){
			scanf("%d%d", &b, &j);
			store.push_back((Job){j,b});	
		}
		sort(store.begin(), store.end());
		int cost = 0;
		int brief = 0;
		for(int i = 0; i < count; i++){
			brief += store[i].b; 
			cost  =  max(cost, brief + store[i].j);		
		}
		printf("Case %d: %d\n", curr++, cost);
	}
return 0;
}
