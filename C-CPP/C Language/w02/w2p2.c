#include<stdio.h>

int main()
{
	char type1 = '0', type2 = '0', type3 = '0';
	char grind1 = '0', grind2 = '0', grind3 = '0';
	char isCream1 = '0', isCream2 = '0', isCream3 = '0';
	int weight1 = 0, weight2 = 0, weight3 = 0;
	float temp1 = 0, temp2 = 0, temp3 = 0;

	//variables for choices\/
	char coffeeStrength = '0',isCreamChoice='0',makerType='0';
	int servings = 0;

	printf("Take a Break - Coffee Shop\n");
	printf("==========================\n");

	printf("\nEnter the coffee product information being sold today...\n\n");
	printf("COFFEE-1...\n");
	printf("Type ([L]ight,[B]lend): ");
	scanf(" %c", &type1);
	printf("Grind size ([C]ourse,[F]ine): ");
	scanf(" %c", &grind1);
	printf("Bag weight (g): ");
	scanf("%d", &weight1);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &isCream1);
	printf("Ideal serving temperature (Celsius): ");
	scanf(" %f", &temp1);

	printf("\nCOFFEE-2...");
	printf("\nType ([L]ight,[B]lend): ");
	scanf(" %c", &type2);
	printf("Grind size ([C]ourse,[F]ine): ");
	scanf(" %c", &grind2);
	printf("Bag weight (g): ");
	scanf("%d", &weight2);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &isCream2);
	printf("Ideal serving temperature (Celsius): ");
	scanf(" %f", &temp2);

	printf("\nCOFFEE-3...\n");
	printf("Type ([L]ight,[B]lend): ");
	scanf(" %c", &type3);
	printf("Grind size ([C]ourse,[F]ine): ");
	scanf(" %c", &grind3);
	printf("Bag weight (g): ");
	scanf("%d", &weight3);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &isCream3);
	printf("Ideal serving temperature (Celsius): ");
	scanf(" %f", &temp3);


	printf("\n---+---------------+---------------+---------------+-------+--------------\n");
	printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
	printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
	printf("   +---------------+---------------+---------------+ With  +--------------\n");
	printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
	printf("---+---------------+---------------+---------------+-------+--------------\n");
	printf(" %d |   %d   |   %d   |    %d   |   %d  |  %d |  %.3f |   %d   |  %.1f | %.1f\n", 1, type1 == 'l' || type1 == 'L', type1 == 'b' || type1 == 'B', grind1 == 'C' || grind1 == 'c', grind1 == 'F' || grind1 == 'f', weight1, 0.00220462 * (double)weight1, isCream1 == 'y' || isCream1 == 'Y', temp1, ((1.8) * temp1 + 32));
	printf(" %d |   %d   |   %d   |    %d   |   %d  |  %d |  %.3f |   %d   |  %.1f | %.1f\n", 2, type2 == 'l' || type2 == 'L', type2 == 'b' || type2 == 'B', grind2 == 'C' || grind2 == 'c', grind2 == 'F' || grind2 == 'f', weight2, 0.00220462 * (double)weight2, isCream2 == 'y' || isCream2 == 'Y', temp2, ((1.8) * temp2 + 32));
	printf(" %d |   %d   |   %d   |    %d   |   %d  |%5d |  %.3f |   %d   |  %.1f | %.1f\n", 3, type3 == 'l' || type3 == 'L', type3 == 'b' || type3 == 'B', grind3 == 'C' || grind3 == 'c', grind3 == 'F' || grind3 == 'f', weight3, 0.00220462 * (double)weight3, isCream3 == 'y' || isCream3 == 'Y', temp3, ((1.8) * temp3 + 32));

	printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
printf("Coffee strength ([M]ild,[R]ich): ");
	scanf(" %c", &coffeeStrength);
	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf(" %c", &isCreamChoice);
	printf("Typical number of daily servings: ");
	scanf(" %d", &servings);
	printf("Maker ([R]esidential,[C]ommercial): ");
	scanf(" %c", &makerType);
	printf("\nThe below table shows how your preferences align to the available products:\n\n");


	printf("--------------------+--------------------+-------------+-------+--------------\n");
	printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
	printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
	printf("--+-----------------+--------------------+-------------+-------+--------------\n");
	printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", (((coffeeStrength == 'M' || coffeeStrength == 'm') && (type1 == 'l' || type1 == 'l')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (type1 == 'B' || type1 == 'b'))), ((makerType == 'r' || makerType == 'R') && (grind1 == 'c'|| grind1 == 'C')) || ((makerType == 'c' || makerType == 'C') && (grind1 == 'f' || grind1 == 'F')), ( (servings>0 && servings<5 &&weight1>0 &&weight1 <= 250)||(servings>4&&servings<10&& weight1==500)||(servings>10 && weight1==1000)), (((isCreamChoice == 'y' || isCreamChoice == 'Y') && (isCream1 == 'y'|| isCream1 == 'Y')) || ((isCreamChoice == 'N' || isCreamChoice == 'n') && (isCream1 == 'n' || isCream1 == 'N'))), ((makerType == 'r' || makerType == 'R') && (temp1 > 59.9 && temp1 < 70.0)) || ((makerType == 'c' || makerType == 'C') && (temp1 >= 70.0)));
	printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", (((coffeeStrength == 'M' || coffeeStrength == 'm') && (type2 == 'l' || type2 == 'l')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (type2 == 'B' || type2 == 'b'))), ((makerType == 'r' || makerType == 'R') && (grind2 == 'c'|| grind2 == 'C')) || ((makerType == 'c' || makerType == 'C') && (grind2 == 'f' || grind2 == 'F')), ( (servings>0 && servings<5 &&weight2>0 &&weight2 <= 250)||(servings>4&&servings<10&& weight2==500)||(servings>10 && weight2==1000)), (((isCreamChoice == 'y' || isCreamChoice == 'Y') && (isCream2 == 'y'|| isCream2 == 'Y')) || ((isCreamChoice == 'N' || isCreamChoice == 'n') && (isCream2 == 'n' || isCream2 == 'N'))), ((makerType == 'r' || makerType == 'R') || (temp2 > 59.9 && temp2< 70.0)) || ((makerType == 'c' || makerType == 'C') && (temp2 >= 70.0)));
	printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n",(((coffeeStrength=='M'||coffeeStrength=='m')&&(type3=='L'||type3=='l'))||((coffeeStrength=='R'||coffeeStrength=='r')&&(type3=='B'||type3=='b'))),                 ((makerType=='r'||makerType=='R')&& (grind3=='c'||grind3=='C'))||((makerType=='c'||makerType=='C')&&(grind3=='f'||grind3=='F'))               ,( (servings>0 && servings<5 &&weight3>0 &&weight3 <= 250)||(servings>4&&servings<10&& weight3==500)||(servings>10 && weight3==1000)),(((isCreamChoice=='y'||isCreamChoice=='Y')&& (isCream3=='y'||isCream3=='Y'))||((isCreamChoice=='N'||isCreamChoice=='n')&&(isCream3=='n'||isCream3=='N'))),((makerType=='r'||makerType=='R')&&(temp3>59.9&&temp3<70.0))||((makerType=='c'||makerType=='C')&&(temp3>=70.0)));

	printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
	printf("Coffee strength ([M]ild,[R]ich): ");
	scanf(" %c", &coffeeStrength);
	printf("Do you like your coffee with cream ([Y]es,[N]o): ");
	scanf(" %c", &isCreamChoice);
	printf("Typical number of daily servings: ");
	scanf(" %d", &servings);
	printf("Maker ([R]esidential,[C]ommercial): ");
	scanf(" %c", &makerType);
	printf("\nThe below table shows how your preferences align to the available products:\n\n");


	printf("--------------------+--------------------+-------------+-------+--------------\n");
	printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
	printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
	printf("--+-----------------+--------------------+-------------+-------+--------------\n");
	printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", (((coffeeStrength == 'M' || coffeeStrength == 'm') && (type1 == 'l' || type1 == 'l')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (type1 == 'B' || type1 == 'b'))), ((makerType == 'r' || makerType == 'R') && (grind1 == 'c'|| grind1 == 'C')) || ((makerType == 'c' || makerType == 'C') && (grind1 == 'f' || grind1 == 'F')), ( (servings>0 && servings<5 &&weight1>0 &&weight1 <= 250)||(servings>4&&servings<10&& weight1==500)||(servings>10 && weight1==1000)), (((isCreamChoice == 'y' || isCreamChoice == 'Y') && (isCream1 == 'y'|| isCream1 == 'Y')) || ((isCreamChoice == 'N' || isCreamChoice == 'n') && (isCream1 == 'n' || isCream1 == 'N'))), ((makerType == 'r' || makerType == 'R') && (temp1 > 59.9 && temp1 < 70.0)) || ((makerType == 'c' || makerType == 'C') && (temp1 >= 70.0)));
	printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", (((coffeeStrength == 'M' || coffeeStrength == 'm') && (type2 == 'l' || type2 == 'l')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (type2 == 'B' || type2 == 'b'))), ((makerType == 'r' || makerType == 'R') && (grind2 == 'c'|| grind2 == 'C')) || ((makerType == 'c' || makerType == 'C') && (grind2 == 'f' || grind2 == 'F')), ( (servings>0 && servings<5 &&weight2>0 &&weight2 <= 250)||(servings>4&&servings<10&& weight2==500)||(servings>10 && weight2==1000)), (((isCreamChoice == 'y' || isCreamChoice == 'Y') && (isCream2 == 'y'|| isCream2 == 'Y')) || ((isCreamChoice == 'N' || isCreamChoice == 'n') && (isCream2 == 'n' || isCream2 == 'N'))), ((makerType == 'r' || makerType == 'R') && (temp2 > 59.9 && temp2< 70.0)) || ((makerType == 'c' || makerType == 'C') && (temp2 >= 70.0)));
	printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n",(((coffeeStrength=='M'||coffeeStrength=='m')&&(type3=='L'||type3=='l'))||((coffeeStrength=='R'||coffeeStrength=='r')&&(type3=='B'||type3=='b'))),                 ((makerType=='r'||makerType=='R')&& (grind3=='c'||grind3=='C'))||((makerType=='c'||makerType=='C')&&(grind3=='f'||grind3=='F'))               ,( (servings>0 && servings<5 &&weight3>0 &&weight3 <= 250)||(servings>4&&servings<10&& weight3==500)||(servings>=10 && weight3==1000)),(((isCreamChoice=='y'||isCreamChoice=='Y')&& (isCream3=='y'||isCream3=='Y'))||((isCreamChoice=='N'||isCreamChoice=='n')&&(isCream3=='n'||isCream3=='N'))),((makerType=='r'||makerType=='R')&&(temp3>59.9&&temp3<70.0))||((makerType=='c'||makerType=='C')&&(temp3>=70.0)));

	printf("\nHope you found a product that suits your likes!\n");
	return 0;
}