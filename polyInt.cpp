// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "systemc.h"
#include "polyInt.h"

// TODO: Place the implementation of your module here
/*
void polyInt::cal_polyInt() {
	double min = (A.read() < B.read()) ? A.read() : B.read();
	double max = (A.read() > B.read()) ? A.read() : B.read();
	double temp_x = min;
	double sum = 0.0;
	cout<<"cal satrted"<<endl;
	if(Start.read() == true) { 
		cout << "start"<<endl;
		while (temp_x < max) {
			x.write(temp_x);
			//wait();
			sum += y.read()*dx;
			temp_x += dx;
		}
		Res.write(sum);
		cout << "result ready"<<endl;
		Finish.write(true);
	}
	else{
		cout<<"no cal"<<endl;
		Finish.write(false);
	}
}
*/

void polyInt::cal_polyInt() {
	double min;
	double max;
	double temp_x;
	double sum = 0.0;
	double dx ;
	cout<<"cal satrted"<<endl;
	while(1){
		if(Start.read() == true) { 
			min = (A.read() < B.read()) ? A.read() : B.read();
			max = (A.read() > B.read()) ? A.read() : B.read();
			temp_x = min;
			sum = 0;
			dx = (max - min )/5000000.0;
			cout << "start"<<endl;
			while (temp_x < max) {
				x.write(temp_x);
				wait(0,SC_NS);
				sum += y.read()*dx;
				temp_x += dx;
			}
			Res.write(sum);
			cout << "result ready"<<endl;
			Finish.write(true);
		}
		else{
			cout<<"no cal"<<endl;
			Finish.write(false);
		}
		wait();
		Finish.write(false);
	}
}
