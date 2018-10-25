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
#pragma HLS ARRAY_PARTITION variable=shift_reg complete dim=1

	acc_t acc = 0;

	TDL: for(int i = N - 1; i > 0; i--){
#pragma HLS PIPELINE
#pragma HLS UNROLL
		shift_reg[i] = shift_reg[i-1];
	}
	shift_reg[0] = x;

	MAC: for(int i = N-1; i >= 0; i--) {
#pragma HLS PIPELINE
#pragma HLS UNROLL
		acc += shift_reg[i] * c[i];
	}

	*y = acc;
}
