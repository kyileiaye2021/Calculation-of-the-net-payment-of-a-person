
#include <iostream>
#include <string>
//declaring constant and global variables
const double FEDERAL = 0.22;
const double SOCIAL = 0.062;
const double MEDICARE = 0.0145;
int option, healthChoice, dentalChoice, visionChoice;
double income, percentage, healthD, dentalD, visionD;
char ans;
std::string state;

//function declaration
void input();
void deductions();
double stateTax(double, std::string);
double pensionPlan(double, double);
double health(double);
double dental(double);
double dental(double);
double insurances();
double caStateTax(double);
double nyStateTax(double);

int main(){
    using namespace std;
    do{
        input();
    }while(ans == 'Y' || ans == 'y');
    return 0;
}
/**
 * @brief taking input from users
 * 
 */
void input(){
    using namespace std;

    cout << "What is your income?: ";
    cin >> income;
    cout << "\nIn what way do you get paid? " << endl;
    cout << "1. Yearly\n2. Monthly\n3. Bi-monthly\n4. Weekly\nChoose one of the above methods: ";
    cin >> option;
    cout << "\nThis paycheck calculation will be based on the CA and NY state tax." << endl;
    cout << "In which state do you live? Please enter the abbreviations of the state: ";
    cin >> state;
    cout << "\nWhat is your pension plan percentage? :";
    cin >> percentage;

    cout << "\nFor Health Insurance, choose one of the following options" << endl;
    cout << "1.Self 2.Self and Others 3.No health insurance: ";
    cin >> healthChoice;

    cout << "\nFor Dental Insurance, choose one of the following options" << endl;
    cout << "1.Self 2.Self and Others 3.No dental insurance: ";
    cin >> dentalChoice;

    cout << "\nFor Vision Insurance, choose one of the following options" << endl;
    cout << "1.Self 2.Self and Others 3.No vision insurance: ";
    cin >> visionChoice;

    deductions();

    cout << "\nDo you want to check the total deductions and net payment again? (Y)es or (N)o: ";
    cin >> ans;
}
/**
 * @brief calculating the federal, social, medicare deductions and output each deduction, total deductions, and net payment to two decimal numbers
 * 
 */
void deductions(){
    using namespace std;

    double federalD = income * FEDERAL;
    double socialD = income * SOCIAL;
    double medicareD = income * MEDICARE;
    double totalD = federalD + socialD + medicareD + stateTax(income, state) + pensionPlan(income, percentage) + insurances();
    double netPayment = income - totalD;

    //using magic formula
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Federal Tax Deduction: $" << federalD << endl;
    cout << "Social Security Tax Deduction: $" << socialD << endl;
    cout << "Medicare/Medicaid Deduction: $" << medicareD << endl;
    cout << "State Tax Deduction: $" << stateTax(income, state) << endl;
    cout << "Pension Deduction: $" << pensionPlan(income, percentage) << endl;
    cout << "Health Deduction: $" << healthD << endl;
    cout << "Dental Deduction: $" << dentalD << endl;
    cout << "Vision Deduction: $" << visionD << endl;
    cout << "Total Deductions: $" << totalD << endl;
    cout << "Total netPayment: $" << netPayment << endl;
}
/**
 * @brief return the state tax deduction amounts based on the user's choice on state
 * 
 * @param pay - income
 * @param s - state
 * @return double 
 */
double stateTax(double pay, std::string s)
{
    if(s == "CA" || s == "Ca" || s == "ca" || s == "cA"){
        return (caStateTax(income));
    }
    else{
        return (nyStateTax(income));
    }
}   
/**
 * @brief return the pension deduction amount with the percentage that the user input 
 * dividing the percentage the user put by 100 and multiply it with income
 * @param payment - income
 * @param percent - percentage
 * @return double 
 */
double pensionPlan(double payment, double percent){
    return (percent / 100) * (payment);
}
/**
 * @brief return health insurance amount based on the plan the user choose
 * 
 * @param h - healthChoice
 * @return double 
 */
double health(int h){
    if(h == 1 || h == 3){
        return 0;
    }
    else{
        return 251.63;
    }  
}
/**
 * @brief return dental insurance amount based on the plan the user choose
 * @param d - dentalChoice
 * @return double 
 */
double dental(int d){
    if(d == 1){
        return 17.58;
    }
    else if(d == 2){
        return 70.88;
    }
    else{
        return 0;
    }
}
/**
 * @brief return vision insurance amount based on the plan the user choose
 * @param v - visionChoice
 */
double vision(int v)
{
    if(v == 1 || v == 3){
        return 0;
    }
    else{
        return 5.61;
    }
}
/**
 * @brief calculating health, dental, and vision deductions based on the way the user is paid and return the total insurance deductions
 * 
 * @return double 
 */
double insurances(){
    using namespace std;
    
    if(option == 1){
        healthD = health(healthChoice) * 24;
        dentalD = dental(dentalChoice) * 24;
        visionD = vision(visionChoice) * 24;
    }
    else if(option == 2){
        healthD = health(healthChoice) * 2;
        dentalD = dental(dentalChoice) * 2;
        visionD = vision(visionChoice) * 2;
    }
    else if(option == 3){
        healthD = health(healthChoice);
        dentalD = dental(dentalChoice);
        visionD = vision(visionChoice);
    }
    else if(option == 4){
        healthD = health(healthChoice) / 2;
        dentalD = dental(dentalChoice) / 2;
        visionD = vision(visionChoice) / 2;
    }
    else{
        cout << "You need to choose from 1 to 4." << endl;
    }
    return (healthD + dentalD + visionD);
}
/**
 * @brief return the deduction amount based on the taxable salary in CA
 * 
 * @param pay - income
 * @return double 
 */
double caStateTax(double pay){
    if(pay <= 8544){
        return (pay * 0.01);
    }
    else if(pay >= 8545 && pay <= 20255){
        return (pay * 0.02);
    }
    else if(pay >= 20256 && pay <= 31969){
        return (pay * 0.04);
    }
    else if(pay >= 31970 && pay <= 44377){
        return (pay  * 0.06);
    }
    else if(pay >= 44378 && pay <= 56085){
        return (pay  * 0.08);
    }
    else if(pay >= 56086 && pay <= 286492){
        return (pay  * 0.093);
    }
    else if(pay >= 286493 && pay <= 343788){
        return (pay  * 0.103);
    }
    else if(pay >= 343789 && pay <= 572980){
        return (pay  * 0.113);
    }
    else if(pay >= 572981 && pay <= 999999){
        return (pay  * 0.123);
    }
    else{
        return (pay * 0.133);
    }
}
/**
 * @brief return the deduction amount based on the taxable salary in NY
 * 
 * @param pay - income
 * @return double 
 */
double nyStateTax(double pay){
    if(pay <= 8500){
        return (pay * 0.04);
    }
    else if(pay >= 8501 && pay <= 11700){
        return (pay * 0.045);
    }
    else if(pay >= 11701 && pay <= 13900){
        return (pay * 0.0525);
    }
    else if(pay >= 13901 && pay <= 21400){
        return (pay * 0.059);
    }
    else if(pay >= 21401 && pay <= 80650){
        return (pay * 0.0597);
    }
    else if(pay >= 80651 && pay <= 215400){
        return (pay  * 0.0633);
    }
    else if(pay >= 215401 && pay <= 1077550){
        return (pay * 0.0685);
    }
    else if(pay >= 1077551 && pay <= 5000000){
        return (income * 0.0965);
    }
    else if(pay >= 5000001 && pay <= 25000000){
        return (pay * 0.103);
    }
    else{
        return (pay * 0.109);
    }
}
