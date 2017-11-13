#pragma once
#include <math.h>
#include <iostream>
#include <omp.h>
#include "MethodResolver.h"
class Jacoby :
	public MethodResolver
{
public:
	Jacoby();
	~Jacoby();
	virtual void ApplyMethod();
};

