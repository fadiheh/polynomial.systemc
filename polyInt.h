// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>


#ifndef POLYMOD_H
#define POLYMOD_H   
#include "systemc.h"
#include "poly.h"

// TODO: Define your module here
SC_MODULE(polyInt) {
	sc_in<double> A, B;
	sc_out<double> Res;
	sc_in<bool> Start;
	sc_out<bool> Finish;
	sc_in<bool> Clk;

	sc_signal<double> x, y;
//	double dx; 

	void cal_polyInt();

	SC_CTOR(polyInt){
		poly* p = new poly("poly");
		p->x(x);
		p->y(y);
//		dx = 0.000001;
//		SC_METHOD(cal_polyInt);
//		sensitive<<Clk.pos();
		SC_THREAD(cal_polyInt);
		sensitive<<Clk.pos();
	}
};


#endif // POLYMOD_H
