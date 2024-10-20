#include <Arduino.h>
#include <LibPrintf.h>

#include "data-manager.h"
#include "display-manager.h"



#include "lvgl.h"
#include "app_hal.h"

#include "demos/lv_demos.h"
#include <demos/widgets/lv_demo_widgets.h>


void setup()
{	
	Arduino::setup();
	Serial.begin(9600);
	Serial.printf("Starting!\n");

	DataManager::init();
	lv_init();

	hal_setup();

    lv_demo_widgets();

}

void loop()
{
	Arduino::loop();
	DataManager::update();
	hal_loop();
	delay(100);
}
