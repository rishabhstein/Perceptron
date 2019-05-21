#include "Perceptron.h"
default_random_engine generator;


void Perceptron::weight(){ 
	uniform_real_distribution<double> distribution(-1,1);
	for (int i = 0; i < 2; ++i)  wt[i] = distribution(generator); 
}

int Perceptron::sign(double o)
{  if (o >= 0) return 1;
   else  return -1;
}

int Perceptron::guess(Perceptron *ptr){
	double sum = ptr->wt[0] * x + ptr->wt[1] * y;
	int op = sign(sum);
	return op;
}


void Perceptron::training_data(){
	uniform_real_distribution<double> distribution(5,470);
	x = distribution(generator);
	y = distribution(generator);

	if (x > y) label =  -1;
	else label = 1; 
}


void Perceptron::update_weights(int gues, Perceptron *ptr){
	double err = label - gues;
	ptr->wt[0] += err * x * 0.1;
	ptr->wt[1] += err * y * 0.1;
}

void Perceptron::gnuplot()
{


}