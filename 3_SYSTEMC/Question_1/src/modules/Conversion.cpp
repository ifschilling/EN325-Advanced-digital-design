/*
 *  Adder.h
 *  SystemC_SimpleAdder
 *
 *  Created by Le Gal on 07/05/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#define SC_INCLUDE_FX
#include "Conversion.h"
#include <systemc.h>

#define WL 1
#define IWL 0

void ConversionCouleurs(unsigned char rvb[3], unsigned char ycbcr[3]){
	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant00 = 0.299;
	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant01 = 0.587;
	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant02 = 0.144;

	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant10 = 0.1687;
	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant11 = 0.3313;
	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant12 = 0.5;


	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant20 = 0.5;
	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant21 = 0.4187;
	sc_ufixed<WL,IWL,SC_RND,SC_SAT> constant22 = 0.0813;

	int aux[3], i;

	//sc_fixed<WL,IWL,SC_RND,SC_SAT> input_rvb0 = rvb[0];
	//sc_fixed<WL,IWL,SC_RND,SC_SAT> input_rvb1 = rvb[1];
	//sc_fixed<WL,IWL,SC_RND,SC_SAT> input_rvb2 = rvb[2];

	aux[0]  = (int)( constant00 * rvb[0] + constant01 * rvb[1] + constant02 * rvb[2]);
	aux[1]  = (int)(-constant10 * rvb[0] - constant11 * rvb[1] + constant12 * rvb[2] + 128);
	aux[2]  = (int)( constant20 * rvb[0] - constant21 * rvb[1] - constant22 * rvb[2] + 128);
	for(i = 0; i<3; i++){
		if(aux[i] < 0)
			ycbcr[i] = 0;
		else if(aux[i] > 255)
			ycbcr[i] = 255;
		else
			ycbcr[i] = (unsigned char)aux[i];
	}
}

void Conversion::do_conversion(){
	while( true ){
		for(int i=0; i<3; i++){
			d[i] = e.read();
		}

	   ConversionCouleurs(d, t);

		for(int i=0; i<3; i++){
			s.write( t[i] );
		}
	}
}
