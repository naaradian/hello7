//calibr.cpp

PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT Is;
PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT Is1;

#define DELAY_KEEP_CALIBR  0x1000000 //1c

extern "C" void KeepCalibrData()
{

//PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT Is;
for(unsigned i = 0; i < 15; i++)
{
delay_mcs(DELAY_KEEP_CALIBR);
wd_reset();
}


PVG610_API_ModemIqImbalanceStatusGet(0, 0,&Is);
delay_mcs(DELAY_KEEP_CALIBR);
PVG610_API_ModemIqImbalanceStatusGet(0, 0,&Is);

PVG610_API_ModemIqImbalanceStatusGet(1, 0,&Is1);
delay_mcs(DELAY_KEEP_CALIBR);
PVG610_API_ModemIqImbalanceStatusGet(1, 0,&Is1);



/*
typedef __PACK_PREFIX__ struct {
    INT16               diffPhaseTenthsDeg;     // in 0.1 deg resolution
    INT16               diffGainTenthsDB;       // in 0.1 dB resolution
    INT16               dcLeakageITenthsPercent;
    INT16               dcLeakageQTenthsPercent;
} __PACK__ PVG610_IQ_IMBALANCE_STRUCT;

typedef __PACK_PREFIX__ struct {
    PVG610_IQ_IMBALANCE_STRUCT    txTx;
    PVG610_IQ_IMBALANCE_STRUCT    rxRx;
    PVG610_IQ_IMBALANCE_STRUCT    rxTx;
} __PACK__ PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT;

  */

}


extern "C" void PrintCalibrData()
{

//PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT Is;
//PVG610_API_ModemIqImbalanceStatusGet(0, 0,&Is);
/*
typedef __PACK_PREFIX__ struct {
    INT16               diffPhaseTenthsDeg;     // in 0.1 deg resolution
    INT16               diffGainTenthsDB;       // in 0.1 dB resolution
    INT16               dcLeakageITenthsPercent;
    INT16               dcLeakageQTenthsPercent;
} __PACK__ PVG610_IQ_IMBALANCE_STRUCT;

typedef __PACK_PREFIX__ struct {
    PVG610_IQ_IMBALANCE_STRUCT    txTx;
    PVG610_IQ_IMBALANCE_STRUCT    rxRx;
    PVG610_IQ_IMBALANCE_STRUCT    rxTx;
} __PACK__ PVG610_MODEM_IQ_IMBALANCE_STATUS_STRUCT;

  */


 printfpd("\n\n\r Is.txTx.diffPhaseTenthsDeg      : %d",Is.txTx.diffPhaseTenthsDeg);
 printfpd("\n\r Is.txTx.diffGainTenthsDB        : %d",Is.txTx.diffGainTenthsDB);
 printfpd("\n\r Is.txTx.dcLeakageITenthsPercent : %d",Is.txTx.dcLeakageITenthsPercent);
 printfpd("\n\r Is.txTx.dcLeakageQTenthsPercent : %d",Is.txTx.dcLeakageQTenthsPercent);
 printfpd("\n\r Is.rxRx.diffPhaseTenthsDeg      : %d",Is.rxRx.diffPhaseTenthsDeg);
 printfpd("\n\r Is.rxRx.diffGainTenthsDB        : %d",Is.rxRx.diffGainTenthsDB);
 printfpd("\n\r Is.rxRx.dcLeakageITenthsPercent : %d",Is.rxRx.dcLeakageITenthsPercent);
 printfpd("\n\r Is.rxRx.dcLeakageQTenthsPercent : %d",Is.rxRx.dcLeakageQTenthsPercent);
 printfpd("\n\r Is.rxTx.diffPhaseTenthsDeg      : %d",Is.rxTx.diffPhaseTenthsDeg);
 printfpd("\n\r Is.rxTx.diffGainTenthsDB        : %d",Is.rxTx.diffGainTenthsDB);
 printfpd("\n\r Is.rxTx.dcLeakageITenthsPercent : %d",Is.rxTx.dcLeakageITenthsPercent);
 printfpd("\n\r Is.rxTx.dcLeakageQTenthsPercent : %d",Is.rxTx.dcLeakageQTenthsPercent);


 printfpd("\n\n\r Is.txTx.diffPhaseTenthsDeg      : %d",Is1.txTx.diffPhaseTenthsDeg);
 printfpd("\n\r Is.txTx.diffGainTenthsDB        : %d",Is1.txTx.diffGainTenthsDB);
 printfpd("\n\r Is.txTx.dcLeakageITenthsPercent : %d",Is1.txTx.dcLeakageITenthsPercent);
 printfpd("\n\r Is.txTx.dcLeakageQTenthsPercent : %d",Is1.txTx.dcLeakageQTenthsPercent);
 printfpd("\n\r Is.rxRx.diffPhaseTenthsDeg      : %d",Is1.rxRx.diffPhaseTenthsDeg);
 printfpd("\n\r Is.rxRx.diffGainTenthsDB        : %d",Is1.rxRx.diffGainTenthsDB);
 printfpd("\n\r Is.rxRx.dcLeakageITenthsPercent : %d",Is1.rxRx.dcLeakageITenthsPercent);
 printfpd("\n\r Is.rxRx.dcLeakageQTenthsPercent : %d",Is1.rxRx.dcLeakageQTenthsPercent);
 printfpd("\n\r Is.rxTx.diffPhaseTenthsDeg      : %d",Is1.rxTx.diffPhaseTenthsDeg);
 printfpd("\n\r Is.rxTx.diffGainTenthsDB        : %d",Is1.rxTx.diffGainTenthsDB);
 printfpd("\n\r Is.rxTx.dcLeakageITenthsPercent : %d",Is1.rxTx.dcLeakageITenthsPercent);
 printfpd("\n\r Is.rxTx.dcLeakageQTenthsPercent : %d",Is1.rxTx.dcLeakageQTenthsPercent);


}



extern "C" void SetCalibrData()
{
 
for(unsigned i = 0; i < 10; i++)
{
delay_mcs(DELAY_KEEP_CALIBR);
wd_reset();
}
 
//PVG610_API_ModemIqImbalanceTxTxSet(BYTE deviceIndex, BYTE modemIndex,
// INT16 diffPhaseTenthsDeg, INT16 diffGainTenthsDB,
//  INT16 dcLeakageITenthsPercent, INT16 dcLeakageQTenthsPercent);

PVG610_API_ModemIqImbalanceTxTxSet(0,0,Is.txTx.diffPhaseTenthsDeg,Is.txTx.diffGainTenthsDB,
				   	  Is.txTx.dcLeakageITenthsPercent, Is.txTx.dcLeakageQTenthsPercent);

PVG610_API_ModemIqImbalanceTxTxSet(1,0,Is1.txTx.diffPhaseTenthsDeg,Is1.txTx.diffGainTenthsDB,
				   	  Is1.txTx.dcLeakageITenthsPercent, Is1.txTx.dcLeakageQTenthsPercent);

}