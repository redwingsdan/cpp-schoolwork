/*
	for(n=theta1;n<=theta3;n+=thetastep)
	{
		radians=(pi*n)/180;
		
		printf("%-16.2f",n);
		printf("%-16.2f",radians);
		
		if(n<=theta2)
		{

		f1=sin(radians)+2*cos(2*radians);
		
		printf("%-16.2f",f1);
		printf("N/A\n");
			if(n==theta2)
			{
			continue;
			}
		}
		if(n>theta2)
		{
			f2=sin(2*radians)-cos(radians);
			printf("%.2f\n",f2);
			
		}
	}
*/