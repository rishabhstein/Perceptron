#include "Perceptron.h"
#include <graphics.h> 

int main(int argc, char const *argv[])
{
	
	cout << "Run the executable with"<< endl; 
	cout <<"Training points, Training iterations and No. of testing points" << endl;
	cout << "In the following way: "<< endl;
	cout << "./run 10 1 100 " << endl << endl;

	//Initializing graphics engine
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, NULL); 
	int maxX = getmaxx();
	int maxY = getmaxy();

	int train = atoi(argv[1]);	//no. of training Data points
	int test = atoi(argv[3]);	//no. of testing Data points
	int iter = atoi(argv[2]);	//Iteration

	Perceptron *a, *p;
	a = new Perceptron [train];
	p = new Perceptron();

	for (int i = 0; i < train; ++i) 	a[i].training_data();

	p->weight();

	//Training the Perceptron
	for(int j = 0; j < iter; j++){
		for (int i = 0; i < train; ++i){
			 int res =  a[i].guess(p);
			 a[i].update_weights(res, p);
		}
	}

	cout <<"================================="<< endl;
	cout << "Training of network has been done"<< endl;
	cout << "================================="<< endl;
	cout << endl << endl;

	//Testing on other data
	Perceptron	*test_data = new Perceptron [test];

	for (int i = 0; i < test; ++i) 	test_data[i].training_data(); 	


	int tmp = 0;
	for (int i = 0; i < test; ++i){
		setcolor(1); line(0,0,470,470);
		if (test_data[i].guess(p) == test_data[i].label) {
			setcolor(5);
			circle(test_data[i].x, test_data[i].y, 5);
			tmp++;
		}
		else{
		setcolor(3);
		circle(test_data[i].x, test_data[i].y, 5);
		}

		delay(100);
	}

	//Closing the graphic engine
	getch(); 
	closegraph(); 

	cout << endl << endl;
	cout <<"================================="<< endl;
	cout << "Correct answers are : "  << tmp << endl;
	cout << "================================="<< endl;
	return 0;
}