#include<stdio.h>

float C_F(float n) {
	n *= 1.8;
	n += 32;
	return n;
}

float C_K(float n) {
	n += 273.15;
	return n;
}

float F_C(float n) {
	n -= 32;
	n /= 1.8;
	return n;
}

float F_K(float n) {
	n = F_C(n);
	n = C_K(n);
	return n;
}

float K_C(float n) {
	n -= 273.15;
	return n;
}

float K_F(float n) {
	n = (n - 273.15) * 1.8;
	n += 32;
	return n;
}

int main(int argc, char* argv[]) {
	char my_type;
	float my_value;
	float C, K, F;

	if (argc <= 1) return 0;
	if (sscanf(argv[1], "%f", &my_value) == 1)
		if (argc == 2) my_type = 'C';
		else if (argc == 3) my_type = argv[2][0];

	switch (my_type) {
		case 'C':
		case 'c':
			C = my_value;
			F = C_F(C);
			K = C_K(C);
			printf("F = %.2f\n", F);
			printf("K = %.2f\n", K);
			break;

		case 'F':
		case 'f':
			F = my_value;
			C = F_C(F);
			K = F_K(F);
			printf("C = %.2f\n", C);
			printf("K = %.2f\n", K);
			break;

		case 'K':
		case 'k':
			K = my_value;
			C = K_C(K);
			F = K_F(K);
			printf("C = %.2f\n", C);
			printf("F = %.2f\n", F);
			break;

		default:
			printf("Error: Invalid type");
			break;
	}
	return 0;
}