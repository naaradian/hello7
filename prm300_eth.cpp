
#ifdef TEST_PRINT_SPI
printfp("\n\r TCP");
#endif

while(len--)
{

#ifdef TEST_PRINT_SPI
 printfpd(" %02X", (unsigned char)*IPBuff);
#endif

 OperateCommand(IPBuff++);
}
//hier need add answer
// printfpd("time1 :  %d", time1);
//  printfpd("timerun :  %d", timerun);
  breakflag = 1;
 timerun = time1;

 //hier need add breakflag
while((time1-timerun) < (TIME_WAIT_SPI_ETH))
	{ 
	  PRM_PCH();
	  if(!breakflag) break;
	}
// printfpd("time1 :  %d", time1);
 // printfpd("timerun :  %d", timerun);



// printfp("\n\r return");
return;