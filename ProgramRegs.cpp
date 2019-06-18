//file : programregs.cpp
extern "C" void ProgramRegs(unsigned char dev)
{
//1.
  LoadReg(dev,0,1); //reset set all regs to default walue
  delay_mcs(5l);
  LoadReg(dev,1,0x11);
  LoadReg(dev,2,0x4);
  LoadReg(dev,3,0x8);
//  LoadReg(dev,4,0x);
  LoadReg(dev,5,0x0);
  LoadReg(dev,6,0x2a); //0x2a); //69
  LoadReg(dev,7,0x0);
  LoadReg(dev,8,0x0);//2
  LoadReg(dev,9,0x8);//0x14//0x8);  //	14
  LoadReg(dev,10,0x8);
  LoadReg(dev,11,0x4f);
// LoadReg(dev,12,0x);
  LoadReg(dev,13,0x0);
//  LoadReg(dev,14,0x);
  LoadReg(dev,15,0x8);
//  LoadReg(dev,16,0x);
  LoadReg(dev,17,0x0);
  LoadReg(dev,18,0x69);//0x69);	  //3b
  LoadReg(dev,19,0x0);//0x0);	 //01
  LoadReg(dev,20,0); //5
  LoadReg(dev,21,0x8);//0x8);	//18
  LoadReg(dev,22,0x0);
  LoadReg(dev,23,0x4B);
//111227   LoadReg(dev,24,0x0);
  LoadReg(dev,24,0x3); //before calibrating get off filter and modulator
  LoadReg(dev,25,0x8);
//  LoadReg(dev,26,0xff);
//  LoadReg(dev,27,0x0);
//  LoadReg(dev,28,0x0);
  LoadReg(dev,29,0x14);
//  LoadReg(dev,30,0x20);
  LoadReg(dev,30,0);
  LoadReg(dev,31,0xFF);
  LoadReg(dev,32,0xF0);
  LoadReg(dev,33,0x1);
  LoadReg(dev,34,0x18);
  LoadReg(dev,35,0x0);
  LoadReg(dev,36,0x02);
  LoadReg(dev,37,0x0);
  LoadReg(dev,38,0x78);
}
