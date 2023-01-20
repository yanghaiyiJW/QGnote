#include <REGX52.H>
#include "Matrixkey.h"
#include "LCD1602.h"
#include "Delay.h"


unsigned char KeyNum;
unsigned int Password,count;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	
	
	while(1)
	{	
		KeyNum=Matrixkey();
		if(KeyNum)
		{
			if(KeyNum<=10)
			{
				if(count<4)
				{
					Password*=10;
					Password+=KeyNum%10;
					count++;
				}
				
				LCD_ShowNum(2,1,Password,4);
			}
			
			
			
			if(KeyNum==11)
			{
				if(Password==2022)
				{
					LCD_ShowString(1,14,"OK ");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
				
					}
				else
				{
					LCD_ShowString(1,14,"ERR");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
				
					}
			}	
			if(KeyNum==12)
			{
				Password=0;
				count=0;
				LCD_ShowNum(2,1,Password,4);
					
			}
			
		}
		
	}
}
