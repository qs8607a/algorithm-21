#include <cstdio>
#include <algorithm>

using namespace std;

const int size = 10000001;

int main(void)
{
	unsigned long long a[size], b[size];
	unsigned long long  n, average, total = 0;
	while(1 == scanf("%d", &n)){
		for(int i = 0; i != n; i++){
			scanf("%d", &a[i]);
			total += a[i];
		}
		average = total/n;
		b[0] = M - a[0];
		for(int i = 1; i!= n; i++){ 
			b[i] = b[i - 1] + total - a[i];
		}	
		sort(b, b + i);
		b[n/2];
	}

}


