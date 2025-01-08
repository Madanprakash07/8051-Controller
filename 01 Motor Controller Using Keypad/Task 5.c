#include<reg51.h>

sbit R1 = P3^0;
sbit R2 = P3^1;
sbit R3 = P3^2;
sbit R4 = P3^3;
sbit C1 = P3^4;
sbit C2 = P3^5;
sbit C3 = P3^6;

void main()
{	
	while(1)
	{
		R1 = R2 = R3 = R4 = C1 = C2 = C3 = 1;
		
		R1 = 0;
		R2 = R3 = 1;
		if(C1==0)
		{
			P2 = 0x01;
		}
		else if(C2==0)
		{
			P2 = 0x02;
		}
		
		
		
	}
	
}