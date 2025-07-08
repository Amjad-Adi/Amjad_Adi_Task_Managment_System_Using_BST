/*
Name: Amjad Qaher Sadek Adi
Student ID:1230800
Section number:3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAULT_HANDLER 33
#define MAX_TASK_NAME_SIZE 201
#define MAX_TASK_DATE_SIZE 11
#define MAX_TASK_DESCRIPTION_LINE 231
#define MAX_TASK_ID_SIZE 11
#define MAX_TASK_DURATION_SIZE 11
#define ID_STRUCTURE 1
#define NAME_STRUCTURE 2
#define DATE_STRUCTURE 3
#define DURATION_STRUCTURE 4
struct TaskNode{
int taskId;
char taskName[MAX_TASK_NAME_SIZE];
char taskDate[MAX_TASK_DATE_SIZE];
double taskDuration;
int performedStatus;
struct TaskNode* leftTask;
struct TaskNode* rightTask;
};
typedef struct TaskNode TaskNode;
typedef struct TaskNode* PtrToTaskNode;
typedef PtrToTaskNode Tree;
Tree makeEmpty(Tree );
Tree getFileInformation(Tree);
Tree InsertSortedById(int, char[] , char[] , double , Tree );
Tree InsertSortedByName(int, char[], char [], double , Tree );
Tree InsertSortedByDate(int ,char[],char[], int,int,int, double, Tree );
PtrToTaskNode findByIdSorted(int, Tree);
int findByIdUnsorted(int taskId, Tree t);
void FindAndPrintByNameSorted(char[], Tree);
void FindAndPrintByNameUnsorted(char[], Tree);
void performTaskByName(char[], Tree);
void performTaskByDate(char[], Tree);
void performTaskByDuration(double, Tree);
void viewUnperformedTasksInOrder(Tree);
void viewPerformedTasksInOrder(Tree);
Tree deleteById(int, Tree,int ,int*);
Tree deleteByName(char[], Tree,int,int*);
Tree deleteByDate(char[],int,int,int, Tree,int,int*);
Tree deleteByDuration(double, Tree,int,int*);
Tree deleteAndInsertSortedByName(Tree, Tree);
Tree InsertPointerSortedByName(PtrToTaskNode,Tree);
void disposeTree(Tree);
PtrToTaskNode findMin(Tree);
Tree deleteAndInsertSortedById(Tree tOld, Tree tNew);
Tree InsertPointerSortedById(PtrToTaskNode, Tree );
Tree deleteAndInsertSortedByDate(Tree, Tree);
Tree InsertPointerSortedByDate(PtrToTaskNode ,int,int,int, Tree );
Tree deleteAndInsertSortedByDuration(Tree, Tree);
Tree InsertPointerSortedByDuration(PtrToTaskNode , Tree );
Tree InsertSortedByDuration(int taskId, char taskName[], char taskDate[], double taskDuration, Tree t);
int heightOfTree(Tree t);
int i=0;
int numOfLeaves=0;
int sizeOfTree=0;
int main(){
    printf("Welcome to your Task Management System.");
    char selectedOption[FAULT_HANDLER];//used to detect false inputs that can cause Runtime error as entering string not a number
    short numericalRepresentationOfSelectedOption;
    Tree taskTree=NULL;
    int structueMode=0;
    do{
        printf("\n\nKindly, Choose an option from the following menu:\n1. Load Tasks File\n2. Add a New Task\n3. Delete a Task\n4. Search for a Task\n5. Perform a Task \n6. View Unperformed Tasks \n7. View Performed Tasks\n8. Restructure the Tasks BST \n9. View the tasks BST info\n10. Exit\n");
        gets(selectedOption);
        numericalRepresentationOfSelectedOption=atoi(selectedOption);
        switch(numericalRepresentationOfSelectedOption){
        case 1:{
            taskTree=makeEmpty(taskTree);
           taskTree= getFileInformation(taskTree);
            structueMode=ID_STRUCTURE;
            printf("\nList has been loaded with file tasks.");
        break;
        }
        case 2:{
            if(structueMode==ID_STRUCTURE){
        printf("\nEnter task ID: ");
        char stringId[MAX_TASK_ID_SIZE];
        gets(stringId);
        int taskId=atoi(stringId);
        PtrToTaskNode existId=findByIdSorted(taskId,taskTree);//search if the id exist in unperformed, then dont add it because its a key value
    if(!existId){
        printf("\nEnter task name: ");
        char taskName[MAX_TASK_NAME_SIZE];
        gets(taskName);
        printf("\nEnter task date: ");
        char taskDate[MAX_TASK_DATE_SIZE];
        gets(taskDate);
        printf("\nEnter task duration in hours: ");
        char stringDuration[MAX_TASK_DURATION_SIZE];
        gets(stringDuration);
        double taskDuration=atof(stringDuration);
        if(taskId&&taskDuration){//this is needed because if the id entered was string which will cause problems with reaching the same task and logic problems
        taskTree=InsertSortedById(taskId,taskName,taskDate,taskDuration,taskTree);
        printf("\nTask with id %d has been inserted successfully.",taskId);
        }
        else printf("\nError in the enterd data.");
    }
    else printf("\nThe task id %d already exists in the system.",taskId);
            }
    else if(structueMode==NAME_STRUCTURE){
        printf("\nEnter task ID: ");
        char stringId[MAX_TASK_ID_SIZE];
        gets(stringId);
        int taskId=atoi(stringId);
        int existId=findByIdUnsorted(taskId,taskTree);//search if the id exist in unperformed, then dont add it because its a key value
        if(!existId){
        printf("\nEnter task name: ");
        char taskName[MAX_TASK_NAME_SIZE];
        gets(taskName);
        printf("\nEnter task date: ");
        char taskDate[MAX_TASK_DATE_SIZE];
        gets(taskDate);
        printf("\nEnter task duration in hours: ");
        char stringDuration[MAX_TASK_DURATION_SIZE];
        gets(stringDuration);
        double taskDuration=atof(stringDuration);
        if(taskId&&taskDuration){//this is needed because if the id entered was string which will cause problems with reaching the same task and logic problems
        taskTree=InsertSortedByName(taskId,taskName,taskDate,taskDuration,taskTree);
        printf("\nTask with id %d and name %s has been inserted successfully.",taskId,taskName);
        }
        else printf("\nError in the enterd data.");
    }
    else printf("\nThe task id %d already exists in the system.",taskId);
    }
    else if(structueMode==DATE_STRUCTURE){
        printf("\nEnter task ID: ");
        char stringId[MAX_TASK_ID_SIZE];
        gets(stringId);
        int taskId=atoi(stringId);
        int existId=findByIdUnsorted(taskId,taskTree);//search if the id exist in unperformed, then dont add it because its a key value
        if(!existId){
        printf("\nEnter task name: ");
        char taskName[MAX_TASK_NAME_SIZE];
        gets(taskName);
        printf("\nEnter task date: ");
        char taskDate[MAX_TASK_DATE_SIZE];
        gets(taskDate);
        printf("\nEnter task duration in hours: ");
        char stringDuration[MAX_TASK_DURATION_SIZE];
        gets(stringDuration);
        double taskDuration=atof(stringDuration);
        if(taskId&&taskDuration){//this is needed because if the id entered was string which will cause problems with reaching the same task and logic problems
                char dateToInsert[MAX_TASK_DATE_SIZE];
        strcpy(dateToInsert, taskDate);
        int dayToInsert = atoi(strtok(dateToInsert, "/"));
        int monthToInsert = atoi(strtok(NULL, "/"));
        int yearToInsert = atoi(strtok(NULL, "/"));
        taskTree=InsertSortedByDate(taskId,taskName,taskDate,yearToInsert,monthToInsert,dayToInsert,taskDuration,taskTree);
        printf("\nTask with id %d has been inserted successfully.",taskId);
        viewdate(taskTree);
        }
        else printf("\nError in the enterd data.");
    }
    else printf("\nThe task id %d already exists in the system.",taskId);
    }
    else if(structueMode==DURATION_STRUCTURE){
        printf("\nEnter task ID: ");
        char stringId[MAX_TASK_ID_SIZE];
        gets(stringId);
        int taskId=atoi(stringId);
        int existId=findByIdUnsorted(taskId,taskTree);//search if the id exist in unperformed, then dont add it because its a key value
        if(!existId){
        printf("\nEnter task name: ");
        char taskName[MAX_TASK_NAME_SIZE];
        gets(taskName);
        printf("\nEnter task date: ");
        char taskDate[MAX_TASK_DATE_SIZE];
        gets(taskDate);
        printf("\nEnter task duration in hours: ");
        char stringDuration[MAX_TASK_DURATION_SIZE];
        gets(stringDuration);
        double taskDuration=atof(stringDuration);
        if(taskId&&taskDuration){//this is needed because if the id entered was string which will cause problems with reaching the same task and logic problems
        taskTree=InsertSortedByDuration(taskId,taskName,taskDate,taskDuration,taskTree);
        printf("\nTask with id %d has been inserted successfully.",taskId);
        }
        else printf("\nError in the enterd data.");
    }
    else printf("\nThe task id %d already exists in the system.",taskId);
    }
    else printf("\nLoad tasks from file, No tree created.");
        break;
            }
        case 3:{
            i=1;
                    int printInfo=1;
            if(structueMode==ID_STRUCTURE){
        char stringId[MAX_TASK_ID_SIZE];
        printf("\nEnter the ID of the task you want to delete: ");
        gets(stringId);

        taskTree=deleteById(atoi(stringId),taskTree,1,&printInfo);
            }
            else if(structueMode==NAME_STRUCTURE){
        char stringName[MAX_TASK_NAME_SIZE];
        printf("\nEnter the Name of the task you want to delete: ");
        gets(stringName);
        taskTree=deleteByName(stringName,taskTree,1,&printInfo);
               }
        else if(structueMode==DATE_STRUCTURE){
        char stringDate[MAX_TASK_DATE_SIZE];
        printf("\nEnter the Date of the task you want to delete: ");
        gets(stringDate);
        char dateToDelete[MAX_TASK_DATE_SIZE];
        strcpy(dateToDelete, stringDate);
        int dayToDelete = atoi(strtok(dateToDelete, "/"));
        int monthToDelete = atoi(strtok(NULL, "/"));
        int yearToDelete = atoi(strtok(NULL, "/"));
        taskTree=deleteByDate(stringDate,yearToDelete,monthToDelete,dayToDelete,taskTree,1,&printInfo);
        viewdate(taskTree);
               }
               else if(structueMode==DURATION_STRUCTURE){
        char stringDuration[MAX_TASK_DURATION_SIZE];
        printf("\nEnter the Duration of the task you want to delete: ");
        gets(stringDuration);
        taskTree=deleteByDuration(atof(stringDuration),taskTree,1,&printInfo);
               }
                else printf("\nLoad tasks from file, No tree created.");
            break;
        }
        case 4:{
            i=1;
            char taskName[MAX_TASK_NAME_SIZE];
        printf("\nEnter the name of the task you want to search: ");
        gets(taskName);
            if(structueMode==NAME_STRUCTURE){
        FindAndPrintByNameSorted(taskName,taskTree);
        }
                    else {
                FindAndPrintByNameUnsorted(taskName,taskTree);
                if(i==1){
                    printf("\nThere is no task with name: %s.",taskName);
                }
               }
        break;
        }
        case 5:{
            i=1;
            if(structueMode==ID_STRUCTURE){
                char stringId[MAX_TASK_ID_SIZE];
        printf("\nEnter the ID of the task you want to perform: ");
        gets(stringId);
        int wantedId=atoi(stringId);
        PtrToTaskNode p=findByIdSorted(atoi(stringId),taskTree);
        if(p){
                if(!(p->performedStatus)){
              p->performedStatus=1;
            printf("\nThe task with id %d has been performed.",wantedId);
                }
                else printf("\nThe task with id %d has been performed before.",wantedId);
        }
        else printf("\nThe task with id %d has doesn't exist.",wantedId);
            }
            else if(structueMode==NAME_STRUCTURE){
        char stringName[MAX_TASK_ID_SIZE];
        printf("\nEnter the Name of the task you want to perform: ");
        gets(stringName);
        performTaskByName(stringName,taskTree);
        if(i==1)
            printf("\nThe task with name %s has been performed before.",stringName);
               }
              else if(structueMode==DATE_STRUCTURE){
        char stringDate[MAX_TASK_ID_SIZE];
        printf("\nEnter the Date of the task you want to perform: ");
        gets(stringDate);
        performTaskByDate(stringDate,taskTree);
                if(i==1)
            printf("\nThe task with date %s has beeen performed before.",stringDate);
               }
               else if(structueMode==DURATION_STRUCTURE){
        char stringDuration[MAX_TASK_ID_SIZE];
        printf("\nEnter the Duration of the task you want to perform: ");
        gets(stringDuration);
        performTaskByDuration(atof(stringDuration),taskTree);
        if(i==1)
            printf("\nThe task with duration %.5f has been performed before.",atof(stringDuration));
        }
         else printf("\nLoad tasks from file, No tree created.");
        break;
        }
        case 6:{
                                i=1;
                    if(structueMode==NAME_STRUCTURE){
            viewUnperformedTasksInOrder(taskTree);
                    }
                else {
                    int tempNumOfLeaves=numOfLeaves;
                    taskTree=deleteAndInsertSortedByName(taskTree,NULL);
                    viewUnperformedTasksInOrder(taskTree);
                    if(structueMode==ID_STRUCTURE)
                    taskTree=deleteAndInsertSortedById(taskTree,NULL);
                    else if(structueMode==DATE_STRUCTURE)
                  taskTree=deleteAndInsertSortedByDate(taskTree,NULL);
                  else if(structueMode==DURATION_STRUCTURE)
                    taskTree=deleteAndInsertSortedByDuration(taskTree,NULL);
                numOfLeaves=tempNumOfLeaves;
               }
                        if(i==1)
                        printf("\nThere is no unperformed tasks to show.");
               break;
               }
        case 7:{
                            i=1;
            if(structueMode==ID_STRUCTURE)
            viewPerformedTasksInOrder(taskTree);
                else {
                        int tempNumOfLeaves=numOfLeaves;
                    taskTree=deleteAndInsertSortedById(taskTree,NULL);
                    viewPerformedTasksInOrder(taskTree);
                    if(structueMode==NAME_STRUCTURE)
                    taskTree=deleteAndInsertSortedByName(taskTree,NULL);
                    else if(structueMode==DATE_STRUCTURE)
                    taskTree=deleteAndInsertSortedByDate(taskTree,NULL);
                  else if(structueMode==DURATION_STRUCTURE)
                    taskTree=deleteAndInsertSortedByDuration(taskTree,NULL);
                numOfLeaves=tempNumOfLeaves;
               }
                            if(i==1)
                        printf("\nThere is no performed tasks to show.");
               break;
        }
        case 8:{
              short numericalRepresentationOfChoice=0;
              numOfLeaves=0;
                do{
                switch(structueMode){
                case 1:{
                    printf("\nRestructure the Tree based on:\n1. Task Name\n2. Task Date\n3. Task Duration\nEnter your choice: ");
                    char choice[FAULT_HANDLER];
                    gets(choice);
                     numericalRepresentationOfChoice=atoi(choice);
                    switch(numericalRepresentationOfChoice){
                case 1:
                    taskTree=deleteAndInsertSortedByName(taskTree,NULL);
                    printf("\nTree restructured based on name.");
                    structueMode=NAME_STRUCTURE;
                    break;
                case 2:
                      taskTree=deleteAndInsertSortedByDate(taskTree,NULL);
                    printf("\nTree restructured based on date.");
                    structueMode=DATE_STRUCTURE;
                    i=1;
                    viewdate(taskTree);
                    break;
                case 3:
                     taskTree=deleteAndInsertSortedByDuration(taskTree,NULL);
                    printf("\nTree restructured based on duration.");
                    structueMode=DURATION_STRUCTURE;
                    viewduration(taskTree);
                    break;
                default:  printf("\nEnter a correct choice.");
                    }
                    break;
                }
                case 2:{
                    printf("\nRestructure the Tree based on:\n1. Task ID\n2. Task Date\n3. Task Duration\nEnter your choice: ");
                    char choice[FAULT_HANDLER];
                    gets(choice);
                     numericalRepresentationOfChoice=atoi(choice);
                    switch(numericalRepresentationOfChoice){
                case 1:
                    taskTree=deleteAndInsertSortedById(taskTree,NULL);
                    printf("\nTree restructured based on ID.");
                    structueMode=ID_STRUCTURE;
                    break;
                case 2:
                      taskTree=deleteAndInsertSortedByDate(taskTree,NULL);
                    printf("\nTree restructured based on date.");
                    structueMode=DATE_STRUCTURE;
                    viewdate(taskTree);
                    break;
                case 3:
                      taskTree=deleteAndInsertSortedByDuration(taskTree,NULL);
                    printf("\nTree restructured based on duration.");
                    structueMode=DURATION_STRUCTURE;
                    break;
                    default:  printf("\nEnter a correct choice.");
                    }
                    break;
                }
                case 3:{
                    printf("\nRestructure the Tree based on:\n1. Task ID\n2. Task Name\n3. Task Duration\nEnter your choice: ");
                    char choice[FAULT_HANDLER];
                    gets(choice);
                     numericalRepresentationOfChoice=atoi(choice);
                    switch(numericalRepresentationOfChoice){
                case 1:
                    taskTree=deleteAndInsertSortedById(taskTree,NULL);
                    printf("\nTree restructured based on ID.");
                    structueMode=ID_STRUCTURE;
                    break;
                case 2:
                      taskTree=deleteAndInsertSortedByName(taskTree,NULL);
                    printf("\nTree restructured based on name.");
                    structueMode=NAME_STRUCTURE;
                    break;
                case 3:
                     taskTree=deleteAndInsertSortedByDuration(taskTree,NULL);
                    printf("\nTree restructured based on duration.");
                    structueMode=DURATION_STRUCTURE;
                    break;
                    default:  printf("\nEnter a correct choice.");
                    }
                    break;
                }
                case 4:{
                printf("\nRestructure the Tree based on:\n1. Task ID\n2. Task Name\n3. Task Date\nEnter your choice: ");
                    char choice[FAULT_HANDLER];
                    gets(choice);
                     numericalRepresentationOfChoice=atoi(choice);
                    switch(numericalRepresentationOfChoice){
                case 1:
                    taskTree=deleteAndInsertSortedById(taskTree,NULL);
                    printf("\nTree restructured based on ID.");
                    structueMode=ID_STRUCTURE;
                    break;
                case 2:
                      taskTree=deleteAndInsertSortedByName(taskTree,NULL);
                    printf("\nTree restructured based on name.");
                    structueMode=NAME_STRUCTURE;
                    break;
                case 3:
                    taskTree=deleteAndInsertSortedByDate(taskTree,NULL);
                    printf("\nTree restructured based on date.");
                    structueMode=DATE_STRUCTURE;
                    break;
                    default:  printf("\nEnter a correct choice.");
                    }
                    break;
                }
                default: printf("\nLoad tasks from file, No tree created.");
        }
        }while(numericalRepresentationOfChoice!=1&&numericalRepresentationOfChoice!=2&&numericalRepresentationOfChoice!=3&&structueMode!=0);
        break;
        }
        case 9:{
            printf("\n-Height of tree: %d\n-Size of tree: %d\n-Number of tree leaves: %d\n-Number of internal nodes: %d",heightOfTree(taskTree),sizeOfTree,numOfLeaves,sizeOfTree-numOfLeaves);
        break;
        }
        case 10:{
            disposeTree(taskTree);
        printf("\nThanks for using the task managment system, see you again.");
        break;
        }
        default: printf("\nplease enter a correct number.");
        }
    }while(numericalRepresentationOfSelectedOption!=10);
    return 0;
}

Tree makeEmpty(Tree t){
if(t){
t->leftTask= makeEmpty(t->leftTask);
t->rightTask= makeEmpty(t->rightTask);
free(t);
}
return NULL;
}

Tree getFileInformation(Tree t){
    FILE *inputFile=fopen("tasks.txt","r");
    if (inputFile==NULL){//checking if the file we tried to open exists
        printf("\nError while opening the file, the file named tasks.txt may not exist.");
    }
    else{
            char dataFromFile[MAX_TASK_DESCRIPTION_LINE],taskName[MAX_TASK_NAME_SIZE],taskDate[MAX_TASK_DATE_SIZE];;
            int taskId;
            double taskDuration;
            for(int i=0,lineCount=1;fgets(dataFromFile,MAX_TASK_DESCRIPTION_LINE,inputFile)!=NULL;i=0,lineCount++){//read data till EOF is reached
                char* token=strtok(dataFromFile,"#");//cut dataFromFile into substrings based on #
                while(token!=NULL){
                        if(i==0)
                        taskId=atoi(token);
                     else if(i==3)
                        taskDuration=atof(token);
                   else strcpy((i==1)?taskName:taskDate,token);//assign taken to variables based on counter as they are arranged in file
                    token=strtok(NULL,"#");//cut based on # till NULL is reached
                i++;
                }
                if(i==4){
                t=InsertSortedById(taskId,taskName,taskDate,taskDuration,t);
                        }
                else {
                printf("\nInvalid file data format in the line %d.",lineCount);
                break;
            }
            }
            fclose(inputFile);//closing the opened file after reading so the memory allocated with it is removed
}
return t;
}

Tree InsertSortedById(int taskId, char taskName[], char taskDate[], double taskDuration, Tree t){
if(!t){
    t=(Tree)malloc(sizeof( TaskNode));
    if(!t){
            printf("\nNo memory, Free memory and come again.");
        return NULL;
    }
else
    {
        t->taskId=taskId;
        strcpy(t->taskName,taskName);
        strcpy(t->taskDate,taskDate);
        t->taskDuration=taskDuration;
        t->performedStatus=0;
        t->leftTask=t->rightTask=NULL;
        numOfLeaves++;
        sizeOfTree++;
    }
}
else if(taskId<t->taskId){
        if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->leftTask=InsertSortedById( taskId, taskName, taskDate, taskDuration,t->leftTask);
}
else if(taskId >t->taskId){
        if(!(t->leftTask)&&!(t->rightTask))
            numOfLeaves--;
t->rightTask = InsertSortedById( taskId, taskName,taskDate,  taskDuration,t->rightTask);
}
else printf("\nthe id of the task you wish to insert already exists.");
return t;
}


Tree InsertSortedByName(int taskId, char taskName[], char taskDate[], double taskDuration, Tree t){
if(!t){
    t=(Tree)malloc(sizeof( TaskNode));
    if(!t){
            printf("\nNo memory, Free memory and come again.");
        return NULL;
    }
else
    {
        t->taskId=taskId;
        strcpy(t->taskName,taskName);
        strcpy(t->taskDate,taskDate);
        t->taskDuration=taskDuration;
        t->performedStatus=0;
        t->leftTask=t->rightTask=NULL;
         numOfLeaves++;
         sizeOfTree++;
    }
}
else if(strcasecmp(taskName,t->taskName)<0){
                if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->leftTask=InsertSortedByName( taskId, taskName, taskDate, taskDuration, t->leftTask);
}
else if(strcasecmp(taskName,t->taskName)>0){
        if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->rightTask = InsertSortedByName( taskId, taskName,taskDate,  taskDuration,t->rightTask);
}
    else {
    Tree temp=(Tree)malloc(sizeof( TaskNode));
    if(!temp)
       {
            printf("\nNo memory, Free memory and come again.");
        return NULL;
    }
        else{
        if(t->rightTask==NULL&&t->leftTask!=NULL)
        numOfLeaves++;
        temp->taskId=taskId;
        strcpy(temp->taskName,taskName);
        strcpy(temp->taskDate,taskDate);
        temp->taskDuration=taskDuration;
        temp->performedStatus=0;
        temp->leftTask=NULL;
        temp->rightTask=t->rightTask;
        t->rightTask=temp;
        sizeOfTree++;
        }
}
return t;
}

Tree InsertSortedByDate(int taskId, char taskName[],char taskDate[],int yearToInsert,int monthToInsert,int dayToInsert, double taskDuration, Tree t){
    if(!t){
        t=(Tree)malloc(sizeof( TaskNode));
        if(!t){
            printf("\nNo memory, Free memory and come again.");
        return NULL;
    }
    else
        {
            t->taskId=taskId;
            strcpy(t->taskName,taskName);
            strcpy(t->taskDate,taskDate);
            t->taskDuration=taskDuration;
            t->performedStatus=0;
            t->leftTask=t->rightTask=NULL;
            numOfLeaves++;
            sizeOfTree++;
        }
    }
    else{
char tempTaskDate[MAX_TASK_DATE_SIZE];
strcpy(tempTaskDate, t->taskDate);
int taskDay = atoi(strtok(tempTaskDate, "/"));
int taskMonth = atoi(strtok(NULL, "/"));
int taskYear = atoi(strtok(NULL, "/"));
    if((yearToInsert<taskYear)||(yearToInsert==taskYear&&monthToInsert<taskMonth)||(yearToInsert==taskYear&&monthToInsert==taskMonth&&dayToInsert<taskDay)){
            if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
    t->leftTask=InsertSortedByDate( taskId, taskName, taskDate,yearToInsert,monthToInsert,dayToInsert, taskDuration, t->leftTask);
    }
    else if((yearToInsert>taskYear)||(yearToInsert==taskYear&&monthToInsert>taskMonth)||(yearToInsert==taskYear&&monthToInsert==taskMonth&&dayToInsert>taskDay)){
            if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
    t->rightTask = InsertSortedByDate( taskId, taskName,taskDate,yearToInsert,monthToInsert,dayToInsert,  taskDuration,t->rightTask);}
       else {
    Tree temp=(Tree)malloc(sizeof( TaskNode));
    if(!temp){
            printf("\nNo memory, Free memory and come again.");
        return NULL;
    }
        else{
            if(t->rightTask==NULL&&t->leftTask!=NULL)
        numOfLeaves++;
        temp->taskId=taskId;
        strcpy(temp->taskName,taskName);
        strcpy(temp->taskDate,taskDate);
        temp->taskDuration=taskDuration;
        temp->performedStatus=0;
        temp->leftTask=NULL;
        temp->rightTask=t->rightTask;
        t->rightTask=temp;
        sizeOfTree++;
        }
}
    }
    return t;
}

Tree InsertSortedByDuration(int taskId, char taskName[], char taskDate[], double taskDuration, Tree t){
if(!t){
    t=(Tree)malloc(sizeof( TaskNode));
    if(!t){
            printf("\nNo memory, Free memory and come again.");
        return NULL;
    }
else
    {
        t->taskId=taskId;
        strcpy(t->taskName,taskName);
        strcpy(t->taskDate,taskDate);
        t->taskDuration=taskDuration;
        t->performedStatus=0;
        t->leftTask=t->rightTask=NULL;
        numOfLeaves++;
        sizeOfTree++;
    }
}
else if(taskDuration<t->taskDuration){
        if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->leftTask=InsertSortedByDuration( taskId, taskName, taskDate, taskDuration, t->leftTask);}
else if(taskDuration>t->taskDuration){
        if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->rightTask = InsertSortedByDuration( taskId, taskName,taskDate,  taskDuration,t->rightTask);}
    else {
    Tree temp=(Tree)malloc(sizeof( TaskNode));
    if(!temp){
            printf("\nNo memory, Free memory and come again.");
        return NULL;
    }
        else{
                if(t->rightTask==NULL&&t->leftTask!=NULL)
        numOfLeaves++;
        temp->taskId=taskId;
        strcpy(temp->taskName,taskName);
        strcpy(temp->taskDate,taskDate);
        temp->taskDuration=taskDuration;
        temp->performedStatus=0;
        temp->leftTask=NULL;
        temp->rightTask=t->rightTask;
        t->rightTask=temp;
        sizeOfTree++;
        }
}
return t;
}

PtrToTaskNode findByIdSorted( int taskId, Tree t ){
if(!t)
return NULL;
else if(taskId<t->taskId)
return findByIdSorted( taskId,t->leftTask);
else if(taskId>t->taskId)
return findByIdSorted( taskId, t->rightTask );
else return t;
}

int findByIdUnsorted(int taskId, Tree t){
    if(t==NULL)
        return 0;
    if(t->taskId==taskId)
        return 1;
    if(findByIdUnsorted(taskId, t->leftTask))
        return 1;
    if(findByIdUnsorted(taskId, t->rightTask))
        return 1;
    return 0;
}


void FindAndPrintByNameSorted(char taskName[],Tree t){
if(!t){
    printf("\nThere is no task with name: %s",taskName);
    return;
}
else if(strcasecmp(taskName,t->taskName)<0)
 FindAndPrintByNameSorted( taskName,t->leftTask);
else if(strcasecmp(taskName,t->taskName)>0)
 FindAndPrintByNameSorted( taskName,t->rightTask);
else{
    while(t&&strcasecmp(t->taskName,taskName)==0){
    printf("\n\n%d.\n-Task Id: %d\n-Task name: %s\n-Task date: %s\n-Task duration: %.5f",i++, t->taskId, t->taskName, t->taskDate, t->taskDuration);
    t=t->rightTask;
}
}
}

void FindAndPrintByNameUnsorted(char taskName[],Tree t){//O(n)
if(t){
    FindAndPrintByNameUnsorted(taskName,t->leftTask);
    if(strcasecmp(t->taskName,taskName)==0)
    printf("\n\n%d. Task Id: %d\n-Task name: %s\n-Task date: %s\n-Task duration: %.5f",i++, t->taskId, t->taskName, t->taskDate, t->taskDuration);
    FindAndPrintByNameUnsorted(taskName,t->rightTask);
}
}

void performTaskByName(char taskName[],Tree t){
        if(!t){
    printf("There is no task with name: %s",taskName);
    i=0;
    return;
}
else if(strcasecmp(taskName,t->taskName)<0)
 performTaskByName( taskName,t->leftTask);
else if(strcasecmp(taskName,t->taskName)>0)
 performTaskByName( taskName,t->rightTask);
else{
    while(t&&strcasecmp(t->taskName,taskName)==0){
    printf("\n%d. task with ID %d and name %s has been performed",i++, t->taskId, taskName);
    t->performedStatus=1;
    t=t->rightTask;
}
}
}

void performTaskByDate(char taskDate[],Tree t){
        char dateToInsert[MAX_TASK_DATE_SIZE], tempTaskDate[MAX_TASK_DATE_SIZE];
    strcpy(dateToInsert, taskDate);
    strcpy(tempTaskDate, t->taskDate);
    int dayToInsert = atoi(strtok(dateToInsert, "/"));
    int monthToInsert = atoi(strtok(NULL, "/"));
    int yearToInsert = atoi(strtok(NULL, "/"));
    int taskDay = atoi(strtok(tempTaskDate, "/"));
    int taskMonth = atoi(strtok(NULL, "/"));
    int taskYear = atoi(strtok(NULL, "/"));
        if(!t){
    printf("\nThere is no task with this date: %s",taskDate);
    i=0;
    return;
}
else if((yearToInsert<taskYear)||(yearToInsert==taskYear&&monthToInsert<taskMonth)||(yearToInsert==taskYear&&monthToInsert==taskMonth&&dayToInsert<taskDay))
 performTaskByDate( taskDate,t->leftTask);
else if((yearToInsert>taskYear)||(yearToInsert==taskYear&&monthToInsert>taskMonth)||(yearToInsert==taskYear&&monthToInsert==taskMonth&&dayToInsert>taskDay))
 performTaskByDate( taskDate,t->rightTask);
else{
    while(strcasecmp(taskDate,t->taskDate)==0){
    printf("\n%d. task with ID %d and date %s has been performed",i++, t->taskId, taskDate);
    t=t->rightTask;
}
}
}

void performTaskByDuration(double taskDuration,Tree t){
        if(!t){
    printf("\nThere is no task with this duration: %.5f",taskDuration);
    i=0;
    return;
}
else if(taskDuration<t->taskDuration)
 performTaskByDuration( taskDuration,t->leftTask);
else if(taskDuration>t->taskDuration)
 performTaskByDuration( taskDuration,t->rightTask);
else{
    while(t->taskDuration==taskDuration){
    printf("\n\n%d. task with ID %d and name %.5f has been performed",i++, t->taskId, taskDuration);
    t=t->rightTask;
}
}
}

void viewUnperformedTasksInOrder(Tree t){
if(t){
    viewUnperformedTasksInOrder(t->leftTask);
    if(t->performedStatus==0)
    printf("\n\n%d.\n-Task Id: %d\n-Task name: %s\n-Task date: %s\n-Task duration: %.5f",i++, t->taskId, t->taskName, t->taskDate, t->taskDuration);
    viewUnperformedTasksInOrder(t->rightTask);
}
}

void viewPerformedTasksInOrder(Tree t){
if(t){
    viewPerformedTasksInOrder(t->leftTask);
    if(t->performedStatus==1)
    printf("\n\n%d.\n-Task Id: %d\n-Task name: %s\n-Task date: %s\n-Task duration: %.5f",i++, t->taskId, t->taskName, t->taskDate, t->taskDuration);
    viewPerformedTasksInOrder(t->rightTask);
}
}

Tree deleteById(int taskId,Tree t,int printFlag, int *deletedFlag){
if(t==NULL){
    printf("\nThe task you wish to delete with Id %d doesn't exist.",taskId);
    *deletedFlag=0;
}
else if(taskId<t->taskId){
    t->leftTask=deleteById( taskId, t->leftTask ,printFlag,deletedFlag);
        if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag){
    numOfLeaves++;
        }
}
else if(taskId>t->taskId){
    t->rightTask = deleteById( taskId, t->rightTask,printFlag,deletedFlag);
    if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag){
    numOfLeaves++;
}
}
else{
    PtrToTaskNode temp;
    if(t->leftTask&&t->rightTask){
    temp=findMin(t->rightTask);
    t->taskId=temp->taskId;
    strcpy(t->taskName, temp->taskName);
    strcpy(t->taskDate, temp->taskDate);
    t->taskDuration = temp->taskDuration;
    t->performedStatus = temp->performedStatus;
    t->rightTask=deleteById(t->taskId, t->rightTask,!printFlag,deletedFlag);
    }
    else{
        if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
    temp=t;
    if(t->leftTask==NULL)
    t=t->rightTask;
    else if(t->rightTask==NULL)
    t=t->leftTask;
    free(temp);
}
sizeOfTree--;
if(printFlag)
printf("\nTask with ID %d has been deleted successfully.",taskId);
}
return t;
}

Tree deleteByName(char taskName[],Tree t,int printFlag, int *deletedFlag){
if(t==NULL){
    printf("\nThe task you wish to delete with name %s doesn't exist.",taskName);
    *deletedFlag=0;
    }
else if(strcasecmp(taskName,t->taskName)<0){
    t->leftTask=deleteByName( taskName, t->leftTask ,printFlag,deletedFlag);
    if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag)
    numOfLeaves++;
    }
else if(strcasecmp(taskName,t->taskName)>0){
    t->rightTask = deleteByName( taskName, t->rightTask,printFlag,deletedFlag);
        if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag)
    numOfLeaves++;
}
else{
    if(t->rightTask)
    if(strcasecmp(t->rightTask->taskName,taskName)==0&&*deletedFlag!=-1){
        PtrToTaskNode temp1=t->rightTask;
        while(temp1&&strcasecmp(temp1->taskName,taskName)==0){
    PtrToTaskNode temp2=temp1->rightTask;
    free(temp1);
    temp1=temp2;
    sizeOfTree--;
    }
    t->rightTask=temp1;
    if(temp1==NULL)
        numOfLeaves--;
    }
    PtrToTaskNode temp;
    if(t->leftTask&&t->rightTask){
    temp=findMin(t->rightTask);
    *deletedFlag=-1;
    t->taskId=temp->taskId;
    strcpy(t->taskName, temp->taskName);
    strcpy(t->taskDate, temp->taskDate);
    t->taskDuration = temp->taskDuration;
    t->performedStatus = temp->performedStatus;
    t->rightTask=deleteByName(t->taskName, t->rightTask,!printFlag,deletedFlag);
    }
    else{
                if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
    temp=t;
    if(t->leftTask==NULL)
    t=t->rightTask;
    else if(t->rightTask==NULL)
    t=t->leftTask;
    free(temp);
}
sizeOfTree--;
if(printFlag)
printf("\nTask with Name %s has been deleted successfully.",taskName);
}
return t;
}

Tree deleteByDate(char taskDate[],int yearToDelete,int monthToDelete,int dayToDelete,Tree t,int printFlag, int *deletedFlag){
if(t==NULL){
    printf("\nThe task you wish to delete with date %s doesn't exist.",taskDate);
    *deletedFlag=0;
    }
     char tempTaskDate[MAX_TASK_DATE_SIZE];
strcpy(tempTaskDate, t->taskDate);
int taskDay = atoi(strtok(tempTaskDate, "/"));
int taskMonth = atoi(strtok(NULL, "/"));
int taskYear = atoi(strtok(NULL, "/"));
 if((yearToDelete<taskYear)||(yearToDelete==taskYear&&monthToDelete<taskMonth)||(yearToDelete==taskYear&&monthToDelete==taskMonth&&dayToDelete<taskDay)){
    t->leftTask=deleteByDate( taskDate,yearToDelete,monthToDelete,dayToDelete, t->leftTask,printFlag,deletedFlag);
       if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag)
    numOfLeaves++;
}
else if((yearToDelete>taskYear)||(yearToDelete==taskYear&&monthToDelete>taskMonth)||(yearToDelete==taskYear&&monthToDelete==taskMonth&&dayToDelete>taskDay)){
    t->rightTask = deleteByDate(taskDate,yearToDelete ,monthToDelete,dayToDelete, t->rightTask,printFlag,deletedFlag);
   if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag)
    numOfLeaves++;
}
else{
    if(t->rightTask)
    if(strcmp(t->rightTask->taskDate,taskDate)==0&&*deletedFlag==-1){
        PtrToTaskNode temp1=t->rightTask;
        while(temp1&&strcmp(temp1->taskDate,taskDate)==0){
    PtrToTaskNode temp2=temp1->rightTask;
    free(temp1);
    temp1=temp2;
    sizeOfTree--;
    }
    t->rightTask=temp1;
    if(temp1==NULL)
        numOfLeaves--;
    }
    PtrToTaskNode temp;
    if(t->leftTask&&t->rightTask){
    temp=findMin(t->rightTask);
    char temp2TaskDate[MAX_TASK_DATE_SIZE];
strcpy(temp2TaskDate, temp->taskDate);
*deletedFlag=-1;
int wantedTaskDay = atoi(strtok(temp2TaskDate, "/"));
int wantedTaskMonth = atoi(strtok(NULL, "/"));
int wantedTaskYear = atoi(strtok(NULL, "/"));
char targetDate[MAX_TASK_DATE_SIZE];
strcpy(targetDate, temp->taskDate);
t->taskId = temp->taskId;
strcpy(t->taskDate, targetDate);
printf("%s",t->taskName);
t->taskDuration = temp->taskDuration;
t->performedStatus = temp->performedStatus;
t->rightTask = deleteByDate(targetDate, wantedTaskYear, wantedTaskMonth, wantedTaskDay, t->rightTask, !printFlag, deletedFlag);
    }
    else{
        if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
    temp=t;
    if(t->leftTask==NULL)
    t=t->rightTask;
    else if(t->rightTask==NULL)
    t=t->leftTask;
    free(temp);
}
sizeOfTree--;
if(printFlag)
printf("\nTask with date %s has been deleted successfully.",taskDate);
}
return t;
}

Tree deleteByDuration(double taskDuration,Tree t,int printFlag, int *deletedFlag){
if(t==NULL){
    printf("\nThe task you wish to delete with duration %.5f doesn't exist.",taskDuration);
        *deletedFlag=0;
        }
else if(taskDuration<t->taskDuration){
    t->leftTask=deleteByDuration( taskDuration, t->leftTask,printFlag,deletedFlag );
            if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag)
    numOfLeaves++;
    }
else if(taskDuration>t->taskDuration){
    t->rightTask = deleteByDuration( taskDuration, t->rightTask,printFlag,deletedFlag);
            if(t!=NULL&&t->leftTask==NULL&&t->rightTask==NULL&&*deletedFlag)
    numOfLeaves++;
    }
else{
    if(t->rightTask)
    if(t->rightTask->taskDuration==taskDuration&&deletedFlag==-1){
        PtrToTaskNode temp1=t->rightTask;
        while(temp1&&temp1->taskDuration==taskDuration){
    PtrToTaskNode temp2=temp1->rightTask;
    free(temp1);
    temp1=temp2;
    sizeOfTree--;
    }
    t->rightTask=temp1;
    if(temp1==NULL)
        numOfLeaves--;
    }
    PtrToTaskNode temp;
    if(t->leftTask&&t->rightTask){
    temp=findMin(t->rightTask);
    t->taskId=temp->taskId;
    strcpy(t->taskName, temp->taskName);
    *deletedFlag    =-1;
    strcpy(t->taskDate, temp->taskDate);
    t->taskDuration = temp->taskDuration;
    t->performedStatus = temp->performedStatus;
    t->rightTask=deleteByDuration(t->taskDuration, t->rightTask,!printFlag,deletedFlag);
    }
    else{
            if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
    temp=t;
    if(t->leftTask==NULL)
    t=t->rightTask;
    else if(t->rightTask==NULL)
    t=t->leftTask;
    free(temp);
}
sizeOfTree--;
if(printFlag)
printf("\nTask with duration %.5f has been deleted successfully.",taskDuration);
}
return t;
}

void disposeTree(Tree t){
if(t){
    disposeTree(t->leftTask);
    disposeTree(t->rightTask);
    free(t);
}
}

PtrToTaskNode findMin(Tree t){
if(t)
while(t->leftTask)
t=t->leftTask;
return t;
}

Tree deleteAndInsertSortedByName(Tree tOld, Tree tNew){
if(tOld){
tNew= deleteAndInsertSortedByName(tOld->leftTask,tNew);
 tNew= deleteAndInsertSortedByName(tOld->rightTask,tNew);
 tNew=InsertPointerSortedByName(tOld,tNew);
}
return tNew;
}


Tree InsertPointerSortedByName(PtrToTaskNode p, Tree t){
if(!t){
        p->leftTask=NULL;
        p->rightTask=NULL;
        numOfLeaves++;
        return p;
}
else if(strcasecmp(p->taskName,t->taskName)<0){//I used strcasecmp to , since its not a complex function, it can be used from libary
                if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->leftTask=InsertPointerSortedByName(p, t->leftTask);
}
else if(strcasecmp(p->taskName,t->taskName)>0){
        if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->rightTask = InsertPointerSortedByName(p,t->rightTask);
}
    else {
        if(t->rightTask==NULL&&t->leftTask!=NULL)
        numOfLeaves++;
        p->leftTask=NULL;
        p->rightTask=t->rightTask;
        t->rightTask=p;
        }
return t;
}

Tree deleteAndInsertSortedById(Tree tOld, Tree tNew){
if(tOld){
tNew= deleteAndInsertSortedById(tOld->leftTask,tNew);
 tNew= deleteAndInsertSortedById(tOld->rightTask,tNew);
 tNew=InsertPointerSortedById(tOld,tNew);
}
return tNew;
}

Tree InsertPointerSortedById(PtrToTaskNode p, Tree t){
if(!t){
        p->leftTask=NULL;
        p->rightTask=NULL;
        numOfLeaves++;
        return p;
}
else if(p->taskId<t->taskId){
         if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->leftTask=InsertPointerSortedById(p, t->leftTask);
}
else if(p->taskId>t->taskId){
         if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->rightTask = InsertPointerSortedById(p,t->rightTask);
}
    else  printf("\nthe id of the task you wish to insert already exists");
return t;
}

Tree deleteAndInsertSortedByDate(Tree tOld, Tree tNew){
if(tOld){
tNew= deleteAndInsertSortedByDate(tOld->leftTask,tNew);
 tNew= deleteAndInsertSortedByDate(tOld->rightTask,tNew);
 char dateToInsert[MAX_TASK_DATE_SIZE];
 strcpy(dateToInsert, tOld->taskDate);
int dayToInsert = atoi(strtok(dateToInsert, "/"));
int monthToInsert = atoi(strtok(NULL, "/"));
int yearToInsert = atoi(strtok(NULL, "/"));
 tNew=InsertPointerSortedByDate(tOld,yearToInsert,monthToInsert,dayToInsert,tNew);
}
return tNew;
}

Tree InsertPointerSortedByDate(PtrToTaskNode p,int yearToInsert,int monthToInsert,int dayToInsert, Tree t){
if(!t){
        p->leftTask=NULL;
        p->rightTask=NULL;
        numOfLeaves++;
        return p;
}
char tempTaskDate[MAX_TASK_DATE_SIZE];
    strcpy(tempTaskDate, t->taskDate);
    int taskDay = atoi(strtok(tempTaskDate, "/"));
    int taskMonth = atoi(strtok(NULL, "/"));
    int taskYear = atoi(strtok(NULL, "/"));
    if((yearToInsert<taskYear)||(yearToInsert==taskYear&&monthToInsert<taskMonth)||(yearToInsert==taskYear&&monthToInsert==taskMonth&&dayToInsert<taskDay)){
            if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
        t->leftTask=InsertPointerSortedByDate(p,yearToInsert,monthToInsert,dayToInsert, t->leftTask);
}
else if((yearToInsert>taskYear)||(yearToInsert==taskYear&&monthToInsert>taskMonth)||(yearToInsert==taskYear&&monthToInsert==taskMonth&&dayToInsert>taskDay)){
                if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->rightTask = InsertPointerSortedByDate(p,yearToInsert,monthToInsert,dayToInsert, t->rightTask);
}
    else {
        if(t->rightTask==NULL&&t->leftTask!=NULL)
        numOfLeaves++;
        p->leftTask=NULL;
        p->rightTask=t->rightTask;
        t->rightTask=p;
        }
return t;
}

Tree deleteAndInsertSortedByDuration(Tree tOld, Tree tNew){
if(tOld){
tNew= deleteAndInsertSortedByDuration(tOld->leftTask,tNew);
 tNew= deleteAndInsertSortedByDuration(tOld->rightTask,tNew);
 tNew=InsertPointerSortedByDuration(tOld,tNew);
}
return tNew;
}

Tree InsertPointerSortedByDuration(PtrToTaskNode p, Tree t){
if(!t){
        p->leftTask=NULL;
        p->rightTask=NULL;
         numOfLeaves++;
        return p;
}
else if(p->taskDuration<t->taskDuration){
         if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->leftTask=InsertPointerSortedByDuration(p, t->leftTask);
}
else if(p->taskDuration>t->taskDuration){
         if(!(t->leftTask)&&!(t->rightTask))
        numOfLeaves--;
t->rightTask = InsertPointerSortedByDuration(p,t->rightTask);
}
    else {
         if(t->rightTask==NULL&&t->leftTask!=NULL)
        numOfLeaves++;
        p->leftTask=NULL;
        p->rightTask=t->rightTask;
        t->rightTask=p;
        }
return t;
}

int heightOfTree(Tree t) {
    if (!t)
    return -1;
    int left=heightOfTree(t->leftTask);
    int right=heightOfTree(t->rightTask);
    return 1+(left>right?left:right);
}

void viewdate(Tree t){
if(t){
    viewdate(t->leftTask);
    printf("\n\n%d.\n-Task Id: %d\n-Task name: %s\n-Task date: %s\n-Task duration: %.5f",i++, t->taskId, t->taskName, t->taskDate, t->taskDuration);
    viewdate(t->rightTask);
}
}

void viewduration(Tree t){
if(t){
    viewduration(t->leftTask);
    printf("\n\n%d.\n-Task Id: %d\n-Task name: %s\n-Task date: %s\n-Task duration: %.5f",i++, t->taskId, t->taskName, t->taskDate, t->taskDuration);
    viewduration(t->rightTask);
}
}
