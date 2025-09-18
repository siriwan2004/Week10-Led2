#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(GPIO_NUM_16); 
LED led2(GPIO_NUM_17); 
LED led3(GPIO_NUM_5); 
LED led4(GPIO_NUM_18); 
LED led5(GPIO_NUM_19); 
LED led6(GPIO_NUM_21); 
LED led7(GPIO_NUM_22); 
LED led8(GPIO_NUM_23); 

LED* leds[] = {&led1, &led2, &led3, &led4, &led5, &led6, &led7, &led8};
const int num_leds = sizeof(leds) / sizeof(leds[0]);

// ดับทั้งหมด
void allOff() {
    for (int i = 0; i < num_leds; i++) leds[i]->OFF();
}

// พิมพ์ pattern ลง Serial Monitor
void printPattern(int on1, int on2 = -1) {
    for (int i = 0; i < num_leds; i++) {
        if (i == on1 || i == on2) printf("*");
        else printf(".");
    }
    printf("\n");
}

extern "C" void app_main(void)
{
    while (true) {

         for (int i = 0; i < num_leds; i++) {
            allOff();
            leds[i]->ON();
            printPattern(i);
            vTaskDelay(pdMS_TO_TICKS(150));
        }
    
        for (int i = num_leds - 2; i > 0; i--) {
            allOff();
            leds[i]->ON();
            printPattern(i);
            vTaskDelay(pdMS_TO_TICKS(150));
        }
    }
}