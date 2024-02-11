#ifndef TIMER_H
#define TIMER_H

#define PIT_FREQUENCY_HZ 1193182

#define PIT_CH_0_DATA_REG 0x40  /* Channel 0 data port */
#define PIT_CH_1_DATA_REG 0x41  /* Channel 1 data port */
#define PIT_CH_2_DATA_REG 0x42  /* Channel 2 data port */
#define PIT_CMD_REG 0x43        /* Mode/Command register */

static unsigned long timer_ticks;

void timer_init();

#endif