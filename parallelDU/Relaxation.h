#pragma once
#include <math.h>
#include <iostream>
#include <omp.h>
#include "MethodResolver.h"
class Relaxation :
	public MethodResolver
{
public:
	Relaxation();
	~Relaxation();
	virtual void ApplyMethod();
};

