// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include <iostream>
#include "poly.h"

// TODO: implement your function(s) for your Module here

double polynomValue( const double coeff[], double x, int deg){
	double y = coeff[deg];
	for(int i = deg - 1; i >= 0; i--){
		y *= x;
		y += coeff[i];
	}

	return y;
}

void poly::cal_poly(){
	y.write( polynomValue(poly_coeff, x.read(), poly_degree) );
}
