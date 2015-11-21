/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//int dateCheck(char*,int);
int length(char*);
int tenPow(int);
int numofDig(int);
int dateCheck(char*, int, int *, int *, int *);
int isOlder(char *dob1, char *dob2) {
	int checkValid = 0;
	int date1 = 0, month1 = 0, year1 = 0;
	int date2 = 0, month2 = 0, year2 = 0;
	/*dateCheck(dob1, length(dob1), &date1, &month1, &year1);
	dateCheck(dob1, length(dob1), &date2, &month2, &year2);*/
	
	checkValid = dateCheck(dob1, length(dob1), &date1, &month1, &year1);
	if (checkValid == -1)
		return(-1);
	checkValid = dateCheck(dob2, length(dob2), &date2, &month2, &year2);
	if (checkValid == -1)
		return(-1);
	if (year1 < year2)
		return 1;
	if (year1 > year2)
		return 2;
	else
	{
		if (month1 > month2)
			return 2;
		if (month1 < month2)
			return 1;
		else
		{
			if (date1 > date2)
				return 2;
			if (date1 < date2)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}

/*void Date(char *dateInput, int len, int *date, int *month, int *year)
{
	int flag, place;	

	for (place = 0, flag = len - 1; dateInput[flag] != '-'&&flag >= 0; flag--, place++)
	{
		(*year) += tenPow(place)*(dateInput[flag] - '0');
	}

	for (place = 0, flag = flag - 1; dateInput[flag] != '/'&&flag >= 0; flag--, place++)
	{
		month += tenPow(place)*(dateInput[flag] - '0');
	}

	for (place = 0, flag = flag - 1; dateInput[flag] != '/'&&flag >= 0; flag--, place++)
	{
		date += tenPow(place)*(dateInput[flag] - '0');
	}
}*/

int length(char *arr)
{
	int flag = 0;
	while (arr[flag] != '\0')
		flag++;
	return(flag);
}

int dateCheck(char *dateInput, int len,int *date,int *month,int *year)
{
	int flag, place;	
	for (place = 0, flag = len - 1; dateInput[flag] != '-'&&flag >= 0; flag--, place++)
	{
		(*year) += tenPow(place)*(dateInput[flag] - '0');
	}
	if (numofDig((*year)) != 4)
	{
		//puts("Invalid format");
		return(-1);
	}	
	for (place = 0, flag = flag - 1; dateInput[flag] != '-'&&flag >= 0; flag--, place++)
	{
		(*month) += tenPow(place)*(dateInput[flag] - '0');
	}
	if ((*month) <= 0 || (*month) > 12)
	{
		//puts("Invalid Date");
		return(-1);
	}
	for (place = 0, flag = flag - 1; dateInput[flag] != '-'&&flag >= 0; flag--, place++)
	{
		(*date) += tenPow(place)*(dateInput[flag] - '0');
	}
	switch ((*date))
	{
	case 0:
		//printf("Invalid Format");
		return(-1);
	case 31:
		if ((*month) == 4 || (*month) == 6 || ((*month) == 9) || ((*month) == 11))
		{
			//printf("Invalid Date");
			return(-1);
		}
	case 29:
		if ((*month) == 2)
		{
			if ((*year) % 100 == 0)
			{
				if ((*year) % 400 != 0)
				{
					//printf("Invalid Date");
					return(-1);
				}
			}
			else if ((*year) % 4 != 0)
			{
				//printf("Invalid Date");
				return(-1);
			}
	default:
		if ((*date) > 31)
		{
			//printf("Invalid Format");
			return(-1);
		}
		}
	}
	return 0;
}

int tenPow(int num)
{
	if (num == 0)
		return 1;
	else
		return(10 * tenPow(num - 1));
}

int numofDig(int num)
{
	int flag;
	for (flag = 0; num>0; num /= 10)
		flag++;
	return(flag);
}