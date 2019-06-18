struct CTableBPSK
{
	unsigned char relative[2];
};

struct CTableQPSK
{
	unsigned char absolute[4];
	unsigned char relative[16];
};

struct CTableQAM16
{
	unsigned char absolute[16];
	unsigned char relative[256];
};

struct CTableQAM32
{
	unsigned char absolute[36];
	unsigned char relative[1024];
};

struct CTableQAM64
{
	unsigned char absolute[64];
	unsigned char relative[4096];
};


struct CTableQAM128
{
	unsigned char absolute[64];
	unsigned char relative[16384];
};

struct CTableQAM256
{
	unsigned char absolute[256];
	unsigned char relative[65536];
};

struct CTableQAM512
{
	unsigned short absolute[576];
	unsigned short relative[262144];
};