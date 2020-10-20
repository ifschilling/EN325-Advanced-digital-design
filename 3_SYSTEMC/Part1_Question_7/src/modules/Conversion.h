/*
 *  Adder.h
 *  SystemC_SimpleAdder
 *
 *  Created by Le Gal on 07/05/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#include "systemc.h"

SC_MODULE(Conversion)
{
private:

public:
	sc_in   <bool>        clk;
  sc_in   < sc_lv<24> >  i_data;
	sc_out  < sc_lv<24> >  o_data;
  sc_in   <bool>        i_valid;
  sc_out  <bool>        o_valid;

	SC_CTOR(Conversion)
	{
		SC_THREAD(do_conversion);
		sensitive << clk.pos();
	}

    void do_conversion();
 };
