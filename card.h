/***************************************************************
*card.h file with functions prototypes and typedefs
****************************************************************/

#pragma once

#ifndef CARD_H
#define CARD_H

#include "STD-DT.h"


typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[5];
}ST_cardData_t;


typedef enum EN_cardError_t
{
	CARD_OK, WRONG_NAME, WRONG_EXP_DATE,
	WRONG_PAN
}EN_cardError_t;

// card functions

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);

EN_cardError_t getCardPAN(ST_cardData_t* cardData);

// test functions

void getCardHolderNameTest(void);

void getCardExpiryDateTest(void);

void getCardPANTest(void);

#endif
