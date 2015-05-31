#pragma once
#define PI 3.141592654
#include<GL\glew.h>

#include<boost\timer.hpp>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

using namespace boost;
static   class particule
{
public:
	particule(float al,float bet,float vit,float lfms,int ind);
	float getLife()
	{
		return lifeTime;
	}
	float getInitV()
	{
		return v;
	}
	void draw(float pos1,float pos2,float pos3);
	float rand_a_b(int a, int b);
	float rand_a_b(int a, int b,int ind);
	float convert_to_radian(float deg)
	{

return (PI/180)*deg;
	}

float getAlpha()const
{
	return alpha;
}


float getBeta()const
{
	return beta;
}

float getStart()const
{
	return start;
}
	~particule(void);
private:
	float lifeTime;//temps de vie 
	float v;


	int col[3];
	float alpha,beta;
	double time;
	int index;
	float start;
	GLuint list;

public:
	static int n;

};


