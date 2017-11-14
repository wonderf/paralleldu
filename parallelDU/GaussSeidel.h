#pragma once
#include <math.h>
#include <iostream>
#include <omp.h>
#include <ctime>
#include "MethodResolver.h"
class GaussSeidel :
	public MethodResolver
{
public:
	GaussSeidel();
	~GaussSeidel();
	virtual void ApplyMethod();
};

