/*
 * main.c
 *
 *  Created on: Feb 27, 2024
 *      Author: abdalla
 */



#include "ultrasonic.h" 	/* Include header file for Ultrasonic sensor functions */
#include "lcd.h" 			/* Include header file for LCD functions */
#include "buzzer.h"			/* Include header file for BUZZER functions */
#include <avr/io.h> 		/* AVR I/O definitions */
#include <util/delay.h> 	/* Delay functions */


/* Main function */
int main (void)
{
    uint16 distance = 0; 	/* Variable to store distance measurement */
    uint8 move_char = 0;

    LCD_init(); 			/* Initialize LCD */
    ULTRASONIC_init(); 		/* Initialize Ultrasonic sensor */
    BUZZER_init();			/* Initialize BUZZER sensor */

    SREG |= (1<<7); 		/* Enable global interrupts */

    LCD_displayString("Distance =    cm"); /* Display initial message on LCD */

    /* Main loop */
    while (1)
    {
    	/* Move cursor to the position to display distance */
        LCD_moveCursor(0,11);

        /* Read distance from Ultrasonic sensor */
        distance = (uint16)ULTRASONIC_readDistance();

        BUZZER_sound(distance);


        /* Check if distance is less than 100 cm */
        if (distance < 100)
        {
            LCD_intgerToString(distance); 	/* Display distance value */
            LCD_displayCharacter(' '); 		/* Display space after distance */
        }
        else
        {
            LCD_intgerToString(distance); 	/* Display distance value */
        }


        if (distance <= MAX_DISTANCE && distance > 20)
        {
            /* Move cursor to the second line */
            LCD_moveCursor(1,0);
        	LCD_displayString("      "); 				/* Clear any remaining stop sign*/
        	LCD_displaySringRowColumn("STOP!", 1,6);
        	LCD_displayString("     "); 				/* Clear any remaining stop sign*/

        }
        else if (distance <= 20 && distance > 10)
        {
            /* Move cursor to the second line */
            LCD_moveCursor(1,0);
        	LCD_displayString("      "); 				/* Clear any remaining stop sign*/
        	LCD_displaySringRowColumn("STOP!", 1,6);
        	LCD_displayString("     "); 				/* Clear any remaining stop sign*/

            /* Move cursor to the 3rd line */
        	LCD_moveCursor(2,0);
        	LCD_displayString("      "); 				/* Clear any remaining stop sign*/
        	LCD_displaySringRowColumn("STOP!", 2,6);
        	LCD_displayString("     "); 				/* Clear any remaining stop sign*/

        	/* Move cursor to the 3rd line */
        	LCD_moveCursor(3,0);
        	LCD_displayString("      "); 				/* Clear any remaining stop sign*/
        	LCD_displaySringRowColumn("STOP!", 3,6);
        	LCD_displayString("     "); 				/* Clear any remaining stop sign*/
        }
        else if (distance <= 10)
        {
        	/* Display stop all over the screen */
        	LCD_moveCursor(2,0);
        	while (move_char++ != 13)
        	{
        		LCD_displayString("STOP!!");
        	}
        	move_char = 0; /* Reset the navigation char */
        }
        else
        {
        	/* Move cursor to the third line  */
        	LCD_moveCursor(2,0);

        	/* Loop over the third line to clear it all */
        	while (move_char++ != 16)
        	{
        		/* Clear all stop signs */
        		LCD_displayCharacter(' ');
        	}
        	move_char = 0;

        	 /* Move cursor to the second line */
        	LCD_moveCursor(1,0);

        	/* Loop over the second & 4th line to clear them all */
        	while (move_char++ != 32)
        	{
        		/* Clear all stop signs */
        		LCD_displayCharacter(' ');
        	}
        	move_char = 0; /* Reset the navigation char */
        }
        _delay_ms(500); /* Delay for 0.5 second before next measurement */
    }

    return 0;
}
