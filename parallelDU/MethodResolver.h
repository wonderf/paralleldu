#pragma once
class MethodResolver
{

public:
	MethodResolver();
	virtual void ApplyMethod() = 0;
	virtual double GetError()=0;
	virtual ~MethodResolver();
private:
protected:
	double x = 1, y = 1;
	const double x = 1, y = 1,eps=1E-3;
	const int N = 1024;
	const double h = 1 / N;
};

