#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fir11.h"

int main(int argc, char* argv[]) {

	const int SAMPLES = 600;
	FILE *fin = fopen("input.dat", "r");
	FILE *fout = fopen("out.dat", "w");

	data_t signal = 0;
	data_t output;

	for(int i = 0; i < SAMPLES; i++) {
		fscanf(fin, "%d", &signal);

		//Call the HLS block
		fir11(&output, signal);

		// Save the results.
		fprintf(fout, "%d\n", output);
		printf("%3i %4d %7d\n", i, signal, output);
	}

	fclose(fin);
	fclose(fout);

	//Comparing results with the golden output.
	printf("Comparing against output data \n");
	if(system("diff -w out.dat out.gold.dat")) {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
		fprintf(stdout, "*******************************************\n");
		return 1;
	}
	else {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "PASS: The output matches the golden output!\n");
		fprintf(stdout, "*******************************************\n");
		return 0;
	}
}

