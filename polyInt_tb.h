// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#ifndef POLYINT_TB_H
#define POLYINT_TB_H   
#include "systemc.h"
const int num = 5;
const double test_vectorA[num] = {5.0 , 0.0 , 10.0, -22.0, 0 };
const double test_vectorB[num] = {54.87, 3.0, 18.0, -11.1, 0.1 };

// TODO: Define your Testbench Module here
SC_MODULE(polyInt_tb){
	sc_in<bool> Clk;
	sc_out<bool> Start;
	sc_in<bool> Finish;
	sc_in<double> Res;
	sc_out<double> A, B;

	void testBench();
	
	SC_CTOR(polyInt_tb){
		SC_THREAD(testBench);
		sensitive<<Clk.pos();
	}
};

#endif // POLYINT_TB_H
