case SPFD5420:
	LCD_Write_COM(0x0000);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0X0001);  
    LCD_Write_DATA(0X0100);
    LCD_Write_COM(0X0002);  
    LCD_Write_DATA(0X0100);
    
    LCD_Write_COM(0X0003);  
    LCD_Write_DATA(0X1030);
    LCD_Write_COM(0x0008);  
    LCD_Write_DATA(0x0808); 
    LCD_Write_COM(0x0009);  
    LCD_Write_DATA(0x0001);
    LCD_Write_COM(0x000B);  
    LCD_Write_DATA(0x0010); 
    LCD_Write_COM(0x000C);  
    LCD_Write_DATA(0x0000);
    LCD_Write_COM(0x000F);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0007);  
    LCD_Write_DATA(0x0001);
    LCD_Write_COM(0x0010);  
    LCD_Write_DATA(0x0013); 
    LCD_Write_COM(0x0011);  
    LCD_Write_DATA(0x0501);
    LCD_Write_COM(0x0012);  
    LCD_Write_DATA(0x0300); 
    LCD_Write_COM(0x0020);  
    LCD_Write_DATA(0x021E);
    LCD_Write_COM(0x0021);  
    LCD_Write_DATA(0x0202); 
    LCD_Write_COM(0x0090);  
    LCD_Write_DATA(0x8000);
    LCD_Write_COM(0x0100);  
    LCD_Write_DATA(0x17B0); 
    LCD_Write_COM(0x0101);  
    LCD_Write_DATA(0x0147);
    LCD_Write_COM(0x0102);  
    LCD_Write_DATA(0x0135); 
    LCD_Write_COM(0x0103);  
    LCD_Write_DATA(0x0700);
    LCD_Write_COM(0x0107);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0110);  
    LCD_Write_DATA(0x0001);
    LCD_Write_COM(0x0210);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0211);  
    LCD_Write_DATA(0x00EF);
    LCD_Write_COM(0x0212);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0213);  
    LCD_Write_DATA(0x018F);
    LCD_Write_COM(0x0280);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0281);  
    LCD_Write_DATA(0x000f);
    LCD_Write_COM(0x0282);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0300);  
    LCD_Write_DATA(0x0101);
    LCD_Write_COM(0x0301);  
    LCD_Write_DATA(0x0B2C); 
    LCD_Write_COM(0x0302);  
    LCD_Write_DATA(0x1030);
    LCD_Write_COM(0x0303);  
    LCD_Write_DATA(0x3010); 
    LCD_Write_COM(0x0304); LCD_Write_DATA(0x2C0B);
    LCD_Write_COM(0x0305);  
    LCD_Write_DATA(0x0101); 
    LCD_Write_COM(0x0306);  
    LCD_Write_DATA(0x0807);
    LCD_Write_COM(0x0307); LCD_Write_DATA(0x0708); 
    LCD_Write_COM(0x0308); LCD_Write_DATA(0x0107);
    LCD_Write_COM(0x0309);  
    LCD_Write_DATA(0x0105); 
    LCD_Write_COM(0x030A);  
    LCD_Write_DATA(0x0F04);
    LCD_Write_COM(0x030B);  
    LCD_Write_DATA(0x0F00); 
    LCD_Write_COM(0x030C);  
    LCD_Write_DATA(0x000F);
    LCD_Write_COM(0x030D);  
    LCD_Write_DATA(0x040F); 
    LCD_Write_COM(0x030E);  
    LCD_Write_DATA(0x0300);
    LCD_Write_COM(0x030F);  
    LCD_Write_DATA(0x0701); 
    LCD_Write_COM(0x0400); 
    LCD_Write_DATA(0x3500); //(01H==0x0000,400H==0xB504,原点设置为对角)
    LCD_Write_COM(0x0401);  
    LCD_Write_DATA(0x0001); 
    LCD_Write_COM(0x0404);  
    LCD_Write_DATA(0x0000);
    LCD_Write_COM(0x0500);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0501);  LCD_Write_DATA(0x0000);
    LCD_Write_COM(0x0502);  LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0503);  LCD_Write_DATA(0x0000);
    LCD_Write_COM(0x0504);  LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0505);  LCD_Write_DATA(0x0000);
    LCD_Write_COM(0x0606);  LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x06F0);  
    LCD_Write_DATA(0x0000);
    LCD_Write_COM(0x07F0);  
    LCD_Write_DATA(0x5420); 
    LCD_Write_COM(0x07DE);  
    LCD_Write_DATA(0x0000);
    LCD_Write_COM(0x07F2);  
    LCD_Write_DATA(0x00DF); 
    LCD_Write_COM(0x07F3);  
    LCD_Write_DATA(0x0810);
    LCD_Write_COM(0x07F4);  
    LCD_Write_DATA(0x0077); 
    LCD_Write_COM(0x07F5);  
    LCD_Write_DATA(0x0021);
    LCD_Write_COM(0x07F0);  
    LCD_Write_DATA(0x0000); 
    LCD_Write_COM(0x0007);  
    LCD_Write_DATA(0x0173);

    LCD_Write_COM(0x0210);  
    LCD_Write_DATA(0); 
    LCD_Write_COM(0x0211);  
    LCD_Write_DATA(239);
    LCD_Write_COM(0x0212);  
    LCD_Write_DATA(0); 
    LCD_Write_COM(0x0213);  
    LCD_Write_DATA(399);
    LCD_Write_COM(0x0200);  
    LCD_Write_DATA(0); 
    LCD_Write_COM(0x0201);  
    LCD_Write_DATA(0);
	break;
