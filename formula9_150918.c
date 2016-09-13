unsigned char *Formula9(unsigned long f, unsigned char m_band, unsigned char m_band2)
{
		unsigned char ver = (m_band>>2)&0x3F;
		unsigned char band = m_band&0x03;
		unsigned char ver050607 = m_band&0x20;
		
		unsigned char u0=256;
		unsigned char u1=4;
		
		unsigned long f_in=f*10;
		unsigned long f_tm;
		
		static unsigned char b[16];
		for(int i=0; i<16; i++) b[i]=0;
		UnEmbHittite ueh;
		ueh.b=0;

		////////////// DDS /////////////////
		double Fdds0 = 190000000.0;
		double Fbase_dds = 700000000.0;
		double df;
		double Fsint;
		double Fint, Fdelta, Fstep_dds, Fdds;
		//		double Fdds_fl;
		unsigned char N;
		////////////////////////////////////
		double dk = 2.980232239;


	if((m_band&0xC3)==0xC3)
	{
		//	double temp_dbl;
		if(m_band2==0x01)
		{
				if((f_in>=5900000)&&(f_in<7500000))
				{
					//if(ver==8)
					//{
					unsigned char att= 0x00;
					
					b[0]=7;
					b[1]=0;
					
					b[12]= (f_in - 5900000)/10000;
					
					if(f_in<6500000)
					{
						f_tm = f_in - 828000;//550000;
						b[2] = 0x02; // K3=0x00 (+5=1) K2=0x01 (+5=1) K1=0x02 (+5=1) женя=0x10

						double Ftemp = f_tm * 10000.0;
						Fsint = (f_tm * 10000.0); // *2 yoi R
						N = Fsint/Fdds0/16; // было 8
						if(N>36)  N=(N>>2)*4;
						Fint = N*Fdds0*16;	// было 8		
						Fdelta = Fsint - Fint;
						Fstep_dds = Fdelta/(N*16);// было 8			
						Fdds = Fdds0 + Fstep_dds;
						//				if(Fdds>Fddsmax) Fddsmax=Fdds;
						Ftemp = N*Fdds*16; // было 8
						
						b[3] = att;	                         
						b[4] = N-4;
						/// DDS
						df = Fdds/Fbase_dds;
						//			__int64 u64base = 281474976710656;
						__int64 u64base =  (__int64)(2814749l);
						u64base *= (__int64)(100000000l);
						u64base += (__int64) (76710656l);
						__int64 u64result = u64base*df;
						unsigned long low = u64result&0xFFFFFFFF;
						unsigned long high = (u64result>>32)&0xFFFFFFFF;
						b[5] = (high>>8)&0xFF;
						b[6] = high&0xFF;
						b[7] = (low>>24)&0xFF;
						b[8] = (low>>16)&0xFF;
						b[9] = (low>>8)&0xFF;
						b[10] = low&0xFF;
					}
					else
					{
						f_tm = f_in - 1588000;//550000;
						b[2] = 0x11; // K3=0x00 (+5=1) K2=0x01 (+5=1) K1=0x02 (+5=1) женя=0x10

						double Ftemp = f_tm * 10000.0;
						Fsint = (f_tm * 10000.0); // *2 yoi R
						N = Fsint/Fdds0/16;  // было 8
						if(N>36)  N=(N>>2)*4;
						Fint = N*Fdds0*16;// было 8			
						Fdelta = Fsint - Fint;
						Fstep_dds = Fdelta/(N*16);// было 8			
						Fdds = Fdds0 + Fstep_dds;
						//				if(Fdds>Fddsmax) Fddsmax=Fdds;
						Ftemp = N*Fdds*16;// было 8
						b[3] = att;	 
						b[4] = N-4;
						/// DDS
						df = Fdds/Fbase_dds;
						//			__int64 u64base = 281474976710656;
						__int64 u64base =  (__int64)(2814749l);
						u64base *= (__int64)(100000000l);
						u64base += (__int64) (76710656l);
						__int64 u64result = u64base*df;
						unsigned long low = u64result&0xFFFFFFFF;
						unsigned long high = (u64result>>32)&0xFFFFFFFF;
						b[5] = (high>>8)&0xFF;
						b[6] = high&0xFF;
						b[7] = (low>>24)&0xFF;
						b[8] = (low>>16)&0xFF;
						b[9] = (low>>8)&0xFF;
						b[10] = low&0xFF;
					}
				}
		}

		if(m_band2==0x02)
		{
			if((f_in>=7100000)&&(f_in<9000000))
			{
				//if(ver==8)
				//{
				unsigned char att= 0x00;
				
				b[0]=7;
				b[1]=0;
				
				b[12]= (f_in - 7100000)/10000;
				
				if(f_in<8000000)
				{
					f_tm = f_in - 828000;//550000;
					b[2] = 0x02; // K3=0x00 (+5=1) K2=0x01 (+5=1) K1=0x02 (+5=1) женя=0x10
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/16; 
//					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*16;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*16);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*16;
					
					b[3] = att;	                         
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
				else
				{
					f_tm = f_in - 1588000;//550000;
					b[2] = 0x11; // K3=0x00 (+5=1) K2=0x01 (+5=1) K1=0x02 (+5=1) женя=0x10
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/16; 
//					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*16;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*16);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*16;
					b[3] = att;	 
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
			}
		}

		if(m_band2==0x03)
		{
			if((f_in>=9000000)&&(f_in<11000000))
			{
				//if(ver==8)
				//{
				unsigned char att= 0x00;
				
				b[0]=7;
				b[1]=0;
				
				b[12]= (f_in - 9000000)/10000;
				
				if(f_in<10000000)
				{
					f_tm = f_in - 828000;//550000;
					b[2] = 0x02; // K3=0x00 (+5=1) K2=0x01 (+5=1) K1=0x02 (+5=1) женя=0x10
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/16; 
//					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*16;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*16);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*16;
					
					b[3] = att;	                         
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
				else
				{
					f_tm = f_in - 1588000;//550000;
					b[2] = 0x11; // K3=0x00 (+5=1) K2=0x01 (+5=1) K1=0x02 (+5=1) женя=0x10
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/16; 
//					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*16;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*16);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*16;
					b[3] = att;	 
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
			}
		}


	}
	else
	{
		if((f_in>=1770000)&&(f_in<2650000))
		{
			if(ver==9)
			{
				unsigned char att= 0x00;
				
				b[0]=7;
				b[1]=0;
				
				b[12]= (f_in - 1770000)/10000;
				
				if((f_in>=1770000)&&(f_in<1912000)) b[1]=0x01;
				if((f_in>=1912000)&&(f_in<2075000)) b[1]=0x04;	
				if((f_in>=2075000)&&(f_in<2247000)) b[1]=0x10;		
				if((f_in>=2247000)&&(f_in<2433000)) b[1]=0x02;		
				if((f_in>=2433000)&&(f_in<2650000)) b[1]=0x08;
				
				if(f_in<2160000)
				{
					f_tm = f_in - 568000;//550000;
					b[2] = 0x02; // Commut K
					if((f_in>=1856000)&&(f_in<1853400))
					{
						b[2] = 0x42; // Commut K		
						f_tm = f_in - 558000;
					}
					if((f_in>=1997500)&&(f_in<2002500))
					{
						b[2] = 0x42; // Commut K		
						f_tm = f_in - 558000;
					}
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/4; 
//					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*4;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*4);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*2;
					
					b[3] = att;	 
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
				else
				{
					f_tm = f_in - 1068000;//550000;
					b[2] = 0x01; // Commut K
					if((f_in>=2191700)&&(f_in<2196700))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2497500)&&(f_in<2502500))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2618000)&&(f_in<2624800))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2230000)&&(f_in<2236000))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2361800)&&(f_in<2367800))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2476300)&&(f_in<2482300))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2540800)&&(f_in<2546000))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2590000)&&(f_in<2597300))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}

					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/4; 
//					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*4;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*4);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*2;
					b[3] = att;	 
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
			}

			if(ver==8)
			{
				unsigned char att= 0x00;
				
				b[0]=7;
				b[1]=0;
				
				b[12]= (f_in - 1770000)/10000;
				
				if((f_in>=1770000)&&(f_in<1912000)) b[1]=0x01;
				if((f_in>=1912000)&&(f_in<2075000)) b[1]=0x04;	
				if((f_in>=2075000)&&(f_in<2247000)) b[1]=0x10;		
				if((f_in>=2247000)&&(f_in<2433000)) b[1]=0x02;		
				if((f_in>=2433000)&&(f_in<2650000)) b[1]=0x08;
				
				if(f_in<2160000)
				{
					f_tm = f_in - 568000;//550000;
					b[2] = 0x02; // Commut K
					if((f_in>=1856000)&&(f_in<1853400))
					{
						b[2] = 0x42; // Commut K		
						f_tm = f_in - 558000;
					}
					if((f_in>=1997500)&&(f_in<2002500))
					{
						b[2] = 0x42; // Commut K		
						f_tm = f_in - 558000;
					}
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/2; 
					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*2;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*2);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*2;
					
					b[3] = att;	 
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
				else
				{
					f_tm = f_in - 1068000;//550000;
					b[2] = 0x01; // Commut K
					if((f_in>=2191700)&&(f_in<2196700))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2497500)&&(f_in<2502500))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2618000)&&(f_in<2624800))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2230000)&&(f_in<2236000))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2361800)&&(f_in<2367800))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2476300)&&(f_in<2482300))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2540800)&&(f_in<2546000))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					if((f_in>=2590000)&&(f_in<2597300))
					{
						b[2] = 0x41; // Commut K		
						f_tm = f_in - 1048000;
					}
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/2;  
					if(N>36)  N=(N>>2)*4;
					Fint = N*Fdds0*2;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*2);
					Fdds = Fdds0 + Fstep_dds;
					//				if(Fdds>Fddsmax) Fddsmax=Fdds;
					Ftemp = N*Fdds*2;
					b[3] = att;	 
					b[4] = N-4;
					/// DDS
					df = Fdds/Fbase_dds;
					//			__int64 u64base = 281474976710656;
					__int64 u64base =  (__int64)(2814749l);
					u64base *= (__int64)(100000000l);
					u64base += (__int64) (76710656l);
					__int64 u64result = u64base*df;
					unsigned long low = u64result&0xFFFFFFFF;
					unsigned long high = (u64result>>32)&0xFFFFFFFF;
					b[5] = (high>>8)&0xFF;
					b[6] = high&0xFF;
					b[7] = (low>>24)&0xFF;
					b[8] = (low>>16)&0xFF;
					b[9] = (low>>8)&0xFF;
					b[10] = low&0xFF;
				}
		}
		
		if(ver==7)
		{
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<2000000)) att=7;
			if((f_in>=2000000)&&(f_in<2070000)) att=9;
			if((f_in>=2070000)&&(f_in<2160000)) att=7;
			if((f_in>=2160000)&&(f_in<2240000)) att=8;
			if((f_in>=2240000)&&(f_in<2450000)) att=10;
			if((f_in>=2450000)&&(f_in<2650000)) att=8;	 
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1912000)) b[1]=0x01;
			if((f_in>=1912000)&&(f_in<2075000)) b[1]=0x04;	
			if((f_in>=2075000)&&(f_in<2247000)) b[1]=0x10;		
			if((f_in>=2247000)&&(f_in<2433000)) b[1]=0x02;		
			if((f_in>=2433000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2160000)
			{
				f_tm = f_in - 568000;//550000;
				b[2] = 0x02; // Commut K
				if((f_in>=1856000)&&(f_in<1853400))
				{
					b[2] = 0x42; // Commut K		
					f_tm = f_in - 558000;
				}
				if((f_in>=1997500)&&(f_in<2002500))
				{
					b[2] = 0x42; // Commut K		
					f_tm = f_in - 558000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2; 
				if(N>36)  N=(N>>2)*4;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*2;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1068000;//550000;
				b[2] = 0x01; // Commut K
				if((f_in>=2191700)&&(f_in<2196700))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2497500)&&(f_in<2502500))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2618000)&&(f_in<2624800))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2230000)&&(f_in<2236000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2361800)&&(f_in<2367800))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2476300)&&(f_in<2482300))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2540800)&&(f_in<2546000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2590000)&&(f_in<2597300))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2;  
				if(N>36)  N=(N>>2)*4;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*2;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==5)
		{
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<2000000)) att=7;
			if((f_in>=2000000)&&(f_in<2070000)) att=9;
			if((f_in>=2070000)&&(f_in<2160000)) att=7;
			if((f_in>=2160000)&&(f_in<2240000)) att=8;
			if((f_in>=2240000)&&(f_in<2450000)) att=10;
			if((f_in>=2450000)&&(f_in<2650000)) att=8;	 
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1912000)) b[1]=0x01;
			if((f_in>=1912000)&&(f_in<2075000)) b[1]=0x04;	
			if((f_in>=2075000)&&(f_in<2247000)) b[1]=0x10;		
			if((f_in>=2247000)&&(f_in<2433000)) b[1]=0x02;		
			if((f_in>=2433000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2160000)
			{
				f_tm = f_in - 568000;//550000;
				b[2] = 0x02; // Commut K
				if((f_in>=1856000)&&(f_in<1853400))
				{
					b[2] = 0x42; // Commut K		
					f_tm = f_in - 558000;
				}
				if((f_in>=1997500)&&(f_in<2002500))
				{
					b[2] = 0x42; // Commut K		
					f_tm = f_in - 558000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2; 
				if(N>38)  N=(N>>1)*2;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*2;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1068000;//550000;
				b[2] = 0x01; // Commut K
				if((f_in>=2191700)&&(f_in<2196700))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2497500)&&(f_in<2502500))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2618000)&&(f_in<2624800))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2230000)&&(f_in<2236000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2361800)&&(f_in<2367800))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2476300)&&(f_in<2482300))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2540800)&&(f_in<2546000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				if((f_in>=2590000)&&(f_in<2597300))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in - 1048000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2;  
				if(N>38)  N=(N>>1)*2;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*2;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==4)
		{
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1790000)) att=1;
			if((f_in>=1790000)&&(f_in<1830000)) att=2;
			if((f_in>=1830000)&&(f_in<1870000)) att=3;
			if((f_in>=1870000)&&(f_in<1910000)) att=4;
			if((f_in>=1910000)&&(f_in<1930000)) att=5;
			if((f_in>=1930000)&&(f_in<2080000)) att=6;	 
			if((f_in>=2080000)&&(f_in<2120000)) att=2;	
			if((f_in>=2120000)&&(f_in<2160000)) att=3;	
			if((f_in>=2160000)&&(f_in<2180000)) att=4;	
			if((f_in>=2180000)&&(f_in<2250000)) att=5;
			if((f_in>=2250000)&&(f_in<2340000)) att=7;
			if((f_in>=2340000)&&(f_in<2360000)) att=5;
			if((f_in>=2360000)&&(f_in<2380000)) att=7;
			if((f_in>=2380000)&&(f_in<2400000)) att=5;
			if((f_in>=2400000)&&(f_in<2430000)) att=6;
			if((f_in>=2430000)&&(f_in<2450000)) att=4;
			if((f_in>=2450000)&&(f_in<2460000)) att=6;
			if((f_in>=2460000)&&(f_in<2470000)) att=4;
			if((f_in>=2470000)&&(f_in<2490000)) att=3;
			if((f_in>=2490000)&&(f_in<2510000)) att=4;
			///
			if((f_in>=2530000)&&(f_in<2540000)) att=1;
			if((f_in>=2540000)&&(f_in<2560000)) att=3;
			if((f_in>=2560000)&&(f_in<2590000)) att=1;
			if((f_in>=2590000)&&(f_in<2630000)) att=3;
			if((f_in>=2630000)&&(f_in<2650000)) att=4;	  
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1912000)) b[1]=0x01;
			if((f_in>=1912000)&&(f_in<2075000)) b[1]=0x04;	
			if((f_in>=2075000)&&(f_in<2247000)) b[1]=0x10;		
			if((f_in>=2247000)&&(f_in<2433000)) b[1]=0x02;		
			if((f_in>=2433000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2160000)
			{
				f_tm = f_in - 568000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2; 
				if(N>38)  N=(N>>1)*2;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*2;
				b[2] = 0x02; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1068000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/2;  
				if(N>38)  N=(N>>1)*2;
				Fint = N*Fdds0*2;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*2);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*2;
				b[2] = 0x01; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==3)
		{
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1850000)) att=0x40;
			if((f_in>=1850000)&&(f_in<2040000)) att=0x50;
			if((f_in>=2040000)&&(f_in<2150000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2200000)) att=0x50;
			if((f_in>=2200000)&&(f_in<2400000)) att=0x60;
			if((f_in>=2400000)&&(f_in<2450000)) att=0x50;	 
			if((f_in>=2450000)&&(f_in<2470000)) att=0x40;	
			if((f_in>=2470000)&&(f_in<2500000)) att=0x30;	
			if((f_in>=2500000)&&(f_in<2510000)) att=0x20;	
			if((f_in>=2510000)&&(f_in<2650000)) att=0x10;
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
		
		if(ver==2)
		{
			
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1800000)) att=0x20;
			if((f_in>=1800000)&&(f_in<1900000)) att=0x30;
			if((f_in>=1900000)&&(f_in<2030000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2400000)) att=0x30;
			if((f_in>=2400000)&&(f_in<2470000)) att=0x20;
			if((f_in>=2400000)&&(f_in<2500000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
		if((ver==1)||(ver==0))
		{
			unsigned char att= 0x00;
			
			if((f_in>=1770000)&&(f_in<1800000)) att=0x20;
			if((f_in>=1800000)&&(f_in<1900000)) att=0x30;
			if((f_in>=1900000)&&(f_in<2150000)) att=0x40;
			if((f_in>=2150000)&&(f_in<2300000)) att=0x30;
			if((f_in>=2300000)&&(f_in<2400000)) att=0x20;
			if((f_in>=2400000)&&(f_in<2500000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=1770000)&&(f_in<1899000)) b[1]=0x10;
			if((f_in>=1899000)&&(f_in<2040000)) b[1]=0x04;	
			if((f_in>=2040000)&&(f_in<2220000)) b[1]=0x01;		
			if((f_in>=2220000)&&(f_in<2302000)) b[1]=0x02;		
			if((f_in>=2302000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<2150000)
			{
				f_tm = f_in - 548000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	}
	
	if((f_in<1770000))
	{
		if((ver==8)||(ver==9))
		{
			unsigned char att= 0x00;
			
			b[12]= (f_in - 260000)/10000;
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x02;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x01;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1452000;//550000;
				double Ftemp = f_tm * 10000.0;
				b[2] = 0x01; // Commut K
				if((f_in>=481000)&&(f_in<487000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				if((f_in>=757500)&&(f_in<762500))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				if((f_in>=893000)&&(f_in<899000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 692000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				b[2] = 0x02; // Commut K
				if((f_in>=1517500)&&(f_in<1502500))
				{
					b[2] = 0x42; // Commut K		
					f_tm = f_in + 682000;
				}
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==7)
		{
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<420000))   att=10;
			if((f_in>=420000)&&(f_in<450000))   att=9;
			if((f_in>=450000)&&(f_in<480000))   att=8;
			if((f_in>=480000)&&(f_in<580000))   att=7;
			if((f_in>=580000)&&(f_in<620000))   att=8;
			if((f_in>=620000)&&(f_in<650000))   att=9;
			if((f_in>=650000)&&(f_in<710000))   att=10;
			if((f_in>=710000)&&(f_in<750000))   att=9;
			if((f_in>=750000)&&(f_in<780000))   att=8;
			if((f_in>=780000)&&(f_in<800000))   att=7;
			if((f_in>=800000)&&(f_in<840000))   att=6;
			if((f_in>=840000)&&(f_in<970000))   att=5;
			if((f_in>=970000)&&(f_in<1000000))  att=4;
			if((f_in>=1000000)&&(f_in<1020000)) att=3;
			if((f_in>=1020000)&&(f_in<1030000)) att=10;
			if((f_in>=1030000)&&(f_in<1120000)) att=11;
			if((f_in>=1120000)&&(f_in<1210000)) att=10;
			if((f_in>=1210000)&&(f_in<1280000)) att=9;
			if((f_in>=1280000)&&(f_in<1300000)) att=10;
			if((f_in>=1300000)&&(f_in<1340000)) att=11;
			if((f_in>=1340000)&&(f_in<1390000)) att=12;
			if((f_in>=1390000)&&(f_in<1490000)) att=13;
			if((f_in>=1490000)&&(f_in<1640000)) att=12;
			if((f_in>=1640000)&&(f_in<1660000)) att=11;
			if((f_in>=1660000)&&(f_in<1700000)) att=9;
			if((f_in>=1700000)&&(f_in<1770000)) att=8;	  
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x02;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x01;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1452000;//550000;
				double Ftemp = f_tm * 10000.0;
				b[2] = 0x01; // Commut K
				if((f_in>=481000)&&(f_in<487000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				if((f_in>=757500)&&(f_in<762500))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				if((f_in>=893000)&&(f_in<899000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 692000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				b[2] = 0x02; // Commut K
				if((f_in>=1517500)&&(f_in<1502500))
				{
					b[2] = 0x42; // Commut K		
					f_tm = f_in + 682000;
				}
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==5)
		{
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<420000))   att=10;
			if((f_in>=420000)&&(f_in<450000))   att=9;
			if((f_in>=450000)&&(f_in<480000))   att=8;
			if((f_in>=480000)&&(f_in<580000))   att=7;
			if((f_in>=580000)&&(f_in<620000))   att=8;
			if((f_in>=620000)&&(f_in<650000))   att=9;
			if((f_in>=650000)&&(f_in<710000))   att=10;
			if((f_in>=710000)&&(f_in<750000))   att=9;
			if((f_in>=750000)&&(f_in<780000))   att=8;
			if((f_in>=780000)&&(f_in<800000))   att=7;
			if((f_in>=800000)&&(f_in<840000))   att=6;
			if((f_in>=840000)&&(f_in<970000))   att=5;
			if((f_in>=970000)&&(f_in<1000000))  att=4;
			if((f_in>=1000000)&&(f_in<1020000)) att=3;
			if((f_in>=1020000)&&(f_in<1030000)) att=10;
			if((f_in>=1030000)&&(f_in<1120000)) att=11;
			if((f_in>=1120000)&&(f_in<1210000)) att=10;
			if((f_in>=1210000)&&(f_in<1280000)) att=9;
			if((f_in>=1280000)&&(f_in<1300000)) att=10;
			if((f_in>=1300000)&&(f_in<1340000)) att=11;
			if((f_in>=1340000)&&(f_in<1390000)) att=12;
			if((f_in>=1390000)&&(f_in<1490000)) att=13;
			if((f_in>=1490000)&&(f_in<1640000)) att=12;
			if((f_in>=1640000)&&(f_in<1660000)) att=11;
			if((f_in>=1660000)&&(f_in<1700000)) att=9;
			if((f_in>=1700000)&&(f_in<1770000)) att=8;	  
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x02;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x01;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1452000;//550000;
				double Ftemp = f_tm * 10000.0;
				b[2] = 0x01; // Commut K
				if((f_in>=481000)&&(f_in<487000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				if((f_in>=757500)&&(f_in<762500))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				if((f_in>=893000)&&(f_in<899000))
				{
					b[2] = 0x41; // Commut K		
					f_tm = f_in + 1432000;
				}
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 692000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				b[2] = 0x02; // Commut K
				if((f_in>=1517500)&&(f_in<1502500))
				{
					b[2] = 0x42; // Commut K		
					f_tm = f_in + 682000;
				}
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==4)
		{
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<420000))   att=10;
			if((f_in>=420000)&&(f_in<450000))   att=9;
			if((f_in>=450000)&&(f_in<480000))   att=8;
			if((f_in>=480000)&&(f_in<580000))   att=7;
			if((f_in>=580000)&&(f_in<620000))   att=8;
			if((f_in>=620000)&&(f_in<650000))   att=9;
			if((f_in>=650000)&&(f_in<710000))   att=10;
			if((f_in>=710000)&&(f_in<750000))   att=9;
			if((f_in>=750000)&&(f_in<780000))   att=8;
			if((f_in>=780000)&&(f_in<800000))   att=7;
			if((f_in>=800000)&&(f_in<840000))   att=6;
			if((f_in>=840000)&&(f_in<970000))   att=5;
			if((f_in>=970000)&&(f_in<1000000))  att=4;
			if((f_in>=1000000)&&(f_in<1020000)) att=3;
			if((f_in>=1020000)&&(f_in<1030000)) att=4;
			if((f_in>=1030000)&&(f_in<1060000)) att=5;
			if((f_in>=1060000)&&(f_in<1090000)) att=5;
			if((f_in>=1090000)&&(f_in<1120000)) att=5;
			if((f_in>=1120000)&&(f_in<1210000)) att=4;
			if((f_in>=1210000)&&(f_in<1280000)) att=3;
			if((f_in>=1280000)&&(f_in<1300000)) att=4;
			if((f_in>=1300000)&&(f_in<1340000)) att=5;
			if((f_in>=1340000)&&(f_in<1390000)) att=6;
			if((f_in>=1390000)&&(f_in<1490000)) att=7;
			if((f_in>=1490000)&&(f_in<1640000)) att=6;
			if((f_in>=1640000)&&(f_in<1660000)) att=5;
			if((f_in>=1660000)&&(f_in<1700000)) att=3;
			if((f_in>=1700000)&&(f_in<1770000)) att=2;	  
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x02;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x01;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1452000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[2] = 0x01; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 692000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[2] = 0x02; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==2)
		{
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x10;
			if((f_in>=1020000)&&(f_in<1160000)) att=0x10;
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x01;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 652000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
		
		if(ver==1)
		{
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x40;
			if((f_in>=560000)&&(f_in<740000)) att=0x30;
			if((f_in>=740000)&&(f_in<810000)) att=0x40;
			if((f_in>=810000)&&(f_in<830000)) att=0x30;	
			if((f_in>=830000)&&(f_in<880000)) att=0x20;	
			if((f_in>=880000)&&(f_in<960000)) att=0x30;	
			if((f_in>=960000)&&(f_in<1110000)) att=0x30;
			if((f_in>=1110000)&&(f_in<1260000)) att=0x10;
			if((f_in>=1260000)&&(f_in<1460000)) att=0x20;	
			if((f_in>=1460000)&&(f_in<=1760000)) att=0x20;	
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1020000)) b[1]=0x01;
			if((f_in>=1020000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1020000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 652000;//852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
		
		if(ver==0)
		{
			unsigned char att= 0x00;
			
			if((f_in>=260000)&&(f_in<560000)) att=0x50;
			if((f_in>=560000)&&(f_in<660000)) att=0x40;
			if((f_in>=660000)&&(f_in<760000)) att=0x30;
			if((f_in>=760000)&&(f_in<910000)) att=0x40;	
			if((f_in>=910000)&&(f_in<960000)) att=0x50;	
			if((f_in>=960000)&&(f_in<1110000)) att=0x40;	
			if((f_in>=1110000)&&(f_in<1610000)) att=0x30;	
			if((f_in>=1610000)&&(f_in<1650000)) att=0x20;	
			if((f_in>=1650000)&&(f_in<1760000)) att=0x10;	 
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=260000)&&(f_in<1050000)) b[1]=0x01;
			if((f_in>=1050000)&&(f_in<1770000)) b[1]=0x02;	
			
			if(f_in<1050000)
			{
				f_tm = f_in + 1412000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;//  *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in + 852000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2;// *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x02+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	}
	if((f_in>=2650000)&&(f_in<40100000))
	{
		if((ver==8)||(ver==9))
		{
			unsigned char att= 0x00;
			
			b[12]= (f_in - 2650000)/10000;
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=2650000)&&(f_in<2790000)) b[1]=0x02;
			if((f_in>=2790000)&&(f_in<2940000)) b[1]=0x20;	
			if((f_in>=2940000)&&(f_in<3100000)) b[1]=0x01;		
			if((f_in>=3100000)&&(f_in<3265000)) b[1]=0x10;		
			if((f_in>=3265000)&&(f_in<3440000)) b[1]=0x40;
			if((f_in>=3440000)&&(f_in<3620000)) b[1]=0x80;		
			if((f_in>=3620000)&&(f_in<3810000)) b[1]=0x04;		
			if((f_in>=3810000)&&(f_in<4010000)) b[1]=0x08;
			
			if(f_in<3310000)//<3000000)
			{
				f_tm = f_in - 828000;//550000;
				b[2] = 0x03; // Commut K
				if((f_in>=3036900)&&(f_in<3042700))
				{
					b[2] = 0x43; // Commut K		
					f_tm = f_in - 818000;
				}
				
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
				
			}
			else
			{
				f_tm = f_in - 1588000;//550000;
				b[2] = 0x04; // Commut K
				if((f_in>=3702300)&&(f_in<3708500))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3797400)&&(f_in<3802400))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3900900)&&(f_in<3903200))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3933400)&&(f_in<3939000))
				{
					b[2] = 0x44; // Commut K	
					f_tm = f_in - 1568000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==7)
		{
			unsigned char att= 0x00;
			
			if((f_in>=2650000)&&(f_in<3160000)) att=16;	
			if((f_in>=3160000)&&(f_in<3310000)) att=15;	
			if((f_in>=3310000)&&(f_in<3460000)) att=14;
			if((f_in>=3460000)&&(f_in<3350000)) att=13;
			if((f_in>=3500000)&&(f_in<3630000)) att=12;
			if((f_in>=3630000)&&(f_in<3690000)) att=10;
			if((f_in>=3690000)&&(f_in<3730000)) att=7;
			if((f_in>=3730000)&&(f_in<3750000)) att=9;
			if((f_in>=3750000)&&(f_in<3800000)) att=7;
			if((f_in>=3800000)&&(f_in<3830000)) att=5;
			if((f_in>=3840000)&&(f_in<3950000)) att=3;
			if((f_in>=3950000)&&(f_in<4000000)) att=1;
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=2650000)&&(f_in<2790000)) b[1]=0x02;
			if((f_in>=2790000)&&(f_in<2940000)) b[1]=0x20;	
			if((f_in>=2940000)&&(f_in<3100000)) b[1]=0x01;		
			if((f_in>=3100000)&&(f_in<3265000)) b[1]=0x10;		
			if((f_in>=3265000)&&(f_in<3440000)) b[1]=0x40;
			if((f_in>=3440000)&&(f_in<3620000)) b[1]=0x80;		
			if((f_in>=3620000)&&(f_in<3810000)) b[1]=0x04;		
			if((f_in>=3810000)&&(f_in<4010000)) b[1]=0x08;
			
			if(f_in<3310000)//<3000000)
			{
				f_tm = f_in - 828000;//550000;
				b[2] = 0x03; // Commut K
				if((f_in>=3036900)&&(f_in<3042700))
				{
					b[2] = 0x43; // Commut K		
					f_tm = f_in - 818000;
				}
				
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
				
			}
			else
			{
				f_tm = f_in - 1588000;//550000;
				b[2] = 0x04; // Commut K
				if((f_in>=3702300)&&(f_in<3708500))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3797400)&&(f_in<3802400))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3900900)&&(f_in<3903200))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3933400)&&(f_in<3939000))
				{
					b[2] = 0x44; // Commut K	
					f_tm = f_in - 1568000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		
		if(ver==5)
		{
			unsigned char att= 0x00;
			
			if((f_in>=2650000)&&(f_in<3160000)) att=16;	
			if((f_in>=3160000)&&(f_in<3310000)) att=15;	
			if((f_in>=3310000)&&(f_in<3460000)) att=14;
			if((f_in>=3460000)&&(f_in<3350000)) att=13;
			if((f_in>=3500000)&&(f_in<3630000)) att=12;
			if((f_in>=3630000)&&(f_in<3690000)) att=10;
			if((f_in>=3690000)&&(f_in<3730000)) att=7;
			if((f_in>=3730000)&&(f_in<3750000)) att=9;
			if((f_in>=3750000)&&(f_in<3800000)) att=7;
			if((f_in>=3800000)&&(f_in<3830000)) att=5;
			if((f_in>=3840000)&&(f_in<3950000)) att=3;
			if((f_in>=3950000)&&(f_in<4000000)) att=1;
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=2650000)&&(f_in<2790000)) b[1]=0x02;
			if((f_in>=2790000)&&(f_in<2940000)) b[1]=0x20;	
			if((f_in>=2940000)&&(f_in<3100000)) b[1]=0x01;		
			if((f_in>=3100000)&&(f_in<3265000)) b[1]=0x10;		
			if((f_in>=3265000)&&(f_in<3440000)) b[1]=0x40;
			if((f_in>=3440000)&&(f_in<3620000)) b[1]=0x80;		
			if((f_in>=3620000)&&(f_in<3810000)) b[1]=0x04;		
			if((f_in>=3810000)&&(f_in<4010000)) b[1]=0x08;
			
			if(f_in<3310000)//<3000000)
			{
				f_tm = f_in - 828000;//550000;
				b[2] = 0x03; // Commut K
				if((f_in>=3036900)&&(f_in<3042700))
				{
					b[2] = 0x43; // Commut K		
					f_tm = f_in - 818000;
				}
				
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
				
			}
			else
			{
				f_tm = f_in - 1588000;//550000;
				b[2] = 0x04; // Commut K
				if((f_in>=3702300)&&(f_in<3708500))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3797400)&&(f_in<3802400))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3900900)&&(f_in<3903200))
				{
					b[2] = 0x44; // Commut K		
					f_tm = f_in - 1568000;
				}
				if((f_in>=3933400)&&(f_in<3939000))
				{
					b[2] = 0x44; // Commut K	
					f_tm = f_in - 1568000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==4)
		{
			unsigned char att= 0x00;
			
			if((f_in>=2650000)&&(f_in<3000000)) att=10;	
			if((f_in>=3000000)&&(f_in<3060000)) att=9;
			if((f_in>=3060000)&&(f_in<3190000)) att=8;
			if((f_in>=3190000)&&(f_in<3280000)) att=7;
			if((f_in>=3280000)&&(f_in<3350000)) att=6;
			if((f_in>=3350000)&&(f_in<3470000)) att=5;
			if((f_in>=3470000)&&(f_in<3540000)) att=4;
			if((f_in>=3540000)&&(f_in<3590000)) att=3;
			if((f_in>=3590000)&&(f_in<3710000)) att=2;
			if(f_in>=3710000) att=0;	  
			
			
			b[0]=7;
			b[1]=0;
			
			if((f_in>=2650000)&&(f_in<2790000)) b[1]=0x02;
			if((f_in>=2790000)&&(f_in<2940000)) b[1]=0x20;	
			if((f_in>=2940000)&&(f_in<3100000)) b[1]=0x01;		
			if((f_in>=3100000)&&(f_in<3265000)) b[1]=0x10;		
			if((f_in>=3265000)&&(f_in<3440000)) b[1]=0x40;
			if((f_in>=3440000)&&(f_in<3620000)) b[1]=0x80;		
			if((f_in>=3620000)&&(f_in<3810000)) b[1]=0x04;		
			if((f_in>=3810000)&&(f_in<4010000)) b[1]=0x08;
			
			if(f_in<3310000)//<3000000)
			{
				f_tm = f_in - 828000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[2] = 0x03; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
				
			}
			else
			{
				f_tm = f_in - 1588000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4;  
				Fint = N*Fdds0*4;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*4);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*4;
				b[2] = 0x04; // Commut K
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver<4)
		{
			unsigned char att= 0x00;
			
			//		if((f_in>=3000000)&&(f_in<3200000)) att=0x30;
			if((f_in>=2650000)&&(f_in<2900000)) att=0x60;	
			if((f_in>=2900000)&&(f_in<3200000)) att=0x70;
			if((f_in>=3200000)&&(f_in<3350000)) att=0x80;
			if((f_in>=3350000)&&(f_in<3700000)) att=0x70;
			if((f_in>=3700000)&&(f_in<3800000)) att=0x60;
			if((f_in>=3800000)&&(f_in<3850000)) att=0x50;
			if((f_in>=3850000)&&(f_in<3900000)) att=0x40;
			if((f_in>=3900000)&&(f_in<3950000)) att=0x30;
			if((f_in>=3950000)&&(f_in<4000000)) att=0x20;
			if(f_in>=4000000) att=0x10;	
			
			b[0]=6;
			b[1]=0;
			
			if((f_in>=2650000)&&(f_in<2750000)) b[1]=0x01;
			if((f_in>=2750000)&&(f_in<2870000)) b[1]=0x02;	
			if((f_in>=2870000)&&(f_in<3010000)) b[1]=0x04;		
			if((f_in>=3010000)&&(f_in<3170000)) b[1]=0x08;		
			if((f_in>=3170000)&&(f_in<3350000)) b[1]=0x10;
			if((f_in>=3350000)&&(f_in<3550000)) b[1]=0x20;		
			if((f_in>=3550000)&&(f_in<3770000)) b[1]=0x40;		
			if((f_in>=3770000)&&(f_in<4010000)) b[1]=0x80;
			
			if(f_in<3200000)//<3000000)
			{
				f_tm = f_in - 518000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x04+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1048000;//550000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0)/2; // *2 yoi R
				N = Fsint/Fdds0;  
				Fint = N*Fdds0;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/N;
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds;
				b[2] = 0x01+att;	 // Eiiiooaoi? K
				ueh.eh.bit7 = 1;
				ueh.eh.bit6 = 0;
				ueh.eh.bit5 = 0;
				ueh.eh.bit4 = 0;
				ueh.eh.bit3 = 0;
				ueh.eh.bit2 = 0;
				ueh.eh.bit1 = 0;
				b[4] = N&0x7F;
				ueh.eh.bit0 = (N&0x80)>>7;
				b[3] = ueh.b;	
				b[5]= 0x00;
				/// DDS
				df = Fdds/Fbase_dds;
				//				__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[6] = (high>>8)&0xFF;
				b[7] = high&0xFF;
				b[8] = (low>>24)&0xFF;
				b[9] = (low>>16)&0xFF;
				b[10] = (low>>8)&0xFF;
				b[11] = low&0xFF;
			}
		}
	}
	if((f_in>4000000)&&(band==3))
	{
		if((ver==8)||(ver==9))
		{
			//			double Fdds0 = 190000000.0; // переопределение переменной для 4 версии 
			unsigned char att= 0x00;
			
			b[12]= (f_in - 4000000)/10000;
			
			b[0]=7;
			b[1]=0;
			
			if(f_in<5000000)
			{
				f_tm = f_in - 768000;
				b[2] = 0x02; // Commut K		//100923
				if((f_in>=4065800)&&(f_in<4086200))
				{
					b[2] = 0x42; // Commut K		//100923
					f_tm = f_in - 758000;
				}
				if((f_in>=4897700)&&(f_in<4902200))
				{
					b[2] = 0x42; // Commut K		//100923
					f_tm = f_in - 758000;
				}
				
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1468000;
				b[2] = 0x01; // Commut K  //100923
				if((f_in>=5597700)&&(f_in<5602200))
				{
					b[2] = 0x41; // Commut K		//100923
					f_tm = f_in - 1448000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==7)
		{
			//			double Fdds0 = 190000000.0; // переопределение переменной для 4 версии 
			unsigned char att= 0x00;
			
			if((f_in>=4310000)&&(f_in<4360000)) att=3;
			if((f_in>=4540000)&&(f_in<4790000)) att=5;
			if((f_in>=4790000)&&(f_in<4910000)) att=3;
			if((f_in>=4910000)&&(f_in<4970000)) att=5;
			if((f_in>=4970000)&&(f_in<5110000)) att=8;
			if((f_in>=5110000)&&(f_in<5350000)) att=10;	 
			if((f_in>=5350000)&&(f_in<5370000)) att=11;	
			if((f_in>=5370000)&&(f_in<5480000)) att=15;	
			if((f_in>=5480000)&&(f_in<5510000)) att=13;	
			if((f_in>=5510000)&&(f_in<5570000)) att=11;	
			if((f_in>=5570000)&&(f_in<5590000)) att=8;	
			if((f_in>=5590000)&&(f_in<5780000)) att=6;	
			if((f_in>=5780000)&&(f_in<5810000)) att=5;
			if((f_in>=5810000)&&(f_in<5840000)) att=3;
			
			b[0]=7;
			b[1]=0;
			
			if(f_in<5000000)
			{
				f_tm = f_in - 768000;
				b[2] = 0x02; // Commut K		//100923
				if((f_in>=4065800)&&(f_in<4086200))
				{
					b[2] = 0x42; // Commut K		//100923
					f_tm = f_in - 758000;
				}
				if((f_in>=4897700)&&(f_in<4902200))
				{
					b[2] = 0x42; // Commut K		//100923
					f_tm = f_in - 758000;
				}
				
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1468000;
				b[2] = 0x01; // Commut K  //100923
				if((f_in>=5597700)&&(f_in<5602200))
				{
					b[2] = 0x41; // Commut K		//100923
					f_tm = f_in - 1448000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		
		if(ver==5)
		{
			//			double Fdds0 = 190000000.0; // переопределение переменной для 4 версии 
			unsigned char att= 0x00;
			
			if((f_in>=4310000)&&(f_in<4360000)) att=3;
			if((f_in>=4540000)&&(f_in<4790000)) att=5;
			if((f_in>=4790000)&&(f_in<4910000)) att=3;
			if((f_in>=4910000)&&(f_in<4970000)) att=5;
			if((f_in>=4970000)&&(f_in<5110000)) att=8;
			if((f_in>=5110000)&&(f_in<5350000)) att=10;	 
			if((f_in>=5350000)&&(f_in<5370000)) att=11;	
			if((f_in>=5370000)&&(f_in<5480000)) att=15;	
			if((f_in>=5480000)&&(f_in<5510000)) att=13;	
			if((f_in>=5510000)&&(f_in<5570000)) att=11;	
			if((f_in>=5570000)&&(f_in<5590000)) att=8;	
			if((f_in>=5590000)&&(f_in<5780000)) att=6;	
			if((f_in>=5780000)&&(f_in<5810000)) att=5;
			if((f_in>=5810000)&&(f_in<5840000)) att=3;
			
			b[0]=7;
			b[1]=0;
			
			if(f_in<5000000)
			{
				f_tm = f_in - 768000;
				b[2] = 0x02; // Commut K		//100923
				if((f_in>=4065800)&&(f_in<4086200))
				{
					b[2] = 0x42; // Commut K		//100923
					f_tm = f_in - 758000;
				}
				if((f_in>=4897700)&&(f_in<4902200))
				{
					b[2] = 0x42; // Commut K		//100923
					f_tm = f_in - 758000;
				}
				
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1468000;
				b[2] = 0x01; // Commut K  //100923
				if((f_in>=5597700)&&(f_in<5602200))
				{
					b[2] = 0x41; // Commut K		//100923
					f_tm = f_in - 1448000;
				}
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver==4)
		{
			//			double Fdds0 = 190000000.0; // переопределение переменной для 4 версии 
			unsigned char att= 0x00;
			
			if((f_in>=4310000)&&(f_in<4360000)) att=3;
			if((f_in>=4540000)&&(f_in<4790000)) att=5;
			if((f_in>=4790000)&&(f_in<4910000)) att=3;
			if((f_in>=4910000)&&(f_in<4970000)) att=5;
			if((f_in>=4970000)&&(f_in<5110000)) att=8;
			if((f_in>=5110000)&&(f_in<5350000)) att=10;	 
			if((f_in>=5350000)&&(f_in<5370000)) att=11;	
			if((f_in>=5370000)&&(f_in<5480000)) att=15;	
			if((f_in>=5480000)&&(f_in<5510000)) att=13;	
			if((f_in>=5510000)&&(f_in<5570000)) att=11;	
			if((f_in>=5570000)&&(f_in<5590000)) att=8;	
			if((f_in>=5590000)&&(f_in<5780000)) att=6;	
			if((f_in>=5780000)&&(f_in<5810000)) att=5;
			if((f_in>=5810000)&&(f_in<5840000)) att=3;
			
			b[0]=7;
			b[1]=0;
			
			if(f_in<5000000)
			{
				f_tm = f_in - 768000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				//100923			b[2] = 0x01; // Commut K
				b[2] = 0x02; // Commut K		//100923
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1468000;
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				//100923			b[2] = 0x02; // Commut K
				b[2] = 0x01; // Commut K  //100923
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
		
		if(ver<4)
		{
			//			double Fdds0 = 190000000.0; // переопределение переменной для 4 версии 
			unsigned char att= 0x00;
			
			if((f_in>=4310000)&&(f_in<4360000)) att=3;
			if((f_in>=4540000)&&(f_in<4790000)) att=5;
			if((f_in>=4790000)&&(f_in<4910000)) att=3;
			if((f_in>=4910000)&&(f_in<4970000)) att=5;
			if((f_in>=4970000)&&(f_in<5110000)) att=8;
			if((f_in>=5110000)&&(f_in<5350000)) att=10;	 
			if((f_in>=5350000)&&(f_in<5370000)) att=11;	
			if((f_in>=5370000)&&(f_in<5480000)) att=15;	
			if((f_in>=5480000)&&(f_in<5510000)) att=13;	
			if((f_in>=5510000)&&(f_in<5570000)) att=11;	
			if((f_in>=5570000)&&(f_in<5590000)) att=8;	
			if((f_in>=5590000)&&(f_in<5780000)) att=6;	
			if((f_in>=5780000)&&(f_in<5810000)) att=5;
			if((f_in>=5810000)&&(f_in<5840000)) att=3;
			
			b[0]=7;
			b[1]=0;
			
			if(f_in<5000000)
			{
				f_tm = f_in - 768000;
				b[2] = 0x02; // Commut K		//100923
				
										 /*				if(test_shift_mode) 
										 {
										 b[2] = 0x42; // Commut K		//100923
										 f_tm = f_in - 758000;
			}*/
				
			/*				if((f_in>=4010000)&&(f_in<4100000))
			{
			b[2] = 0x42; // Commut K		//100923
			f_tm = f_in - 758000;
			}*/
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				//100923			b[2] = 0x01; // Commut K
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
			else
			{
				f_tm = f_in - 1468000;
				b[2] = 0x01; // Commut K  //100923
				
										 /*				if(test_shift_mode) 
										 {
										 b[2] = 0x41; // Commut K		//100923
										 f_tm = f_in - 1448000;
			}*/
			/*
			if((f_in>=5100000)&&(f_in<5200000))
			{
			b[2] = 0x41; // Commut K		//100923
			f_tm = f_in - 1448000;
			}*/
				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/8;  
				if(N>38) N = (N>>1)*8; // увеличиваем шаг синтезатора в 2 раза
				Fint = N*Fdds0*8;			
				Fdelta = Fsint - Fint;
				Fstep_dds = Fdelta/(N*8);
				Fdds = Fdds0 + Fstep_dds;
				//				if(Fdds>Fddsmax) Fddsmax=Fdds;
				Ftemp = N*Fdds*8;
				//100923			b[2] = 0x02; // Commut K
				
				b[3] = att;	 
				b[4] = N-4;
				/// DDS
				df = Fdds/Fbase_dds;
				//			__int64 u64base = 281474976710656;
				__int64 u64base =  (__int64)(2814749l);
				u64base *= (__int64)(100000000l);
				u64base += (__int64) (76710656l);
				__int64 u64result = u64base*df;
				unsigned long low = u64result&0xFFFFFFFF;
				unsigned long high = (u64result>>32)&0xFFFFFFFF;
				b[5] = (high>>8)&0xFF;
				b[6] = high&0xFF;
				b[7] = (low>>24)&0xFF;
				b[8] = (low>>16)&0xFF;
				b[9] = (low>>8)&0xFF;
				b[10] = low&0xFF;
			}
		}
	}
	}
 return b;
}