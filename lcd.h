/* 
 * File:   newfile.h
 * Author: srubi
 *
 * Created on Pondelok, 2021, augusta 16, 11:47
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "xc.h"
#include "mcc_generated_files/device_config.h"

#define RS LATB5
#define EN LATB4
#define D4 LATB0
#define D5 LATB1
#define D6 LATB2
#define D7 LATB3

void Lcd_SetBit(char data_bit);
void Lcd_Cmd(char a);
void Lcd_Clear();
void Lcd_Set_Cursor(char a, char b);
void Lcd_Start();
void Lcd_Print_Char(char data);
void Lcd_Print_String(char *a);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

