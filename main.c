# include <reg51.h>
# include "lcd.h"
# include "keypad.h"
# include <stdio.h>
sbit Door_Switch =P2^0; // Door  pin

unsigned char key1,key,key2;              
int minutes , seconds,sec,min,i;         
bit flag=1;                               
char input[4];                             
char formattedTime[6] ;                    


typedef enum {Time_Entered_State ,Door_Status_State, RUN_COUNTER_State} State;    //STATE MACHINE with Three State

State current_state=Time_Entered_State;                                          

//Main function
void main(void) 
	{
    LCD_Intialization();                                      
    LCD_ShowString(1, 0, "Oven Controller");                 
    Delay(200);
    while (1)                                                 
			{               
// STATE MACHINE        
switch (current_state) 
					{
case Time_Entered_State:                                
           LCD_ShowString(2, 0, "EnterTime");    
           Delay(200);
           LCD_ShowString(2, 10, "00:00");

 if (flag)                 
	{
		for (i = 0; i < 4; i++)    
    {
        input[i] = '0';
     }
    for (i = 0; i < 4; i++) 
	 {
       key = Key_Pressed(); 
    
       // Check if the input key is between 0 and 9
     if (key >= '0' && key <= '9')
			 {
     
         input[3] = input[2];
         input[2] = input[1];
         input[1] = input[0];
        
       //  new input value
         input[0] = key;
        
        //  updated input
          LCD_ShowChar(2, 10, input[3]);
          LCD_ShowChar(2, 11, input[2]);
          LCD_ShowString(2, 12, ":");
          LCD_ShowChar(2, 13, input[1]);
          LCD_ShowChar(2, 14, input[0]);
			 }
   }
			 
  minutes = (input[3] - '0') * 10 + (input[2] - '0');      
  seconds = (input[1] - '0') * 10 + (input[0] - '0');
  sprintf(formattedTime, "%02d:%02d", minutes, seconds);    

  LCD_ShowString(2, 10, formattedTime);                    
	    flag = 0;   													 
													 
      if (input[0] != '0' || input[1] != '0' || input[2] != '0' || input[3] != '0') 
      {
        current_state = Door_Status_State; 
				}
     }
	else
		{
      current_state = Door_Status_State;            
      }
break;                                                                 

case Door_Status_State:                                          
	     key1 = Key_Pressed();                                                       

      if (key1 == 'C')                                  
				{
      if (Door_Switch == 0)                    
			{                                      
         LCD_ClearSecondLine();            
         LCD_ShowString(2, 0, "Door Open");    
				Delay(1000);
		    Beep(10);
        }				
			else                                                                 
			{
        LCD_ClearSecondLine();               
				LCD_ShowString(2, 0, "Door Close");  
				Delay(3000);                         
        LCD_ClearSecondLine(); 
        Delay	(1000);										
        current_state = RUN_COUNTER_State;   //Change Stste to Run counter State
		    Delay	(1000);	
         }
			}
				else if (key1 == '=')                          
				{       
					flag=1;                             
		      Delay(250);
          current_state = Time_Entered_State;  
			    Delay(100);
	}										
break;

      
case RUN_COUNTER_State:              
          
      sec = seconds;               
      min = minutes;                               
   if(min<59 && sec<59)  
		 {
      	while(1)              
						{      
							
	//if Counter Run and Door is Open
				while (Door_Switch == 0)       
                    
					{                                  
            LCD_ShowString(2, 0, "Door Open");   
					  Beep(10);                                  
					 while(Key_Pressed() != 'C');       
           LCD_ShowString(2, 0, "DoorClose");  
				   Delay (3000);
        		LCD_ClearLine(9);								
        }
	// Count Down Counter
		sec--;                               

  if (sec < 0) 
		{
     sec = 59;
      min--;
    }

   if (min < 0) 
			{
        min = 0;
        sec = 0;
        }
     Timmer_Delay(160);                   
     LCD_ShowNum(2, 10, min, 2);       
     LCD_ShowString(2, 12, ":");
     LCD_ShowNum(2, 13, sec, 2);
										
//if Counter Run and On/Off Button Press
   if (Key1_Pressed() == 'C')             
     {  
			while(Key_Pressed() != 'C')          
					{
						Delay(500);
				 if(Key1_Pressed() == '=')        
				   {     
						 flag=1;                  
             current_state = Time_Entered_State; break;      
			}
	}
											
 if (flag)                         
		{
       break;                       
  }
}
                        
//Count Down reach to zero
	if (min == 0 && sec == 0)        
    {  
			flag=1;                                  
      current_state = Time_Entered_State; 
       break;                         
      }                     
	}							
		 }
		else
			{        
				LCD_ClearSecondLine();
        Delay(100);
 				LCD_ShowString(2,0, "Invalid Formate");
		    Beep(10);
			  Delay(25000);
			  LCD_ClearSecondLine();
				flag=1;                                  
        current_state = Time_Entered_State;
					
			}
								
break;

      }
    }
}
