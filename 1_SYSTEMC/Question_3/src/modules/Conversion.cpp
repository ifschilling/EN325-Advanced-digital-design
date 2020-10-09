/*
 *  Adder.h
 *  SystemC_SimpleAdder
 *
 *  Created by Le Gal on 07/05/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */
#include "Conversion.h"

void ConversionCouleurs(int rvb[3], int ycbcr[3]){
	ycbcr[0]  = (int)( 0.299 * rvb[0] + 0.587 * rvb[1] + 0.114 * rvb[2]);
	ycbcr[1]  = (int)(-0.1687 * rvb[0] - 0.3313 * rvb[1] + 0.5 * rvb[2] + 128);
	ycbcr[2]  = (int)(0.5 * rvb[0] - 0.4187 * rvb[1] - 0.0813 * rvb[2] + 128);
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

