unsigned char *Formula1L(unsigned long f, unsigned char m_band)
{
	unsigned char ver = (m_band>>2)&0x3C;
	unsigned char band = m_band&0xC3;

	unsigned char u0=256;
	unsigned char u1=4;

	unsigned long f_in=f*100;
	unsigned long f_tm;

	static unsigned char b[16];
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
//	double temp_dbl;
	if(band==0x80)
	{
//		if(ver==5)
	  {
			unsigned char att= 0x00;

//			if((f_in>=1770000)&&(f_in<2000000)) att=7;
//			if((f_in>=2000000)&&(f_in<2070000)) att=9;
//			if((f_in>=2070000)&&(f_in<2160000)) att=7;
//			if((f_in>=2160000)&&(f_in<2240000)) att=8;
//			if((f_in>=2240000)&&(f_in<2450000)) att=10;
//			if((f_in>=2450000)&&(f_in<2650000)) att=8;	 
														
			b[0]=7;
			b[1]=0;
			
//			if((f_in>=1770000)&&(f_in<1912000)) b[1]=0x01;
//			if((f_in>=1912000)&&(f_in<2075000)) b[1]=0x04;	
//			if((f_in>=2075000)&&(f_in<2247000)) b[1]=0x10;		
//			if((f_in>=2247000)&&(f_in<2433000)) b[1]=0x02;		
//			if((f_in>=2433000)&&(f_in<2650000)) b[1]=0x08;
			
			if(f_in<=960000)
			{
//			f_tm = f_in - 568000;//550000;
				f_tm = f_in + 1600000;//550000;
				b[2] = 0x01; // Commut K

				double Ftemp = f_tm * 10000.0;
				Fsint = (f_tm * 10000.0); // *2 yoi R
				N = Fsint/Fdds0/4; 
				if(N>38)  N=(N>>1)*2;
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
				if(f_in<=1100000)
				{
					f_tm = f_in + 800000;//550000;
					b[2] = 0x02; // Commut K
					
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/4; 
					if(N>38)  N=(N>>1)*2;
					Fint = N*Fdds0*4;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*4);
					Fdds = Fdds0 + Fstep_dds;
			 //		if(Fdds>Fddsmax) Fddsmax=Fdds;
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
					f_tm = f_in + 800000;//550000;
					b[2] = 0x04; // Commut K
					
					double Ftemp = f_tm * 10000.0;
					Fsint = (f_tm * 10000.0); // *2 yoi R
					N = Fsint/Fdds0/4; 
					if(N>38)  N=(N>>1)*2;
					Fint = N*Fdds0*4;			
					Fdelta = Fsint - Fint;
					Fstep_dds = Fdelta/(N*4);
					Fdds = Fdds0 + Fstep_dds;
			 //		if(Fdds>Fddsmax) Fddsmax=Fdds;
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
		}
	}
	return b;
}