/*******************************************************************************
 *	Filename: fir11.cpp
 *
 *	INPUT:
 *		x: signal (chirp)
 *
 *	OUTPUT:
 *		y: filtered output
 *
 ******************************************************************************/

#include "fir11.h"

void fir11(data_t *y, data_t x) {
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};

	static data_t shift_reg[N];

	acc_t acc = 0;

	Shift_Accum_Loop: for(int i = N - 1; i > 0; i--) {
		shift_reg[i] = shift_reg[i-1];
		acc += shift_reg[i] * c[i];
	} // end Shift_Accum_Loop

	acc += x*c[0];
	shift_reg[0] = x;

	*y = acc;
}
