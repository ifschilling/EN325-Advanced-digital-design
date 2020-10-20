#include "fifo_sync.h"

void fifo_sync::do_fifo_sync(){
  while (true) {
    wait();
    if(e.num_available() != 0){
      o_data.write(e.read());
      o_valid.write(1);
      wait();
      o_data.write(0);
      o_valid.write(0);
      wait();
      wait();
    }
  }
}
