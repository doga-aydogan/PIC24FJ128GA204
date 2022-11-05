/*
 Author: Do?a M. Aydo?an
 Date: Nov., 2022
 */

/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GA204
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/*
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"   

/*
  Section: define
*/
#define INT_MIN -2147483648;

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
     
    int numberofSwitch1Press = 0;
    int numberofSwitch2Press = 0;
    
    LED1_SetHigh(); //LED1 ON
    LED2_SetHigh(); //LED2 ON
    
    bool isSwitch1PressedAlready = false; // the switch1 is not pressed yet
    bool isSwitch2PressedAlready = false; // the switch1 is not pressed yet
    
    while (1) //super loop, infinite loop
    {
         //if the button is pressed its 0, false, if its not pressed than 1, true
        if(!SWITCH1_GetValue() && !SWITCH2_GetValue()) //When both switches are pressed simultaneously
        {
            //Restart the game
            //number of presses to each switch is set to zero
            numberofSwitch1Press = 0;
            numberofSwitch2Press = 0;
            
            LED1_SetLow(); //LED1 OFF
            LED2_SetLow(); //LED2 OFF 
        }
        
        if(!SWITCH1_GetValue() && !isSwitch1PressedAlready) //switch1 is pressed
        {
          numberofSwitch1Press++; //count it
          isSwitch1PressedAlready = true;
        } 
        
        if(!SWITCH2_GetValue() && !isSwitch2PressedAlready) //switch2 is pressed
        {
            numberofSwitch2Press++; //count it
            isSwitch2PressedAlready = true;
        }
        
        if(numberofSwitch1Press == 1 && numberofSwitch2Press == 1)
        {
            //You won!
            LED1_SetHigh(); //LED1 ON
            LED2_SetHigh(); //LED2 ON        
        }
        
        if(SWITCH1_GetValue() && SWITCH2_GetValue()) //When both switches are not pressed simultaneously
        {
            isSwitch1PressedAlready = false;
            isSwitch2PressedAlready = false;
        }
    }
    
    return 1;
}
/**
 End of File
*/

