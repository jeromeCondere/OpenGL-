
#include<iostream>
#include<time.h>
#include<math.h>

#include "particule.h"
#include<GL\glew.h>
#include<boost\timer.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

using namespace boost;
int particule::n=0;
particule::particule(float al,float bet,float vit,float lifems,int ind):alpha(al),v(vit),lifeTime(lifems),index(ind)
{
	

	beta=bet;
	/*
	
	alpha et beta en degre
	
	*/
	
	start=rand_a_b(0,3,index*9)*(1/(rand_a_b(1,30,index*3)));
	float randA=rand_a_b(-10,10);

alpha+=randA;
	


float randV=rand_a_b(5,10);

if(randV!=0)
v+=(3/randV);

float randT=rand_a_b(2,10);
lifeTime+=(1/randT);



col[0]=rand_a_b(0,255,1);
col[1]=rand_a_b(0,255,2);
col[2]=rand_a_b(0,255,3);



list=glGenLists(1);
glNewList(list,GL_COMPILE);
glPointSize(5);
	glBegin(GL_POINTS);


	glColor3ub(col[0],col[1],col[2]);
	  glVertex3d(0,0,0);
		glColor3ub(col[0],col[1],col[2]);
     glEnd();
glEndList();
}


particule::~particule(void)
{
}
static	boost::mt19937 gen;
static int n;
float particule::rand_a_b(int a,int b)
{
	


	gen.seed(index*17);

	boost::uniform_int<> dist(a, b);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(gen, dist);
    return die();
	n++;

}

void particule::draw(float pos1,float pos2,float pos3)
{
	
	glPointSize(5);
	glCallList(list);



}

float particule::rand_a_b(int a,int b,int ind)
{
	


	gen.seed(ind*17*index);

	boost::uniform_int<> dist(a, b);
    boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(gen, dist);
    return die();
	n++;

}
