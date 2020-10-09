/*
	Copyright @ Bertrand LE GAL (2012), ENSEIRB-MATMECA School, Talence, France

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 1
*/

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void RGB_2_YCbCr (int rvb[3], int ycbcr[3]){
	ycbcr[0]  = (int)( 0.299 * rvb[0] + 0.587 * rvb[1] + 0.114 * rvb[2]);
	ycbcr[1]  = (int)(-0.1687 * rvb[0] - 0.3313 * rvb[1] + 0.5 * rvb[2] + 128);
	ycbcr[2]  = (int)(0.5 * rvb[0] - 0.4187 * rvb[1] - 0.0813 * rvb[2] + 128);
}

void YCbCr_2_RGB (int ycbcr[3], int rvb[3]){
	rvb[0] = ycbcr[0] + 1.402 * (ycbcr[2] - 128);
	rvb[1] = ycbcr[0] - 0.34414 * (ycbcr[1] - 128) - 0.71414 *  (ycbcr[2] - 128);
	rvb[2] = ycbcr[0] + 1.772 * (ycbcr[1] - 128);
}

//
// Programme de test des fonctions de conversion
//
int main (int argc, char * argv []){
	// main R G B
	int rvb[3] = {  0,   128,   0};
	int ycbcr[3];

	RGB_2_YCbCr (rvb, ycbcr);
	printf("%d %d %d = %d %d %d\n", rvb[0], rvb[1], rvb[2], ycbcr[0], ycbcr[1], ycbcr[2]);

	return 0;
}
