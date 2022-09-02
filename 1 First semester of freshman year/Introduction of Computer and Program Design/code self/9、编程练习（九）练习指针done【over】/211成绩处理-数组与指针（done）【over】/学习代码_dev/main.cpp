#include<stdio.h>

int main()
{
	double aver(double s);
	int fals(double *p, int m);
	int well(double *p1, int num); //ÉùÃ÷º¯Êı 
	
	int i,j,fail,number;
	double sum=0,average,stu[5][4];
	
	for(i=0; i<5; i++)
		for(j=0; j<4; j++)
			scanf("%lf", &stu[i][j]);
	
	for(i=0; i<5; i++)
		sum = sum + stu[i][0];
	
	average = aver(sum);
	
	fail = fals(*stu,20);
	
	number = well(*stu,20);
	
	printf("%.1lf %d %d", average, fail, number);
	
	return 0;
 } 
 
 
double aver(double s)
{
	return (s/5);	
}


int fals(double *p,int m)
{
	int i=0,n=0,c=0,flag=0;
	double *p_end;
	
	p_end = p+m;
	
	for(;p<p_end;p++)
	{
		i++;
		if((*p) < 60) 
			n++;
		if(n>=2 && flag==0)
		{
			flag=1;
			c++;	
		}
		if(i%4 == 0) 
		{
			n=0;
			flag=0;
		}
	}
	return (c);
}

int well(double *p1, int num)
{
	double zongfen=0,pingjun;
	int i=0,count=0,f=0;
	double *p1_end;
	
	p1_end=p1+num;
	
	for(;p1<p1_end;p1++)
	{
		i++;
		if(*p1<85) f=1;
		zongfen = zongfen + (*p1);
		if(i%4==0) 
		{
			pingjun = zongfen/4;
			if((pingjun>=90) || (f==0))
			count++;
			f=0;
			zongfen=0;	
		}
	}
	return (count);
}
 
