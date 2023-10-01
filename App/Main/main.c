#include "KeyPad_Core.h"
#include "LCD_Core.h"
#include "PORT_CORE.h"
#include "Calculator.h"

#define F_CPU 16000000U
#include <util/delay.h>


int main(void)
{
	PORT_INIT();
	LCD_Init();
	KeyPad_Init();
	uint8 res=0;
	while (1)
	{
		LCD_Clear();
		res=Start_Calculate();
		LCD_WriteInteger(res);
		while(1)
		{
			res=KeyPad_GetValue();
			if(res=='c')
			{
				break;
			}
		}
	}
}