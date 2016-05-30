// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
// 
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
// 
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "polyInt.h"
#include "polyInt_tb.h"

using namespace std;


int sc_main(int argc, char* argv[])
{
  sc_signal<double> ASig, BSig, ResSig;
  sc_signal<bool> StartSig, FinishSig;

// a clock that has a positive edge only at 10 ns 
  sc_clock TestClk("TestClock", 10, SC_NS,0.5, 10, SC_NS);
  cout<<"salam"<<endl;
  // TODO insert your module here
  polyInt p("polyInt");
  p.A(ASig);
  p.B(BSig);
  p.Res(ResSig);
  p.Start(StartSig);
  p.Finish(FinishSig);
  p.Clk(TestClk);
  // TODO insert your testbench here
  polyInt_tb tb("polyInt_tb");
  tb.A(ASig);
  tb.B(BSig);
  tb.Res(ResSig);
  tb.Start(StartSig);
  tb.Finish(FinishSig);
  tb.Clk(TestClk);

  sc_start();  // run forever

  return 0;

}
