/*
 *  Adder.h
 *  SystemC_SimpleAdder
 *
 *  Created by Le Gal on 07/05/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#include "Conversion.h"

void ConversionCouleurs(unsigned char rvb[3], unsigned char ycbcr[3]){
	int aux[3], i;
	aux[0]  = (int)( 0.299 * rvb[0] + 0.587 * rvb[1] + 0.114 * rvb[2]);
	aux[1]  = (int)(-0.1687 * rvb[0] - 0.3313 * rvb[1] + 0.5 * rvb[2] + 128);
	aux[2]  = (int)(0.5 * rvb[0] - 0.4187 * rvb[1] - 0.0813 * rvb[2] + 128);
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

