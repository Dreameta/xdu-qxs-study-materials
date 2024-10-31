# include <stdio.h>

int main(void)
{
    int t;
    float j;

    printf("请输入华氏温度 t =");
    scanf("%d", &t);

    j = ((float)t-32)*5/9;
    //执行进制换算：从左到右依次执行：先乘再除；
    //考点：不同数据类型的强制转换；

    printf("摄氏温度 = %.2f\n", j);

    return 0;
}
