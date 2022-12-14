# Calculation-of-the-net-payment-of-a-person

# Paycheck Calculator 
##### Editor - Kyi Lei Aye

### Overview
Calculate the Net Payment based on the Raw Income of the user after the deduction amounts of Federal Income Tax, Social Security Tax, Medicare/Medicaid Tax, State Tax, Pension Plan Percentages, Health, Dental, and Vision Insurances.

### Problem Solving Phase
1. Find each deduction amount based on the income the user put
2. Find the total deductions and net payment


### Implementation Phase
1. Add include and using directives for I/O statements
2. Declare global variables to store values and to be called by the functions
3. Declare the functions, some with formal parameters
4. Put input() function for taking input
5. Define deductions() function to calculate tax deductions and output the results
6. Find taxable salary amounts of CA and NY based on the income by using stateTax() function with initializing formal parameters that are the Raw Income and State the user live
7. Calculate the pension plan deduction by defining the pensionPlan() function
8.  Define health(), dental(), and vision() functions to return bi-monthly based deduction amounts based on the user's choice
9. Find all insurance values based on the way the user is paid

### References
1. "**Problem Solving with C++**" by Walter Savitch, Chapter 2, 3, 4
2. For New York income state tax: **https://www.nerdwallet.com/article/taxes/new-york-state-tax**
