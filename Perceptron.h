#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#include <random>
#include <iostream>
using namespace std;


class Perceptron
{
public:
	double x, y;
	int label;
	double wt[2];

public:
	Perceptron(){x = 0; y = 0; label = 0; wt[0] = 0; wt[1] = 0;}
	~Perceptron(){};


	void weight();
	int sign(double o);
	int guess(Perceptron *ptr);
	void training_data();
	void update_weights(int gues, Perceptron *ptr);
	void gnuplot();
};

#endif //PERCEPTRON_H_