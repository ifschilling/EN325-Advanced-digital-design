#include "./analyseur/ImageOut.h"
#include "./gene/ImageIn.h"
#include "./modules/Conversion.h"
#include "./modules/ConversionInverse.h"
#include "./wrappers/fifo_sync.h"
#include "./wrappers/sync_fifo.h"

#include <iostream>
#include <math.h>

using namespace std;

// POUR EVITER LES DISTORTIONS, IL EST NECESSAIRE D'ULISER DES CANAUX DE TYPE
// INT CAR SINON LES TRONCATURES INT => UNSIGNED INT SONT FAUSSE !
int main (int argc, char * argv []){
	cout << "Initialisation des composants..." << endl;
	ImageIn      		gene ("Data_Generator_1");
	Conversion 			conv ("conversion");
	ConversionInverse 	iconv("iConversion");
	ImageOut 			term ("Terminal_1");
	fifo_sync			wrapin("Wrapper_In");
	sync_fifo			wrapout("Wrapper_Out");

	cout << "Creation des signaux d'interconnexion..." << endl;
	sc_fifo<unsigned char>  s1("FIFO_1", 128);
	sc_fifo<unsigned char>  s2("FIFO_2", 128);
	sc_fifo<unsigned char>  s3("FIFO_3", 128);
	sc_lv<24>	d1("DATA1", 128);
	bool v1("VALID1", 128);
	sc_lv<24>	d2("DATA2", 128);
	bool v2("VALID2", 128);


	cout << "Mapping des composants..." << endl;
	gene.s(s1);
	wrapin.e(s1);

	wrapin.o_data(d1);
	conv.i_data(d1);

	wrapin.o_valid(v1);
	conv.i_valid(v1);

	conv.o_data(d2);
	wrapout.i_data(d2);

	conv.o_valid(v2);
	wrapout.i_valid(v2);

	wrapout.s (s2);
	iconv.e(s2);

	iconv.s(s3);
	term.e (s3);

	cout << "Lancement de la simulation du circuit..." << endl;
	sc_start(100,SC_MS);
	cout << "Fin de la simulation du circuit..." << endl;

    return 0;
}
