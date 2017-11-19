#include <iostream>
#include "Jacoby.h"
#include "GaussSeidel.h"
#include "Relaxation.h"
using namespace std;

int main() {
	
	Jacoby j;
	j.ApplyMethod();
	
	GaussSeidel gs;
	gs.ApplyMethod();

	Relaxation r;
	r.ApplyMethod();
}