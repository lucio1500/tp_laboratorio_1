#define TRUE 0
#define FALSE 1
#define ELEMENTS 5

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;


int initEmployees(Employee list[], int len);
int createAnEmployee(Employee list[],int len,float accumSalary,int counterInc,int index,int id);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list[], int len,int id);
int verifyRemoveEmployees(Employee list[], int len, int id);
int removeEmployee(Employee list[], int len, int id);
int verifyModifyEmployees(Employee list[], int len, int id);
int modifyEmployees(Employee list[], int len, int id);
int sortEmployees(Employee list[], int len, int order);
int printEmployees(Employee list[], int length);
void printEmployee (Employee list);
void showEmployees (Employee list[],int len,float average,float accumSalary,int counterSalaryHigh,int counterInc);
float addSalarys(Employee list[],int len);
float salaryAverage(float accumSalary, int counterInc);
int numberOfEmployeesAboveAverage (float average,Employee list[],int len);
int getId(Employee list[],char message[], char messageError []);
int generateId(int index);
int searchIsEmpty(Employee list[], int len);
