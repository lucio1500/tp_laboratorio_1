
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int id);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_setEmployee(LinkedList* pArrayListEmployee);
int controller_clearListEmployee(LinkedList* pArrayListEmployee,LinkedList* pSubListEmployee);
LinkedList* controller_createSubList(LinkedList* pArrayListEmployee);
int controller_compareList(LinkedList* pArrayListEmployee,LinkedList* pArrayListEmployee2);
int controller_pushEmployee(LinkedList* pArrayListEmployee);
int controller_popEmployee(LinkedList* pArrayListEmployee);
int controller_containsEmployee(LinkedList* pArrayListEmployee,LinkedList* pSubListEmployee);
