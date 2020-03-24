---
title: Review Questions for Chapter 3
author: Ken Goettler
---

1. Which data type would ou use for each of the following kinds of data
   (sometimes more than one type could be appropriate)?
   a. The population of East Simpleton
   b. The cost of a move on DVD
   c. The most common letter in this chatper
   d. The number of time sthat the letter occurs in this chapter

   a. `int`
   b. `float`; `double` could also be used but the extra precision is likely 
       not needed
   c. `char` is most appropriate, but string could also be used
   d. `int` or `long int` could be used

2. Why would you use a type `long` variable instead of a type `int`?

   If the number you are trying to store is larger than the usual integer size
   for the computer on which your program will run, you will want to use 
   `long` to avoid overflow.

3. What portable types might you use to get a 32-bit signed integer, and what 
   would the rationale be for each choice?

   `int32_t` could be used, if defined.

4. Identify the type and meaning, if any, of each of the following constants:
   a. '\b'
   b. 1066
   c. 99.44
   d. 0XAA
   e. 2.0e30

   a. `char` constant
   b. `int` constant
   c `double` constant
   d. `unsigned int` constant
   e. `double` constant

5. Dottie Cawm has concocted an error-laden program. Help her find the mistakes.
   
   ```c
   include <stdio.h>

   main
   {
     float g; h;
     float tax, rate;

     g = e21;
     tax = rate*g;
   }
   ```

   A number of problems
    - Need `#` before `include`
    - Function definition should be `int main (void)`
    - Variable declarations should be separated by commas, not colons
    - `e21` is not defined
    - `rate` is not initialized before being multiplied by rate

6. Identify the data type (as used in declaration statements) and the `printf()`
   format specifier for each of the following constants

   | 12          | `int`
   | 0x3         | 
   | 'C'         |
   | 2.34E07     |
   | '\040'      |
   | 7.0         |
   | 6L          |
   | 6.0f        |
   | 0x5.b6p12   |

   
