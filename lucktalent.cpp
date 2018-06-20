#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iomanip>

using namespace std;

double rand_normal(double, double);
void bubble_sort(double* myArray, int BUBBLE);

int main(int argc, char const *argv[]){
	bool dados = (bool)atoi(argv[1]);
	int numsim = atoi(argv[2]);
	double probgood; 
	int numiteracoes = 80;
	int numintervalos = atoi(argv[3]);
	double binwidth = atof(argv[4]);
	double mean = 0.6;
	double stddev = 0.1;
	int N = 1000; //número de indivíduos
	double talento[N];
	double capital[N];
	double capitalmedia[N];
	double capitalhist[numintervalos];
	double E; //evento aleatorio

	
	
	ofstream arquivo("dados.txt");
	ofstream histograma("hist.txt");
	srand(4);
	
	for( int i = 0; i< numintervalos; i++){
		capitalhist[i] = 0;
	}
	
	for (int w = 0; w < numsim; w++){

		for (int i = 0; i< N; i++){
			talento[i] = rand_normal(mean, stddev);
			capital[i] = 10;
		}	

		for (int i = 1; i <= numiteracoes; i++){
			
			for (int j = 0; j < N; j++){
				E = rand() / ((double) RAND_MAX);
				probgood = (rand() / ((double) RAND_MAX))*(0.09) + 0.005;
				if (E < probgood){
						if (rand() / ((double) RAND_MAX) < talento[i]){
						capital[j] = 2*capital[i];	
					}
				}
				else if( E < probgood*2){
					capital[j] = capital[i]/2;
		
				}
				
			}
			
			
		
		}
		
		bubble_sort(capital, N);
		if (dados == true){
			for (int j = 0; j < N; j ++){
				arquivo << capital[j] << '\t' << talento[j] << endl;
			}
		}
        //Gerar histograma
		int csi = 0;
		for (int j = 0; j < numintervalos; j++ ){
			//capitalhist[j] = 0;
			if (csi < N){
				while (capital[csi] < (j+1)*binwidth){
					capitalhist[j]++;
					csi++;
					if (csi >= N) break;
				} 
			}
		}
	
	
	
	}
	
	for (int j = 0; j < numintervalos; j++){
		histograma << (j)*binwidth << '\t' << capitalhist[j]/(double)numsim << endl;

	}	
	

	
	arquivo.close();
	histograma.close();
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

void bubble_sort(double* myArray, int BUBBLE) {
		//sort array
	double temp;
	for(int i = 0; i < BUBBLE; i++)
	{

		for (int j = 0; j < BUBBLE-1; j++)
        {
            if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
			}
        }/*End inner for loop*/
	}/*End outer for loop*/
	
}