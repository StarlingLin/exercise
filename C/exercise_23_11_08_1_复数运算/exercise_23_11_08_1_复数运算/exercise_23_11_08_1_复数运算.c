#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

struct Complex
{
	double Re;
	double Im;
};

struct Complex ComAdd(struct Complex c1, struct Complex c2)
{
	struct Complex c_add = { c1.Re + c2.Re, c1.Im + c2.Im };
	return c_add;
}

struct Complex ComSub(struct Complex c1, struct Complex c2)
{
	struct Complex c_sub = { c1.Re - c2.Re, c1.Im - c2.Im };
	return c_sub;
}

struct Complex ComMult(struct Complex c1, struct Complex c2)
{
	struct Complex c_mult = { c1.Re * c2.Re - c1.Im * c2.Im, c1.Re * c2.Im + c1.Im * c2.Re };
	return c_mult;
}

int main()
{
	struct Complex c1;
	struct Complex c2;
	scanf("%lf%lf%lf%lf", &c1.Re, &c1.Im, &c2.Re, &c2.Im);
	struct Complex c_add = ComAdd(c1, c2);
	struct Complex c_sub = ComSub(c1, c2);
	struct Complex c_mult = ComMult(c1, c2);
	printf("%.2lf", c_add.Re);
	c_add.Im == 0 ? printf("    ") : printf("%+.2lfi    ", c_add.Im);
	printf("%.2lf", c_sub.Re);
	c_sub.Im == 0 ? printf("    ") : printf("%+.2lfi    ", c_sub.Im);
	printf("%.2lf", c_mult.Re);
	c_mult.Im == 0 ? printf("") : printf("%+.2lfi", c_mult.Im);
}