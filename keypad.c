# include <reg51.h>
# include "lcd.h"
# include "keypad.h"
sbit C1=P1^3;
sbit C2=P1^2;
sbit C3=P1^1;
sbit C4=P1^0;                                                             
sbit R1=P1^7;
sbit R2=P1^6;
sbit R3=P1^5;
sbit R4=P1^4;

void Beep(unsigned int duration)         
{
    unsigned char i,j,k;
	for(k=1;k<=duration;k++)    
  { 
		for(i=0;i<250;i++)            
	{
	  R3=0;
	  for(j=0;j<50;j++);
		R3=1;
    for(j=0;j<50;j++);

  }
Delay(500);
  }
}

char Key_Pressed ()                 
{  
       
while(1)                         
{ 
	R1=0; R2=1; R3=1; R4=1;           
	     if(C1==0)                                       
			 {  Delay(2000);
				 while(C1==0)
				   {
				     Beep(1);  return '7';
				   }   
			 }  
			 if(C2==0)                                      
			 {     Delay(2000);
    				 while(C2==0)
			       { Beep(1);return '8';}  
			 }       
			  
			 if(C3==0)
			 {   Delay(2000); while(C3==0)
			    { Beep(1);return '9';}  
			 }
			 
			 if(C4==0)
			 {    Delay(2000);
			    while(C4==0)
			    { Beep(1);return '/';} 
			 
			 }
	 
  R1=1; R2=0; R3=1; R4=1;                             
	     if(C1==0)                                   
			 {   Delay(2000);
           while(C1==0)
			    { Beep(1);return '4';} 


			 }  
	      if(C2==0)
			 {  Delay(2000);
           while(C2==0)
			    { Beep(1);return '5';} 
			 }
			  if(C3==0)
			 {  Delay(2000);
         while(C3==0)
			    { Beep(1);return '6';} 

			 }
			  if(C4==0)
			 {  Delay(2000);
				 while(C4==0)
			    { Beep(1);return '*';}   }
			 
  R1=1; R2=1; R3=0; R4=1;                             
	     if(C1==0)
			 {  Delay(2000);
         while(C1==0)
			    { Beep(1);return '1';} 

			 } 
	      if(C2==0)
			 {  Delay(2000);
				 while(C2==0)
			    { Beep(1);return '2';} 
			 }
			  if(C3==0)
			 {  Delay(2000);
				 while(C3==0)
			    { Beep(1);return '3';}   
			 }
			  if(C4==0)
			 {  Delay(2000);
				 while(C4==0)
			    { Beep(1);return '-';}   }
			 
			 
	R1=1; R2=1; R3=1; R4=0;                         
	     if(C1==0)
			 {   Delay(2000);
				 while (C1 == 0); 
				 { Beep(1); return 'C';}
			 } 
	      if(C2==0)
			 {  
				 Delay(2000);
				 while(C2==0)
			    { Beep(1);return '0';}  
			 
		   }  
			  if(C3==0)
			 {  Delay(2000);
				  while(C3==0)
			    { Beep(1);return '=';}  
			 }
			  if(C4==0)
			 {   Delay(2000);
				   while(C4==0)
			    { Beep(1);return '+';} 
			 }
	 
	 R4=1;
}
}
char Key1_Pressed ()               
{  
	R1=1; R2=1; R3=1; R4=0;                              
	     if(C1==0)
			 {   Delay(2000);
				 while (C1 == 0); 
				 { Beep(1); return 'C';}
			 } 
	       
			  if(C3==0)
			 {  Delay(2000);
				  while(C3==0)
			    { Beep(1);return '=';}  
			 } 
	 R4=1;


}


