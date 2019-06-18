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

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // for memset   


#include "rf_progress_error_parse.h"

#ifdef WIN32
    #define NEW_LINE "\n"
#else
    #define NEW_LINE "\n\r"
#endif

static const char *HALRF_PROGRESS_STRING[] = {
    FOREACH_RF_PRGORESS(GENERATE_STRING)
};

static const char *HALRF_ERROR_STRING[] = {
    FOREACH_RF_ERROR(GENERATE_STRING)
};



static char gChip[16]                                       = { 0 };
static char gEnumString[256]                                = { 0 };
static char gFunction[128]                                  = { 0 };
static char gMsgText[128]                                   = { 0 };
static char gOutputMsg[128]                                 = { 0 };
static char gErrorString[256]                               = { 0 };
static char gNumber[16]                                     = { 0 };

/////////////////////////////////////////////////////////
//                                                     //
/////////////////////////////////////////////////////////
static BCM_UW_RF_PROGRESS_ERROR_STRUCT s_ProgressErrorData;//   = { {{0}},{0} };
static BYTE s_StartingPosition, s_NumOfMessages, s_gIteration, s_MaxNumOfMessages;
BCM_UW_ERROR_MSG_ENUM rf_ProgressErrorBufferParse(BCM_UW_RF_PROGRESS_ERROR_STRUCT *progressErrorData, char *progressErrorBuffer, UINT32 progressErrorBufferLen, UINT16 *errorBitMap)
{
    BYTE index;
    BYTE errorBitMapIndex = 0;

    // If progressErrorData is not null, initalize the static variables to the new object, else - use exisiting
    if (progressErrorData != NULL)
    {
        s_MaxNumOfMessages = sizeof(progressErrorData->message)/sizeof(BCM_UW_RF_PROGRESS_ERROR_MSG_STRUCT); // 14 - gNumber of messages
        s_gIteration = 0;
        s_NumOfMessages = MIN(progressErrorData->lastMessageIdx, s_MaxNumOfMessages);
        s_StartingPosition = (progressErrorData->lastMessageIdx < s_MaxNumOfMessages) ? 0 : progressErrorData->lastMessageIdx % s_MaxNumOfMessages;
        memset(&s_ProgressErrorData, 0, sizeof(BCM_UW_RF_PROGRESS_ERROR_STRUCT));
        memcpy(&s_ProgressErrorData, progressErrorData, sizeof(BCM_UW_RF_PROGRESS_ERROR_STRUCT));
    }
    if (errorBitMap != NULL)
    {
        *errorBitMap = 0;
    }
    memset(progressErrorBuffer, 0, progressErrorBufferLen);

    for (; s_gIteration < s_NumOfMessages; s_gIteration++)
    {
        char *funcIdx, *msgIdx;
        unsigned int c, outputC, dIndex = 0, sIndex = 0;

        index = (s_gIteration + s_StartingPosition) % s_NumOfMessages;
        // Reset global variable to be used for current message
        memset(gChip,        0, sizeof(gChip)       );
        memset(gEnumString,  0, sizeof(gEnumString) );
        memset(gFunction,    0, sizeof(gFunction)   );
        memset(gMsgText,     0, sizeof(gMsgText)    );
        memset(gOutputMsg,   0, sizeof(gOutputMsg)  );
        memset(gErrorString, 0, sizeof(gErrorString));

        if (s_ProgressErrorData.message[index].rfDevType == BCM_UW_RF_CHIP_TYPE_TX_E)
        {
            strcat(gChip, "TX");
        }
        else if (s_ProgressErrorData.message[index].rfDevType == BCM_UW_RF_CHIP_TYPE_RX_E)
        {
            strcat(gChip, "RX");
        }
        else if (s_ProgressErrorData.message[index].rfDevType == BCM_UW_RF_CHIP_TYPE_TXSYNT_E)
        {
            strcat(gChip, "TX-Synt");
        }
        else if (s_ProgressErrorData.message[index].rfDevType == BCM_UW_RF_CHIP_TYPE_RXSYNT_E)
        {
            strcat(gChip, "RX-Synt");
        }

        if (strlen(gChip) > 0) // Add rfDevIdx to gChip, unless gChip is BCM_UW_RF_CHIP_TYPE_MAX_E
        {
            sprintf(gChip, "%s %d - ", gChip, s_ProgressErrorData.message[index].rfDevIdx);
        }

        // messageIdx < 0 indicate error message - add to errorBitMap
        if (s_ProgressErrorData.message[index].messageIdx < 0)
        {
            if (errorBitMap != NULL)
            {
                (*errorBitMap) |= (1 << errorBitMapIndex);
            }
            strcpy(gEnumString,  HALRF_ERROR_STRING[ABS(s_ProgressErrorData.message[index].messageIdx)]);
        }
        else
        {
            strcpy(gEnumString,  HALRF_PROGRESS_STRING[s_ProgressErrorData.message[index].messageIdx]);
        }

        funcIdx = strstr(gEnumString, "_FUNC_"); // All enums starts with HALRF_ERROR_FUNC/HALRF_PROGRESS_FUNC
        if (funcIdx == NULL)
        {
            continue;
        }
        strcpy(gFunction, funcIdx + strlen("_FUNC_"));

        if (strstr(gFunction,"_MSG_") == NULL) //sanity check - avoid strlen of null string
        {
            continue;
        }
        gFunction[strlen(gFunction) - strlen(strstr(gFunction,"_MSG_"))] = 0;

        msgIdx = strstr(gEnumString, "_MSG_"); // All enums contains _MSG_ between the gFunction and the error
        if (msgIdx == NULL)
        {
            continue;
        }
        strcpy(gMsgText, msgIdx + strlen("_MSG_"));
        gMsgText[strlen(gMsgText)-2] = 0; // Trim '_E'

        for (c = 0, outputC = 0; c < strlen(gMsgText); ++c, ++outputC)
        {
            // Search for '_D_' first
            if (gMsgText[c] == '_' && strlen(&gMsgText[c]) >= strlen("_D_") && gMsgText[c + 1] == 'D' && gMsgText[c + 2] == '_' && dIndex < 2)
            {
                memset(gNumber, 0, sizeof(gNumber));

                sprintf(gNumber, " %ld " ,s_ProgressErrorData.message[index].paramsInt[dIndex++]);
                strcat(gOutputMsg, gNumber);
                c += strlen("_D_") - 1;
                outputC += strlen(gNumber) - 1;
            }
            // Search for '_S_'
            else if (gMsgText[c] == '_' && strlen(&gMsgText[c]) >= strlen("_S_") && gMsgText[c + 1] == 'S' && gMsgText[c + 2] == '_' && sIndex < 1)
            {
                memset(gNumber, 0, sizeof(gNumber));

                sprintf(gNumber, " %d " ,s_ProgressErrorData.message[index].paramsShort);
                strcat(gOutputMsg, gNumber);
                c += strlen("_S_") - 1;
                outputC += strlen(gNumber) - 1;
                sIndex++;
            }
            // Search for '_D10_'
            else if (gMsgText[c] == '_' && strlen(&gMsgText[c]) >= strlen("_D10_") && gMsgText[c + 1] == 'D' && gMsgText[c + 2] == '1' && gMsgText[c + 3] == '0' && gMsgText[c + 4] == '_' && dIndex < 2)
            {
                memset(gNumber, 0, sizeof(gNumber));

                sprintf(gNumber, " %.2f ", s_ProgressErrorData.message[index].paramsInt[dIndex++]/10.0);
                strcat(gOutputMsg, gNumber);
                c += strlen("_D10_") - 1;
                outputC += strlen(gNumber) - 1;
            }
            // Search for '_D100_'
            else if (gMsgText[c] == '_' && strlen(&gMsgText[c]) >= strlen("_D100_") && gMsgText[c + 1] == 'D' && gMsgText[c + 2] == '1' && gMsgText[c + 3] == '0' && gMsgText[c + 4] == '0' && gMsgText[c + 5] == '_' && dIndex < 2)
            {
                memset(gNumber, 0, sizeof(gNumber));

                sprintf(gNumber, " %.2f ", s_ProgressErrorData.message[index].paramsInt[dIndex++]/100.0);
                strcat(gOutputMsg, gNumber);
                c += strlen("_D100_") - 1;
                outputC += strlen(gNumber) - 1;
            }
            // Search for '_T_'
            else if (gMsgText[c] == '_' && strlen(&gMsgText[c]) >= strlen("_T_") && gMsgText[c + 1] == 'T' && gMsgText[c + 2] == '_' && strlen(gErrorString) == 0)
            {
                strncpy(gErrorString, (char*)s_ProgressErrorData.text, sizeof(s_ProgressErrorData.text));

                c += strlen("_T_") - 1;
                // Check that we have enough space to copy the string
                if (sizeof(gOutputMsg) - strlen(gOutputMsg) - 1 > strlen(gErrorString))
                {
                    char errorStringToCopy[256] = { 0 };
                    sprintf(errorStringToCopy, " %s ", gErrorString); // Add spaces
                    strcat(gOutputMsg, errorStringToCopy);
                    outputC += strlen(errorStringToCopy) - 1;
                }

            }
            else // Copy original character
            {
                gOutputMsg[outputC] = gMsgText[c];
            }
        }

        for (c = 0; c < strlen(gOutputMsg); ++c)
        {
            if (gOutputMsg[c] == '_')
            {
                gOutputMsg[c] = ' ';
            }
        }
        if (s_ProgressErrorData.message[index].messageIdx < 0 && s_ProgressErrorData.message[index].uwErrorCode != 0) // messageIdx < 0 indicate error message
        {
            char errorCodeMsg[16] = { 0 };
            sprintf(errorCodeMsg, " (UW Error %d)", s_ProgressErrorData.message[index].uwErrorCode);
            if (strlen(gOutputMsg) + strlen(errorCodeMsg) < sizeof(gOutputMsg))
            {
                strcat(gOutputMsg, errorCodeMsg);
            }
        }

        if (strlen(progressErrorBuffer) + strlen(gChip) + strlen(gFunction) + strlen(gOutputMsg) + 5 > progressErrorBufferLen) // Check that we have room left in the buffer to add the new message. + 3 is for ': ' and '\n' and '\r'
        {
            if (strlen(progressErrorBuffer) == 0) // No message was inserted yet, buffer is too small
            {
                return BCM_UW_INVALID_PARAMS_E;
            }
            return BCM_UW_SUCCESS_MSG_E; 
        }
        
        errorBitMapIndex++;
        strcat(progressErrorBuffer, gChip);
        strcat(progressErrorBuffer, gFunction);
        strcat(progressErrorBuffer, ": ");
        strcat(progressErrorBuffer, gOutputMsg);
        strcat(progressErrorBuffer, NEW_LINE);
    }
    
    return BCM_UW_SUCCESS_MSG_E; 
}




