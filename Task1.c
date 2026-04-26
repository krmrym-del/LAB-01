#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
int main(){
int id;
int guardianId;
char name[40];
int birthyear;
int solde;
char acctype;
int cont;
id = 100;
cont = id;
int choice = 1;
//المعلومات الصخية
while (choice != 0) {
printf("Please enter your complete information:\n");
int hasError;
do {
hasError = 0;
printf("Full name:\n");
fgets(name, 40, stdin);
name[strcspn(name, "\n")] = 0;
if (strlen(name) == 0) {
printf("Error: Name cannot be empty.\n");
hasError = 1;
continue;
}
for (int i = 0; i < strlen(name); i++) {
if (isdigit(name[i])) {
printf("Error: Name must not contain numbers.\n");
hasError = 1;
break;
}
}
} while (hasError);
do {
printf("Birth year:\n");
scanf("%d", &birthyear);
if (birthyear > 2026 || birthyear < 1900) {
printf("Error: Birth year must be between 1900 and 2026.\n");
}
} while (birthyear > 2026 || birthyear < 1900);
do {
printf("Enter your account type(P/M/C):\n");
scanf(" %c", &acctype);
if (acctype != 'P' && acctype != 'M' && acctype != 'C') {
printf("Error: Account type must be P, M, or C.\n");
}
} while (acctype != 'P' && acctype != 'M' && acctype != 'C');
int age = 2026 - birthyear;
if (acctype == 'P' && age < 18) {
printf("You must be 18!");
}
else if (acctype == 'M') {
printf("Please enter your Guardian's ID:");
scanf("%d", &guardianId);
FILE *f = fopen("clients.txt", "a");
if (f != NULL) {
fprintf(f, "%d %s %d %c %d\n", id, name, birthyear, acctype, guardianId);
fclose(f);
printf("Minor account created successfully for %s! And your ID number is: %d\n", name, id);
id++;
}
}
else {
FILE *f = fopen("clients.txt", "a");
if (f != NULL) {
fprintf(f, "%d %s %d %c\n", id, name, birthyear, acctype);
fclose(f);
printf("Account created successfully for %s! And youID number is: %d\n", name, id);
id++;
}
}
printf("\nEnter 1 to add another client, or 0 to exit: ");
scanf("%d", &choice);
getchar();
}
printf("Program closed. Goodbye!\n");
 return 0;
}
