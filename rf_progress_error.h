/*****************************************************************************************   
* MaxLinear, Inc. retains all right, title and interest (including all intellectual
* property rights) in and to this computer program, which is protected by applicable
* intellectual property laws.  Unless you have obtained a separate written license from
* MaxLinear, Inc. or an authorized licensee of MaxLinear, Inc., you are not authorized
* to utilize all or a part of this computer program for any purpose (including
* reproduction, distribution, modification, and compilation into object code), and you
* must immediately destroy or return all copies of this computer program.  If you are
* licensed by MaxLinear, Inc. or an authorized licensee of MaxLinear, Inc., your rights
* to utilize this computer program are limited by the terms of that license.
*
* This computer program contains trade secrets owned by MaxLinear, Inc. and, unless
* authorized by MaxLinear, Inc. in writing, you agree to maintain the confidentiality
* of this computer program and related information and to not disclose this computer
* program and related information to any other person or entity.
*
* Misuse of this computer program or any information contained in it may results in
* violations of applicable law.  MaxLinear, Inc. vigorously enforces its copyright,
* trade secret, patent, contractual, and other legal rights.
*
* THIS COMPUTER PROGRAM IS PROVIDED “AS IS” WITHOUT ANY WARRANTIES, AND MAXLINEAR, INC.
* EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING THE WARRANTIES OF
* MERCHANTIBILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND NONINFRINGEMENT.
****************************************************************************************
*                                        Copyright (c) 2012, MaxLinear, Inc.
****************************************************************************************/

#ifndef _rf_progress_error_
#define _rf_progress_error_


#ifdef __cplusplus
extern "C" {
#endif



//////////////////////////////////////////////////////////////////////////////
// RF last error handlers
//////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------
// enums
// ** update also mdp enum **
//-----------------------------------------------------------

#define FOREACH_RF_PRGORESS(RF_PROGRESS)                                                                                        \
        RF_PROGRESS(HALRF_PROGRESS_SUCCESS_E)                                                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_Working_Mode_1T1R_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_Working_Mode_2T2R_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_AGC_Configuration_Open_Loop_Rate_D_dB_Per_Sec_PW_D10_dBm_E)        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_AGC_Configuration_Closed_Loop_Rate_D_dB_Per_Sec_PW_D10_dBm_E)        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RF_AllInitialize_MSG_WB_TX_AGC_Configure_DAC_D__E)                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_OTA_D_Enabled_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_OTA_D_Disabled_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_OTA_D_Disabled_Due_To_DAC_Transmission_Mode_E)                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_AllInitialize_MSG_NCO_Tx0_D_KHz_Tx1_D_KHz_E)                                        \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_LoSharingSet_MSG_Share_PLL_From_STX_D_To_STX_D__E)                                  \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_LoSharingSet_MSG_Share_PLL_From_SRX_D_To_SRX_D__E)                                  \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Started_E)                                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Done_E)                                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_RF_System_Reset_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_ADPD_Enabled_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_ADPD_Disabled_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Working_Mode_Single_Channel_E)                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Working_Mode_Dual_Channel_E)                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Channel_Spacing_D_MHz_LPF_D_MHz_E)                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Channel_Spacing_D_MHz_LPF_Dual_Channel_E)                              \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Master_Configuration_File_Loaded_E)                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Freeze_AGC_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_General_Registers_Initialize_E)                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Initialize_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Synt_Initialize_Started_E)                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxInitialize_MSG_Synt_Initialize_Done_E)                                            \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_RF_System_Reset_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_General_Registers_Initialize_E)                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_Synt_Init_Freq_D_KHz_E)                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_Synt_Calib_Bg_D_Vref_D__E)                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_Synt_MSG_Synt_Actual_Freq_D_KHz_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_SyntFreqOffsetSet_MSG_DCC_Offset_D_KHz_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_SyntFreqOffsetSet_MSG_DDS_Offset_D_KHz_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_Synt_MSG_Clock_Mode_DDS0_Freq_D_KHz_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_Synt_MSG_Clock_Mode_DDS1_Freq_D_KHz_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_Synt_MSG_Clock_Mode_TCXO_Freq_D_KHz_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_Synt_VCOArrayInit_MSG_A1_Locking_Failed_Assuming_A1M4_E)                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_Clock_Mode_TCXO_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_Clock_Mode_DDS0_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_Clock_Mode_DDS1_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_Clock_Mode_VCXO_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_Clock_Mode_NONE_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_SyntInitialize_MSG_NCO_Offset_D_KHz_E)                                                \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Started_E)                                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Done_E)                                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_RF_System_Reset_E)                                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Working_Mode_Single_Channel_E)                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Working_Mode_Dual_Channel_E)                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Channel_Spacing_D_MHz_E)                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_LPF_D_MHz_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Master_Configuration_File_Loaded_E)                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Freeze_AGC_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_General_Registers_Initialize_E)                                    \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Initialize_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Synt_Initialize_Started_E)                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Synt_Initialize_Done_E)                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxInitialize_MSG_Assume_External_Synt_E)                                            \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxStandbySet_MSG_Enable_is_D__E)                                                    \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Started_E)                                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Done_E)                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Calibration_XML_Load_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Calibration_Data_Set_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Load_TX_AGC_Tables_To_Modem_E)                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Post_General_Registers_Initialize_E)                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Synt_Post_General_Registers_Initialize_E)                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Unfreeze_AGC_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_TxCalibrate_MSG_Set_BB_LPF_To_Max_E)                                                \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Started_E)                                                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Done_E)                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Calibration_XML_Load_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Calibration_Data_Set_E)                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Load_RX_AGC_Tables_To_Modem_E)                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Post_General_Registers_Initialize_E)                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Synt_Post_General_Registers_Initialize_E)                            \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Unfreeze_AGC_E)                                                        \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_API_RxCalibrate_MSG_Reset_And_Set_RX_Over_RX_E)                                            \
                                                                                                                                \
        RF_PROGRESS(HALRF_PROGRESS_FUNC_DEBUG_MSG__D__D__S__E)                                                                    \
        RF_PROGRESS(HALRF_PROGRESS_MAX_E)   


#define FOREACH_RF_ERROR(RF_ERROR) \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_StatusGet_MSG_Chip_Not_Initialized_E)                                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_Invalid_Input_Params_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_Invalid_XPIC_Mode_D_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_Both_TX_NOT_IN_USE_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_FW_Params_Get_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_WB_TX_AGC_ADPD_Mode_Set_DAC_D_Failed_E)                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_WB_TX_AGC_Configure_DAC_D_Failed_E)                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_WB_TX_AGC_Target_Power_D_Set_DAC_D_Failed_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_DC_Band_Invalid_Exist_D_Expected_D__E)                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_AllInitialize_MSG_DC_Freq_S_Is_Not_Compatible_Valid_Freq_D_to_D_MHz_E)                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_LoSharingSet_MSG_Invalid_Master_RF_Index_D__E)                                         \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_LoSharingSet_MSG_Invalid_Slave_RF_Index_D__E)                                          \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_LoSharingSet_MSG_Master_And_Slave_Cannot_Be_Equal_E)                                   \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Invalid_RF_Index_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Invalid_channelMode_State_E)                                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Invalid_Settings_Freq_D_is_0_While_Dual_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_FW_Params_Get_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Chip_ID_Get_Failed_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Invalid_RF_Chip_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Invalid_CS_D__E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Dual_Channel_Invalid_LPF_D__E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Dual_Channel_Not_Supported_RF_Separation_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_Dual_Channel_RF_Separation_Smaller_Than_0_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_TX_AGC_Freeze_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxInitialize_MSG_TX_Init_Failed_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_TxLoDualChGet_MSG_XML_Tx_Diplexer_Load_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_TxLoDualChGet_MSG_XML_Tx_Diplexer_slope_D_Invalid_E)                                            \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxCalibrate_MSG_File_Name_Set_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxCalibrate_MSG_Frequency_D_KHz_Not_Found_In_CalibXML_File_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxCalibrate_MSG_Calibration_Load_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxCalibrate_MSG_TX_Calib_Failed_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxCalibrate_MSG_TX_Params_Set_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_CALLTO_MSG_RFIF_TxFreqOffsetSet_D__E)                                                            \
        RF_ERROR(HALRF_ERROR_FUNC_CALLTO_MSG_RFIF_DdsFreqSet_D__E)                                                                \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Invalid_RF_Index_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Invalid_channelMode_State_E)                                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Invalid_Settings_Freq_D_is_0_While_Dual_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_WB_RX_Source_ADC_Get_Failed_E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_FW_Params_Get_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Chip_ID_Get_Failed_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Invalid_RF_Chip_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Invalid_CS_D__E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Dual_Channel_Not_Supported_RF_Separation_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_Dual_Channel_RF_Separation_Smaller_Than_0_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_RX_LO_Dual_Channel_Get_Failed_E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_RX_AGC_Freeze_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxInitialize_MSG_RX_Init_Failed_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_RF_RXBB_LPF1_TuneSet_MSG_Invalid_LPF_tune_D__E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_RF_RX_AgcRssiCalibrate_MSG_Invalid_level_D__E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_RXBB_VGA_GainControlSet_MSG_Invalid_gain_D__E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_RXBB_LPF1_ChannelSpacingSet_MSG_Invalid_BB_Filter_D__E)                                        \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_SyntInitialize_MSG_Invalid_CS_D__E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_SyntFreqOffsetSet_MSG_DCC_Offset_D_KHz_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_Synt_MSG_DDS_Freq_D_KHz_Set_Failed_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_SyntInitialize_MSG_Synt_Init_D_KHz_Failed_E)                                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_SyntInitialize_MSG_Synt_Actual_Freq_Get_Failed_E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_SyntInitialize_MSG_loDualFreqKhz_0_E)                                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxCalibrate_MSG_File_Name_Set_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxCalibrate_MSG_Frequency_D_KHz_Not_Found_In_CalibXML_File_E)                            \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxCalibrate_MSG_Calibration_Load_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxCalibrate_MSG_Mixer_BW_Load_Failed_Missing_CS_D_E)                                    \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_RxCalibrate_MSG_RX_Calib_Failed_E)                                                        \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_API_RF_TxStatusGet_MSG_Invalid_ADC_Index_E)                                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_Lock_Failed_D__E)                                                            \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_CALIBRATION_ModuleModeSet_MSG_Invalid_Param_calMode_D_calModule_D__E)                    \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_freqSet_MSG_Freq_D__E)                                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_bpfCal_MSG_Freq_D__E)                                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_VcoCal_MSG_Failed_E)                                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_DivCal_MSG_Lock_Failed_FVCO_D_Divider_D__E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_BgCal_MSG_Failed_Target_Vbg_D__E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_AdcRefCal_MSG_Failed_Target_Vref_D__E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_VCO_Selection_Failed_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_VCO_Selection_Failed_Divider_D_NmmD_D__E)                                    \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_VCO_D_Switch_Cap_Selection_Failed_E)                                            \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_Gap_Correction_Failed_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_DIV_Selection_Failed_E)                                                        \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_DIV_Selection_Failed_FVCO_D_Divider_D__E)                                    \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_FreqSet_MSG_FVCO_Out_Of_Range_FLogen_D__E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_BpfCal_MSG_BPF_Frequency_Calibration_Failed_E)                                            \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_BpfCal_MSG_BPF_Gain_Calibration_Failed_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_PLL2_VControlLevelGet_MSG_PLL_Control_Level_Get_Failed_E)                                \
        RF_ERROR(HALRF_ERROR_FUNC_Synt_OpenLoopDivCal_MSG_Not_Supported_Chip_Revision_A0_E)                                \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_rf_GRS_Set_MSG_Magic_Num_0_E)                                                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_rf_CALIB_RX_AgcToModemSet_MSG_Invalid_RF_Index_E)                                                \
        RF_ERROR(HALRF_ERROR_FUNC_rf_CALIB_RX_AgcToModemSet_MSG_No_AGC_Policy_Match_Found_E)                                    \
        RF_ERROR(HALRF_ERROR_FUNC_rf_CALIB_RX_AgcToModemSet_MSG_Invalid_Calib_Mode_E)                                            \
        RF_ERROR(HALRF_ERROR_FUNC_rf_CALIB_TX_AgcToModemSet_MSG_No_AGC_Policy_Match_Found_E)                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_rf_CALIBXML_InitSAX_MSG_File_T_Open_Failed_E)                                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_mctFileOpen_MSG_Open_T_Failed_E)                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_mctFileRead_MSG_Read_Failed_E)                                                                \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_mct_StaticLoad_MSG_Checksum_Failed_Calculated_D_Read_D__E)                                    \
        RF_ERROR(HALRF_ERROR_FUNC_mct_StaticLoad_MSG_Version_D_Not_Supported_Expected_D__E)                                     \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_mct_RxLoad_MSG_Magic_Num_0_E)                                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_mct_RxLoad_MSG_MCT_Criterias_Not_Found_Freq_D_CS_D__E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_mct_RxLoad_MSG_MCT_Synt_Criterias_Not_Found_Freq_D__E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_mct_RxLoad_MSG_MCT_Fields_Criterias_Not_Found_Freq_D_CS_D__E)                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_mct_TxLoad_MSG_Magic_Num_0_E)                                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_mct_TxLoad_MSG_MCT_Criterias_Not_Found_Freq_D_CS_D__E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_mct_TxLoad_MSG_MCT_Synt_Criterias_Not_Found_Freq_D__E)                                        \
        RF_ERROR(HALRF_ERROR_FUNC_mct_TxLoad_MSG_MCT_Fields_Criterias_Not_Found_Freq_D_CS_D__E)                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_FLASH_FileList_MSG_FFS_Not_Initialized_Flash_Index_D__E)                                        \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_halRF_AGC_SPI_MODE_AllDACsWrite_MSG_Invalid_Checksum_E)                                        \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_halRF_RFCPU_AdcRead_MSG_Invalid_Checksum_E)                                                    \
        RF_ERROR(HALRF_ERROR_FUNC_halRF_RFCPU_GPIORead_MSG_Invalid_Checksum_E)                                                    \
                                                                                                                                \
        RF_ERROR(HALRF_ERROR_FUNC_DEBUG_MSG_ERROR_D__D__S_E)                                                                    \
        RF_ERROR(HALRF_ERROR_MAX_E)    


// Macros to generate enums and enums' names as strings
#define GENERATE_ENUM(ENUM) ENUM,


typedef enum {
    FOREACH_RF_PRGORESS(GENERATE_ENUM)
} HALRF_PROGRESS_ENUM;


typedef enum {
    FOREACH_RF_ERROR(GENERATE_ENUM)
} HALRF_ERROR_ENUM;



#ifdef __cplusplus
}
#endif


#endif /* _rf_progress_error_ */



