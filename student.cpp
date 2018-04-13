#include<stdio.h>
#include<conio.h>
struct students{
	int id;
	int time;
	int ct = 0;
	int bt;
};
void sort(students s[]);
bool incomp(students s[]);
void completiontime(students s[]);

int main()
{
	students s[3];
	int i;
	for(i=0;i<3;i++)
	{
		printf("Enter the student id: ");
		scanf("%d",&s[i].id);
		printf("Enter the food taken time from mess: \n");
		scanf("%d",&s[i].time);
		s[i].bt = s[i].time;
		printf("\n");
	}
	sort(s);
	int count=0;
    printf("Longest Remaining Time First Algorithm Output\n");
    printf("___________________________\n");
	while(incomp(s)){
        printf("%d|",s[0].id);
        completiontime(s);
        s[0].time--;
        sort(s);
    }
    printf("\n");
    printf("___________________________");
    int tat = 0;
    int wt = 0;
    printf("\n");
	printf("________________________________________________________\n");
	printf("students id\t| Turn around time\t|Waiting time\t|\n");
    printf("________________|_______________________|_______________|\n");

    for(int i=0;i<3;i++){
        printf("%d\t\t|%d\t\t\t|",s[i].id,s[i].ct);
        printf("%d\t\t|\n",s[i].ct - s[i].bt);
		tat += s[i].ct;
        wt += s[i].bt;
    }
        printf("________________|_______________________|_______________|\n");
        printf("\n");
        printf("Average Turn Around Time:%d\n",tat/3);
        printf("Average Waiting Time:%d\n",wt/3);

}

void completiontime(students s[])
{
	int i=0;
	while(i<=3)
	{
		if(s[i].time!=0)
			s[i].ct=s[i].ct+1;
		i++;
	}
}

bool incomp(students s[])
{
	for (int i=0;i<3;i++)
	{
	    if(s[i].time!=0)
		{
	        return true;
	    }
	}
	    return false;
}
	
void sort(students s[])
{
    for(int i=1;i<3;i++)
	{
        for(int j=0;j<3-i;j++)
		{
            if(s[j].time < s[j+1].time)
			{
                students temp = s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
            else if(s[j].time == s[j+1].time){
	                if(s[j].id > s[j+1].id){
	                    students temp = s[j];
	                    s[j]=s[j+1];
	                    s[j+1]=temp;
	                }
	            }
	        }
	    }
    }
