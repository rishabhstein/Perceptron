// C++ Implementation for drawing line 
#include <graphics.h> 
// driver code 
#include<iostream>
#include<random>

using namespace std;

#define NOP 3	//No. of Pipes
#define NOB 1 	//No. of Birds 		

class Bird
{
public:
	double x,y;	//position of Bird
	double vx,vy;	//velocity
	int tmp; //for testing

public:
	Bird(double x1, double y1, double vx1, double vy1, int tmp1){	
		x = x1; y = y1; vx = vx1; vy = vy1; tmp = tmp1;
	}
	~Bird();
	void bird_update();
	
};

void Bird::bird_update(){
	y += vy; 
	vy += 1.0;
}


class Pipe
{
public:

	double locx[4], locy[4];
	double speed;

public:
	Pipe(){
		speed = 10;
		for (int i = 0; i < 4; ++i)	 {
			locx[i] = 0; locy[i] = 0 ;
		 } 	 
	}
	~Pipe();

	void pipe_update();
};


void Pipe::pipe_update(){	
	for (int i = 0; i < 4; ++i)	locx[i] -= speed;
}


void farthest_pipe(Pipe *pip[NOP], int ind){
	double tmp = 0;
	tmp = pip[ind]->locx[1];
	
	for (int i = 0; i < NOP; ++i){
		tmp = max(tmp, pip[i]->locx[1]);
	}

	pip[ind]->locx[0] = tmp+100;
	pip[ind]->locx[1] = tmp+200;
	pip[ind]->locx[2] = tmp+100;
	pip[ind]->locx[3] = tmp+200;
}

int main() 
{ 

	int gd = DETECT, gm; 
	initgraph(&gd, &gm, NULL); 
	
	int maxX = getmaxx();
	int maxY = getmaxy(); 

	Bird *bob;
	bob = new Bird(maxX/4.0, maxY/2.0, 1, 1, 1);

	double p_x[4], p_y[4];

	//Upper part of Pipe 						//Lower part of pipe
	p_x[0] = maxX/3.0; p_x[1] = maxX/3.0+100; 		p_x[2] = maxX/3.0; p_x[3] = maxX/3.0+100;
	p_y[0] = 0; p_y[1] = maxY/2 - 100; 			p_y[2] = maxY/2 + 100;  p_y[3] = maxY;


	int r  = 0; 
	Pipe **p_new;
	p_new = new Pipe *[NOP];

	for (int i = 0; i < NOP; ++i)	{
		p_new[i] = new Pipe();
		for (int j = 0; j < 4; ++j)	{
			r = rand()%100 + 1;
			p_new[i]->locx[j] = p_x[j] + i*200;
			p_new[i]->locy[j] = p_y[j];
			
			if(i != 0){
				p_new[i]->locy[1] = maxY/2 - r;
				p_new[i]->locy[2] =  maxY/2 + r;
			}
		}
	}
 
	int i = 0;
	while (i < 100)
		{
	
		circle(bob->x, bob->y, 20);
		floodfill(bob->x, bob->y, 4);

		if (bob->y < (maxY-30)) bob->bird_update(); 

		for (int i = 0; i < NOP; ++i){
			rectangle(p_new[i]->locx[0], p_new[i]->locy[0], p_new[i]->locx[1], p_new[i]->locy[1]);
			floodfill((p_new[i]->locx[0] + p_new[i]->locx[1])/2.0,
			 		   (p_new[i]->locy[0] + p_new[i]->locy[1])/2.0, 4);	
			
			rectangle(p_new[i]->locx[2], p_new[i]->locy[2], p_new[i]->locx[3], p_new[i]->locy[3]);
			floodfill((p_new[i]->locx[2] + p_new[i]->locx[3])/2.0,
					 (p_new[i]->locy[2] + p_new[i]->locy[3])/2.0, 4);	

		}

		for (int i = 0; i < NOP; ++i) {
			p_new[i]->pipe_update();
			if (p_new[i]->locx[0] < 10){
				farthest_pipe(p_new, i);
			}
		}

		

		delay(10);

		cleardevice();	
		i++;
		}

		getch(); 
		closegraph(); 

	delete []p_new;
} 
