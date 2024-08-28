#include <stdbool.h>
#ifndef MYLIB_H
	#define MYLIB_H
	// Start Functions Declaration
	size_t strlenS (const char *str);
	char *strcatS (char *dest, const char *src);
	int strcmpS (const char *lhs, const char *rhs);
	char *strcpyS (char* destination, char* source);
	char *strchrS (const char *str, int c);
	char *strstrS (const char *s1, const char *s2);
	char *strtokS (char *str, const char *delims);
	char *strncpyS (char *dest, const char *src, size_t n);
	char *strncatS (char *dest, const char *src, size_t n);
	int strncmpS (const char *str1, const char *str2, size_t n);
	char *strrevS (char *str);
	size_t strspnS (const char *str1, const char *str2);
	char *strrepeat(const char *str, int n, char c, bool showEnd);
	char *Zfill(char *str, int n, char fill);
	void generateString(int n);
	int getMin(int *vector);
	int getMax(int *vector);
	int calculator(int *vector, char operation);
	void touppercase(char *str);
	void tolowercase(char *str);
	void toswapcase(char *str);
	int ParseInteger(char *str);
	bool IsNaN(char *str);
	char *trim_string(char *str, int direction, char ch);
	char *subString(char *str, int start, int end);
	char *cleanString(char *str);
	double randomNumber();
	// End Functions Declaration
#endif
















