#include<reg51.h>
#define lcd_dat P3

sbit R1 = P2^0;
sbit R2 = P2^1;
sbit R3 = P2^2;
sbit R4 = P2^3;
sbit C3 = P2^4;
sbit C2 = P2^5;
sbit C1 = P2^6;

sbit LED = P1^0;
sbit buzzer = P1^2;

sbit rs = P1^7;
sbit rw = P1^6;
sbit e = P1^5;



void delay()
{
	int i;
	for(i=0; i<250; i++)
	{
		TMOD = 0x01;
		TH0=0xFC;
		TL0=0xC7;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;	
	}
}

void lcd_cmd(unsigned char cmd)
{
	lcd_dat=cmd;
	rs=0;
	rw=0;
	e=1;
	delay();
	e=0;
}

void lcd_data(unsigned char a)
{
	lcd_dat=a;
	rs=1;
	rw=0;
	e=1;
	delay();
	e=0;
}


void main()
{
	
	char password[100] = "2006";
	int current_num = 0;
	LED = 0;
	buzzer = 0;
	
	lcd_cmd(0x38);
	delay();
	lcd_cmd(0x0F);	// turn on display
	delay();
	lcd_cmd(0x01);	// clear display
	delay();
	lcd_cmd(0x80);	//First row second character
	delay();
	
	
	while(1)
	{
		R1=R2=R3=R4=C1=C2=C3=1;
		
		// for row one 
		R1 = 0;
		R2 = R3 = 1;
	
		if(C1==0)					//number 1
		{
			lcd_data('1');
			delay();
			current_num = current_num*10 + 1;
			delay();
		}
		else if(C2==0)		//number 2
		{
			lcd_data('2');
			delay();
			current_num = current_num*10 + 2;
			delay();
		}
		else if(C3==0)		//number 3
		{
			lcd_data('3');
			delay();
			current_num = current_num*10 + 3;
			delay();
		}
		
		//for second row
		R2 = 0;
		R1 = R3 = 1;
	
		if(C1==0)					//number 4
		{
			lcd_data('4');
			delay();
			current_num = current_num*10 + 4;
			delay();
		}
		else if(C2==0)		//number 5
		{
			lcd_data('5');
			delay();
			current_num = current_num*10 + 5;
			delay();
		}
		else if(C3==0)		//number 6
		{
			lcd_data('6');
			delay();
			current_num = current_num*10 + 6;
			delay();
		}
		
		
		R3 = 0;
		R1 = R2 = 1;
	
		if(C1==0)					//number 7
		{
			lcd_data('7');
			delay();
			current_num = current_num*10 + 7;
			delay();
		}
		else if(C2==0)		//number 8
		{
			lcd_data('8');
			delay();
			current_num = current_num*10 + 8;
			delay();
		}
		else if(C3==0)		//number 9
		{
			lcd_data('9');
			delay();
			current_num = current_num*10 + 9;
			delay();
		}
		
		// for 0 in fourth row
		R4 = 0;
		R1 = R2 = R3 = 1;
		if(C2==0)					//number 0
		{
			lcd_data('0');
			delay();
			current_num = current_num*10 + 0;
			delay();
		}
		
		else if(C3==0)					//hash button
		{
			if(current_num == 2006)
			{
				LED = 1;
			}
			else if(current_num!=2006)
			{
				buzzer = 1;
			}

			
		}
		
	}
}
