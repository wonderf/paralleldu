#pragma once
#include <math.h>
#include <iostream>
#include <omp.h>
#include <ctime>

#include "MethodResolver.h"
class Jacoby :
	public MethodResolver
{
public:
	Jacoby();
	~Jacoby();
	void SetZero(double ** u);
	virtual void ApplyMethod();
};

