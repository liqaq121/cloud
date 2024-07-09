#include "protocal.h"
#include <malloc.h>
#include <string.h>

PDU *mkPDU(uint uiMsgLen)
{
    uint uiPDULen=sizeof(PDU) + uiMsgLen;
    PDU* pdu=(PDU*)malloc(uiPDULen);
    memset(pdu,0,uiPDULen);
    pdu->uiPDULen=uiPDULen;
    pdu->uiMsgLen=uiMsgLen;
    return pdu;
}
