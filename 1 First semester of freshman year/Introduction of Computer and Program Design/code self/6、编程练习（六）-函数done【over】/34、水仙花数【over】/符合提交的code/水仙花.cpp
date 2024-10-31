
int function(int a, int b)
{
	int sum_narcissistic_number = 0;
	double number;
	
  	a = (double)a;
    b = (double)b;
	for(double i=a; i<=b; i++)
	{
		int n = (int)i;

		int y;
        y = (int)i;
        int m;
        for(m=1; m>0; m++)
        {
            y = y/10;
            if (y == 0)
            break;
         }
        number = m;

		if (number == 1)
			continue;
		double intermediate_variable = 0;
		for(int j = number ; j>0; j--)
		{
			intermediate_variable =  intermediate_variable + pow((double)(n%10),number);
			n /= 10;
		}

		if(i == intermediate_variable)
			sum_narcissistic_number ++;
		else
			continue;
	}

	return sum_narcissistic_number;
}
