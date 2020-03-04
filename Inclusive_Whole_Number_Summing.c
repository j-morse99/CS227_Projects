/**********************************************************************/
/*                                                                    */
/* This program uses recursion to inclusively sum all the even        */
/* numbers in a given number range and prints the sum.                */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* printf and scanf                                */
#include <ctype.h> /* tolower                                         */

/**********************************************************************/
/*                         Symbolic Constants                         */
/**********************************************************************/
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define PROGRAM_NUMBER  4       /* Teacher assgigned program number   */
#define PROGRAMMER_NAME "Morse" /* The programmer's last name         */
#define MINIMUM_RANGE   -5000   /* Minimum range value                */
#define MAXIMUM_RANGE   5000    /* Maximum range value                */

/**********************************************************************/
/*                         Function Prototypes                        */ 
/**********************************************************************/
void print_heading();
   /* Prints the heading                                              */
void print_instructions();
   /* Prints the instructions                                         */
char get_response();
   /* Gets the response to continue or exit the program               */
void get_range(int *p_first_number_range, int *p_last_number_range);
   /* Receives the range of numbers to be processed                   */
void swap_numbers(int *p_first_number, int *p_last_number);
   /* Swaps an integer value from one variable into another variable  */
int recursive_sum(int first_number_range, int last_number_range);
   /* Sums the even numbers in a given number range                   */
int is_even(int number);
   /* Determines whether an integer is even                           */
 
/**********************************************************************/
/*                            Main Function                           */
/**********************************************************************/
int main()
{
   int first_number_range, /* The first number in the number range    */
       last_number_range;  /* The last number in the number range     */

   /* Prints the program heading                                      */
   print_heading();

   /* Prints the program instructions                                 */
   print_instructions();

   /* Loops processing a given number range until the user says to    */
   /* quit                                                            */
   while(get_response() == 'y')
   {

      /* Receives the whole number range of numbers to be processed   */
      get_range(&first_number_range, &last_number_range);

      /* Prints the even numbers sum in the given number range        */
      if(first_number_range > last_number_range)
         swap_numbers(&first_number_range, &last_number_range);
      printf("\nProcessing the range %d to %d",
            first_number_range, last_number_range);
      printf("\nThe sum of all even numbers in the range %d to %d is: "
             "%d", first_number_range, last_number_range, 
             recursive_sum(first_number_range, last_number_range));
   }  

   /* Says goodbye and terminates the program                         */
   printf("\nThanks for \"even summing\".  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                      Prints the program heading                    */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n\n\n\n");
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        PROGRAMMER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   return;
}

/**********************************************************************/
/*                        Prints the instructions                     */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program recursively calculates the sum of all");
   printf("\neven whole numbers between two numbers inclusively.");
   printf("\nYou are repeatedly asked to enter in the start and");
   printf("\nend of a range, and the sum of all even numbers in");
   printf("\nthat range is calculated and printed.  Information");
   printf("\nabout the recursive action of the function is also");
   printf("\nprinted so the recursive nature of the calculation");
   printf("\n                 may be observed.");
   return;
}

/**********************************************************************/
/*         Gets the response to continue or exit the program          */
/**********************************************************************/
char get_response()
{
   char response[2]; /* Receives response to continue or exit the     */
                     /* program                                       */
   do
   {
      printf("\n\nDo you want to process another range (y or n): ");
      scanf ("%1s", &response[0]);
      response[0] = tolower(response[0]);
   }while(response[0] != 'y' && response[0] != 'n');
   return response[0];
}

/**********************************************************************/
/*             Gets the range of numbers to be processed              */
/**********************************************************************/
void get_range(int *p_first_number_range, int *p_last_number_range)
{
   do
   {
      printf("\nEnter in the first number (from %d to %d): ", 
            MINIMUM_RANGE, MAXIMUM_RANGE);
      scanf("%d", p_first_number_range);
   }while((*p_first_number_range < MINIMUM_RANGE) ||
         (*p_first_number_range > MAXIMUM_RANGE));
   do
   {
      printf("\nEnter in the last number (from %d to %d): ",
            MINIMUM_RANGE, MAXIMUM_RANGE);
      scanf("%d", p_last_number_range);
   }while((*p_last_number_range < MINIMUM_RANGE) ||
         (*p_last_number_range > MAXIMUM_RANGE));
   return;
}

/**********************************************************************/
/*         Swaps the last and first number in the number range        */
/**********************************************************************/
void swap_numbers(int *p_first_number, int *p_last_number)
{
   *p_first_number += *p_last_number;
   *p_last_number   =  (*p_first_number - *p_last_number);
   *p_first_number  =  (*p_first_number - *p_last_number);
   return;
}

/**********************************************************************/
/*        Recursively sums the even numbers in the number range       */
/**********************************************************************/
int recursive_sum(int first_number_range, int last_number_range)
{
   int sum_total = 0; /* The total sum of all even integers in the    */
                      /* number range                                 */
   printf("\n    Entering sum function for range %d to %d", 
         first_number_range, last_number_range);
      
   if (first_number_range <= last_number_range)
   {
      if (is_even(first_number_range))
      {
         printf("\n        Adding: %d", first_number_range);
         sum_total += first_number_range; 
      }
      else
         printf("\n        Skipping %d", first_number_range);
      sum_total += recursive_sum(first_number_range + 1, 
                                 last_number_range);      
   }
   printf("\n    Exiting sum function for range %d to %d with result"
          ": %d", first_number_range, last_number_range, sum_total);
   return sum_total;
}

/**********************************************************************/
/*              Determines if a whole number is even                  */
/**********************************************************************/
int is_even(int number)
{
   return(number % 2 == 0);
}
