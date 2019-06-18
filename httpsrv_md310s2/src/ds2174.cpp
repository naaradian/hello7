//expdata.cpp
#include "ds2174.h"
//#include "disp.h"
//#include "menu.h"
//define global timer counter in internal memory
//Uint32 TimerCounter;
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Ds2174::Ds2174, "ExtFuncs")
#endif	
extern "C" Ds2174::Ds2174()
{
// testexp = 5;
//	State.Reg1.bit.Zumm = 0; //zummer off
//	State.Reg2.bit.LDDS = 1; //need load dds
//	State.Reg2.bit.Some = 1;
}
/*
#ifdef __cplusplus
#pragma CODE_SECTION("ExtFuncs")
#else
#pragma CODE_SECTION(Ds2174::Init, "ExtFuncs")
#endif	
extern "C" void Ds2174::Init()
{

}
*/
//end of file