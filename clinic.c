/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  :FanghaoMeng
Student ID#:180210213
Email      :fmeng18@myseneca.ca
Section    :IPC144 NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_PETS 7
#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

#include<string.h>
//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////
//int k = 0;
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);

        printf(" (%s)\n", patient->phone.description);
    }
    
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    displayPatientTableHeader();
    int i;
    //char* ptr={0};
    for (i = 0; i < max; i++)
    {
        //ptr = &patient[i];
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
        }
        
    } 
    putchar('\n');
    

}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
    int selection;
    do {
        
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");
        //selection = inputIntRange(0, 2);
        switch (selection)
        {

        case 1:
            searchPatientByPatientNumber(patient, max);
            //suspend();
            break;

        case 2:
            searchPatientByPhoneNumber(patient, max);
            //suspend();
            break;
        }
    } while (selection);

}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {

    //int i;
    //for (i = 0; i < max; i++)
    //{
    //    if (patient[i].patientNumber == 0)
    //    {
    //        patient->patientNumber = nextPatientNumber(patient, max);
    //        inputPatient(patient);
    //        break;
    //    }
    //}
    //if (patient[i].patientNumber != 0)
    //{
    //    printf("ERROR: Patient listing is FULL!\n");
    //    suspend();
    //}
    //printf("*** New patient record added ***\n");
  
    int i = 0;  int a = 0;
    int pause = 0;

    for (i = 0; i < max && pause == 0; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            a = i;
            pause++;
        }
        
    }
    if (pause != 0)
    {
        patient[a].patientNumber = nextPatientNumber(&patient[a-1], max);


        inputPatient(&patient[a]);

        putchar('\n');

        printf("*** New patient record added ***\n");
        printf("\n");
        clearInputBuffer();
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    //patient->patientNumber = k;
    //for (i = 0; i < max; i++)
    //{
    //    if (patient[i].patientNumber == 0)
    //    {  k = nextPatientNumber(patient, max);
    //        patient[i].patientNumber = k;
    //        //patient->patientNumber = nextPatientNumber(patient, max);
    //       
    //        inputPatient(patient);

    //        putchar('\n');
    //     
    //       printf("*** New patient record added ***\n"); 
    //       
    //       putchar('\n');
    //       break;
    //    }
    //    else if(patient[i].patientNumber != 0&& i == (max - 1))
    //    {
    //        printf("ERROR: Patient listing is FULL!");
    //    }




}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
    int edit = 0;
    int i = 0;
    printf("Enter the patient number: ");
    //scanf("%d", &edit);
    //edit =  inputIntRange(0, 99999);
    scanf("%d", &edit);
    printf("\n");
    i = findPatientIndexByPatientNum(edit, patient, max);
    if (i == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[i]);
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int rm_patient = 0, i = 0;
    char selection;
    printf("Enter the patient number: ");
    scanf("%d", &rm_patient);
    i = findPatientIndexByPatientNum(rm_patient, patient, max);
    if (i == -1)
    {
        printf("\nERROR: Patient record not found!\n");
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[i], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &selection);

        if (selection == 'y')
        {  
            
            
            strcpy(patient[i].name, "");
            strcpy(patient[i].phone.description, "");
            strcpy(patient[i].phone.number, "");
           patient[i].patientNumber = 0;
            printf("Patient record has been removed!\n");
        }
        else if (selection == 'n')
        {
            printf("Operation aborted.\n");
        }
        else
        {
            printf("Wrong choice!\n");
        }
    }
    printf("\n");
    clearInputBuffer();
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    printf("Search by patient number: ");
    int patient_number;
    int i = 0;
    int j = 0;
   // scanf("%d", &patient_number);
    //patient_number = inputIntRange(0, 99999);
    //putchar('\n');
    scanf("%d", &patient_number);
    printf("\n");
    for (i = 0; patient[i].patientNumber != '\0'; i++)
    {
        if (patient_number == patient[i].patientNumber)
        {
            printf("Name  : %s\n"
                "Number: %05d\n"
                "Phone : ", patient[i].name, patient[i].patientNumber);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            j = 1;
        }
    }
    if (j == 0)
    {
        printf("*** No records found ***\n");
    }
    printf("\n");
    clearInputBuffer();
    suspend();
    /*int i = findPatientIndexByPatientNum(patient_number, patient, max);

    if (i >= 0)
    {
        displayPatientData(&patient[i], FMT_FORM);
    }
    else {

        printf("*** No records found ***\n");
    }
    suspend();*/
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    printf("Search by phone number: ");
    char str[11]; int i = 0;
    int k = 0;
    //scanf("%[^\n]%*c", str);
    //inputCString(str, 0, PHONE_LEN);
    //putchar('\n');
    scanf("%s", str);
    printf("\n");
   displayPatientTableHeader();

   for (k = 0; patient[k].patientNumber != '\0'; k++)
   {

       if (strcmp(str, patient[k].phone.number) == 0)
       {
           displayPatientData(&patient[k], FMT_TABLE);
           i = 1;
       }
   }
   if (i == 0)
   {
       printf("\n");
       printf("*** No records found ***\n");
   }
        /*if (i == 0)
        {

            displayPatientData(&patient[k], FMT_TABLE);

        }

        else if (k == max && (i != 0))
        {
            printf("*** No records found ***\n");
        }*/
    

    

putchar('\n');
clearInputBuffer();
suspend();
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
    //int i, j = 0;
    //int nextPN;
    //for (i = 0; i < max; i++)
    //{

    //    if (patient[i].patientNumber == 0 && j == 0)
    //    {
    //        j++;

    //        nextPN = patient[i - 1].patientNumber + 1;
    //        return nextPN;
    //    }


    //}
    
    int nextPN;
    nextPN = patient->patientNumber;
    nextPN++;
   /* for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > nextPN)
        {
            nextPN = patient[i].patientNumber;
        }
    }*/
    return nextPN;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max) {

    //char* ptr = { 0 };
    int k;
    int i = 0;
    int c = 0;
    for (k = 0; k < max; k++)
    {
        //ptr = &patient[i];
        if (patientNumber == patient[k].patientNumber)
        {
            i = k;
            c++;
         }  
    } 
        if (c == 1)
        {
           return i; 
       }
        
        /*else if (patientNumber != patient[k].patientNumber)
        {
            break;
        }*/
        else
        {
            return  -1;
            
        }
        
}        
         


    




//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
   
    //char str[NAME_LEN];
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: ");


    printf("%05d\n", patient->patientNumber);

    printf("Name  : ");
    scanf(" %[^\n]", patient->name);
    //inputCString(patient->name, 1, NAME_LEN);
    /*scanf("%[^\n]s", str);
    strcpy(patient[i-1].name, str);*/
    putchar('\n');

    //inputPhoneData(&patient->phone.description);
    
    inputPhoneData(&patient->phone);


}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {
    /* int i, j=0; */
    
    int selection = 0;
    /* char str[11];*/
     //char phoneDS[] = {'CELL', 'HOME', 'WORK', 'TAB'};
     /*for (i = 0; j==0&& i < 7; i++)
     {
         if ( phone[i].description == ' ');
         {
                 j++;
         }

     }*/



    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    //selection = inputIntRange(1, 4);
    scanf("%d", &selection);


    if (selection == 1)
    {
        printf("\n");
        strcpy(phone->description,"CELL");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phone->number);
        //inputCString(phone->number, PHONE_LEN, PHONE_LEN);
    }
    else if (selection == 2)
    {
        printf("\n");
        strcpy(phone->description, "HOME");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phone->number);
        //inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        /*printf("Contact: %s\n", phone[i - 1].description);
        printf("Number : ");
        scanf("%[^\n]%*c", str);
        strcpy(phone[i - 1].number, str);*/
    }
    else if (selection == 3)
    {
        printf("\n");
        strcpy(phone->description, "WORK");
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phone->number);
        //inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        /*printf("Contact: %s\n", phone[i - 1].description);
        printf("Number : ");
        scanf("%[^\n]%*c", str);
        strcpy(phone[i - 1].number, str);*/
    }
    else if (selection == 4)
    {
        
        strcpy(phone->description,"TBD");
        strcpy(phone->number, "");

    }



}




