SC_MODULE(sync_fifo)
{
private:

public:
  sc_in        <bool>        clk;
  sc_in        <bool>        i_valid;
  sc_in        < sc_lv<24> >  i_data;
  sc_fifo_out  < sc_lv<24> >  s;



	SC_CTOR(sync_fifo)
	{
		SC_THREAD(do_sync_fifo, clk.pos());
	}

    void do_sync_fifo();
 };
