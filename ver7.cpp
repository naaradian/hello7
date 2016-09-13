




				if((f_in>4000000)&&(band==3))
	{
	  if(ver==7)
	  {
//			double Fdds0 = 190000000.0; // переопределение переменной для 4 версии 
			unsigned char att= 0x00;

			if((f_in>=4000000)&&(f_in<4020000)) att=2;
			if((f_in>=4020000)&&(f_in<4040000)) att=4;
			if((f_in>=4040000)&&(f_in<4060000)) att=6;
			if((f_in>=4060000)&&(f_in<4120000)) att=8;
			if((f_in>=4120000)&&(f_in<4200000)) att=5;
			if((f_in>=4200000)&&(f_in<4240000)) att=3;	 
			if((f_in>=4240000)&&(f_in<4260000)) att=5;	
			if((f_in>=4260000)&&(f_in<4280000)) att=7;	
			if((f_in>=4280000)&&(f_in<4500000)) att=10;	
			if((f_in>=4500000)&&(f_in<4530000)) att=7;	
			if((f_in>=4530000)&&(f_in<4550000)) att=5;	
			if((f_in>=4550000)&&(f_in<4570000)) att=3;	
			if((f_in>=4570000)&&(f_in<4600000)) att=1;	
			
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

