#include<iostream>
#include<math.h>
#include"particule.h"
#include<boost\timer.hpp>
#include<windows.h>
#include<time.h>

#include <GL/glew.h>

#include<GL/glut.h>
#include<vector>
#include"glsl.h"
using namespace std;
using namespace boost;
using namespace cwc;


void sleep(int seconds)
{
        clock_t endwait;
        endwait = clock () + seconds * CLOCKS_PER_SEC ;
        while (clock() < endwait) {}
}
void keyboard(unsigned char key,int x, int y);
void Repere()
{
	glLineWidth(3);
glBegin(GL_LINES);
//bleu x
glColor3f(0,0,1);
glVertex3f(0,0,0);
glVertex3f(1,0,0);

//vert y
glColor3f(0,1,0);
glVertex3f(0,0,0);
glVertex3f(0,1,0);

//rouge z
glColor3f(1,0,0);
glVertex3f(0,0,0);
glVertex3f(0,0,1);
	glEnd();

glLineWidth(1);
}
void idle()
{
	glutPostRedisplay();
}
static void display()
{static int n;
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	static glShaderManager SM;
static glShader *shader;
if(!n)
{
shader=	SM.loadfromFile("vert2.txt","frag2.txt");

}

static	 timer t;
double t2=t.elapsed();
	glPointSize(23);
static	vector< particule> v;



	Repere();
	if(!n)
	{
	for(int i=0;i<2000;i++)
	{
		v.push_back(particule(45,20,8,1,i));
	}
}
	
	
	
	shader->begin();
	

int c=v.size();

	for(int i=0;i<c;i++)
	{
		

	shader->setUniform1f("p.alpha",v[i].getAlpha(),shader->GetUniformLocation("p.alpha"));
	shader->setUniform1f("p.beta",v[i].getBeta(),shader->GetUniformLocation("p.beta"));
	shader->setUniform1f("p.vIn",v[i].getInitV(),shader->GetUniformLocation("p.vIn"));
	shader->setUniform1f("p.t",t2/2,shader->GetUniformLocation("p.t"));
	shader->setUniform1f("p.start",v[i].getStart(),shader->GetUniformLocation("p.start"));
	shader->setUniform1f("p.life",v[i].getLife(),shader->GetUniformLocation("p.life"));


	v[i].draw(0,0,0);
	}


	shader->end();
	n++;
	
	if(n>2)
		n=1;

glutSwapBuffers();

}
static void resize(int w,int h)
{

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(75.,(GLfloat)w/(GLfloat)h,0.2,100.0);
  gluLookAt(7,3,9,0,0,0,0,0,1);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


}






void init();
int main(int argc,char **argv)
{

glutInit(&argc,argv);
glutInitWindowSize(800,600);
glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);



glutCreateWindow("particule");
GLenum err=glewInit();
if(err!=GLEW_OK)
{return 0;}
init();
glutKeyboardFunc(keyboard);
glutDisplayFunc(display);
glutReshapeFunc(resize);
glutIdleFunc(idle);
glutMainLoop();// ne jamais oublier sinon rien
return 0;
}

void init()
{
     glShadeModel(GL_SMOOTH);
   
    glClearColor(0.0,0.0,0.0,0.0);
glEnable(GL_DEPTH_TEST);







}

void keyboard(unsigned char key,int x, int y)
{

    switch(key) {
    case 27  :
    exit(0);
    break;


default:
break;

break;
    }
    glutPostRedisplay();

}
