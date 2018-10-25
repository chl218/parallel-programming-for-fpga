#ifndef _FIR11_H_
#define _FIR11_H_

#include <stdio.h>
#include "ap_int.h"

#define N 11

typedef ap_int<10>	coef_t;
typedef ap_int<18>	data_t;
typedef ap_int<18>	acc_t;

void fir11(data_t *y, data_t x);

#endif
