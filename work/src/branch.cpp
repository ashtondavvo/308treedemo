/*
 * branch.cpp
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

class Branch{
public: bool isNull; //  = false;
	public: Branch* parent;
	public: vec3 position;
	public: vec3 direction;
	public: int count = 0;
	public: vec3 saveDirection;
	float length = 5;

	public: Branch(vec3 v, vec3 d){
		isNull = false;
		parent = nullptr;
		position = v; // may need to copy
		direction = d; // may need to copy
		saveDirection = d; // may need to copy
		std::cout << "standard constructor called" << std::endl;
	}

	public: Branch(Branch* par){
		isNull = false;
		parent = par;
		position = parent->next();
		direction = parent->direction; // need to copy
		saveDirection = direction; // need to copy
	}

//	public: Branch(bool n){
//		//std::cout << "overload 2 constructor called" << std::endl;
//		isNull = n;
//		parent = nullptr;
//		position = vec3(0,0,0); // may need to copy
//		direction = vec3(0,0,0); // may need to copy
//		saveDirection = vec3(0,0,0); // may need to copy
//	}

	public: void reset(){
		this->count = 0;
		direction = saveDirection; // need to copy
	}

	public: vec3 next(){
		vec3 v = direction * length;
		vec3 next = position + v;
		return next;
	}

};
