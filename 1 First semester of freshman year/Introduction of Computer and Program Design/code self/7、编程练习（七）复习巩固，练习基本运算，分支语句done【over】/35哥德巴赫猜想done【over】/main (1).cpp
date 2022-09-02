# include <stdio.h>

/*
	@relief 判断 n 是否为素数
*/

bool Primes_judgment(int n) 
{
	int a = 0;
	if (n == 2)
		return true;
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				return false;
			} 
		}
		return true;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	//printf("%d %d\n", Primes_judgment(3),Primes_judgment(9));
	//思路：先判断第一个数是不是素数，再判断第二个数是不是素数
	
	/*下面判断哥德巴赫猜想，从两头进行分析是值得留有印象的。这便是关键的思维*/
	for (int j = 2; j < n; j++) {
		if (Primes_judgment(j)) {
			if (Primes_judgment(n - j)) {
				printf("%d %d\n", j, n - j);
				break;
			} else
				continue;
		} else
			continue;
	}

	return 0;
}

