# LibProject

LibProject is a collection of built-in functions for string manipulation, mathematical operations, and utility functions in C. Below is a detailed description of each function included in this library.

## Functions 📜

| Function Name                       | Description                                                                                   |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| `size_t strlenS(const char *str)`   | Calculates the length of the string `str`.                                                    |
| `char *strcatS(char *dest, const char *src)` | Appends the string `src` to the string `dest`.                                                |
| `int strcmpS(const char *lhs, const char *rhs)` | Compares the string `lhs` to the string `rhs`.                                               |
| `char *strcpyS(char *destination, char *source)` | Copies the string `source` to `destination`.                                                  |
| `char *strchrS(const char *str, int c)` | Finds the first occurrence of the character `c` in the string `str`.                         |
| `char *strstrS(const char *s1, const char *s2)` | Finds the first occurrence of the string `s2` in the string `s1`.                            |
| `char *strtokS(char *str, const char *delims)` | Tokenizes the string `str` using the delimiters `delims`.                                    |
| `char *strncpyS(char *dest, const char *src, size_t n)` | Copies up to `n` characters from the string `src` to `dest`.                                 |
| `char *strncatS(char *dest, const char *src, size_t n)` | Appends up to `n` characters from the string `src` to the string `dest`.                     |
| `int strncmpS(const char *str1, const char *str2, size_t n)` | Compares up to `n` characters of the strings `str1` and `str2`.                               |
| `char *strrevS(char *str)` | Reverses the string `str`.                                                                     |
| `size_t strspnS(const char *str1, const char *str2)` | Calculates the length of the initial segment of `str1` which consists entirely of characters in `str2`. |
| `char *strrepeat(const char *str, int n, char c, bool showEnd)` | Repeats the string `str` `n` times, optionally ending with character `c` if `showEnd` is true. |
| `char *Zfill(char *str, int n, char fill)` | Fills the string `str` to length `n` with the character `fill`.                              |
| `void generateString(int n)` | Generates a random string of length `n`.                                                      |
| `int getMin(int *vector)` | Returns the minimum value in the integer array `vector`.                                      |
| `int getMax(int *vector)` | Returns the maximum value in the integer array `vector`.                                      |
| `int calculator(int *vector, char operation)` | Performs the given `operation` on the elements of the integer array `vector`.                |
| `void touppercase(char *str)` | Converts all characters in the string `str` to uppercase.                                      |
| `void tolowercase(char *str)` | Converts all characters in the string `str` to lowercase.                                      |
| `void toswapcase(char *str)` | Swaps the case of all characters in the string `str`.                                          |
| `int ParseInteger(char *str)` | Parses the string `str` and returns its integer value.                                         |
| `bool IsNaN(char *str)` | Checks if the string `str` is not a number (NaN).                                                |
| `char *trim_string(char *str, int direction, char ch)` | Trims the character `ch` from the string `str` in the specified `direction`.                  |
| `char *subString(char *str, int start, int end)` | Extracts a substring from the string `str` starting at index `start` and ending at index `end`. |
| `char *cleanString(char *str)` | Cleans the string `str` by removing any non-printable characters.                             |
| `double randomNumber()` | Generates a random number.                                                                       |


## How to Compile and Execute 🚀

To compile and execute the project, use the following commands:

```bash
gcc main.c mylib.c -o main
./main
```

## Contributions 🤝

We welcome and encourage contributions to LibProject. If you have suggestions, improvements, or bug fixes, 
please submit a pull request. Your support helps us improve and evolve! 

Developed by Abdellah Karani. © 2024




