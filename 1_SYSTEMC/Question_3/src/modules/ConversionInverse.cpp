/*
 *  Adder.h
 *  SystemC_SimpleAdder
 *
 *  Created by Le Gal on 07/05/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#include "ConversionInverse.h"

void ConversionCouleursInverse(int ycbcr[3], int rvb[3]){
	rvb[0] = ycbcr[0] + 1.402 * (ycbcr[2] - 128);
	rvb[1] = ycbcr[0] - 0.34414 * (ycbcr[1] - 128) - 0.71414 *  (ycbcr[2] - 128);
	rvb[2] = ycbcr[0] + 1.772 * (ycbcr[1] - 128);
}

void ConversionInverse::do_conversion(){
	while( true ){
		for(int i=0; i<3; i++){
			d[i] = e.read();
		}

    	ConversionCouleursInverse(d, t);

		for(int i=0; i<3; i++){
			s.write( t[i] );
		}
	}
}

