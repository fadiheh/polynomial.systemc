// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "systemc.h"
#include "polyInt_tb.h"
#include "poly.h"

// TODO: Implement your Testbench here

void polyInt_tb::testBench(){
	double int_coeff[poly_degree+2], correct, res, err;
	int_coeff[0] = 0.0;
	for (unsigned int i=0; i < poly_degree+1; i++) {
		int_coeff[i+1] = poly_coeff[i] / ( (double)(i+1) );
	}
	for(int i=0; i < num; i++){
		cout<<"first test"<<endl;
		A.write(test_vectorA[i]);
		B.write(test_vectorB[i]);
		Start.write(true);
		cout<<"Start <- 1"<<endl;
		do{
			wait();
			//cout<<"wait for result"<<endl;
			Start.write(false);
		} while(Finish.read() == false);
		res = Res.read();
		correct = polynomValue(int_coeff, test_vectorB[i], poly_degree + 1) - polynomValue(int_coeff, test_vectorA[i], poly_degree + 1);
		err = fabs(correct - res) / correct;
		if (err < 0.01) {
			cout<<"correct result for range: ["<<test_vectorA[i]<<","<<test_vectorB[i]<<"], result->"<<res<<"  error->"<<err<<endl;
		}
		else {
			cout<<"wrong result for range: ["<<test_vectorA[i]<<","<<test_vectorB[i]<<"], result->"<<res<<"  correct->"<<correct<<"  error->"<<err<<endl;
		}
		wait();
	}
	sc_stop();
}
