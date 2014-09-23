#include <stdio.h>
#define NUM 10
int max(int input_scores[]);
char finalgrade ( int exam1_score, int exam2_score);
int main()
{
    int i;
    int Exam1[NUM];
    int Exam2[NUM];
    int max_exam1 = 0;
    int max_exam2 = 0;
    char final_grade;
 
    /* input Exam1 scores*/
    int tmp;
    printf("Input Exam1 scores\n");
    for (int j = 0; j <NUM; j++)
    { 
        int stu_num = j +1;
        printf("Student %d score: ",stu_num);
        scanf("%d", &tmp);
        Exam1[j] = tmp;
    }
        
 
    /* input Exam2 scores*/
    int tmp1;
    printf("Input Exam2 scores\n");
    for (int k = 0; k <NUM; k++)
    { 
        int stu_num = k +1;
        printf("Student %d score: ",stu_num);
        scanf("%d", &tmp1);
        Exam2[k] = tmp1;
    }
 
    /* calculate the max score for each exams. */
    max_exam1 = max(Exam1);
    max_exam2 = max(Exam2);
    printf ( "The highest score in exam1 is %d \n", max_exam1);
    printf ( "The highest score in exam2 is %d \n", max_exam2);
 
    /* using for loop to print out the final grade for each students. */
    printf( "Final grades\n") ;
    for ( i=0 ; i<NUM ; i++) 
    {
        int stu_num = i +1;
        final_grade = finalgrade ( Exam1[i], Exam2[i] );
        printf ("Student %d final grade: %c\n", stu_num, final_grade);
    }
    return 0;
}
 
int max(int input_scores[])
{
        int max = 0;
        int temp = 0;
        for (int q = 0; q < NUM; q++)
        {
            if(input_scores[q] >temp)
            temp = input_scores[q];
        }  
        max = temp;
        return max;
 }
char finalgrade ( int exam1_score, int exam2_score)
{
    char grade;
    int avg = exam1_score + exam2_score;
    avg = avg / 2;
   
    if(avg >= 88)
    {
        grade = 'A';
    }

    else if(88 > avg && avg >= 75)
    {
        grade = 'B';
    }

    else if(75 > avg)
    {
        grade = 'C';
    }
 
    return grade;
}
