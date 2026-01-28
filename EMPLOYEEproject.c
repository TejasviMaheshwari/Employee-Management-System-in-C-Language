#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct PID
{
    int tid;
}pid;
struct EID
{
    int Emp_No ;
    char name[30];
    char Dept[20];
    char position[15];
    char city[20];
    float salary ;
}eid , eeid;
void addEmployee();
void showEmployee();
int autoid();
void modifyEmployee();
void DeleteEmployee();
void showRecycle();
void recoverRecycle();
void searchEmployee();
void byId();
void byDept();
void byCity();
void main()
{
    char c;
    system("cls");
    printf("******Employee Information System******\n\n");
    printf("1. Add Employee \t2.Show Employee\n");
    printf("3. Modify Employee \t4.Delete Employee\n");
    printf("5. Show Recylce Bin \t6.Recycle Bin Recovery\n");
    printf("7. Search Employee \t8. Exit\n");
    printf("\n\nEnter your choice -- \n\n");
    c = getch();
    if(c == '1'){
        addEmployee();
    }
    else if(c == '2'){
        showEmployee();
    }
    else if(c == '3'){
        modifyEmployee();
    }
    else if(c == '4'){
        DeleteEmployee();
    }
    else if(c == '5'){
        showRecycle();
    }
    else if(c == '6'){
        recoverRecycle();
    }
    else if(c == '7'){
        searchEmployee();
    }
    else
        exit(0);

    printf("\n\nDo you want to continue. press 1 else any key... \n\n");
    c = getch();
    if (c == '1')
        main();
}

void addEmployee()
{
    FILE *fp , *fp1;
    char c;
    printf("\n\nAdd Employee Module \n\n");
    pid.tid = eid.Emp_No = autoid();
    printf("Enter Employee Id --%d\n",eid.Emp_No);
    fflush(stdin);
    printf("\nEnter Employee NAME --\n");
    scanf("%[^\n]s",&eid.name);
    fflush(stdin);
    printf("Enter Employee Department --\n");
    scanf("%[^\n]s",&eid.Dept);
    fflush(stdin);
    printf("Enter Employee Position --\n");
    scanf("%[^\n]s",&eid.position);
    fflush(stdin);
    printf("Enter Employee City --\n");
    scanf("%[^\n]s",&eid.city);
    fflush(stdin);
    printf("Enter Employee Salary --\n");
    scanf("%f",&eid.salary);
    fflush(stdin);
    printf("\n\nDo you want to insert data. Press 1 else any key...\n\n");
    c = getch();
    if(c == '1')
    {
        fp = fopen("EID.bin","a+");
        fp1 = fopen("EID_TEMP.bin","a+");
        fwrite(&eid,sizeof(eid),1,fp);
        fwrite(&eid,sizeof(eid),1,fp1);
        printf("Data inserted successfully...");
        fclose(fp1);
        fclose(fp);
    }
    printf("\n\nDo you want to continue with Add Employee Module or go to Main Menu or Exit Project\n\n");
    printf("1. Add Employee Module \t 2. Main Menu \t 3. Exit");
    c = getch();
    if (c == '1'){
        addEmployee();
    } else if (c == '2'){
        main();
    } else{
        exit(0);
    }
}

void showEmployee()
{
    FILE *fp;
    int reccont=0 ;
    int count=0;
    char c ;
    printf("\n\nShow Employee Module\n\n");
    printf(" %10s %25s %20s %15s %20s %15s \n","Id No.","Employee Name" , "Department","Position","Employee's City" , "Salary");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    fp = fopen("EID.bin","r+");
    while (fread(&eid,sizeof(eid),1,fp))
    {
        printf(" %10d %25s %20s %15s %20s %15.2f\n",eid.Emp_No,eid.name,eid.Dept,eid.position,eid.city,eid.salary);
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        reccont = 1 ;
        count++ ;
        if (count % 8 == 0) {
            printf("\n--- Press any key to see the next 8 records ---\n");
            getch();
            printf(" %10s %25s %20s %15s %20s %15s \n","Id No.","Employee Name" , "Department","Position","Employee's City" , "Salary");
            printf("---------------------------------------------------------------------------------------------------------------------\n");

        }
    }
    if (reccont == 0){
        printf("\n\nNo record found..\n\n");
    }
    fclose(fp);
    printf("\n\nDo you want to continue with Show Employee Module or  go to Main Menu or Exit\n");
    printf("1. Show Employee Module\t 2. Main Menu \t 3. Exit");
    c = getch();
    if (c == '1'){
        showEmployee();
    }
     else if (c == '2'){
        main();
    } else
        exit(0);
}
int autoid()
{
    FILE *fp;
    int m = 1000;
    fp = fopen("EID.bin","r+");
    while(fread(&eid,sizeof(eid),1,fp))
    {
        if (eid.Emp_No > m){
            m = eid.Emp_No;
        }
    }
    fclose(fp);
    return m+1 ;
}


void modifyEmployee()
{
    FILE *fp,*fp1;
    int empid , rfound=0;
    char c ;
    int ustatus=0 , modistat=0;
    printf("\n\nModify Employee Module\n\n");
    printf("Enter Employee ID for modify-- ");
    scanf("%d",&empid);
    fp = fopen("EID.bin","r+");
    fp1 = fopen("EID_TEMP.bin","w");
    while(fread(&eid,sizeof(eid),1,fp))
    {
        eeid=eid;
        if(eeid.Emp_No == empid){
            printf("Employee ID is - %d\n",eid.Emp_No);
            printf("Employee Name is - %s\n",eid.name);
            printf("Employee City is - %s\n",eid.city);
            printf("Employee Department is - %s\n",eid.Dept);
            printf("Employee Position is - %s\n",eid.position);
            printf("Employee Salary is - %.2f\n",eid.salary);
            printf("\n\nChoose Options -- \n\n");
            printf("1.Modify Name \t 2.Modify City\n");
            printf("3.Modify Dept. \t 4.Modify Position \n");
            printf("5.Modify Salary \t 6.Modify All Records\n");
            printf("7.Exit\n");
            c=getch();
            rfound=1;
            if(c == '1')
            {
                fflush(stdin);
                printf("Enter Employee Name --\n");
                scanf("%[^\n]s",&eeid.name);
                ustatus=1;
            }
            else if (c == '2')
            {
                fflush(stdin);
                printf("Enter Employee City --\n");
                scanf("%[^\n]s",&eeid.city);
                ustatus=1;
            }
            else if (c == '3')
            {
                fflush(stdin);
                printf("Enter Employee Dept. --\n");
                scanf("%[^\n]s",&eeid.Dept);
                ustatus=1;
            }
            else if (c == '4')
            {
                fflush(stdin);
                printf("Enter Employee Position --\n");
                scanf("%[^\n]s",&eeid.position);
                ustatus=1;
            }
            else if (c == '5')
            {
                fflush(stdin);
                printf("Enter Employee Salary --\n");
                scanf("%f",&eeid.salary);
                ustatus=1;
            }else if (c =='6')
            {
                fflush(stdin);
                printf("Enter Employee Name --\n");
                scanf("%[^\n]s",&eeid.name);
                fflush(stdin);
                printf("Enter Employee City --\n");
                scanf("%[^\n]s",&eeid.city);
                fflush(stdin);
                printf("Enter Employee Dept. --\n");
                scanf("%[^\n]s",&eeid.Dept);
                fflush(stdin);
                printf("Enter Employee Position --\n");
                scanf("%[^\n]s",&eeid.position);
                fflush(stdin);
                printf("Enter Employee Salary --\n");
                scanf("%f",&eeid.salary);
                ustatus=1;
            }
            if (ustatus == 1)
            {
                printf("\n\nPress 1 for modify record else any key...\n\n");
                c=getch();
                if(c == '1')
                {
                    fwrite(&eeid,sizeof(eeid),1,fp1);
                    ustatus=0;
                    modistat=1;
                    printf("\n\nModify Succesfully\n\n");
                }
                else
                {
                    fwrite(&eid,sizeof(eid),1,fp1);
                    ustatus =0;
                    printf("\n\nOpertation Aborted\n\n");
                }
            }
        }
        else
        {
            fwrite(&eid,sizeof(eid),1,fp1);
        }
    }
    fclose(fp1);
    fclose(fp);
    if (rfound == 0)
    {
        printf("\n\nNo Record found.. Please Enter valid ID\n\n");
    }
    else
    {
        if (modistat==1){
            remove("EID.bin");
            rename("EID_TEMP.bin","EID.bin");
        }
    }
    if (modistat==0)
    {
            remove("EID_TEMP.bin");
    }
    printf("\n\nDo you want to continue with Add Employee Module or go to Main Menu or Exit Project\n\n");
    printf("1. Modify Employee Module \t 2. Main Menu \t 3. Exit\n\n");
    c = getch();
    if (c == '1'){
        modifyEmployee();
    } else if (c == '2'){
        main();
    } else{
        exit(0);
    }
}

void DeleteEmployee()
{
    FILE *fp , *fp1 , *fp2;
    int empid , rfound=0;
    char c;
    int ustatus = 0 , delstat = 0 ;
    printf("\n\n Delete employee Status\n\n");
    printf("Enter Employee ID for delete\n");
    scanf("%d",&empid);
    fp =fopen("EID.bin","r+");
    fp1 =fopen("EID_TEMP.bin","w");
    while(fread(&eid,sizeof(eid),1,fp))
    {
        eeid=eid;
        if(empid==eid.Emp_No){
            printf("Employee ID is - %d\n",eid.Emp_No);
            printf("Employee Name is - %s\n",eid.name);
            printf("Employee City is - %s\n",eid.city);
            printf("Employee Department is - %s\n",eid.Dept);
            printf("Employee Position is - %s\n",eid.position);
            printf("Employee Salary is - %.2f\n",eid.salary);
            printf("\n\nChoose Options -- \n\n");
            printf("1.Delete Temperory \t 2.Delete Permanent\n");
            printf("3.Skip Operation\n");
            rfound=1;
            c=getch();
            if(c=='1')
            {
                printf("Are you sure you want to delete record temperory...\n");
                printf("Press 1 to Delete else any key...\n");
                c=getch();
                if (c=='1')
                {
                    fp2 = fopen("EID_REC.bin","a+");
                    fwrite(&eid,sizeof(eid),1,fp2);
                    delstat=1;
                    fclose(fp2);
                }
                else
                {
                    fwrite(&eid,sizeof(eid),1,fp1);
                    ustatus=0;
                }
            }
            else if (c == '2')
            {
                printf("Are you sure you want to delete record Permanent...\n");
                printf("Press 1 to Delete else any key...\n");
                c=getch();
                if (c !='1')
                {
                    delstat=1;
                    fwrite(&eid,sizeof(eid),1,fp1);
                    break;
                }
            }
            else if (c == '3'){
                delstat=0;
            }
        }
        else
        {
            fwrite(&eid,sizeof(eid),1,fp1);
        }
    }
    fclose(fp1);
    fclose(fp);
    if(rfound==0)
    {
        printf("No Record Found...  Please Enter Valid ID...\n\n");
    }
    else
    {
        if(delstat=1)
        {
            remove("EID.bin");
            rename("EID_TEMP.bin","EID.bin");
            printf("Data Deleted Successfully\n");
        }
        else
        {
            remove("EID_TEMP.bin");
            printf("Delete Operation Aborted...\n\n");
        }
    }
    printf("\n\nDo you want to continue with Delete Employee Module or GoTo Main Menu or Exit Project\n");
    printf("1. Continue with Delete Employee\t2. Main Menu\t 3. Exit");
    c = getch();
    if ( c == '1'){
        DeleteEmployee();
    }
    else if ( c == '2'){
        main();
    }
    else if (c == '3'){
        exit(0);
    }
}

void showRecycle()
{
    FILE *fp;
    int reccont = 0;
    int count=0;
    char c ;
    printf("\n\nShow Reccycle Bin Module\n\n");
    printf(" %10s %25s %20s %15s %20s %15s \n","Id No.","Employee Name" , "Department","Position","Employee's City" , "Salary");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    fp =fopen("EID_REC.bin","r+");
    while (fread(&eid,sizeof(eid),1,fp))
    {
    printf(" %10d %25s %20s %15s %20s %15.2f\n",eid.Emp_No,eid.name,eid.Dept,eid.position,eid.city,eid.salary);
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    reccont = 1 ;
    count++ ;
    if (count % 8 == 0) {
            printf("\n--- Press any key to see the next 8 records ---\n");
            getch();
            printf(" %10s %25s %20s %15s %20s %15s \n","Id No.","Employee Name" , "Department","Position","Employee's City" , "Salary");
            printf("---------------------------------------------------------------------------------------------------------------------\n");
        }
    }
    fclose(fp);
    if (reccont == 0){
        printf("\n\nNo record found..\n\n");
    }
    printf("\n\nDo you want to continue with Show Recycle Bin Module or  go to Main Menu or Exit\n");
    printf("1. Show Recycle Bin Module\t 2. Main Menu \t 3. Exit");
    c = getch();
    if (c == '1'){
        showRecycle();
    }
     else if (c == '2'){
        main();
    } else
        exit(0);
}

void recoverRecycle()
{
    FILE *fp,*fp1,*fp2;
    int reccont = 0;
    char c ;
    int rid ;
    int recall=0 , recone=0;
    printf("\n\nShow Reccycle Bin Module\n\n");
    fp =fopen("EID_REC.bin","r+");
    while (fread(&eid,sizeof(eid),1,fp))
    {
    printf(" %10d %25s %20s %15s %20s %15.2f\n",eid.Emp_No,eid.name,eid.Dept,eid.position,eid.city,eid.salary);
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    reccont = 1 ;
    }
    if (reccont == 0){
        printf("\n\nNo record found..\n\n");
        return 0;
    }
    fclose(fp);
    printf("\n\nOPeration for Recovering Data...\n");
    printf("1.Recover All \t 2.Recover 1 By 1\n");
    printf("3.Skip Operation\n\n");
    c=getch();
    reccont=0;
    fp=fopen("EID.bin","a+");
    fp1=fopen("EID_REC.bin","r+");
    fp2=fopen("EID_REC_TMP.bin","w");
    if(c == '1'){
        printf("\n\nAre you sure you want to Recover all Data.. ");
        printf("Press 1 to continue else any key to abort\n\n");
        c=getch();
        if (c=='1'){
            while(fread(&eid,sizeof(eid),1,fp1))
            {
                fwrite(&eid,sizeof(eid),1,fp);
            }
            recall=1;
        }
    } else if (c == '2'){
        printf("\nEnter Employee ID for Recover --- ");
        scanf("%d",&rid);
        while(fread(&eid,sizeof(eid),1,fp1))
        {
            if(eid.Emp_No==rid)
            {
                reccont=1;
                printf("\nDo you want to Recover Record.. Press 1 else any key to abort\n\n");
                c=getch();
                if(c=='1'){
                    fwrite(&eid,sizeof(eid),1,fp);
                    recone=1;
                    printf("Record Recovered Successfully..\n\n");
                }
                else {
                    recone=0;
                    printf("\n\nOperation Aborted..");
                }
            }
            else{
                fwrite(&eid,sizeof(eid),1,fp2);
            }
        }
        if ( reccont == 0){
            printf("\n\nNo Record Found, Please Enter valid ID\n\n");
        }
    }
    else if (c == '3'){

    }
    if(recall==1){
        fclose(fp1);
        remove("EID_REC.bin");
        printf("All Data Recovered Succesfully\n\n");
    }
    if(recone==0){
        fclose(fp2);
        remove("EID_REC_TMP.bin");
    }
    if(recone==1){
        fclose(fp2);
        fclose(fp1);
        remove("EID_REC.bin");
        rename("EID_REC_TMP.bin","EID_REC.bin");
    }
    fclose(fp2);
    fclose(fp1);
    fclose(fp);
    printf("\n\nDo you want to continue with Recover Recycle Bin Module or GO TO Main Menu or Exit Project...\n");
    printf("1.Recover Recycle \t 2.Main Menu \n");
    printf("3.Exit Project");
    c=getch();
    if(c=='1'){
        recoverRecycle();
    } else if(c=='2'){
        main();
    } else if (c=='3'){
        exit(0);
    }
}

void searchEmployee()
{
    int rfound =0;
    char c;
    printf("\n\nSearch Employee Module\n\n");
    printf("Operation for Searching Employees Records...\n");
    printf("1.By Employee ID \t 2.By Department\n");
    printf("3.By City \t 4.Skip Operation");
    c=getch();
    if(c=='1'){
        byId();
    }else if (c=='2'){
        byDept();
    }else if (c=='3'){
        byCity();
    }else {

    }
}

void byId()
{
    FILE *fp;
    int rfound=0;
    int seid;
    char c;
    printf("Search By Employee ID\n\n");
    printf("Enter Employee ID for Search--");
    scanf("%d",&seid);
    fp=fopen("EID.bin","r+");
    while(fread(&eid,sizeof(eid),1,fp)){
        if(eid.Emp_No==seid){
            printf("\n\nEmployee ID is - %d\n",eid.Emp_No);
            printf("Employee Name is - %s\n",eid.name);
            printf("Employee City is - %s\n",eid.city);
            printf("Employee Department is - %s\n",eid.Dept);
            printf("Employee Position is - %s\n",eid.position);
            printf("Employee Salary is - %.2f\n\n",eid.salary);
            rfound=1;
        }
    }
    fclose(fp);
    if(rfound==0){
        printf("No Record Found..  Please Enter Valid ID..\n\n");
    }
    printf("\n\nDo you want to continue with Search by Employee ID or Go To Search Employee or Go To Main Menu or Exit Project..\n");
    printf("1.Search By Employee ID \t 2.Search Employee\n");
    printf("3.Main Menu \t 4.Exit Project\n\n");
    c=getch();
    if(c=='1'){
        byId();
    }else if (c=='2'){
        searchEmployee();
    }else if (c=='3'){
        main();
    }else if (c=='4'){
        exit(0);
    }
}
void byDept(){
    FILE *fp,*fp1,*fp2;
    int rfound=0;
    int search=0;
    char edept[15];
    char c;
    printf("Search By Employee Department\n\n");
    printf("Enter Employee Department for Search--");
    fflush(stdin);
    scanf("%[^\n]s",&edept);
    fp=fopen("EID.bin","r+");
    while(fread(&eid,sizeof(eid),1,fp)){
        if(strcasecmp(eid.Dept,edept)==0){

            rfound=1;
            fp1=fopen("EID_SEARCH_DEPT.bin","a+");
            fwrite(&eid,sizeof(eid),1,fp1);
            fclose(fp1);
        }
    }
    fclose(fp);
    if(rfound==0){
        printf("No Record Found..  Please Enter Valid Department..\n\n");
        remove("EID_SEARCH_DEPT_TEMP.bin");
    }else {
        fp2 =fopen("EID_SEARCH_DEPT.bin","r+");
                printf("\n\n %10s %25s %20s %15s %20s %15s \n","Id No.","Employee Name" , "Department","Position","Employee's City" , "Salary");
                printf("---------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&eid,sizeof(eid),1,fp2))
            {
                printf(" %10d %25s %20s %15s %20s %15.2f\n",eid.Emp_No,eid.name,eid.Dept,eid.position,eid.city,eid.salary);
                printf("---------------------------------------------------------------------------------------------------------------------\n");
            }
        fclose(fp2);
        remove("EID_SEARCH_DEPT.bin");
        rename("EID_SEARCH_DEPT_TEMP.bin","EID_SEARCH_DEPT.bin");
    }
    printf("\n\nDo you want to continue with Search by Employee Department or Go To Search Employee or Go To Main Menu or Exit Project..\n");
    printf("1.Search By Employee Deptartment \t 2.Search Employee\n");
    printf("3.Main Menu \t 4.Exit Project\n\n");
    c=getch();
    if(c=='1'){
        byDept();
        remove("EID_SEARCH_DEPT.bin");
    }else if (c=='2'){
        searchEmployee();
        remove("EID_SEARCH_DEPT.bin");
    }else if (c=='3'){
        main();
        remove("EID_SEARCH_DEPT.bin");
    }else if (c=='4'){
        exit(0);
        remove("EID_SEARCH_DEPT.bin");
    }
}

void byCity(){
FILE *fp,*fp1,*fp2;
    int rfound=0;
    char ecity[15];
    char c;
    printf("Search By Employee City\n\n");
    printf("Enter Employee City for Search--");
    fflush(stdin);
    scanf("%[^\n]s",&ecity);
    fp=fopen("EID.bin","r+");
    while(fread(&eid,sizeof(eid),1,fp)){
        if(strcasecmp(eid.city,ecity)==0){

            rfound=1;
            fp1=fopen("EID_SEARCH_CITY.bin","a+");
            fwrite(&eid,sizeof(eid),1,fp1);
            fclose(fp1);
        }
    }
    fclose(fp);
    if(rfound==0){
        printf("No Record Found..  Please Enter Valid City..\n\n");
        remove("EID_SEARCH_CITY_TEMP.bin");
    }else {
        fp2 =fopen("EID_SEARCH_City.bin","r+");
                printf("\n\n %10s %25s %20s %15s %20s %15s \n","Id No.","Employee Name" , "Department","Position","Employee's City" , "Salary");
                printf("---------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&eid,sizeof(eid),1,fp2))
            {
                printf(" %10d %25s %20s %15s %20s %15.2f\n",eid.Emp_No,eid.name,eid.Dept,eid.position,eid.city,eid.salary);
                printf("---------------------------------------------------------------------------------------------------------------------\n");
            }
        fclose(fp2);
        remove("EID_SEARCH_CITY.bin");
        rename("EID_SEARCH_CITY_TEMP.bin","EID_SEARCH_CITY.bin");
    }
    printf("\n\nDo you want to continue with Search by Employee City or Go To Search Employee or Go To Main Menu or Exit Project..\n");
    printf("1.Search By Employee City \t 2.Search Employee\n");
    printf("3.Main Menu \t 4.Exit Project\n\n");
    c=getch();
    if(c=='1'){
        byCity();
        remove("EID_SEARCH_CITY.bin");
    }else if (c=='2'){
        searchEmployee();
        remove("EID_SEARCH_CITY.bin");
    }else if (c=='3'){
        main();
        remove("EID_SEARCH_CITY.bin");
    }else if (c=='4'){
        exit(0);
        remove("EID_SEARCH_CITY.bin");
    }
}
