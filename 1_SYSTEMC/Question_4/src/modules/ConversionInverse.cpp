/*
 *  Adder.h
 *  SystemC_SimpleAdder
 *
 *  Created by Le Gal on 07/05/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#include "ConversionInverse.h"

void ConversionCouleursInverse(unsigned char ycbcr[3], unsigned char rvb[3]){
	int aux[3], i;
	aux[0] = (int)(ycbcr[0] + 1.402 * (ycbcr[2] - 128));
	aux[1] = (int)(ycbcr[0] - 0.34414 * (ycbcr[1] - 128) - 0.71414 *  (ycbcr[2] - 128));
	aux[2] = (int)(ycbcr[0] + 1.772 * (ycbcr[1] - 128));
	for(i = 0; i<3; i++){
		if(aux[i] < 0)
			rvb[i] = 0;
		else if(aux[i] > 255)
			rvb[i] = 255;
		else
			rvb[i] = (unsigned char)aux[i];
	}
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

