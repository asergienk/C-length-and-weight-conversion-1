/*
  Program: Daily16
  Author: Anna Sergienko
  Date: 11/01/2019
  Purpose: This program asks the user whether he wants to do length or weight
  conversion, and then to choose a system of conversion within those two.
  All the functions have a void return type. However, with the use of pointers
  we can still change the value of the variables just by pointing to their address.
  The program runs until the user enters 0.
*/

#include <stdio.h>
#include<math.h>

void clear_keyboard_buffer(void);

void convert_lengths(void);
void convert_weights(void);

void length_to_metric(void);
void length_to_us(void);

void weight_to_metric(void);
void weight_to_us(void);

void input_values_length_to_metric(int *pFeet, double *pInches);
void do_conversion_length_to_metric(int feet, double inches, int *pMeters, double *pCm);
void output_result_length_to_metric(int feet, double inches, int meters, double cm);

void input_values_length_to_us(int *pMeters, double *pCm);
void do_conversion_length_to_us(int meters, double cm, int *pFeet, double *pInches);
void output_result_length_to_us(int meters, double cm, int feet, double inches);

void input_values_weight_to_metric(int *pPounds, double *pOunces);
void do_conversion_weight_to_metric(int pounds, double ounces, int *pKilograms, double *pGrams);
void output_result_weight_to_metric(int pounds, double ounces, int kilograms, double grams);

void input_values_weight_to_us(int *pKilograms, double *pGrams);
void do_conversion_weight_to_us(int kilograms, double grams, int *pPounds, double *pOunces);
void output_result_weight_to_us(int kilograms, double grams, int pounds, double ounces);


const double METERS_IN_FOOT = 0.3048;
const int INCHES_IN_FOOT = 12;
const int CENTIMETERS_IN_METER = 100;

const double POUNDS_IN_KILOGRAM = 2.2046;
const int GRAMS_IN_KILOGRAM = 1000;
const int OUNCES_IN_POUND = 16;

 
int main(int argc, char* argv[])
{
    
    int choice=1;
    int noc;
    
    while(choice!=0)
    {
    printf("Please choose 1 for length conversion or 2 for weight conversion: ");
    noc=scanf("%d", &choice);
    clear_keyboard_buffer();
    
    while((choice!=0 && choice!=1 && choice!=2) || noc!=1)
    {
        printf("Please choose 1 for length conversion or 2 for weight conversion: ");
        noc=scanf("%d", &choice);
        clear_keyboard_buffer();
    }
    
    if(choice==1)
    {
        convert_lengths();
    }
    else if(choice==2)
    {
        convert_weights();
    }
    else if(choice==0)
    {
        return 0;
    }
    }
    return 0;
}

//CONVERT LENGTHS
void convert_lengths(void)
{
    int input;
    int noc;
    printf("You chose length converion.\n");
    printf("Please choose 1 to convert lengths from feet/inches to meters/centimeters or 2 to convert from meters/centimeters to feet/inches: ");
    noc=scanf("%d", &input);
    clear_keyboard_buffer();
    
    while((input!=0 && input!=1 && input!=2) || noc!=1)
    {
        printf("Please choose 1 to convert lengths from feet/inches to meters/centimeters or 2 to convert from meters/centimeters to feet/inches: ");
        noc=scanf("%d", &input);
        clear_keyboard_buffer();
    }
    
    if(input==1)
    {
        length_to_metric();
    }
    else if(input==2)
    {
        length_to_us();
    }
    else if(input==0)
    {
        return;
    }
}

//CONVERT WEIGHTS
void convert_weights(void)
{
    int input2;
    int noc;

    printf("You chose weight converion.\n");
    printf("Please choose 1 to convert weights from pounds/ounces to kilograms/grams or 2 to convert from kilograms/grams to pounds/ounces: ");
    noc=scanf("%d", &input2);
    clear_keyboard_buffer();
    
    while((input2!=0 && input2!=1 && input2!=2) || noc!=1)
    {
        printf("Please choose 1 to convert weights from pounds/ounces to kilograms/grams or 2 to convert from kilograms/grams to pounds/ounces: ");
        noc=scanf("%d", &input2);
        clear_keyboard_buffer();
    }
    
    if(input2==1)
    {
        weight_to_metric();
    }
    else if(input2==2)
    {
        weight_to_us();
    }
    else if(input2==0)
    {
        return;
    }
}

//LENGTH TO METRIC
void length_to_metric(void)
{
    int feet;
    double inches;
    int meters;
    double cm;
    
    printf("You chose length to metric conversion.\n");
    input_values_length_to_metric(&feet, &inches);
    do_conversion_length_to_metric(feet, inches, &meters, &cm);
    output_result_length_to_metric(feet, inches, meters, cm);
}

void input_values_length_to_metric(int *pFeet, double *pInches)
{
    printf("Please enter feet: \n");
    scanf("%d", pFeet);
    clear_keyboard_buffer();
    printf("Please enter inches: \n");
    scanf("%lf", pInches);
    clear_keyboard_buffer();
}

void do_conversion_length_to_metric(int feet, double inches, int *pMeters, double *pCm)
{
    double feet_to_meters;
    double total_feet;
    
    total_feet=feet+(inches/INCHES_IN_FOOT);
    
    feet_to_meters=total_feet*METERS_IN_FOOT;

    *pCm=(feet_to_meters*CENTIMETERS_IN_METER)-((int)feet_to_meters)*CENTIMETERS_IN_METER;
    *pMeters=(int)feet_to_meters;
}

void output_result_length_to_metric(int feet, double inches, int meters, double cm)
{
    printf("%d feet and %.2f inches is equivalent to %d meters and %.2f centimeters.\n", feet, inches, meters, cm);
}


//LENGTH TO US
void length_to_us(void)
{
    int feet;
    double inches;
    int meters;
    double cm;
    printf("You chose length to us conversion.\n");
    
    input_values_length_to_us(&meters, &cm);
    do_conversion_length_to_us(meters, cm, &feet, &inches);
    output_result_length_to_us(meters, cm, feet, inches);
}

void input_values_length_to_us(int *pMeters, double *pCm)
{
    printf("Please enter meters: \n");
    scanf("%d", pMeters);
    clear_keyboard_buffer();
    printf("Please enter centimeters: \n");
    scanf("%lf", pCm);
    clear_keyboard_buffer();
}

void do_conversion_length_to_us(int meters, double cm, int *pFeet, double *pInches)
{
    double meters_to_feet;
    double total_meters;
    
    total_meters=meters+(cm/CENTIMETERS_IN_METER);
    
    meters_to_feet=total_meters/METERS_IN_FOOT;
    
    *pInches=(meters_to_feet*INCHES_IN_FOOT)-((int)meters_to_feet)*INCHES_IN_FOOT;
    *pFeet=(int)meters_to_feet;
}

void output_result_length_to_us(int meters, double cm, int feet, double inches)
{
    printf("%d meters and %.2f centimeters is equivalent to %d feet and %.2f inches.\n", meters, cm, feet, inches);
}



//WEIGHT TO METRIC
void weight_to_metric(void)
{
    int pounds;
    double ounces;
    int kilograms;
    double grams;
    printf("You chose weight to metric conversion.\n");
    
    input_values_weight_to_metric(&pounds, &ounces);
    do_conversion_weight_to_metric(pounds, ounces, &kilograms, &grams);
    output_result_weight_to_metric(pounds, ounces, kilograms, grams);
}

void input_values_weight_to_metric(int *pPounds, double *pOunces)
{
    printf("Please enter pounds: \n");
    scanf("%d", pPounds);
    clear_keyboard_buffer();
    printf("Please enter ounces: \n");
    scanf("%lf", pOunces);
    clear_keyboard_buffer();
}

void do_conversion_weight_to_metric(int pounds, double ounces, int *pKilograms, double *pGrams)
{
    double pounds_to_kilograms;
    double total_pounds;
    
    total_pounds=pounds+(ounces/OUNCES_IN_POUND);
    
    pounds_to_kilograms=total_pounds/POUNDS_IN_KILOGRAM;
    
    *pGrams=(pounds_to_kilograms*GRAMS_IN_KILOGRAM)-((int)pounds_to_kilograms)*GRAMS_IN_KILOGRAM;
    *pKilograms=(int)pounds_to_kilograms;
}

void output_result_weight_to_metric(int pounds, double ounces, int kilograms, double grams)
{
    printf("%d pounds and %.2f ounces is equivalent to %d kilograms and %.2f grams.\n", pounds, ounces, kilograms, grams);
}


//WEIGHT TO US
void weight_to_us(void)
{
    int pounds;
    double ounces;
    int kilograms;
    double grams;
    printf("You chose weight to us conversion.\n");
    
    input_values_weight_to_us(&kilograms, &grams);
    do_conversion_weight_to_us(kilograms, grams, &pounds, &ounces);
    output_result_weight_to_us(kilograms, grams, pounds, ounces);
}

void input_values_weight_to_us(int *pKilograms, double *pGrams)
{
    printf("Please enter kilograms: \n");
    scanf("%d", pKilograms);
    clear_keyboard_buffer();
    printf("Please enter grams: \n");
    scanf("%lf", pGrams);
    clear_keyboard_buffer();
}

void do_conversion_weight_to_us(int kilograms, double grams, int *pPounds, double *pOunces)
{
    double kilograms_to_pounds;
    double total_kilograms;
    
    total_kilograms=kilograms+(grams/GRAMS_IN_KILOGRAM);
    
    kilograms_to_pounds=total_kilograms*POUNDS_IN_KILOGRAM;
    
    *pOunces=(kilograms_to_pounds*OUNCES_IN_POUND)-((int)kilograms_to_pounds)*OUNCES_IN_POUND;
    *pPounds=(int)kilograms_to_pounds;   
}


void output_result_weight_to_us(int kilograms, double grams, int pounds, double ounces)
{
    printf("%d kilograms and %.2f grams is equivalent to %d pounds and %.2f ounces.\n", kilograms, grams, pounds, ounces);
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}

}










