#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include "myLib.h"
#include <unistd.h>

/*
strlen() strcat() strcmp() strcpy() strchr()
strstr() strtok() strncpy() strncat() strncmp()
strrev() strspn() strrepeat() 
*/

// Start The Fucntions Implementation

/**
 * @brief Calculates the length of a string.
 *
 * @param str Pointer to the string whose length will be calculated.
 * 
 * @return The number of characters in the string, excluding the null-terminator.
 */

size_t strlenS(const char *str) {
	size_t len = 0;
	while (str[len] != '\0') len++;
	return len;
}


/**
 * @brief Cat a string to another string
 *
 * This function adds the content of the `src` to `dest`.
 *
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * 
 * @return Pointer to the destination string `dest`.
 */

char *strcatS(char *dest, const char *src) {
	char *ptr = dest;
	int dest_size = strlenS(dest);
	int src_size = strlenS(src);
	for (int i = dest_size; i < dest_size + src_size; i++) {
		dest[i] = src[i - dest_size];
	}
	dest[dest_size + src_size] = '\0';
	return ptr;
}



/**
 * @brief Compare two strings.
 *
 * This function compares the two strings `lhs` and `rhs` character by character.
 *
 * @param lhs The first string to be compared.
 * @param rhs The second string to be compared.
 * 
 * @return An integer indicating the result of the comparison:
 *         - A value less than 0 if `lhs` is less than `rhs`.
 *         - 0 if `lhs` is equal to `rhs`.
 *         - A value greater than 0 if `lhs` is greater than `rhs`.
 */

int strcmpS(const char *lhs, const char *rhs) {
	int i = 0;
	while (lhs[i] != '\0' || rhs[i] != '\0') {
		if (lhs[i] == rhs[i]) i++;
		else return (int) lhs[i] - rhs[i];
	}
	return 0;
}



/**
 * @brief Copies a source string to a destination string.
 *
 * @param destination Pointer to the destination array.
 * @param source Pointer to the source string.
 *
 * @return Pointer to the destination string.
 */

char *strcpyS(char* destination, char* source) {
	int i;	
	for (i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}



/**
 * @brief Searches for the first occurrence
 *
 * @param str − This is the C string to be scanned.
 * @param c − This is the character to be searched in str.
 *
 * @return A Pointer to the first occurrence of the character c in the string str,
		  	or NULL if the character is not found.
 */

char *strchrS(const char *str, int c) {
	for (; *str != '\0'; str++) {
		if ((int) *str == c) {
			return (char *) str;
		}
	}
	return NULL;
}


/**
 * @brief Finds the first occurrence of the string s2 in the string s1.
 *
 * @param s1: This is the main string to be examined.
 * @param s2: This is the sub-string to be searched in string.
 *
 * @return A Pointer to the first occurrence of the character c in the string str,
		  	or NULL if the character is not found.
 */


char *strstrS (const char *s1, const char *s2) {
	if (s1 == NULL || s2 == NULL) return NULL;
	if (*s2 == '\0') return (char *) s1;
	for (; *s1 != '\0'; s1++) {
		if (*s2 == *s1) {
			const char *temp1 = (char *) s1; 
			const char *temp2 = (char *) s2;
			while (*temp1 != '\0' && *temp1 == *temp2) {
				temp1++; temp2++;
			}
			if (*temp1 == '\0') return (char *) s1;
			s1 = temp1;
		}
	}
	return NULL;
}



/**
 * @brief Splits str[] according to given delimiters.
 *
 * @param str: It is the pointer to the string to be tokenized.
 * @param delims: It is a string containing all delimiters.
 *
 * @return A Pointer to the first token encountered in the string.
		  	 NULL when there are no more tokens.
 */

char *strtokS (char *str, const char *delims) {
    // "Hello, world! Welcome to C programming." and " ,.!"
    static char *start = NULL;
    char *temp;
    bool check;

    if (str != NULL) start = str;
    else if (start == NULL) return NULL;

    for (char *p = start; *p != '\0'; p++) {
        check = false;
        for (const char *q = (char *) delims; *q != '\0'; q++) {
            if (*p == *q) {
                *p = '\0'; temp = start; start = ++p; check = true; break;
            }
        }
        if (check) return temp;
    }
    return NULL;
}



/**
 * @brief copies up to n characters from the string pointed to, by src to dest.
 *
 * @param dest : This is the pointer to the destination array where the content is to be copied.
 * @param src : This is the string to be copied.
 * @param n : The number of characters to be copied from source.
 *
 * @return  returns the pointer to the copied string.
 */

char *strncpyS(char *dest, const char *src, size_t n) {
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}



/**
 * @brief appends the string pointed to by src to the end of the string pointed to by dest up to n characters long.
 *
 * @param dest − This is pointer to the destination array, which should contain a C string, and should be large
 *      enough to contain the concatenated resulting string which includes the additional null-character.
 *      src − This is the string to be appended.
 * @param n − This is the maximum number of characters to be appended.
 *
 * @return  returns a pointer to the resulting string dest.
 */

char *strncatS (char *dest, const char *src, size_t n) {
    char *p;
    int i = 0;
    for (p = dest; *p != '\0'; p++);
    for (; p < p + n; p++) {
         *p = src[i];
         i++;
    }
    return dest;
}



/**
 * @brief compares at most the first n bytes of str1 and str2.
 *
 * @param str1 − This is the first string to be compared.
 * @param str2 − This is the second string to be compared.
 * @param n − The maximum number of characters to be compared.
 *
 * @return
        if Return value < 0 then it indicates str1 is less than str2.
        if Return value > 0 then it indicates str2 is less than str1.
        if Return value = 0 then it indicates str1 is equal to str2.
 */

int strncmpS (const char *str1, const char *str2, size_t n) {
    int i = 0;
    while (i < n) {
        if (str1[i] == str2[i]) i++;
        else return (int) str1[i] - str2[i];
    }
    return 0;
}



/**
 * @brief function is used to reverse the given string.
 *
 * @param z: The given string which is needed to be reversed.
 *
 * @return the string reversed
 */

char *strrevS(char *str) {
    if (str == NULL) return NULL;
    char *p1 = str;
    char *p2 = str + strlenS(str) - 1;
    while (p1 < p2) {
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++; p2--;
    }
    return str;
}



/**
 * @brief function is used to reverse the given string.
 *
 * @param str1: string to be scanned.
 * @param str2: string containing the characters to match.
 *
 * @return the number of characters in the initial segment of str1 which consist only of characters from str2.
 */

size_t strspnS (const char *str1, const char *str2) {
    char *temp1 = (char *) str1, *temp2;
    size_t count = 0;
    while (*temp1 != ' ') {
        temp2 = (char *) str2;
        while (*temp2 != '\0') {
            if (*temp1 == *temp2) {
                count++; break;
            }
            temp2++;
        }
        if (*temp2 == '\0') break;
        temp1++;
    }
    return count;
}



/**
 * @brief This Function Will Repeat The String
 *
 * @param str: The String That Will Be Repeated
 * @param n: The Number Of Repeating
 * @param sep: The Separator Between The Repeated Strings
 * @param showEnd: Show The Separator At The End Of The String
 *
 * return Nothing
 */

char *strrepeat(const char *str, int n, char sep, bool showEnd) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1 && !showEnd) {
            printf("%s", str);
        } else printf("%s%c", str, sep);
    }
}



/**
 * @brief This function fills the spaces in a string.
 *
 * @param str The string to be filled.
 * @param n The width of the string after filling.
 * @param fill The character to fill the string with.
 *
 * @return The filled string.
 */

char *Zfill(char *str, int n, char fill) {
    int size_str = strlenS(str);
    if (size_str >= n) return str;
    for (int i = 0; i < size_str; i++) {
        str[n - size_str + i] = str[i];
    }
    for (int i = 0; i < n + size_str; i++) {
        if (i < n - size_str) str[i] = fill;
        else {
            if (str[i] == ' ') str[i] = fill;
        }
    }
    return str;
}



/**
 * @brief Generate a random string
 *
 * @param n number of characters
 *
 * @return The generated string
 */

void generateString(int n) {
    char str[n];
    int randomNumber = 0;
    for (int i = 0; i < n; i++) {
        randomNumber = rand() % 126 + 1;
        if (randomNumber < 33) randomNumber += 32;
        str[i] = (char) randomNumber;
    }
    printf("%s", str);
}



/**
 * @brief get the min in vector
 *
 * @param vector that will be get from him
 *
 * @return the minimum value in vector
 */

int getMin(int *vector) {
    int length = sizeof(vector) / sizeof(int);
    int min = vector[0];
    for (int i = 1; i < length; i++) {
        if (vector[i] < min) min = vector[i];
    }
    return min;
}



/**
 * @brief get the max in vector
 *
 * @param vector that will be get from him
 *
 * @return the maximum value in vector
 */

int getMax(int *vector) {
    int length = sizeof(vector) / sizeof(int);
    int max = vector[0];
    for (int i = 1; i < length; i++) {
        if (vector[i] > max) max = vector[i];
    }
    return max;
}



/**
 * @brief Perform an operation on all elements of a vector.
 *
 * @param vector A pointer to the integer array.
 * @param operation The operation: '+' for addition, '-' for subtraction,
 *                  '*' for multiplication, '/' for division.
 *
 * @return The result of the operation, or -1 for division by zero or
 *         invalid operation.
 */

int calculator(int *vector, char operation) {
    int result = vector[0];
    int length = sizeof(vector) / sizeof(int);
    for (int i = 1; i < length; i++) {
        if (operation == '+') result += vector[i];
        else if (operation == '-') result -= vector[i];
        else if (operation == '*') result *= vector[i];
        else if (operation == '/') {
            if (vector[i] == 0) return -1;
            result /= vector[i];
        }
        else return -1;
    }
    return result;
}



/**
 * @brief Converts all lowercase letters in the given string to uppercase.
 *
 * @param str Pointer to a null-terminated string.
 */
 
void touppercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
    }
}



/**
 * @brief Converts all uppercase letters in the given string to lowercase.
 *
 * @param str Pointer to a null-terminated string.
 */
void tolowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
    }
}



/**
 * @brief Swaps the case of each letter in the given string. 
 * Converts uppercase letters to lowercase and lowercase letters to uppercase.
 *
 * @param str Pointer to a null-terminated string.
 */
void toswapcase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
        else if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
        else;
    }
}




/**
 * @brief Return The Numbers that exit in the string 
 *
 * @param str Pointer to a null-terminated string.
 *
 * @return the number that exit in str
 */

int ParseInteger(char *str) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (result == 0) result += ((int) str[i] - 48);
            else {
                result *= 10;
                result += ((int) str[i] - 48);
            }
        }
    }
    return result;
}



/**
 * Checks if a given string represents a non-negative integer (i.e., contains only digits).
 * 
 * @param str The input string to be checked.
 * 
 * @return true if the string contains only digits (0-9), false otherwise.
 */

bool IsNaN(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}



/**
 * Trims a specified character from a given string either from the start, the end, or both ends.
 * 
 * @param str The input string to be trimmed.
 * @param direction The direction of trimming:
 *        0 - Trim from both ends.
 *       -1 - Trim from the start.
 *        1 - Trim from the end.
 * @param ch The character to be trimmed from the string.
 * 
 * @return A new string with the specified character trimmed as per the direction. 
 *         The caller is responsible for freeing the allocated memory.
 */
 
char *trim_string(char *str, int direction, char ch) {
    int count = 0;
    int length = strlenS(str);
    int end_trim = -1, start_trim = -1;
    // find start and end of triming
    for (int i = 0, j = length - 1; start_trim == -1 || end_trim == -1; i++, j--) {
        if (str[i] != ch && start_trim == -1) start_trim = i;
        if (str[i] != ch && end_trim == -1) end_trim = j; 
    }
    // set thet start and end
    int start, end;
    if (direction == 0) { start = start_trim; end = end_trim + 1; }
    else if (direction == -1) { start = start_trim; end = length; }
    else if (direction == 1) { start = 0; end = end_trim + 1; }
    else return str;
    char *new_str = (char *) malloc(sizeof(char) * (end));
    // remove charcter that we want to remove it
    for (int i = start; i < end; i++) {
        new_str[count] = str[i];
        count++;
    }
    new_str[count] = '\0';
    return new_str;
}



/*
    Extracts a substring from 'str' starting at index 'start' up to index 'end' (exclusive).

    @param str    Input string to extract from.
    @param start  Starting index of the substring.
    @param end    Ending index of the substring.

    @return       Extracted substring as a new dynamically allocated string. 
                  Returns 'str' if 'end' exceeds the string length.
*/
char *subString(char *str, int start, int end) {
    int length = strlenS(str);
    if (end > length) return str;
    char *new_str = (char *) malloc(sizeof(char) * (end - start + 1));
    int count = 0;
    for (int i = start; i < end; i++) {
        new_str[count] = str[i];
        count++;
    }
    new_str[count] = '\0';
    return new_str;
}




/*
    Removes non-alphanumeric characters from the input string 'str'.

    @param str    Input string to clean.

    @return       A new string containing only alphanumeric characters 
                  from 'str', allocated dynamically. The caller is 
                  responsible for freeing the memory.
*/
char *cleanString(char *str) {
    int length = strlenS(str);
    char *result = (char*) malloc(sizeof(char) * length);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            result[count] = str[i];
            count++;
        }
    }
    return result;
}



/*
struct timeval {
    time_t      tv_sec;    // seconds 
    suseconds_t tv_usec;   // microseconds 
};
*/
/*
    Generates a pseudo-random number based on the current system time in microseconds.

    @return  A pseudo-random integer between 0 and 4.
*/
double randomNumber() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    int current_time =  tv.tv_usec; // get the micro second time
    static int num = 1;
    
    if (num == 1) num = current_time;
    
    num = (num + current_time) % 5;
    double result = (double) num / 4.0 - 0.01;
    if (result < 0) result *= -1;
    return result;
}


















// end The Functions Implementation
