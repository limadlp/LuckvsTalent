#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace std;

double rand_normal(double, double);

int main(){
	int numpontos;
	double mean;
	double stddev;
	cin >> numpontos >> mean >> stddev;
	cout << endl;
		
	ofstream arquivo("dados.txt");
	
	for (int i = 1; i <= numpontos; i++){
	
		arquivo << rand_normal(mean, stddev) << endl;
	
	}
	
	arquivo.close();
	return 0;
}

double rand_normal(double mean, double stddev)
{//Box muller method
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            double result = n1*stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2*stddev + mean;
    }
}