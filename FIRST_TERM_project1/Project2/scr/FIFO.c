/*
 * FIFO.c
 *
 *  Created on: May 15, 2023
 *      Author: Ahmed
 */
#include "FIFO.h"
FIFO_status FIFO_init(FIFO_t *FIFO,element_type *buff,usint32_t length)
{
	if(buff==NULL)
		return FIFO_null;
	FIFO->base=buff;
	FIFO->head=buff;
	FIFO->tail=buff;
	FIFO->length=length;
	FIFO->count=0;
	return FIFO_no_error;

	}
Student_status Chek_ID_Status(FIFO_t *FIFO,usint32_t ID){
if(!FIFO->base || !FIFO->head || !FIFO->tail)
		return FIFO_null;
	//check if FIFO is full or not
	element_type *temp=FIFO->tail;
if(FIFO->count==0)
		return FIFO_empty;
	for(int i=0;i<FIFO->count;i++){
		if(ID==temp->ID){
			return ID_exist;
		}else if((temp < ((FIFO->base) + (sizeof(element_type)*FIFO->length)))){
			temp++;
	}else{
		temp=FIFO->base;
	}
}
	return ID_Not_exist;

}
FIFO_status FIFO_PUSH_Manually(FIFO_t *FIFO,usint32_t ID)
{
	//check if fifo has been init befor or not
	if(!FIFO->base || !FIFO->head || !FIFO->tail)
		return FIFO_null;
	//check if FIFO is full or not
	 if((FIFO->head > ((FIFO->base) + (sizeof(element_type)*FIFO->length)))||(FIFO->count==FIFO->length))
		 return FIFO_FULL;
	 if((FIFO->head < ((FIFO->base) + (sizeof(element_type)*FIFO->length)))||(FIFO->count==FIFO->length)){
	 	element_type *temp=FIFO->head;
	 	if(Chek_ID_Status(FIFO,ID)==ID_exist){
	 		printf("%d ID is taken\n\n",ID);
	 	}else{
	  temp->ID=ID;
	  printf("Enter The First Name:");
	  scanf("%s",&temp->F_name);
	  printf("Enter The Last Name:");
	  scanf("%s",&temp->L_name);
	  printf("Enter The GPA");
	  scanf("%f",&temp->GPA);
	  for(int i=0;i<Courses_N;i++){
	  	printf("Enter The ID of the %d Course",i+1);
	  	scanf("%d",&temp->Courses_ID[i]);
	  }
	 FIFO->head++;
	 FIFO->count++;	
	 	}

	 }else{
		 FIFO->head=FIFO->base;
	 }
	 return FIFO_no_error;
	}
FIFO_status FIFO_POP_ID(FIFO_t *FIFO,usint32_t ID)
{
		element_type* temp= FIFO->tail;

	//check if fifo has been init befor or not
	if(!FIFO->base || !FIFO->head || !FIFO->tail)
		return FIFO_null;
	//check if FIFO emty of not
	if(FIFO->count==0)
		return FIFO_empty;
	for(int i=0;i<FIFO->count;i++){
		if(ID==temp->ID){
	if((FIFO->tail < ((FIFO->base) + (sizeof(element_type)*FIFO->length)))){
	FIFO->tail++;
	FIFO->count--;
	}else{
		FIFO->tail=FIFO->base;
	}
		}


	}

	return FIFO_no_error;
	}

void FIFO_print(FIFO_t *FIFO)
{
	int i;
		element_type* temp= FIFO->tail;

	if(FIFO->count==0){
		printf("FIFO is EMPTY\n");
	}else{
	for(i=0;i<FIFO->count;i++){
				printf("---------Studentd %d---------\n",i+1);
				printf("Student %d ID is : %d\n",i+1,temp->ID);
				printf("Student %d First Name is : %s\n",i+1,&(temp->F_name));
				printf("Student %d Last Name is : %s\n",i+1,&(temp->L_name));
				printf("Student %d GPA is : %0.2f\n",i+1,temp->GPA);
				printf("Student %d Reg Courses is : \n",i+1);

				for(int j=0;j<Courses_N;j++){
					printf("Course %d ID is :%d\n",j+1,temp->Courses_ID[j]);
				}
				printf("---------Studentd %d DONE---------\n",i+1);


	temp++;

	
	}


}
}
void Find_From_ID(FIFO_t *FIFO,usint32_t ID){
if(FIFO->count==0)
	printf("FIFO is EMPTY\n");
	//check if FIFO is full or not
	element_type *temp=FIFO->tail;

	for(int i=0;i<FIFO->count;i++){
		if(ID==temp->ID){
		printf("---------Studentd ---------\n");
		printf("Student  ID is : %d\n",temp->ID);
		printf("Student  First Name is : %s\n",&(temp->F_name));
		printf("Student  Last Name is : %s\n",&(temp->L_name));
		printf("Student GPA is : %0.2f\n",temp->GPA);
		printf("Student  Reg Courses is : \n");

				for(int j=0;j<Courses_N;j++){
					printf("Course %d ID is :%d\n",j+1,temp->Courses_ID[j]);
				}
				printf("---------Studentd Finding DONE---------\n",i+1);

		}else if((temp < ((FIFO->base) + (sizeof(element_type)*FIFO->length)))){
			temp++;
					printf("This ID Not Found\n");

	}else{
		printf("This ID Not Found\n");
	}
}	


}
void Find_From_F_Name(FIFO_t *FIFO,char* name){
if(FIFO->count==0)
	printf("FIFO is EMPTY\n");
	//check if FIFO is full or not
	element_type *temp=FIFO->tail;

	for(int i=0;i<FIFO->count;i++){
		if(strcmp(&name,&(temp->F_name))==0){
		printf("---------Studentd ---------\n");
		printf("Student  ID is : %d\n",temp->ID);
		printf("Student  First Name is : %s\n",&(temp->F_name));
		printf("Student  Last Name is : %s\n",&(temp->L_name));
		printf("Student GPA is : %0.2f\n",temp->GPA);
		printf("Student  Reg Courses is : \n");

				for(int j=0;j<Courses_N;j++){
					printf("Course %d ID is :%d\n",j+1,temp->Courses_ID[j]);
				}
				printf("---------Studentd Finding DONE---------\n",i+1);

		}else if((temp < ((FIFO->base) + (sizeof(element_type)*FIFO->length)))){
			temp++;
					printf("This Name Not Found\n");

	}else{
		printf("This Name Not Found\n");
	}
}	


}
void Find_From_Course_ID(FIFO_t *FIFO,usint32_t ID){
if(FIFO->count==0)
	printf("FIFO is EMPTY\n");
	//check if FIFO is full or not
	element_type *temp=FIFO->tail;

	for(int i=0;i<FIFO->count;i++){
		for(int w=0;w<Courses_N;w++){
		if(ID==temp->Courses_ID[w]){
		printf("---------Studentd ---------\n");
		printf("Student  ID is : %d\n",temp->ID);
		printf("Student  First Name is : %s\n",&(temp->F_name));
		printf("Student  Last Name is : %s\n",&(temp->L_name));
		printf("Student GPA is : %0.2f\n",temp->GPA);
		printf("Student  Reg Courses is : \n");

				for(int j=0;j<Courses_N;j++){
					printf("Course %d ID is :%d\n",j+1,temp->Courses_ID[j]);
				}
				printf("---------Studentd Finding DONE---------\n",i+1);

		}
}
	if((temp < ((FIFO->base) + (sizeof(element_type)*FIFO->length)))){
			temp++;

	}else{
		printf("This Course ID Not Found\n");
	}
}	


}
usint32_t Total_number(FIFO_t *FIFO){
return FIFO->count;
}

void Update_From_ID(FIFO_t *FIFO,usint32_t ID){
if(FIFO->count==0)
	printf("FIFO is EMPTY\n");
	//check if FIFO is full or not
	element_type *temp=FIFO->tail;
	usint32_t up_num,c_ID,i;

	for(int i=0;i<FIFO->count;i++){
		if(ID==temp->ID){
		printf("1.GPA\n");
		printf("2.Courses ID\n");
		scanf("%d",&up_num);
		switch(up_num){
		case 1:
			printf("Enter The New GPA");
			scanf("%f",&temp->GPA);
			break;
		case 2:
			printf("Enter Which Course ID do you want to update :");
			scanf("%d",&c_ID);
			for(i=0;i<Courses_N;i++){
				if(c_ID==temp->Courses_ID[i])
					break;
			}
			printf("The new Course ID");
			scanf("%d",&temp->Courses_ID[i]);
		}



		}else if((temp < ((FIFO->base) + (sizeof(element_type)*FIFO->length)))){
			temp++;
					printf("This ID Not Found\n");

	}else{
		printf("This ID Not Found\n");
	}
}	


}



FIFO_status ADD_from_FILE(FIFO_t *FIFO){
	element_type temp_S;

//check if fifo has been init befor or not
	if(!FIFO->base || !FIFO->head || !FIFO->tail)
		return FIFO_null;
	//check if FIFO is full or not
	 if((FIFO->head > ((FIFO->base) + (sizeof(element_type)*FIFO->length)))||(FIFO->count==FIFO->length))
		 return FIFO_FULL;
		FILE *data_From_file;
		data_From_file=fopen("student.txt","r");
		if(data_From_file==NULL){
			printf("File Can't Open");

		}
		while(!feof(data_From_file)){
			fscanf(data_From_file,"%d",&temp_S.ID);
			if(Chek_ID_Status(&FIFO,temp_S.ID)==ID_exist){
				printf("ERROR--------------- ID_exist");
				continue;
			}else{
			fscanf(data_From_file,"%s",&temp_S.F_name);
			fscanf(data_From_file,"%s",&temp_S.L_name);
			fscanf(data_From_file,"%f",&temp_S.GPA);
			for(int i=0;i<Courses_N;i++){
			fscanf(data_From_file,"%d",&temp_S.Courses_ID[i]);

			}
			}
			*(FIFO->head)=temp_S;
			 if((FIFO->head > ((FIFO->base) + (sizeof(element_type)*FIFO->length)))||(FIFO->count==FIFO->length))
		 return FIFO_FULL;
		FIFO->head++;
		FIFO->count++;
		}
    fclose(data_From_file);

}