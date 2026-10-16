// This file is part of the SV-Benchmarks collection of verification tasks:
// https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks
//
// SPDX-FileCopyrightText: 2025 Jana Berger
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Prototype declarations of the functions used to communicate with the model checkers
extern unsigned long __VERIFIER_nondet_ulong(void);
extern long __VERIFIER_nondet_long(void);
extern unsigned char __VERIFIER_nondet_uchar(void);
extern char __VERIFIER_nondet_char(void);
extern unsigned short __VERIFIER_nondet_ushort(void);
extern short __VERIFIER_nondet_short(void);
extern float __VERIFIER_nondet_float(void);
extern double __VERIFIER_nondet_double(void);

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error(void) { __assert_fail("0", "Req1_Prop1_Batch132Wrapper_AP.c", 13, "reach_error"); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } return; }
void assume_abort_if_not(int cond) { if(!cond) { abort(); } }



#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define abs(a) (((a) < 0 ) ? -(a) : (a))





// Function prototypes
void initially(void);
void step(void);
void updateVariables(void);
void updateLastVariables(void);
int property(void);
int main(void);


// Internal control logic variables
unsigned char isInitial = 0;

// Signal variables
unsigned char BOOL_unsigned_char_Array_0[2] = {
	0, 1
};
unsigned char* BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var0_Pointer = &(BOOL_unsigned_char_Array_0[0]);
unsigned char* BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var1_Pointer = &(BOOL_unsigned_char_Array_0[1]);
double double_Array_0[2][2] = {
	{0.375, 999999.6}, {16.6, 9999.5}
};
double* double_Array_0_arraydouble_Array_0arrayVar0_Pointer = &(double_Array_0[0][0]);
double* double_Array_0_arraydouble_Array_0arrayVar1_Pointer = &(double_Array_0[1][0]);
double* double_Array_0_arraydouble_Array_0arrayVar2_Pointer = &(double_Array_0[0][1]);
double* double_Array_0_arraydouble_Array_0arrayVar3_Pointer = &(double_Array_0[1][1]);
signed char signed_char_Array_0[2][2] = {
	{10, 2}, {64, 2}
};
signed char* signed_char_Array_0_arraysigned_char_Array_0Var0_Pointer = &(signed_char_Array_0[0][0]);
signed char* signed_char_Array_0_arraysigned_char_Array_0Var1_Pointer = &(signed_char_Array_0[1][0]);
signed char* signed_char_Array_0_arraysigned_char_Array_0Var2_Pointer = &(signed_char_Array_0[0][1]);
signed char* signed_char_Array_0_arraysigned_char_Array_0Var3_Pointer = &(signed_char_Array_0[1][1]);
signed long int signed_long_int_Array_0[1] = {
	-2
};
signed long int* signed_long_int_Array_0_arraysigned_long_int_Array_0Var0_Pointer = &(signed_long_int_Array_0[0]);
signed short int signed_short_int_Array_0[2] = {
	-5, 31574
};
signed short int* signed_short_int_Array_0_arraysigned_short_int_Array_0Var0_Pointer = &(signed_short_int_Array_0[0]);
signed short int* signed_short_int_Array_0_arraysigned_short_int_Array_0Var1_Pointer = &(signed_short_int_Array_0[1]);
unsigned short int unsigned_short_int_Array_0[2][2] = {
	{8, 256}, {50, 0}
};
unsigned short int* unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var0_Pointer = &(unsigned_short_int_Array_0[0][0]);
unsigned short int* unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var1_Pointer = &(unsigned_short_int_Array_0[1][0]);
unsigned short int* unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var2_Pointer = &(unsigned_short_int_Array_0[0][1]);
unsigned short int* unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var3_Pointer = &(unsigned_short_int_Array_0[1][1]);

// Calibration values

// Last'ed variables

// Additional functions


void initially(void) {
}



void step(void) {
	// From: Req1Batch132Wrapper_AP
	if (128 <= (*(signed_long_int_Array_0_arraysigned_long_int_Array_0Var0_Pointer))) {
		(*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var3_Pointer)) = 25;
	}


	// From: Req2Batch132Wrapper_AP
	if ((*(BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var1_Pointer))) {
		(*(double_Array_0_arraydouble_Array_0arrayVar3_Pointer)) = (*(double_Array_0_arraydouble_Array_0arrayVar2_Pointer));
	} else {
		(*(double_Array_0_arraydouble_Array_0arrayVar3_Pointer)) = ((*(double_Array_0_arraydouble_Array_0arrayVar1_Pointer)) + (*(double_Array_0_arraydouble_Array_0arrayVar0_Pointer)));
	}


	// From: Req3Batch132Wrapper_AP
	if ((*(BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var1_Pointer)) || (*(BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var0_Pointer))) {
		(*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var0_Pointer)) = (abs (min ((*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var1_Pointer)) , (*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var2_Pointer)))));
	} else {
		(*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var0_Pointer)) = (*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var1_Pointer));
	}


	// From: Req4Batch132Wrapper_AP
	signed long int stepLocal_0 = 1000 - (*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var2_Pointer));
	if (7.2 < (*(double_Array_0_arraydouble_Array_0arrayVar1_Pointer))) {
		if (((*(signed_char_Array_0_arraysigned_char_Array_0Var0_Pointer)) - ((*(signed_char_Array_0_arraysigned_char_Array_0Var2_Pointer)) + (*(signed_char_Array_0_arraysigned_char_Array_0Var3_Pointer)))) >= stepLocal_0) {
			(*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var0_Pointer)) = (abs ((*(signed_char_Array_0_arraysigned_char_Array_0Var2_Pointer))));
		} else {
			(*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var0_Pointer)) = ((max ((*(signed_char_Array_0_arraysigned_char_Array_0Var0_Pointer)) , (*(signed_char_Array_0_arraysigned_char_Array_0Var2_Pointer)))) - ((*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var1_Pointer)) - (*(signed_char_Array_0_arraysigned_char_Array_0Var3_Pointer))));
		}
	}


	// From: Req5Batch132Wrapper_AP
	if ((*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var0_Pointer)) > ((- 128) + (*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var1_Pointer)))) {
		(*(signed_char_Array_0_arraysigned_char_Array_0Var1_Pointer)) = (*(signed_char_Array_0_arraysigned_char_Array_0Var3_Pointer));
	}
}



void updateVariables(void) {
	BOOL_unsigned_char_Array_0[0] = __VERIFIER_nondet_uchar();
	assume_abort_if_not(BOOL_unsigned_char_Array_0[0] >= 0);
	assume_abort_if_not(BOOL_unsigned_char_Array_0[0] <= 1);
	BOOL_unsigned_char_Array_0[1] = __VERIFIER_nondet_uchar();
	assume_abort_if_not(BOOL_unsigned_char_Array_0[1] >= 0);
	assume_abort_if_not(BOOL_unsigned_char_Array_0[1] <= 1);
	double_Array_0[0][0] = __VERIFIER_nondet_double();
	assume_abort_if_not((double_Array_0[0][0] >= -461168.6018427383000e+13F && double_Array_0[0][0] <= -1.0e-20F) || (double_Array_0[0][0] <= 4611686.018427383000e+12F && double_Array_0[0][0] >= 1.0e-20F ));
	double_Array_0[1][0] = __VERIFIER_nondet_double();
	assume_abort_if_not((double_Array_0[1][0] >= -461168.6018427383000e+13F && double_Array_0[1][0] <= -1.0e-20F) || (double_Array_0[1][0] <= 4611686.018427383000e+12F && double_Array_0[1][0] >= 1.0e-20F ));
	double_Array_0[0][1] = __VERIFIER_nondet_double();
	assume_abort_if_not((double_Array_0[0][1] >= -922337.2036854766000e+13F && double_Array_0[0][1] <= -1.0e-20F) || (double_Array_0[0][1] <= 9223372.036854766000e+12F && double_Array_0[0][1] >= 1.0e-20F ));
	signed_char_Array_0[0][0] = __VERIFIER_nondet_char();
	assume_abort_if_not(signed_char_Array_0[0][0] >= -1);
	assume_abort_if_not(signed_char_Array_0[0][0] <= 127);
	signed_char_Array_0[0][1] = __VERIFIER_nondet_char();
	assume_abort_if_not(signed_char_Array_0[0][1] >= 0);
	assume_abort_if_not(signed_char_Array_0[0][1] <= 64);
	signed_char_Array_0[1][1] = __VERIFIER_nondet_char();
	assume_abort_if_not(signed_char_Array_0[1][1] >= 0);
	assume_abort_if_not(signed_char_Array_0[1][1] <= 63);
	signed_long_int_Array_0[0] = __VERIFIER_nondet_long();
	assume_abort_if_not(signed_long_int_Array_0[0] >= -2147483648);
	assume_abort_if_not(signed_long_int_Array_0[0] <= 2147483647);
	signed_short_int_Array_0[1] = __VERIFIER_nondet_short();
	assume_abort_if_not(signed_short_int_Array_0[1] >= 16383);
	assume_abort_if_not(signed_short_int_Array_0[1] <= 32766);
	unsigned_short_int_Array_0[1][0] = __VERIFIER_nondet_ushort();
	assume_abort_if_not(unsigned_short_int_Array_0[1][0] >= 0);
	assume_abort_if_not(unsigned_short_int_Array_0[1][0] <= 65534);
	unsigned_short_int_Array_0[0][1] = __VERIFIER_nondet_ushort();
	assume_abort_if_not(unsigned_short_int_Array_0[0][1] >= 0);
	assume_abort_if_not(unsigned_short_int_Array_0[0][1] <= 65534);
}



void updateLastVariables(void) {
}

int property(void) {
	return (((((128 <= (*(signed_long_int_Array_0_arraysigned_long_int_Array_0Var0_Pointer))) ? ((*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var3_Pointer)) == ((unsigned short int) 25)) : 1) && ((*(BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var1_Pointer)) ? ((*(double_Array_0_arraydouble_Array_0arrayVar3_Pointer)) == ((double) (*(double_Array_0_arraydouble_Array_0arrayVar2_Pointer)))) : ((*(double_Array_0_arraydouble_Array_0arrayVar3_Pointer)) == ((double) ((*(double_Array_0_arraydouble_Array_0arrayVar1_Pointer)) + (*(double_Array_0_arraydouble_Array_0arrayVar0_Pointer))))))) && (((*(BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var1_Pointer)) || (*(BOOL_unsigned_char_Array_0_arrayBOOL_unsigned_char_Array_0Var0_Pointer))) ? ((*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var0_Pointer)) == ((unsigned short int) (abs (min ((*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var1_Pointer)) , (*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var2_Pointer))))))) : ((*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var0_Pointer)) == ((unsigned short int) (*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var1_Pointer)))))) && ((7.2 < (*(double_Array_0_arraydouble_Array_0arrayVar1_Pointer))) ? ((((*(signed_char_Array_0_arraysigned_char_Array_0Var0_Pointer)) - ((*(signed_char_Array_0_arraysigned_char_Array_0Var2_Pointer)) + (*(signed_char_Array_0_arraysigned_char_Array_0Var3_Pointer)))) >= (1000 - (*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var2_Pointer)))) ? ((*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var0_Pointer)) == ((signed short int) (abs ((*(signed_char_Array_0_arraysigned_char_Array_0Var2_Pointer)))))) : ((*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var0_Pointer)) == ((signed short int) ((max ((*(signed_char_Array_0_arraysigned_char_Array_0Var0_Pointer)) , (*(signed_char_Array_0_arraysigned_char_Array_0Var2_Pointer)))) - ((*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var1_Pointer)) - (*(signed_char_Array_0_arraysigned_char_Array_0Var3_Pointer))))))) : 1)) && (((*(unsigned_short_int_Array_0_arrayunsigned_short_int_Array_0Var0_Pointer)) > ((- 128) + (*(signed_short_int_Array_0_arraysigned_short_int_Array_0Var1_Pointer)))) ? ((*(signed_char_Array_0_arraysigned_char_Array_0Var1_Pointer)) == ((signed char) (*(signed_char_Array_0_arraysigned_char_Array_0Var3_Pointer)))) : 1)
;
}
int main(void) {
	isInitial = 1;
	initially();

	while (1) {
		updateLastVariables();

		updateVariables();
		step();
		__VERIFIER_assert(property());
		isInitial = 0;
	}

	return 0;
}
