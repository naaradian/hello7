struct MACS {
 unsigned char B0;
 unsigned char B1;
 unsigned char B2;
 unsigned char B3;
 unsigned char B4;
 unsigned char B5;
} ;
struct IPS {
 unsigned char B0;
 unsigned char B1;
 unsigned char B2;
 unsigned char B3;
};

struct PORTS {
 unsigned char B0;
 unsigned char B1;
};

struct CHANNEL {
 	MACS	macs;
	IPS		ips;
	IPS		ipu;
	PORTS	pu;
};

struct STMUDPData {
	CHANNEL   ch[2];
 	unsigned char tp[2];
 	unsigned char scr[2];
	unsigned char rz[4];   //36
};
 
union  uSTMUDPData {
	STMUDPData  sud;
	unsigned char byte[sizeof(STMUDPData)];
};
extern uSTMUDPData SUD;
