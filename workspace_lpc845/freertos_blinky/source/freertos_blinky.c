#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

#include "FreeRTOS.h"
#include "task.h"

void task_hello(void *params) {

		while(1) {
			PRINTF("Skewer the winged beast...\r\n");
			vTaskDelay(555);
		}
}

int main(void) {

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    xTaskCreate(
    	task_hello,
		"Hello.",
		configMINIMAL_STACK_SIZE,
		NULL,
		1,
		NULL
    );

    vTaskStartScheduler();

  while(1);
  return 0;

}
