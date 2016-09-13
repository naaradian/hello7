extern "C" void SetMEbN(signed short ebn)
{
ebn *= -1;
float64  tmp = 10 * ( my_log(pow(10,(ebn/100))  - 1) -  my_log(MRCode.Value)) ; //temp

 switch((unsigned)MRModul.Value)
{
 case 0 :  MEbN0.Value = (float64)(tmp - 3.0)/(float64)1.0; break;  //QPSK
 case 1 :  MEbN0.Value = (float64)(tmp - 4.8)/(float64)1.0; break;  //QPSK
 case 2 :  MEbN0.Value = (float64)(tmp - 4.8)/(float64)1.0; break;  //QPSK
 case 3 :  MEbN0.Value = (float64)(tmp - 6.0)/(float64)1.0; break;  //QPSK
 case 4 :  MEbN0.Value = (float64)(tmp - 6.0)/(float64)1.0; break;  //QPSK
 case 5 :  MEbN0.Value = (float64)(tmp - 7.0)/(float64)1.0; break;  //QPSK
 case 6 :  MEbN0.Value = (float64)(tmp - 7.8)/(float64)1.0; break;  //QPSK
 default : MEbN0.Value = (float64)(tmp - 3.0)/(float64)1.0; break;  //QPSK
}

if(SatSound.Value)
 		{
		 if(MEbN0.Value < MTEbN0.Value)
		 {
		 Ring(1,1,5,4);
	//		printfp("\n\r ring! \n\r");
		 }
 		}
dev1.md100se.MEbN00 = (unsigned)(MEbN0.Value *10) 		 & 0xff;
dev1.md100se.MEbN01 = ((unsigned)(MEbN0.Value *10) >> 8)  & 0xff;
}
