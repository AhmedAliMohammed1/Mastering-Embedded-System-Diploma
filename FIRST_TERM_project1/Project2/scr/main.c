#include "Platform_Types.h"
#include "FIFO.h"
#define Student_N 50

element_type Student_data[Student_N];
FIFO_t Student;
int main(){
	int x=0,ID;
	FIFO_init(&Student,Student_data,Student_N);
	printf("FIFO INIT DONE \n -------------------------- \n");
	while(1){
 printf("1: Add the Student Details Manually\n");
 printf(" 2: Add the Student Details From the Text File\n");
 printf("3: Find the Student Details by Roll Number\n");
 printf("4: Find the Student’s Details by First Name\n");
 printf("5: Find the Student Details by CourseID\n");
 printf("6: Find the Total Number Of Students\n");
 printf("7: Delete the Student Details by Roll Number\n");
 printf("8: Update the Student Details by Roll Number\n");
 printf("9: Show All Information\n");
 printf("10: To Exit");
 scanf("%d",&x);
 	switch(x){
 	case 1:
 		printf("Please Enter The Roll Number");
 		scanf("%d",&ID);
 		FIFO_PUSH_Manually(&Student,ID);
 		break;
 	case 10:
 		return 0;
 	case 9:
 	FIFO_print(&Student);	
 	break;
 case 3:
 		printf("Please Enter The Roll Number");
 		scanf("%d",&ID);
 	Find_From_ID(&Student,ID);
 	break;
 case 4:
 	char *name;
 	printf("Please Enter The Name");
 	scanf("%s",&name);
 	Find_From_F_Name(&Student,name);
 	break;

 case 5:
 	 		printf("Please Enter The CourseID ");
 		scanf("%d",&ID);
 		Find_From_Course_ID(&Student,ID);
break;
case 6:
	printf("-------------------------\n");
	printf("The Total Students Number is %d\n",Total_number(&Student));
	printf("-------------------------\n");

	break;
case 7:
	printf("Please Enter The Roll Number");
 		scanf("%d",&ID);
 		FIFO_POP_ID(&Student,ID);
 		break;
case 8:
	printf("Please Enter The Roll Number");
 		scanf("%d",&ID);
 		Update_From_ID(&Student,ID);
 		break;
 case 2:
 	ADD_from_FILE(&Student);
 	break;
 	}

	}


}