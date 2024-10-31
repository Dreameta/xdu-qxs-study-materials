# include <stdio.h>
# include <string.h>

/*
	感受：每次做题都是在训练or发现自己逻辑的不严密之处。 
*/

int main(void)
{
	void Find_the_longest_word (char *str);
	
	char string[100];
	
	for(int i = 0; i<100; i++){
		scanf("%c", &string[i]);
		if (string[i] == '.')
			break;
	}
	
	Find_the_longest_word(string);

	return 0;
}

void Find_the_longest_word (char *str)
{
	char *p = str; //将输入的指针（地址）赋予给另一个指针变量；
	
	int sum[100] = {0}; //使用数组进行多组计数
	int cycle_index = 0; 
	
	/*计算每个单词的长度。一个前提，每个字符指针所占据1个bite，凭此来进行计数。 */
	for (int i = 0; (*p != '.'); i++){ //只要不到结尾就不停止循环；
		if (*p == ' ')	//若有空格则跳过空格 
		{
			p++; //用来跳过空格对应的位置 
			
			while( *p != ' ' ){ //每个空格进行一次计数 
				p++; 
				sum[i]++;
				if(*p == '.')
					break;
			}
			/*
			下面的逻辑是不对的，“ ”和“.”的条件其实是一直成立的，所以要思考每段逻辑的顺序。 
			while( (*p != ' ') || (*p != '.') ){ //每个空格进行一次计数 
				p++; 
				sum[i]++;
			}
			*/
			cycle_index ++; //记录循环次数 
		}
		else  //没有空格则直接计数 
		{
			while(*p != ' '){ //每个空格进行一次计数 
				p++; 
				sum[i]++;
			}
			cycle_index ++; //记录循环次数 
		}
	}
	
	/*查找算法：找出最长单词的长度。本质是排序算法找出其中最大*/的 
	for(int i = 0; i<cycle_index; i++){
		for(int j = i + 1; j<cycle_index; j++){
			if(sum[j] > sum[i]){
				int t;
				t = sum[j];
				sum[j] = sum[i];
				sum[i] = t;
			}	
		}
	}
	
	/*直接在函数中输出最后的结果*/
	printf("%d", sum[0]);

}





