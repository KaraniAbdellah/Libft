#include <stdio.h>
#include  "myLib.h"
#include <string.h>
#include <stdbool.h>


int main() {
	// Test strlenS Function
	char hello[] = "HelloWorld";
	printf("\nlength = %ld\n", strlenS(hello));
	// Test strcatS() Function
	char word1[20] = "A";
	char word2[6] = "A";
	char *word = strcatS(word1, word2);
	for (int i = 0; word[i] != '\0'; i++) printf("%c", word[i]);
	printf("\n");
	// Test strcmpS() Function
	char str1[20] = "W";
	char str2[60] = "W";
	printf("\nCompare = %d\n", strcmpS(str1, str2));
	printf("\nCompare = %d\n", strcmp(str1, str2));
	// Test strcpyS()
	char string1[20] = "C programming";
	char string2[2];
	strcpyS(string2, string1);
    puts(string2);
	printf("\n%s\n", string2);
	// Test strchr()
	const char link[] = "https://www.github.com";
	char ch = 'b';
	char *ret;
	ret = strchrS(link, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	// Test strstrS()
	char str_test[] = "geeksforGEEKS";
	char f[] = "forGEEKS";
	char *p_tr = strstrS(str_test, f);
	printf("\nThe String Is : |%s|\n", p_tr);
	// Test  strtokS()
    char str_str[] = "world!    Welcome to C programming.";
    const char delim[] = " ,.!";
    char *token = strtokS(str_str, delim);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtokS(NULL, delim);
    }
    // Test strncpyS()
    char src_str[]= "To be or not to be";
    char dest_str2[40];
    char dest_str3[40];
    strncpyS ( dest_str2, src_str, sizeof(dest_str2) );
    strncpyS ( dest_str3, dest_str2, 5);
    dest_str3[5] = '\0';
    puts (src_str);
    puts (dest_str2);
    puts (dest_str3);
    printf("\n");
    // Test strncutS()
   char src_cut[50], dest_cut[50];
   strcpy(src_cut,  "This is source");
   strcpy(dest_cut, "This is destination");
   strncat(dest_cut, src_cut, 15);
   printf("Final destination string : |%s|\n", dest_cut);
   // Test strncmpS()
   char str1_cmp[15];
   char str2_cmp[15];
   int ret_cmp;
   strcpyS (str1_cmp, "abcdef");
   strcpyS (str2_cmp, "ABCDEF");
   ret_cmp = strncmp(str1_cmp, str2_cmp, 4);
   if(ret_cmp < 0) {
      printf("str1 is less than str2\n");
   } else if(ret_cmp > 0) {
      printf("str2 is less than str1\n");
   } else {
      printf("str1 is equal to str2\n");
   }
   // Test strrevS ()
   char rev_str[20] = "1234567";
   printf("After reversing string is = %s\n", strrevS(rev_str));
   // Test strspnS ()
   printf("Length of initial segment matching : %zu\n", strspnS ("abcrd","abcdef")); // Output: 4
   printf("Length of initial segment matching : %zu\n", strspn ("abcrd","abcdef")); // Output: 4
    // Test strrepeat()
    char repeat[10] = "Be Nice";
    strrepeat(repeat, 3, '_', true);
    printf("\n");
    // Test ZFill()
    char str_fill[50] = "10";
    Zfill(str_fill, 10, '@');
    printf("\nThe String After Filling Is %s\n", str_fill);
    // Test generateString();
    printf("The Generated Numbes Is :"); generateString(10);
    printf("\n");
    // Test getMin(); && getMax();
    int vector1[10] = {2, 1};
    printf("The Min Is %d\n", getMin(vector1));
    printf("The Max Is %d\n", getMax(vector1));
    // Test calculator();
    printf("The Mutiplication is %d\n", calculator(vector1, '*'));
    printf("The Sum is %d\n", calculator(vector1, '+'));
    printf("The Substraction is %d\n", calculator(vector1, '-'));
    printf("The Division is %d\n", calculator(vector1, '/'));
    // Test toupper() && tolower() functions
    char cases[20] = "Hello World";
    tolowercase(cases);
    printf("To Lower Case : %s\n", cases);
    touppercase(cases);
    cases[0] = 'E';
    printf("To Upper Case : %s\n", cases);
    char cases1[20] = "HeLlo AbdeLlah";
    toswapcase(cases1);
    printf("To Swap Case : %s\n", cases1);
    // Test ParseInteger()
    printf("The Number In This Integer is %d\n", ParseInteger("Hello123OP340"));
    // Test IsNaN();
    char check_if_number[10] = "1293";
    if (IsNaN(check_if_number)) printf("%s is Number \n", check_if_number);
    else printf("%s Is Not A Number\n", check_if_number);
    // Test trim_string()
    char trim_string_test[30] = "^^^Abde^^^llah^^^";
    printf("The Trimed String From Right is %s\n", trim_string(trim_string_test, 1, '^'));
    printf("The Trimed String From Left is %s\n", trim_string(trim_string_test, -1, '^'));
    printf("The Trimed String From All is %s\n", trim_string(trim_string_test, 0, '^'));
    // Test subString()
    char sub_str_test[20] = "Hello World";
    printf("The SubString from %s From %d to %d is \"%s\"\n", sub_str_test, 4, 8, subString(sub_str_test, 4, 6));
    // Test cleanString()
    char clean_str[20] = "Elzero//?4$$%930";
    printf("The Cleaned String Is %s\n", cleanString(clean_str));
    // Test randomNumber()
    printf("The randomNumber Are : \n");
    for (int i = 0; i < 10; i++) {
        printf("iter %d : %lf\n", i, randomNumber(i));
    }
    return 0;
}

























