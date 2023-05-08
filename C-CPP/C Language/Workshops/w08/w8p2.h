/*
*****************************************************************************
                          Workshop - #8 (P2)
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
#define NO_OF_PRODUCTS 3
#define GRAMS_PER_SERVING 64
#define LBS_TO_KGS 2.20462
// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int skuNumber;
    double price;
    int calPerServing;
    double weight;
};

struct ReportData
{
    int skuNumber;
    double price;
    int calPerServe;
    double weightInLbs;
    double weightInKgs;
    int weightInGrams;
    double totalServings;
    double costPerServing;
    double calCostPerServe;
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intNum);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *doubleNum);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(void);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numOfProducts);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
//In this declaration, the value of the variable are unmodifiable for the scope of the pointer but the adress of the pointer is modifiable
void displayCatFoodData(const int sku, double * const price, const int calPerServing, double * const weight);


// 7. Logic entry point
void start(void);

double convertLbsKg(double* const weightLbs,double* weightKgs);

int convertLbsG(double* const weightLbs,int* weightG);

void convertLbs(double* const weightLbs,double* weightKg, int* weightG);

double calculateServings(const int servingSizeGrams, const int totalGrams, double* res);

double calculateCostPerServing(double* const price, double* const totalServings,double* costPerServing);

double calculateCostPerCal(double* const price, int* const calories, double* costPerCalorie);

struct ReportData calculateReportData(const struct CatFoodInfo data);

void displayReportHeader(void);

void displayReportData(const struct ReportData data,const int isCheapest);

void displayFinalAnalysis(struct CatFoodInfo const cheapestData);