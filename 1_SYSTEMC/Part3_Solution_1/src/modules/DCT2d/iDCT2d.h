/*
 *  Adder.h
 *  SystemC_SimpleAdder
 *
 *  Created by Le Gal on 07/05/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#include "systemc.h"

SC_MODULE(iDCT2d)
{
private:
	int t[3];

public:
	sc_fifo_in <int> e;
    sc_fifo_out<int> s;

	SC_CTOR(iDCT2d)
	{
		SC_THREAD(do_conversion);
		//sensitive << e;
	}

    void do_conversion();
 };
