// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // defined in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if(matchPtr != NULL) {
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee ID is NOT found in the record\n");
    }

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL) {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); // (matchPtr - EmployeeTable)/bytes  bytes = 32
    } else {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }

    // Search Phone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");
    if (matchPtr != NULL) {
        printf("Employee Phone 909-555-2134 is in the record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Empolyee Phone 909-555-2134 is NOT found in the record\n");
    }
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "626-555-1234");
    if (matchPtr != NULL) {
        printf("Employee Phone 626-555-1234 is in the record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Empolyee Phone 626-555-1234 is NOT found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);
    if (matchPtr != NULL) {
        printf("Employee Salary 7.80 is in the record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee Salary 7.80 is NOT found in the record\n");
    }
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.75);
    if (matchPtr != NULL) {
        printf("Employee Salary 6.75 is in the record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee Salary 6.75 is NOT found in the record\n");
    }

    return EXIT_SUCCESS;
}