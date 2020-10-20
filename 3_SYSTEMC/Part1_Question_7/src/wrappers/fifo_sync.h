SC_MODULE(fifo_sync)
{
private:

public:
  sc_in       <bool>        clk;
  sc_fifo_in  < sc_lv<24> >  e;
	sc_out      < sc_lv<24> >  o_data;
  sc_out      <bool>        o_valid;

	SC_CTOR(fifo_sync)
	{
		SC_THREAD(do_fifo_sync, clk.pos());
	}

    void do_fifo_sync();
 };
