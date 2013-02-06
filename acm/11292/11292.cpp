#include <cstdio>
#include <algorithm>

int main()
{
	using namespace std;
	int m, n;
	const int SIZE = 20000 + 5;
	int a[SIZE], b[SIZE];
	while(scanf("%d%d", &n, &m) == 2 && m && n){
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < m; i++) scanf("%d", &b[i]);
	
		sort(a, a + n);
		sort(b, b + m);
		int flag  = 0;
		int money = 0;
		int curr  = 0;					//the head num
		for(int i = 0; i < m; i++){
			if( b[i] >= a[curr]){
				money += b[i];			//set money 
				++curr;					
			}
			if(curr == n){	
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("%d\n", money);
		else
			printf("Loowater is doomed!\n");
	}
return 0;
}
