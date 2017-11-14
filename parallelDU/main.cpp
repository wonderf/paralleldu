#include <iostream>
#include "Jacoby.h"
#include "GaussSeidel.h"
#include "Relaxation.h"
using namespace std;

int main() {
	
	/*
	Relaxation r;
	r.ApplyMethod();
	*/
	GaussSeidel gs;
	gs.ApplyMethod();

	Jacoby j;
	j.ApplyMethod();
	
}