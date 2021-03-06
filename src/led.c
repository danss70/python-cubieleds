/**
 * Copyright (C) 2013  Mikkel Oscar Lyderik
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

#include "leds.h"

int main()
{
    struct leds_t leds;

    if (leds_init(&leds) < 0)
        return 1;
    
    for (int i=0; i < 20; i++) {
        if (i % 2 == 0) {
            leds_on(&leds, "blue");
            leds_off(&leds, "green");
        } else {
            leds_off(&leds, "blue");
            leds_on(&leds, "green");
        }
        usleep(1000*100);
    }

    leds_off(&leds, "blue");
    leds_off(&leds, "green");

    leds_trigger(&leds, "blue", "usb-online");

    char trigger[1024];
    leds_trigger_status(&leds, "blue", trigger);

    printf("trigger: %s\n", trigger);

    return 0;
}
