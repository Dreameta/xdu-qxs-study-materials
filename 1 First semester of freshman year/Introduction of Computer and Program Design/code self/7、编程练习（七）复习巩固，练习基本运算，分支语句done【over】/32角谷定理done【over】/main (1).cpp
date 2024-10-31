#include <stdio.h>

/*
	@relief 判断一个整数奇偶性，返回为ture为偶数，返回为false为奇数
*/
bool Odd_even_judgment(int n) {
	if (n % 2 == 0)
		return true;
	else
		return false;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; n != 1; i++) {
		if (Odd_even_judgment(n))
			n = n / 2;
		else
			n = n * 3 + 1;
	}

	printf("%d", i);

}





