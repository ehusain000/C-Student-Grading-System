/*
 *	Assignment 2 by Eftekher Husain starts here
 */
#include <iostream>
#include"student.h"
#include <stdlib.h>
#include<string>
#include <math.h>

using namespace std;

double Student::rand_normal(double mean, double stddev) //Box Muller Method
{
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            double result = n1*stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2*stddev + mean;
    }
}

void Student::get_test_averages()
{
    for(int i=0; i<300; i++)
    {
    		midterm_one_score = nearbyint(rand_normal(70,12));
        midterm_1_array[i] = midterm_one_score;

        midterm_two_score = nearbyint(rand_normal(60,14));
        midterm_2_array[i] = midterm_two_score;

        final_exam_score = nearbyint(rand_normal(50,16));
        final_exam_array[i] = final_exam_score;

        avarage_score_array[i] = ((midterm_1_array[i]+midterm_2_array[i]+final_exam_array[i])/3);
    }
}

void Student::get_count_of_grade(){
    int maxGrade = 0;
    for(int i=0;i<300;i++)
    {
        if(avarage_score_array[i]>maxGrade)
        maxGrade=avarage_score_array[i];
    }

    count_A = 0;
    count_B = 0;
    count_C = 0;
    count_D = 0;
    count_F = 0;

    for(int i = 0; i<300; i++)
    {
        if((maxGrade-(maxGrade*.15))<=avarage_score_array[i])
        {
        	count_A++;

        }else if((maxGrade-(maxGrade*.35))<=avarage_score_array[i])
        {
        	count_B++;

        }else if((maxGrade-(maxGrade*.60))<=avarage_score_array[i])
        {
        	count_C++;

        }else if((maxGrade-(maxGrade*.80))<=avarage_score_array[i])
        {
        	count_D++;

        }else
        {
        	count_F++;
        }
    }
}

void Student::get_curved_grade(){

    for(int i=0; i<300; i++)
    {
        if(midterm_2_array[i]-midterm_1_array[i]>=30)
        {
        		new_midterm_1_array[i] = midterm_1_array[i] + (midterm_1_array[i]*.20);
        }
        else if(midterm_1_array[i]-midterm_2_array[i]>=25)
        {
        	new_midterm_1_array[i] = midterm_1_array[i] - (midterm_1_array[i]*.15);
        }
        else
        {
        	new_midterm_1_array[i] = midterm_1_array[i];
        }
        if(final_exam_array[i]-midterm_2_array[i]>=30)
        {
        	new_midterm_2_array[i] = midterm_2_array[i] + (midterm_2_array[i]*.20);
        }
        else if(midterm_2_array[i]-final_exam_array[i]>=25)
        {
        	new_midterm_2_array[i] = midterm_2_array[i] - (midterm_2_array[i]*.15);
        }
        else
        {
        	new_midterm_2_array[i] = midterm_2_array[i];
        }

    }
    for(int i=0; i<300; i++)
    {
    	new_avarage_score_array[i] = nearbyint((new_midterm_1_array[i] + new_midterm_2_array[i] + final_exam_array[i])/3);

    }
}

void Student::get_new_count_of_grade(){

    int new_max_Grade = 0;
    for(int i=0;i<300;i++)
    {
        if(new_avarage_score_array[i]>new_max_Grade)
        	new_max_Grade=new_avarage_score_array[i];
    }

    new_count_A = 0;
    new_count_B = 0;
    new_count_C = 0;
    new_count_D = 0;
    new_count_F = 0;

    for(int i = 0; i<300; i++)
    {
        if((new_max_Grade-(new_max_Grade*.15))<=new_avarage_score_array[i])
        {
        	new_count_A++;
        }
        else if((new_max_Grade-(new_max_Grade*.35))<=new_avarage_score_array[i])
        {
        	new_count_B++;
        }
        else if((new_max_Grade-(new_max_Grade*.60))<=new_avarage_score_array[i])
        {
        	new_count_C++;
        }
        else if((new_max_Grade-(new_max_Grade*.80))<=new_avarage_score_array[i])
        {
        	new_count_D++;
        }
        else
        {
        	new_count_F++;
        }
    }
}

void Student::get_differences(){
	difference_in_A = 0;
	if(new_count_A > count_A)
	{
		difference_in_A = new_count_A - count_A;
	}

	difference_in_B = 0;
	if(new_count_B > count_B)
	{
		difference_in_B = new_count_B - count_B;
	}
	difference_in_C = 0;
	if(new_count_C > count_C)
	{
		difference_in_C = new_count_C - count_C;
	}
	difference_in_D = 0;
	if(new_count_D > count_D)
	{
		difference_in_D = new_count_D - count_D;
	}

	float total = (difference_in_A+difference_in_B+difference_in_C+difference_in_D);
	cout << "Number of students promoted to higher grades by the rule: " << total <<endl;
	cout << "- A from lower grade: " << difference_in_A <<endl;
	cout << "- B from lower grade: " << difference_in_B <<endl;
	cout << "- C from lower grade: " << difference_in_C<<endl;
	cout << "- D from lower grade: " << difference_in_D<<endl;
	cout<< "- "<< (total/300)*100 <<"% of enrollment " << endl;

	if(count_A > new_count_A)
	{
		difference_in_A = count_A - new_count_A;
	}

	if(count_B > new_count_B)
	{
		difference_in_B = count_B - new_count_B;
	}

	if(count_C > new_count_C)
	{
		difference_in_C = count_C - new_count_C;
	}

	if(count_D > new_count_D)
	{
		difference_in_D = count_D - new_count_D;
	}

	float new_total = (difference_in_A+difference_in_B+difference_in_C+difference_in_D);
	cout << "Number of students descended to lower grades by the rule: " << new_total <<endl;
	cout << "- A from higher grade: " << difference_in_A <<endl;
	cout << "- B from higher grade: " << difference_in_B <<endl;
	cout << "- C from higher grade: " << difference_in_C<<endl;
	cout << "- D from higher grade: " << difference_in_D<<endl;
	cout<< "- "<<(total/300)*100 <<"% of enrollment " << endl;

	float same_grade = (300-(total+new_total));

	cout << "Number of students staying in the same grades: " << same_grade<< endl;
	cout<< "- "<<(same_grade/300)*100<<"% of enrollment "<< endl;
}

void Student:: print_result(){
	get_test_averages();
	get_count_of_grade();
	get_curved_grade();
	get_new_count_of_grade();
	get_differences();
}

/* Assignment 2 by Eftekher Husain ends here */





