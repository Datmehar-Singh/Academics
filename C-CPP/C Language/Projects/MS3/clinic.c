/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Datmehar Singh
Student ID#: 108011214
Email      : datmehar-singh@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu (hub) for application
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
            menuAppointment(data);
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
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0;

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        //if (patient[i].patientNumber)
            displayPatientData(&patient[i], fmt);
    }
    printf("\n");
    return;
}

void sortByDate(struct Appointment* appoints,int max)
{    
    int i = 0, j = 0;
    struct Appointment sort = appoints[i];
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < max - 1; j++)
        {
            if  (appoints[j].date.year > appoints[j + 1].date.year || (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month > appoints[j + 1].date.month) || (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month == appoints[j + 1].date.month && appoints[j].date.day > appoints[j + 1].date.day) ||
                (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month == appoints[j + 1].date.month && appoints[j].date.day == appoints[j + 1].date.day && appoints[j].time.hour > appoints[j + 1].time.hour) ||
                (appoints[j].date.year == appoints[j + 1].date.year && appoints[j].date.month == appoints[j + 1].date.month && appoints[j].date.day == appoints[j + 1].date.day && appoints[j].time.hour == appoints[j + 1].time.hour && appoints[j].time.min > appoints[j + 1].time.min))
            {
                sort = appoints[j];
                appoints[j] = appoints[j+1];
                appoints[j+1] = sort;
            }
        }
    }
}
int checkDate(struct Date* date,int year, int month, int day)
{
    return (date->day==day && date->month==month && date->year==year)?1:0;

}



// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int ch = -1;
    do
    {
        printf("Search Options\n");
        printf("==========================\n"
               "1) By patient number\n"
               "2) By phone number\n"
               "..........................\n"
               "0) Previous menu\n"
               "..........................\n"
               "Selection: ");
        ch = inputIntRange(0, 2);
        printf("\n");
        switch (ch)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (ch != 0);
    return;
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i = 0, flag = 1;
    for (i = 0; i < max && flag; i++)
    {
        if (patient[i].patientNumber==0)
            flag = 0;
    }
    if (flag)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
        return;
    }
    patient[i - 1].patientNumber = nextPatientNumber(patient, max);
    inputPatient(&patient[i - 1]);
    printf("*** New patient record added ***\n\n");
    return;
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int patNum = -1;
    printf("Enter the patient number: ");
    patNum = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(patNum, patient, max);
    if (index != -1)
        menuPatientEdit(&patient[index]);
    else
        printf("ERROR: Patient record not found!\n");
        
    return;
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    char ch = '0';
    int patNum = -1;
    printf("Enter the patient number: ");
    patNum = inputIntPositive();

    int index = findPatientIndexByPatientNum(patNum, patient, max);

    if (index != -1)
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        ch = inputCharOption("yn");
        if (ch == 'y' || ch == 'Y')
        {
            // struct Patient patTemp = {0};
            // patient[index] = patTemp;
            patient[index].patientNumber = 0;
            strcpy(patient[index].name,"NULL");
            strcpy(patient[index].phone.description,"NULL");
            strcpy(patient[index].phone.number,"NULL");

            printf("Patient record has been removed!\n\n");
          
        }
        else if (ch == 'n' || ch == 'N')
        {
            printf("Operation aborted.\n\n");
        }
    }
    else
        printf("\nERROR: Patient record not found!\n\n");
//getchar();
    return;
}

/*void removePatient(struct Patient patient[], int max)
{
	int patientNumber = 0, i = 0;
	char selection;
	printf("Enter the patient number: ");
	patientNumber = inputIntPositive();
	putchar('\n');
	i = findPatientIndexByPatientNum(patientNumber, patient, max);
	if (i != -1) {
		displayPatientData(&patient[i], FMT_FORM);
		printf("\nAre you sure you want to remove this patient record? (y/n): ");
		selection = inputCharOption("yn");
		if (selection == 'n') {
			printf("Operation aborted.\n\n");
		}
		else if(selection=='y') {
			strcpy(patient[i].name, "");
			strcpy(patient[i].phone.number, "");
			strcpy(patient[i].phone.description, "");
			patient[i].patientNumber = 0;
			printf("Patient record has been removed!\n\n");
		}

	}
	else {
		printf("ERROR: Patient record not found!\n\n");
	}
}*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
int flg=1;
void viewAllAppointments(struct ClinicData* const clinic)
{
    int i=0,j=0,isMax=1;
    displayScheduleTableHeader(&(clinic->appointments->date), 1);
    //if(flg){
    sortByDate((clinic->appointments),clinic->maxAppointments);
    //flg--;
    //}
    for(i=0;i<clinic->maxAppointments && isMax;i++)
    {
        //printf("BYE BYE");
        if (clinic->appointments[i].patientNumber!=0)
         {
            int flag = 1;
            printf("%d-%02d-%02d %02d:%02d %05d ",
                clinic->appointments[i].date.year, clinic->appointments[i].date.month, clinic->appointments[i].date.day,
                clinic->appointments[i].time.hour, clinic->appointments[i].time.min,
                clinic->appointments[i].patientNumber);

            for (j = 0;j < clinic->maxPatient && flag;j++)
            {
                if (clinic->patients[j].patientNumber == clinic->appointments[i].patientNumber)
                {
                    printf("%-15s ", clinic->patients[j].name);
                    //j=clinic->maxPatient;
                    flag = 0;
                }
            }
            j--;
            displayFormattedPhone(clinic->patients[j].phone.number);
            //printf("%s",clinic->patients[i].phone.number);
            printf(" (%s)\n", clinic->patients[j].phone.description);
        }
    }
    printf("\n");
}



// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* const clinic){
    int year=0,month=0,day=0,j=0,idx=0;
    inputDate(&year,&month,&day);
    //day = inputIntPositive();
    //month = inputIntPositive();
    //year = inputIntPositive();
    struct Date date={day,month,year};

    putchar('\n');
    sortByDate(clinic->appointments,clinic->maxAppointments);

    displayScheduleTableHeader(&date, 0);

        for(j=0; j<clinic->maxAppointments; j++ )//koi hai equal ya nahi
        {
            // if(checkDate(&(clinic->appointments[j].date),year,month,day))
            if(clinic->appointments[j].patientNumber &&(clinic->appointments[j].date.day==day && clinic->appointments[j].date.month==month && clinic->appointments[j].date.year==year))
            {
                idx = findPatientIndexByPatientNum(clinic->appointments[j].patientNumber,clinic->patients,clinic->maxPatient);
                if (idx!=-1) 
                {
                    displayScheduleData(&(clinic->patients[idx]), &(clinic->appointments[j]), 0);
                }
            }
        }
        putchar('\n');
        
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoints, int maxAppointments, const struct Patient* patients, int maxPatient)
{
	int flag = 1, i = 0,mainFlag=1,checker=1,j=0;
	int hour = 0, min = 0;
	int patientNumber = 0, patientIndex = 0;
    	int idx=-1;
	struct Date date;

	printf("Patient Number: ");
	patientNumber = inputIntPositive();
	patientIndex = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);
	if (patientIndex == -1)
	{
		printf("\nERROR: Patient record not found!\n\n");
	}
	else
	{
		while (mainFlag )
		{
				inputDate(&(date.year),&(date.month),&(date.day));
			while (flag)
			{
				printf("Hour (0-23)  : ");
				hour = inputIntRange(0, 23);
				printf("Minute (0-59): ");
				min = inputIntRange(0, 59);
				if (hour < 10 || hour >14 ||  (min!=30&&min!=0) ||(hour==14&&min==30))
				{
					printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
				}
				else
				{
					flag =0;
				}
			}
			flag = 1;


			for (i = 0,checker=1; checker && i < maxAppointments;i++)
			{
				if ( checkDate(&(appoints[i].date),date.year,date.month,date.day)==1 &&  appoints[i].time.hour == hour && appoints[i].time.min == min)
					checker =0;
			}
			if (!checker)
				printf("\nERROR: Appointment timeslot is not available!\n\n");
            
			else
			{

                for(j=0;j<maxAppointments;j++)
                    if(appoints[j].patientNumber==0)
                    {
                        idx=j;
                        j=maxAppointments;
                    }

                

				if (idx == -1)
					printf("ERROR: Appointment is not available!\n\n");

				else {
					appoints[idx].date.year = date.year;
					appoints[idx].date.month = date.month;
					appoints[idx].date.day = date.day;
					appoints[idx].patientNumber = patientNumber;
					appoints[idx].time.hour = hour;
					appoints[idx].time.min = min;
					printf("\n*** Appointment scheduled! ***\n");
					mainFlag = 0;
				}
			}
		}
	}
    printf("\n");
}



// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments,
                    int maxAppointments,
                    struct Patient* patients,
                    int maxPatient){
    int patNum=0,i=0,flag=1,year=0,month=0,day=0,flagForDateAndPatNum=1;
    char ch='0';

    printf("Patient Number: ");
    patNum=inputIntPositive();
    for(;i<maxAppointments && flag;i++)
    {
        if(appointments[i].patientNumber==patNum)
            flag=0;
    }
    if(flag)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else{

        inputDate(&year,&month,&day);
        printf("\n");
        for(i=0;i<maxAppointments && flagForDateAndPatNum;i++)
        {
            if(checkDate(&(appointments[i].date),year,month,day)==1 && appointments[i].patientNumber==patNum)
            {
                flagForDateAndPatNum=0;
            }
        }
        if(!flagForDateAndPatNum)
        {
            for(i=0;i<maxPatient;i++)
            {
                if(patients[i].patientNumber==patNum)
                {
                    displayPatientData(&patients[i],FMT_FORM);
                    printf("Are you sure you want to remove this appointment (y,n): ");
                    ch=inputCharOption("yn");
                    i=maxPatient;
                }
            }
            for(i=0;i<maxAppointments;i++)
            {
                if(appointments[i].patientNumber==patNum &&checkDate(&(appointments[i].date),year,month,day)==1 &&ch=='y' )
                {
                    appointments[i].date.day=0;
                    appointments[i].date.year=0;
                    appointments[i].date.month=0;
                    appointments[i].patientNumber=0;
                    appointments[i].time.hour=0;
                    appointments[i].time.min=0;
                    printf("\nAppointment record has been removed!\n\n");
                    flagForDateAndPatNum=0;
                }
            }
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////




// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int i = 0, patientNum = -1, checker = -2;

    printf("Search by patient number: ");
    patientNum = inputIntPositive();
    printf("\n");
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNum)
        {
            displayPatientData(&patient[i], FMT_FORM);
        }
    }
    checker = findPatientIndexByPatientNum(patientNum, patient, max);
    if (checker == -1)
        printf("*** No records found ***\n");

    printf("\n");
    return;
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i = 0, flag = 0;
    char phNum[PHONE_LEN + 1];

    printf("Search by phone number: ");
    inputCString(phNum, 10, 10);

    printf("\n");

    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, phNum) == 0)
        {

            displayPatientData(&patient[i], FMT_TABLE);
            flag++;
        }
    }
    printf("\n");
    clearInputBuffer();

    if (!flag)
        printf("*** No records found ***\n\n");
    return;
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i = 0;
    int maxPatNum = -1;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > max)
            maxPatNum = patient[i].patientNumber;
    }
    return maxPatNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i = 0, flag = 1;
    for (i = 0; i < max && flag; i++)
    {
        if (patient[i].patientNumber == patientNumber)
            flag = 0;
    }
    return flag ? -1 : i - 1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient *patient)
{

    printf("Patient Data Input\n"
           "------------------\n"
           "Number: %05d\n"
           "Name  : ",
           patient->patientNumber);
    inputCString(&(*patient->name), 0, NAME_LEN);
    printf("\n");
    inputPhoneData(&(patient->phone));

    return;
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone *phone)
{
    int ch = -1;
    printf("Phone Information\n"
           "-----------------\n"
           "How will the patient like to be contacted?\n"
           "1. Cell\n"
           "2. Home\n"
           "3. Work\n"
           "4. TBD\n"
           "Selection: ");
    ch = inputIntRange(1, 4);
    switch (ch)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }
    if (strcmp(phone->description, "TBD") != 0)
    {
        printf("\nContact: %s\n"
               "Number : ",
               phone->description);
        inputPhoneNumber((phone->number));
        clearInputBuffer();
        printf("\n");
    }
    return;
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

/*double power(int X, int Y) {

	double power = 1, i=0;

	for (i = 1; i <= Y; ++i)
	 {
		power = power * X;
	}

	return power;

}*/

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int counter=-1;
    int fieldCounter=0;
    int i=0,j=0;
    FILE* file;
    char patientRecord[200];
    file = fopen(datafile,"r");
    while (fgets(patientRecord, 200, file) && ++counter!=max)
    {
        fieldCounter=0;
        char patientNumber[10];
        int patientNumberInt=0;
        
        for(i=0,j=0;i<strlen(patientRecord)&&patientRecord[i]!='\n';i++,j++)
        {
            if(patientRecord[i]=='|')
            {
                fieldCounter++;
                j=-1;
            }
            else
            switch(fieldCounter)
            {
                case 0:
                patientNumber[j]=patientRecord[i];
                patientNumber[j+1]='\0';

                case 1:
                patients[counter].name[j]=patientRecord[i];

                case 2:
                patients[counter].phone.description[j]=patientRecord[i];
                (patients[counter].phone.description[j+1])='\0';

                case 3:
                patients[counter].phone.number[j]=patientRecord[i];
                patients[counter].phone.number[j+1]='\0';


            }
        }
        for(i=0;i<strlen(patientNumber);i++)
        {
            patientNumberInt+= ((int)(patientNumber[i]-48)) * power(10,strlen(patientNumber)-1-i);
            //printf("\\%d %lf\\",(int)(patientNumber[i]-48), pow(10,strlen(patientNumber)-1-i));
        }
        patients[counter].patientNumber=patientNumberInt;
    }
    return counter;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int counter=-1;
    int fieldCounter=0;
    char appointmentRecord[200],patientNumber[10],year[8],month[4],date[4],hour[4],minutes[4];
    int i=0,j=0;
    FILE* file;
    file = fopen(datafile,"r");
    while (fgets(appointmentRecord,200,file) && ++counter!=max)
    {
        fieldCounter = 0;
        for(i=0,j=0;i<strlen(appointmentRecord);i++,j++)
        {
            if(appointmentRecord[i]==','|| appointmentRecord[i] == '\n')
            {
                fieldCounter++;
                j=-1;

            }
            else
            {
                switch (fieldCounter)
                {
                case 0:
                    patientNumber[j] = appointmentRecord[i];
                    patientNumber[j + 1] = '\0';
                    break;
                case 1:
                    year[j] = appointmentRecord[i];
                    year[j + 1] = '\0';
                    break;

                case 2:
                    month[j] = appointmentRecord[i];
                    month[j + 1] = '\0';
                    break;
                case 3:
                    date[j] = appointmentRecord[i];
                    date[j + 1] = '\0';
                    break;
                case 4:
                    hour[j] = appointmentRecord[i];
                    hour[j + 1] = '\0';
                    break;
                case 5:
                    minutes[j] = appointmentRecord[i];
                    minutes[j + 1] = '\0';break;


                default:
                    i = strlen(appointmentRecord);
                    break;
                }
            }
        }
        appoints[counter].patientNumber=stringToInteger(patientNumber);
        appoints[counter].date.year=stringToInteger(year);
        appoints[counter].date.month=stringToInteger(month);
        appoints[counter].date.day=stringToInteger(date);
        appoints[counter].time.hour=stringToInteger(hour);
        appoints[counter].time.min=stringToInteger(minutes);
    }
    return counter+1;
}