 #include "input.h"
 void output(){
    fprintf(out,"______________________________________________________________________________________________________\n");
    fprintf(out,"Class Average Percentage: %f\n",total_percentage/count);
    fprintf(out,"Highest percentage = %f\n",highest);
    fprintf(out,"Lowest percentage=%f\n",lowest);
    fprintf(out,"No. of student in O grade: %d\n",count_O);
    fprintf(out,"No. of student in A+ grade: %d\n",count_AP);
    fprintf(out,"No. of student in A grade: %d\n",count_A);
    fprintf(out,"No. of student in B+ grade: %d\n",count_BP);
    fprintf(out,"No. of student in B grade: %d\n",count_B);
    fprintf(out,"No. of student in C grade: %d\n",count_C);
    fprintf(out,"No. of student in D grade: %d\n",count_D);
    fprintf(out,"No. of student in F grade: %d\n",count_F);

 }