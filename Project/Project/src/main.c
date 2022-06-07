/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>

void configure_extint_channel(void);

int main (void)
{
	system_init();
	configure_extint_channel();
	system_interrupt_enable_global();		//POLLING	while (true) {
	 if (extint_chan_is_detected(BUTTON_0_EIC_LINE)) {
		// Do something in response to EXTINT edge detection
		bool button_pin_state = port_pin_get_input_level(BUTTON_0_PIN);
		port_pin_set_output_level(LED_0_PIN, button_pin_state);
		extint_chan_clear_detected(BUTTON_0_EIC_LINE);
		}
	}
}

void configure_extint_channel(void)
{
 struct extint_chan_conf config_extint_chan;
 extint_chan_get_config_defaults(&config_extint_chan);
 config_extint_chan.gpio_pin = BUTTON_0_EIC_PIN;
 config_extint_chan.gpio_pin_mux = BUTTON_0_EIC_MUX;
 config_extint_chan.gpio_pin_pull = EXTINT_PULL_UP;
 config_extint_chan.detection_criteria = EXTINT_DETECT_BOTH;
 extint_chan_set_config(BUTTON_0_EIC_LINE, &config_extint_chan);
}