//stringPkg.cpp
//Implementation of the stringPkg library for CSC 2430
//Written by: Charlie Ang 
//02/01/16

#include "stringPkg.h"

// -------------------------------------------------------------
// Return length of a string, length >= 0.
// Length is a count of the characters in the string-value,
// not including the null at the end.
// An empty string ("") has length 0.
int stringLength(const char s[])
{
	int len = 0;

	while (s[len] != 0) ++len;	//count chars until encounter null char

	return (len);
}

// -------------------------------------------------------------
// Copy string src to string dest.
void stringCopy(char dest[], const int destBuffSize, const char src[])
{
	int len = stringLength(src);

	if (len >= destBuffSize)
		len = destBuffSize - 1;	//truncate if necessary, leave room for null

	for (int i = 0; i < len; i++)	//count through string-value
	{
		dest[i] = src[i];	//copy each character
	}
	dest[len] = 0;	//append the ACIIZ null at end 
}

// -------------------------------------------------------------
// Concatenate string t to end of string dest
void stringConcatenate(char dest[], const int destBuffSize, const char t[])
{
	int len = stringLength(dest);

	if (len >= destBuffSize)
		len = destBuffSize - 1;	//truncate if necessary, leave room for null
	int j = 0;	//variable to iterate through t 
	for (int i = len; i < destBuffSize - 1; i++)
	{
		dest[i] = t[j];	//concatenate
		j++;
	}
	dest[destBuffSize - 1] = 0;	//apppend the ASCIIZ null at end 
}

// -------------------------------------------------------------
// Retrieve character from string s[position].
// Position must be between 0 and (stringLength-1).
// Return 0 if position is out of range.
char stringGetchar(const char s[], const int position)
{
	if (position < 0 || position > stringLength(s))	//out of range
	{
		return 0;	
	}
	return(s[position]);	//return the char at position
}

// -------------------------------------------------------------
// Find ch in string s and return position: 0 - (stringLength-1)
// Return -1 if ch not found in s.
int  stringFindchar(const char s[], const char ch)
{
	for (int i = 0; i < stringLength(s); i++)
	{
		if (s[i] == ch)	//if char at i is equal to ch
		{
			return i;	//return position
		}
	}
	return -1;	//if not found 
}

// -------------------------------------------------------------
// Set resultString[] to a string value that is a copy of
//    a specified substring of original string s.
// If specified start position is not located within the string s,
//    then set resultString to the empty string ("").
// If specified len < 0, or if (start + len) > the length of s
//    then set resultString to the longest possible substring.
void stringSubstring(
	char resultString[],		// new string buffer
	const int resultBuffSize,	// result array buffer size
	const char s[],				// the original string
	const int start,			// starting position of substring within s
	const int len)				// length of substring within s
								//   len<0: longest possible substring
{
	if (start < 0 || (start > stringLength(s) - 1))
	{
		stringCopy(resultString, 2, "");	//empty string if start is not within original string 
	}

	else if (len < 0 || ((start + len) > stringLength(s)))	//if len < 0 or (start+len)>length s
	{
		for (int i = 0; i < resultBuffSize - 1; i++)	//longest possible substring
		{
			resultString[i] = s[i + start];
		}
		resultString[stringLength(s)] = 0;		//append ASCII null at end 
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			resultString[i] = s[i + start];
		}
		resultString[len] = 0;	//append ASCII null at end
	}
}
// -------------------------------------------------------------
// Alphabetically compare string s to string t, based on ASCII charset.
// Return an integer value < 0 if s <  t
// Return an integer value 0   if s == t
// Return an integer value > 0 if s >  t
int  stringCompare(const char s[], const char t[])
{
	int lengths = stringLength(s);	//length s
	int lengtht = stringLength(t);	//length t 
	int max = lengths;
	if (lengtht >= lengths)
	{
		max = lengtht;	//find max length out of two strings 
	}

	for (int i = 0; i < max; i++)
	{
		if (s[i] < t[i])
		{
			return -1;
		}
		if (s[i] > t[i])
		{
			return 1;
		}
	}
	return 0;	//s[i] == t[i]	
}

// -------------------------------------------------------------

