#include <omp.h>
#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
const int n = 2;
double func(double* y, double time, int i) {
	double w = 0.0;
	switch (i) {
	case 0: {w = y[1]; break; }
	case 1: {w = -0.07 * time * y[1] - time * time * y[0]; break; };
	}
	return w;
}

int main() {
	setlocale(LC_CTYPE, "");
	double y[n] = { 0.0, 0.125 };
double tmax = 1.0; double tau = 0.001; double t = 0.0;
	double yy[n] = { 0.0 };
	double tn = omp_get_wtime();
	while (t < tmax) {
		for (int i = 0; i < n; i++) {
			yy[i] = y[i] + tau * func(y, t, i);
		}
		for (int i = 0; i < n; i++) y[i] = yy[i];
	
		t += tau;
	
	}
	double tk = omp_get_wtime();
	for (int i = 0; i < n; i++) {
		cout << y[i] << endl;
	}
	double deltat = tk - tn;
	cout << "time= " << deltat;
	return 0;
}
