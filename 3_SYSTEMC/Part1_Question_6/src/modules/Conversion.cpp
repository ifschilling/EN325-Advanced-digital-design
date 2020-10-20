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

#define WL 2
#define IWL 0
#define POW2 (1<<(WL-IWL))

void ConversionCouleurs(unsigned char rvb[3], unsigned char ycbcr[3]){
	sc_uint<WL> constant00 = sc_uint<WL>(round(POW2 * 0.299));
	sc_uint<WL> constant01 = sc_uint<WL>(round(POW2 * 0.587));
	sc_uint<WL> constant02 = sc_uint<WL>(round(POW2 * 0.144));

	sc_uint<WL> constant10 = sc_uint<WL>(round(POW2 * 0.1687));
	sc_uint<WL> constant11 = sc_uint<WL>(round(POW2 * 0.3313));
	sc_uint<WL> constant12 = sc_uint<WL>(round(POW2 * 0.5));


	sc_uint<WL> constant20 = sc_uint<WL>(round(POW2 * 0.5));
	sc_uint<WL> constant21 = sc_uint<WL>(round(POW2 * 0.4187));
	sc_uint<WL> constant22 = sc_uint<WL>(round(POW2 * 0.0813));

	int aux[3], i;

	aux[0]  = (int)(( constant00 * rvb[0] + constant01 * rvb[1] + constant02 * rvb[2])/POW2);
	aux[1]  = (int)((-constant10 * rvb[0] - constant11 * rvb[1] + constant12 * rvb[2])/POW2 + 128);
	aux[2]  = (int)(( constant20 * rvb[0] - constant21 * rvb[1] - constant22 * rvb[2])/POW2 + 128);
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
