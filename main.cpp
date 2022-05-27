#include <iostream>
#include<ctime> //for random
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include<string> //for string
#include<cmath> // for sqrt
using namespace std;

/*
* I have used  example of box muller method. */

/* Important: After compiling, please make sure to expand the the window size of the terminal
* for the table to be clear and organized */

/* Note: I mostly have used cplusplus.com and stack overflow as my resouces */

//generate 3 digit numbers for ss
int ssid_3_digits(){
    int max = 999;
    int random_number = (rand() % max);

    return random_number;
}
//generate 2 digit numbers for ss
int ssid_2_digits(){
    int max = 99;
    int random_number = (rand() % max);

    return random_number;
}
//generate 4 digit numbers for ss
int ssid_4_digits(){
    int max = 9999;
    int random_number = (rand() % max);

    return random_number;
}

/*generate random upper */
char rand_upper(){
    char first_letter = (90 - (rand() % 26));
    return first_letter;
}

char get_lower_char(){
    char lower_part_of_name = ('a' + (rand() % 26));
    return lower_part_of_name;
}
/*generate random lower case letters with first letter cap */
string rand_lower(){
    string name;
    int max = 12;
    int min = 3;
    int random_number = (rand() % max) + min;
    for(int i = 1; i <= random_number; i++){
        name += get_lower_char();
    }
    return name;

}
//generate random name(Last and First)
string rand_name(){
    string random_name = rand_upper() + rand_lower();

    return random_name;
}

//generate random major
string major(){
string majors[6]={"CS", "CS", "CS", "CE", "EE", "ME"};
int random_index =(rand() % 6);

return majors[random_index];

}
//to computer test score
double rand_box_muller(double mean, double std_dev)
{
    static double m1;
    static double m2 = 0.0; // variable intialized
    static int el = 0;// variable intialized
    double dev,num1, num2, x;// variables intialized

if (!el) //when not 0
{   do
    {
        num1 = ( (2.0) * rand() / (RAND_MAX) ) -1;
        num2 = ( (2.0) * rand() / (RAND_MAX) ) -1;
        x = (num1*num1) + (num2*num2);
    }

    while (x == 0.0 || x > 1.0);
    {
        dev = sqrt(-2.0*log(x)/x);
        m1 = num1*dev;
        m2 = num2*dev;
        el = 1;
        return (m1 * std_dev + mean);
    }
}else
{
    el = 0;
    return m2*std_dev + mean;
}
}

//function for test scores
void rand_testScores()
{
    float mid_term1_Score = nearbyint(rand_box_muller(70,14));
    float mid_term2_Score = nearbyint(rand_box_muller(80,13));
    float final_score = nearbyint(rand_box_muller(90,12));
    cout << setfill(' ') <<setw(15) << mid_term1_Score <<
            setfill(' ') <<setw(15) <<  mid_term2_Score<<
            setfill(' ') <<setw(15) << final_score;
}

int main()
{
    int number_of_students;
    cout << "Enter the number of students record you want to be displayed: ";
    cin >> number_of_students;

cout << setw(3)  << "ssid" <<
        setw(18) << "fname" <<
        setw(18) << "lname" <<
        setw(18) << "major" <<
        setw(18) << "midterm1" <<
        setw(18) << "midterm2" <<
        setw(10) << "final" << '\n';

    srand(time(NULL));
    for(int i=0; i < number_of_students; i++){
        cout << setfill('0') << setw(3) << ssid_3_digits() << "-";
        cout << setfill('0') << setw(2) << ssid_2_digits() << "-";
        cout << setfill('0') << setw(4) << ssid_4_digits() << " ";

        cout << setfill(' ') <<setw(15) << rand_name() <<
                setfill(' ') <<setw(15) << rand_name() <<
                setfill(' ') <<setw(15) << major();
                rand_testScores();
        cout << endl;
    }

    return 0;
}
