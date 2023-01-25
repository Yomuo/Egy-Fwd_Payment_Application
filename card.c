/***************************************************************
*card.c file that contain card functions
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "card.h"
#include "STD-DT.h"

// define max&min of datatypes
#define MIN_C_H_N 20
#define MAX_C_H_N 24
#define MaxCardPAN 19
#define MinCardPAN 16
#define ExpiryDateStrLen 5


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	puts("Please enter the Card Holder's Name : ");

	scanf_s("%[^\n]s", &cardData->cardHolderName, MAX_C_H_N);

	if ((cardData->cardHolderName) == NULL || strlen(cardData->cardHolderName) < MIN_C_H_N || strlen(cardData->cardHolderName) > MAX_C_H_N)
	{
		return WRONG_NAME; // terminates the execution of function
	}

	printf("Hello, %s\n", cardData->cardHolderName);

	return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	puts("please enter the card expiry date in form MM/YY : ");
	scanf_s("%s", &cardData->cardExpirationDate, ExpiryDateStrLen);

	if ((cardData->cardExpirationDate) == NULL || strlen(cardData->cardExpirationDate) != ExpiryDateStrLen)
	{
		return WRONG_EXP_DATE;
	}
	if (!isdigit(cardData->cardExpirationDate[0]) || !isdigit(cardData->cardExpirationDate[1]))
	{
		return WRONG_EXP_DATE;
	}
	if ((cardData->cardExpirationDate[2]) != '/')
	{
		return WRONG_EXP_DATE;
	}
	if (!isdigit(cardData->cardExpirationDate[3]) || !isdigit(cardData->cardExpirationDate[4]))
	{
		return WRONG_EXP_DATE;
	}
	else
	{
		printf("Your Card Expiry Date is : %s", cardData->cardExpirationDate);
	}
	return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	puts("Please enter the Card PAN: ");
	scanf_s("%s", &cardData->primaryAccountNumber, MaxCardPAN);

	if (strlen(cardData->primaryAccountNumber) == NULL)
	{
		return WRONG_PAN;
	}
	else if (strlen(cardData->primaryAccountNumber) < MinCardPAN || strlen(cardData->primaryAccountNumber) > MaxCardPAN)
	{
		return WRONG_PAN;
	}
	return CARD_OK;
}

// testing functions
void getCardHolderNameTest(void)
{
	ST_cardData_t Card;

	puts("Tester Name: Ahmed Jawdah\n"
		"Function Name: getCardHolderName\n\n"
		"  NOTE! IF random string shows as Input Data it means it didn't take any charecter.\n"
		"  rather then we have pressed Enter\n\n");

	printf("Test Case 1: NULL\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_NAME == 1\n"
		"Actual Result: (%d)\n", Card.cardHolderName, getCardHolderName(&Card));

	printf("Test Case 2: Ahmed\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_NAME == 1\n"
		"Actual Result: (%d)\n", Card.cardHolderName, getCardHolderName(&Card));

	printf("Test Case 3: Ahmed Mohamed\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_NAME\n"
		"Actual Result: (%d)\n", Card.cardHolderName, getCardHolderName(&Card));

	printf("Test Case 4: Ahmed Mohamed Jawdah\n"
		"Input Data: (%s)\n"
		"Expected Result: CARD_OK\n"
		"Actual Result: (%d)\n", Card.cardHolderName, getCardHolderName(&Card));
}

void getCardExpiryDateTest(void)
{
	ST_cardData_t Card;

	puts("Tester Name: Ahmed Jawdah\n"
		"Function Name:  getCardExpiryDate\n");

	printf("Test Case 1: NULL\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_EXP_DATE == 2\n"
		"Actual Result: (%d)\n", Card.cardExpirationDate, getCardExpiryDate(&Card));

	printf("Test Case 2: less then five characters 06/0 \n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_EXP_DATE == 2\n"
		"Actual Result: (%d)\n", Card.cardExpirationDate, getCardExpiryDate(&Card));

	printf("Test Case 3: less then five characters 02 \n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_EXP_DATE == 2\n"
		"Actual Result: (%d)\n", Card.cardExpirationDate, getCardExpiryDate(&Card));

	printf("Test Case 4: more then five characters 06/12/20 \n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_EXP_DATE == 2\n"
		"Actual Result: (%d)\n", Card.cardExpirationDate, getCardExpiryDate(&Card));

	printf("Test Case 5: more then five characters 02/56/ \n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_EXP_DATE == 2\n"
		"Actual Result: (%d)\n", Card.cardExpirationDate, getCardExpiryDate(&Card));
}

void getCardPANTest(void)
{
	ST_cardData_t Card;

	puts("Tester Name: Ahmed Jawdah\n"
		"Function Name:  getCardPAN\n");

	printf("Test Case 1: NULL\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_PAN == 3\n"
		"Actual Result: (%d)\n", Card.primaryAccountNumber, getCardPAN(&Card));

	printf("Test Case 1: NULL\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_PAN == 3\n"
		"Actual Result: (%d)\n", Card.primaryAccountNumber, getCardPAN(&Card));

	printf("Test Case 1: NULL\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_PAN == 3\n"
		"Actual Result: (%d)\n", Card.primaryAccountNumber, getCardPAN(&Card));

	printf("Test Case 1: NULL\n"
		"Input Data: (%s)\n"
		"Expected Result: WRONG_PAN == 3\n"
		"Actual Result: (%d)\n", Card.primaryAccountNumber, getCardPAN(&Card));
}