# include <stdio.h>

void selection_sort(int *a, int *b, int n) {
	for (int i = 0; i < n; ++i) {
		int ith = i;
		for (int j = i + 1; j <= n; ++j) {
			if (a[j] > a[ith])
				ith = j;
		}
		//交换
		//对于a来说，做好排序
		int t = a[i];
		a[i] = a[ith];
		a[ith] = t;

		//对于b来说：要做好和每次数字的对应
		int p = b[i];
		b[i] = b[ith];
		b[ith] = p;
	}
}
/*
试数：
设 a[0]= 27; a[1]=10; a[2]=2; a[3]=2; a[4]=1
n = 5

i=0
    ith=0
        j = 1
            a[1]<a[0] :  ith = j = 1
        j = 2
            a[2]<a[1] :  ith = j = 2
        j = 3
            a[3]=a[2] ;  stay  ith = 2
        j = 4
            a[4]<a[2] :  ith = j = 5
    t = a[1]
    a[i] = a[ith] = 1
    a[ith] = t;
思路总结
    每次内容循环找出最小的放在前面
    经修改后，排序结果为
    从大到小依次减小
*/

int main(void) {
	int n;//储存整数个数
	int m[1000];//用来储存每个整数
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m[i]);
	}

	int Sn[1000] = {0};//用来储存每个整数的每位数字之和
	for (int i = 0; i < n; i++) {
		int t = m[i]; //千万要记住要在最后输出的变量，不要在中间进行运算
		for (int j = 0; t != 0; j++) {
			Sn[i] = Sn[i] + (t % 10);
			t = t / 10;
		}
	}

	//接下来是学习算法
	selection_sort(Sn, m, n);

	for (int i = 0; i < n; i++) {
		printf("%d %d", m[i], Sn[i]);
		printf("\n");
	}

	return 0;
}


