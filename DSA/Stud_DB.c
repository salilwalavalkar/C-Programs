/***************************************************************************
       Aim  : Implementation of Student DB using File Operations.
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

FILE *fp;
FILE *ftmp;

struct stud
{
  char name[15],course[5];
  int rollno,age;
  int sub[3];
  float total,perc;
};

void acceptdetails(struct stud *ob)
{
   int i;
   ob->total=0;
   ob->perc=0;
   printf("\nEnter name: ");
   scanf("%s",ob->name);
   printf("Enter rollno: ");
   scanf("%d",&ob->rollno);
   printf("Enter age: ");
   scanf("%d",&ob->age);
   printf("Enter course: ");
   scanf("%s",ob->course);
   printf("Enter subject marks: ");
   for(i=0;i<3;i++)
   {
	   scanf("%d",&ob->sub[i]);
	   ob->total+=ob->sub[i];
   }
   ob->perc=(ob->total/150)*100;
}

fileopen(char mode[5])
{
   fp=fopen("stud.txt",mode);
   if(fp==NULL)
      printf("Error in File");
}

void main()
{
  int i,ch,size,tmprl,cnt;
  struct stud ob;

  size=sizeof(ob);
  while(ch!=6)
  {
    printf("\n1.Create DB\n2.Add Stud\n3.Delete Stud\n4.Search\n5.Display\n6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1: // Create
		fileopen("w");
		fclose(fp);
		break;
     case 2: // Add
		fileopen("a");
		acceptdetails(&ob);
		fwrite(&ob,size,1,fp);
		fclose(fp);
		break;
	 case 3: // Delete
		fileopen("r");
		ftmp=fopen("temp.txt","w");
		cnt=0;
		printf("Enter rollno: ");
		scanf("%d",&tmprl);
		while(fread(&ob,size,1,fp)!=NULL)
		{
		 if(ob.rollno!=tmprl)
			 fwrite(&ob,size,1,ftmp);
		 else
			 cnt=1;
		}
		fclose(fp);
		fclose(ftmp);
		
		if(cnt==1)
		{
			printf("Record %d Deleted\n",tmprl);
			remove("stud.txt");
			rename("temp.txt","stud.txt");
		}
		else
			printf("Record Not Found\n");		

		break;	 
	 case 4: // Search
		fileopen("r");
		cnt=0;
		printf("Enter rollno: ");
		scanf("%d",&tmprl);
		while(fread(&ob,size,1,fp)!=NULL)
		{
		 if(ob.rollno==tmprl)
		 {
		   cnt=1;
	       printf("\nName  Rl Age CS M1 M2 M3\tTotal\t\tPercentage\n");
		   printf("\n%5s %2d %3d %2s",ob.name,ob.rollno,ob.age,ob.course);
		   for(i=0;i<3;i++)
		   {
			   printf(" %2d",ob.sub[i]);
		   }
		   printf("\t%f\t%f\n",ob.total,ob.perc);
		 }
		}
		if(cnt==0)
			printf("Record Not Found\n");
		fclose(fp);
		break;
	 case 5: // Display
		fileopen("r");
		printf("\nName  Rl Age CS M1 M2 M3\tTotal\t\tPercentage\n");
		while(fread(&ob,size,1,fp)!=NULL)
		{
		   printf("\n%5s %2d %3d %2s",ob.name,ob.rollno,ob.age,ob.course);
		   for(i=0;i<3;i++)
		   {
			   printf(" %2d",ob.sub[i]);
		   }
		   printf("\t%f\t%f\n",ob.total,ob.perc);
		}
		fclose(fp);
		break;
	 case 6: // Exit
		break;
	 default:
		printf("Invalid Choice\n");
		break;
	}
  }
}
