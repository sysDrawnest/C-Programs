#include <stdio.h>
#include <math.h>

double f(double x) {
    // Define the function to be integrated, for example, f(x) = x^2
    return x * x;
}

double gaussianIntegration(double a, double b, int n) {
    // Gaussian quadrature weights and nodes for n=2
    double weights[] = {1.0, 1.0};
    double nodes[] = {-0.5773502692, 0.5773502692};  // Square root of 1/3

    double result = 0.0;

    for (int i = 0; i < n; i++) {
        // Map nodes from [-1, 1] to [a, b]
        double x = 0.5 * ((b - a) * nodes[i] + (a + b));
        result += weights[i] * f(x);
    }

    // Scale result based on interval width
    result *= 0.5 * (b - a);

    return result;
}

double rombergIntegration(double a, double b, int n) {
    double h, result = 0.0;
    double rombergTable[10][10]; // Adjust the size based on your needs

    // Initialize the first column of the Romberg table
    h = (b - a);
    rombergTable[0][0] = 0.5 * h * (f(a) + f(b));

    // Iterate to fill the Romberg table
    for (int i = 1; i <= n; i++) {
        h = 0.5 * h;
        result = 0.0;

        // Calculate the composite trapezoidal rule approximation
        for (int j = 1; j <= pow(2, i - 2); j++) {
            result += f(a + (2 * j - 1) * h);
        }

        rombergTable[i][0] = 0.5 * rombergTable[i - 1][0] + h * result;

        // Fill the rest of the table using Richardson extrapolation
        for (int k = 1; k <= i; k++) {
            rombergTable[i][k] = rombergTable[i][k - 1] +
                                 (rombergTable[i][k - 1] - rombergTable[i - 1][k - 1]) / (pow(4, k) - 1);
        }
    }

    // The final result is in the last column of the last row
    return rombergTable[n][n];
}


int main() {
    double a, b;
    int n;

    // Input the integration limits and the number of divisions
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);

    // Perform Gaussian integration with n=2
    double gaussianResult = gaussianIntegration(a, b, 2);
    printf("Approximate value using Gaussian integration: %lf\n", gaussianResult);
    
     // Perform Romberg integration
    double rombergResult = rombergIntegration(a, b, n);
    printf("Approximate value using Romberg integration: %lf\n", rombergResult);

    return 0;
}

/* 
	#include <stdio.h>
#include <math.h>

double f(double x) {
    // Define the function to be integrated, for example, f(x) = x^2
    return x * x;
}

double gaussianIntegration(double a, double b, int n) {
    // Gaussian quadrature weights and nodes for n=2
    double weights[] = {1.0, 1.0};
    double nodes[] = {-0.5773502692, 0.5773502692};  // Square root of 1/3

    double result = 0.0;

    for (int i = 0; i < n; i++) {
        // Map nodes from [-1, 1] to [a, b]
        double x = 0.5 * ((b - a) * nodes[i] + (a + b));
        result += weights[i] * f(x);
    }

    // Scale result based on interval width
    result *= 0.5 * (b - a);

    return result;
}

double rombergIntegration(double a, double b, int n) {
    double h, result = 0.0;
    double rombergTable[10][10]; // Adjust the size based on your needs

    // Initialize the first column of the Romberg table
    h = (b - a);
    rombergTable[0][0] = 0.5 * h * (f(a) + f(b));

    // Iterate to fill the Romberg table
    for (int i = 1; i <= n; i++) {
        h = 0.5 * h;
        result = 0.0;

        // Calculate the composite trapezoidal rule approximation
        for (int j = 1; j <= pow(2, i - 2); j++) {
            result += f(a + (2 * j - 1) * h);
        }

        rombergTable[i][0] = 0.5 * rombergTable[i - 1][0] + h * result;

        // Fill the rest of the table using Richardson extrapolation
        for (int k = 1; k <= i; k++) {
            rombergTable[i][k] = rombergTable[i][k - 1] +
                                 (rombergTable[i][k - 1] - rombergTable[i - 1][k - 1]) / (pow(4, k) - 1);
        }
    }

    // The final result is in the last column of the last row
    return rombergTable[n][n];
}

int main() {
    double a, b;
    int n;

    // Input the integration limits and the number of divisions
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter the number of iterations (n): ");
    scanf("%d", &n);

    // Perform Gaussian integration with n=2
    double gaussianResult = gaussianIntegration(a, b, 2);
    printf("Approximate value using Gaussian integration: %lf\n", gaussianResult);

    // Perform Romberg integration
    double rombergResult = rombergIntegration(a, b, n);
    printf("Approximate value using Romberg integration: %lf\n", rombergResult);

    return 0;
}

*/
