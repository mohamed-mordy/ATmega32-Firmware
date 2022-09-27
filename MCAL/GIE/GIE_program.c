/*
 * GIE_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed
 */

#include <Std_Types.h>
#include <Bit_Math.h>
#include <GIE_interface.h>
#include "GIE_private.h"
#include <GIE_config.h>


void GIE_vEnable(void)
{
	SET_BIT(SREG, 7);
}

void GIE_vDisable(void)
{
	CLEAR_BIT(SREG, 7);
}
