#ifndef __PINMAP_H__
#define __PINMAP_H__

#define GPIO_LED    2       //LED提示灯
#define GPIO_0      0       //GPIO0
#define GPIO_KEY1   34      //KEY1,NEXT
#define GPIO_KEY2   35      //KEY2,ENTER
#define GPIO_BAT    36      //ADC_BAT,2分压
#define GPIO_5V     39      //ADC_5V(USB),2分压
#define GPIO_CHRG   26      //#CHRG,充电提示
#define GPIO_STDBY  27      //#STDBY,充电完成
#define GPIO_LCD_CS 32      //LCD的CS
#define GPIO_BUZZ   12      //蜂鸣器引脚
#define GPIO_5V_EN  22      //电荷泵升压的EN引脚,默认使能
#define GPIO_LCDRS  18      //LCD的RS
#define GPIO_LCDBLK 16      //LCD的背光控制
#define GPIO_LIGHT  4       //光敏电阻引脚
#define GPIO_LCD_D4 33      //这四个为LCD的数据引脚
#define GPIO_LCD_D5 25
#define GPIO_LCD_D6 23
#define GPIO_LCD_D7 14

#endif