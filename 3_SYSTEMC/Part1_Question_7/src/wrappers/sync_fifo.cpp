#include "sync_fifo.h"

void sync_fifo::do_sync_fifo(){
  while (true) {
    wait();
    if(i_valid.read() == 1){
      s.write(i_data.read());
    }
  }
}
