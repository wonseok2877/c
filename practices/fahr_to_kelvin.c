#include <stdio.h>

#define LOWER	0
#define UPPER 300
#define STEP 20

/* fahrToKelvin : formula (°F − 32) × 5/9 + 273.15 */
float fahrToKelvin(float F) {
	return (F - 32.0) * 5 / 9 + 273.15;
}


int main() {
    for (float fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3.0f \t %6.1f\n", fahr, fahrToKelvin(fahr));

	return 0;
}
