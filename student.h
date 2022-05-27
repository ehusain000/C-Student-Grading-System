/*
 * student.h
 *
 *  Created on: Mar 29, 2018
 *      Author: Eftekher Husain
 */

#ifndef STUDENT_H_
#define STUDENT_H_

class Student{
private:
	int midterm_1_array[300];
	int midterm_2_array[300];
	int final_exam_array[300];
	int avarage_score_array[300];

	int midterm_one_score;
	int midterm_two_score;
	int final_exam_score;

    int new_midterm_1_array[300];
    int new_midterm_2_array[300];
    int new_avarage_score_array[300];

    int count_A;
    int count_B;
    int count_C;
    int count_D;
    int count_F;

    int new_count_A;
    int new_count_B;
    int new_count_C;
    int new_count_D;
    int new_count_F;

    int difference_in_A;
    int difference_in_B;
	int difference_in_C;
	int difference_in_D;
	int difference_in_F;
public:
	double rand_normal(double mean, double stddev) ;
	void get_test_averages();
	void get_count_of_grade();
	void get_curved_grade();
	void get_new_count_of_grade();
	void get_differences();
	void print_result();
};


#endif /* STUDENT_H_ */
