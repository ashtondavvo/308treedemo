/*
 * leaf.cpp
 *
 *  Created on: 13/06/2017
 *      Author: Ashton
 */
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept>

#include "cgra_geometry.hpp"
#include "cgra_math.hpp"
#include "simple_image.hpp"
#include "simple_shader.hpp"
#include "opengl.hpp"

using namespace std;
using namespace cgra;


class Leaf{
	public: vec3 position;
	public: bool reached = false;

public: Leaf(){
	position = vec3::random();
	position.x = (position.x *200) -100;
	position.y = (position.y *200) +80;
	position.z = (position.z *200) -100;
}

public: void setReached(){
	//std::cout << "A leaf has been reached" << std::endl;
	reached = true;
}

public: void show(){
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(1, 0, 0);
	cgraSphere(2,10,10,false);
	glPopMatrix();
}

};



//class Leaf{
//
//	private:int WINDOW_WIDTH = 100;
//	private:int WINDOW_HEIGHT = 100;
//	public:vec3 position;
//	public:bool reached = false;
//
//	public:Leaf(){
//		std::cout << "Leaf contructor run" << std::endl;
//		position = vec3(rand() % 100, (rand() % 100) + 100, rand() % 100); // add random variables to this to create random position
//		int r = rand() % (WINDOW_WIDTH / 2);
//		//position = position * r;
//		//position.y = position.y - (WINDOW_WIDTH / 4);
//	}
//
//	public:void setReached(){
//		reached = true;
//	}
//
//	public:void show(){
//		glColor3f(255,255,255);
//		glPushMatrix();
//		glTranslatef(position.x, position.y, position.z);
//		cgraSphere(1.0f, 8, 8, false);
//		glPopMatrix();
//	}
//
//	public:string toString(){
//		return "This is a leaf";
//	}
//};




