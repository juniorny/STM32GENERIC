case ILI9486:
	LCD_Write_COM(0x2a); 
	LCD_Write_DATA(x1>>8);
	LCD_Write_DATA(x1&0xff);
	LCD_Write_DATA(x2>>8);
	LCD_Write_DATA(x2&0xff);
	LCD_Write_COM(0x2b); 
	LCD_Write_DATA(y1>>8);
	LCD_Write_DATA(y1&0xff);
	LCD_Write_DATA(y2>>8);
	LCD_Write_DATA(y2&0xff);
	LCD_Write_COM(0x2c); 
	break;
