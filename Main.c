#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main1()
{
    printf("I like pipi\n");
    printf("It's really good");
    return 0;  //optional but good practice
}

// to run code in system prompt
/*
cd <directory>
gcc HelloWorld.c (generates a.exe)
a.exe
*/

/*
escape sequence
\n newline
\t tab
\" \' \\
*/

//variables
int main2()
{
    int x; //declaration
    x = 10; //initialization
    int y = 123; //declaration + initialization

    int age = 21; //integer %d
    float gpa = 2.05; //floating point number %f
    char grade = 'C'; //single character %c  single or double quote
    char name[] = "Bro"; //array of characters %s  must be double quotes

    printf("Hello %s\n", name);
    printf("You are %d years old\n", age);
    printf("Your average grade is %c\n", grade);
    printf("Your gpa is %f\n", gpa);
}

//more about variables
int main3()
{

    char a = 'C';                   // %c single character    
    char b[] = "Bro";               // %s array of characters 

    float c = 3.141592;             // %f 4 bytes (32 bits precision) 6-7 digits.:  even if longer it will display only the supported number of digits, and if force specify format `%0.15f` it will lose precision
    double d = 3.1415926536589793;  // %lf 8 bytes (64 bits precision) 15-16 digits

    bool e = true;                  // %d 1 byte (true of false).: must include <stdbool.h>

    char f = 100;                   // %d %c 1 byte (-128 to +127)
    unsigned char g = 255;          // %d %c 1 byte (0 to +255)

    short int h = 32767;            // %d 2 bytes (-32,768 to +32,767).: can dismiss keyword `int`
    unsigned short int i = 65535;   // %d 2 bytes (0 to +65,535).: can dismiss keyword `int`

    int j = 2147483648;             // %d 4 bytes (-2,147,483,648 to +2,147,483,647).: can dismis keyword `long`
    unsigned int k = 4294967295;    // %u 4 bytes (0 to +4,294,967,295)

    long long int l = 9223372036854775807;           // %lld 8 bytes (-9 quitillion to +9 quintillion)
    unsigned long long int m = 18446744073709551615U; // %llu 8 bytes (0 to +18 quintillion).: adding `U` at the end will display the number without warnings
}


//format specifier
int main4()
{
    /*
    %c character
    %f float
    %lf double
    %d integer

    %.1 decimal precision
    %1 minimum field width/padding, auto right aligned
    %- left align
    */

    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 100.99;

    printf("Item 1: $%8.2f\n", item1);
    printf("Item 2: $%8.2f\n", item2);
    printf("Item 3: $%8.2f\n", item3);
}


//constant = fixed value that cannot be altered by the program during its execution
int main5()
{

    const float PI = 3.14159;  //const naming convention Uppercase. good practive, not mandatory
    // PI = 210; ERROR
}


//arithmetic operators
int main6()
{
    /*
    + addition
    - subtraction
    * multiplication
    / division
    % modulus (remainder)
    ++ increment
    -- decrement
    */

    int x = 5;
    int y = 2;

    float z = x / (float) y;  //division between integers will only outputs integer, must convert it in real time `(float)` or change its datatype in declaration

    x++; //incremented by 1

    printf("%f", z);
}


//augmented assingment operators
int main7()
{
    int x = 10;
    x = x + 2;
    x+=2;
    x-=2;
    x*=2;
    x/=2;
    x%=2;
}


//user input
int main8()
{

    char name[25]; //max 25 bytes
    int age;

    printf("\nWhat's your name?");
    scanf("%s", &name);  //doesn't support whitespaces
    fgets(name, 25, stdin);  //suport whitespaces.: auto includes newline character at end

    printf("\nHow old are you?");
    scanf("%d", &age);

    printf("%s have %d years old", name, age);
}


//math functions
#include <math.h>
int main9()
{

    double A = sqrt(9); //3
    double B = pow(2, 4); //16
    int C = round(3.14); //3
    int D = ceil(3.14); //4
    int E = floor(3.99); //3
    double F = fabs(-100); //100
    double G = log(3); //1.098612
    double H = sin(45); //seno
    double I = cos(45); //cosseno
    double J = tan(45); //tangente
}


//exercise circle
int main10()
{

    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nEnter radius of a circle in meters:");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * pow(radius, 2);

    printf("Circumference is %lf m\n", circumference);
    printf("Area is %lf m2\n", area);
}


//exercise pitagoras
#include <math.h>
int main11()
{

    double A;
    double B;
    double C;

    printf("Enter side A: ");
    scanf("%lf", &A);

    printf("Enter side B: ");
    scanf("%lf", &B);

    C = sqrt(pow(A,2) + pow(B,2));

    printf("The hipotenusa is %lf", C);
}

//if statements
int main12()
{

    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 18){
        printf("You're an adult");
    }
    else if(age >= 16){
        printf("At your age you can do certain things");
    }
    else if(age < 0){
        printf("You haven't been born yet!");
    }
    else{
        printf("You're underage");
    }
}

//switch statements
int main13()
{
    char grade;

    printf("Enter a letter grade: ");
    scanf("%c", &grade);

    grade = toupper(grade);

    switch(grade){
        case 'A':
            printf("perfect!");
            break; //if break is not used it will match all cases
        case 'B':
            printf("You did good");
            break;
        case 'C':
            printf("Almost there");
            break;
        default:
            printf("Please enter only valid grades");
    }
}


//exercise temperature conversion
// #include <ctype.h>
int main14()
{
    char unit;
    float temp;

    printf("Is the temperature in F or C?\n");
    scanf("%c", &unit);

    unit = toupper(unit);

    if (unit == 'C'){
        printf("Enter the temp in Celsius:");
        scanf("%f",& temp);
        // unit_long = 'Celsius';
        temp = (temp * 9/5) + 32;
        printf("The temperature in Farenheit is %1.f", temp);
    }
    else if(unit == 'F'){
        printf("Enter the temp in Farenheit:");
        scanf("%f",& temp);
        // unit_long = 'Farenheit';
        temp = (temp - 32) * 5/9;
        printf("The temperature in Celsius is %1.f", temp);
    }
    else{
        printf("%c is not a valid unit of measurement", unit);
        return 1;
    }
}


//exercise calculator
int main15()
{
    char operator;
    double num1, num2, result;

    printf("Enter an math operator (+ - * /)");
    scanf("%c", &operator);

    printf("Enter number 1:");
    scanf("%lf", &num1);

    printf("Enter number 2:");
    scanf("%lf", &num2);

    switch(operator){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("%c is not a valid operator", operator);
    }

    printf("result: %.2lf", result);
}


//logical operators && || !
int main16()
{

    float temp = 25;
    bool sunny = true;
    bool windy = false;

    if(temp >= 0 && temp <= 30 && sunny && !windy) {
        printf("The weather is good");
    }
    else if(temp <= 0 || temp >= 30) {
        printf("The weather is bad");
    }
    else{
        printf("Inconclusive");
    }
}


//functions and arguments
void birthday(char name[], int age)  //void is a non-return type function
{
    printf("Happy birthday dear %s!\n", name);
    printf("You are %d years old", age);
}

int main17()
{
    char name[12];
    int age;

    printf("Enter your name:");
    scanf("%s", &name);

    printf("Enter your age:");
    scanf("%d", &age);
    
    birthday(name, age);
}


//ternary operator
int findMax(int x, int y)
{
    // if(x > y) {
    //     return x;
    // }
    // else {
    //     return y;
    // }
    return (x > y) ? x : y; //<<< (condition) ? value if true : value if false
}


//function prototype
/*
-function declaration w/o a body before main()
-ensures that calls to a functino are made with the correct arguments
-missing arguments will result in unexpected behavior
-a function prototype causes the compiler to flag an error if arguments are missing
-easir to navigate a program with main() at the top
-helps with debugging
-commonly used in header files
*/
void hello(char[], int); //function prototype

int main18()
{
    hello("Bro", 12);
}

void hello(char name[], int age)
{
    printf("Hello %s, you are %d years old", name, age);
}


//string functions
//#include <string.h>
int main19()
{
    char str1[] = "Bro";
    char str2[] = "Code";

    //In-place operations
    // strlwr(str1);           // bro     converts a string to lowercase
    // strupr(str1);           // BRO     converts a string to uppercase
    // strcat(str1, str2);     // BroCode appends str2 to end of str1
    // strncat(str1, str2, 2); // BroCo   appends n characters from str2 to str1
    // strcpy(str1, str2);     // Code    copy str2 to str1
    // strncpy(str1, str2, 2); // Coo     copy n characters of str2 to str1
    // strset(str1, '?');      // ???     sets all characters of a string to a given character
    // strnset(str1, 'x', 1);  // xro     sets first n characters of a string to a given character
    // strrev(str1);           // orB     reverses a string

    // int result = strlen(str1);            //  3 returns string length as int
    // int result = strcmp(str1, str2);      // -1 compare all characters, true=0 false=-1
    // int result = strncmp(str1, str2, 1);  // -1 compare n characters, true=0 false=-1
    // int result = strcmpi(str1, str2);     // -1 compare all & ignore case, true=0 false=-1
    // int result = strnicmp(str1, str2, 1); // -1 compare n chars & ignore case, true=0 false=-1

    // printf("%d", result);
}

//for loop
int main20()
{
    for(int i = 2; i <= 10; i*=2)
    {
        printf("%i\n", i);
        if(i==5){break;}
    }
}

//while loop -> checks a condition, THEN executes a block of code if condition is true
int main21()
{
    int x = 1;
    while (x < 10) {
        printf("%d\n", x);
        x++;
        if(x==5){break;}
    }
}

//do while loop -> always executes a block of code once, THEN checks a condition
int main22()
{
    do {
        printf("It executes at least once");
    }
    while(false);
}

//nested loops
int main23()
{
    int cols = 4;
    int rows = 3;
    char symbol = '*';

    for(int i=  0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}

//self exercise pyramid
int main24()
{
    const int limit = 30; //limit display size in case of bad input
    int size;
    printf("Enter size of pyramid: ");
    scanf("%d", &size);

    if(size<=0 || size>limit)
    {
        printf("Bad input: <%d>, falling back to height limit\n", size);
        size = limit;
    }

    int cols = !(size%2) ? size-1 : size; //avoid even numbers
    int rows = cols/2 + 1; //adapt pyramid base to its height
    int left = rows;
    int right = rows;

    char full = '*';
    char empt = ' ';

    // printf("%d %d\n", cols, rows);
    // printf("%d %d\n", left, right);

    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=cols; j++)
        {
            if(j<left || j>right)
            {
                printf("%c", empt);
            }
            else
            {
                printf("%c", full);
            }
        }
        left--;
        right++;
        printf("\n");
    }
}

//break vs continue
int main25()
{
    for(int i=0; i<=10; i++){
        if(i==5){continue;}
        if(i==8){break;}
        printf("%d\n", i);
    }
}

//arrays (lists) -> a data structure that can store many values of the same data type.: strings are also array of chars
int main26()
{
    double pricespre[] = {5.0, 2, 15.0, 20.0}; //pre assign declaration
    double prices[5]; //post assign declaration
    prices[0] = 5.0; //element post assign
    prices[0] = 10.0; //can reassign element
    prices[2] = 3; //will be automatically converted to float
    prices[10] = 2.0; //assigning outside array range has no effect

    int size = sizeof(prices)/sizeof(prices[0]); //sizeof is in bytes, so need to divide it by one element size

    for(int i=0; i<size; i++){
        printf("%f\n", prices[i]);
    }
}

//2D arrays -> an array where each element is an entire array
//https://iq.opengenus.org/3d-array-in-c/
int main27()
{
    //pre assign declaration
    int numberspre[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    //post assign declaration
    int numbers[2][3]; //warning, it will store garbage values
    int numbers1[2][3] = {}; //will store zeroes
    int numbers2[2][3] = {1,2,3,4,5,6}; //will distribute values to its blocks 2x3

    numbers[0][0] = 1;
    numbers[0][1] = 'a'; //will be automatically converted to int (utf-8 # in decimal)
    numbers[0][2] = 3;
    numbers[1][0] = 4;
    numbers[1][1] = 5;
    numbers[1][2] = 6;
    numbers[1][3] = 7; //no effect since "cols" size is only 3
    numbers[2][0] = 8; //no effect since "rows" size is only 2

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int cols = sizeof(numbers[0])/sizeof(numbers[0][0]);

    printf("rows: %d\n", rows);
    printf("col: %d\n", cols);

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
}

//array of strings
int main28()
{
    char cars[][10] = {"Mustang", "Corvette", "Camaro"};
    //cars[0] = "Tesla"; //cannot post assign
    strcpy(cars[0], "Tesla"); //use this to post assign

    for(int i=0; i < sizeof(cars)/sizeof(cars[0]); i++){
        printf("%s\n", cars[i]);
    }
}

//swap values of two variables
int main29()
{
    char x[] = "water";
    char y[] = "lemonade";
    char temp[15];

    strcpy(temp, x); //store x value
    strcpy(x, y); //assign y to x, warning: if sizeof(y) < sizeof(x) it will cause bugs
    strcpy(y, temp); //assign x to temp

    printf("x: %s\n", x);
    printf("y: %s\n", y);
}

//sort an array
void sort(int array[], int size)
{
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }

        }
    }
}

void printArray(int array[], int size)
{
    for(int i=0; i<size; i++){
        printf("%d  ", array[i]);
    }
}

int main30()
{
    int array[] = {9,3,6,4,2,8,7,1};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array, size);
    printArray(array, size);
}

//struct
/*
collection of related members (variables)
can be different data types (except methods) listed under one name in a block of memory
very similar to classes in other languages without methods
*/
struct Player
{
    char name[12];
    int score;
};

int main31()
{
    struct Player player1;
    struct Player player2;

    strcpy(player1.name, "Bro");
    player1.score = 4;

    strcpy(player2.name, "Bruh");
    player2.score = 5;

    printf("player1 is called %s and have %d score\n", player1.name, player1.score);
    printf("player2 is called %s and have %d score\n", player2.name, player2.score);
}

//typedef -> shortcut, reserved keyword that gives an existing datatype a "nickname"
typedef char user[25];

typedef struct
{
    char name[25];
    char pass[12];
    int id;
} User; //using typedef the nickname comes at the end

int main32()
{
    // char user1[25] = "Bro"; //without typedef
    user user1 = "Bro"; //with typedef

    // struct User user1 = {"Bro", "secret", 123}; //without typedef
    User user2 = {"Bro", "secret", 123}; //with typedef
}

//array of structs
struct Student
{
    char name[20];
    float gpa;
};

int main33()
{
    struct Student student1 = {"Spongebob", 3.0};
    struct Student student2 = {"Patrick", 2.5};
    struct Student student3 = {"Sandy", 4.0};

    struct Student students[] = {student1, student2, student3};

    for(int i=0; i < sizeof(students)/sizeof(students[0]); i++)
    {
        printf("%-12s %.2f\n", students[i].name, students[i].gpa);
    }
}

//enums -> a user defined type of named integer identifiers, helps to make a program more readable
enum Day{Sun=1, Mon=2, Tue=3, Wed=4, Thu=5, Fri=6, Sat=7};

int main34()
{
    enum Day today = Sun;
    printf("%d", today); //1 enums are not strings, but they can be trated as int

    if(today==Sat || today==Mon)
    {
        printf("It's weekend");
    }
    else
    {
        printf("Working time");
    }
}

//pseudo random numbers
// #include <stdlib.h>
// #include <time.h>
int main35()
{
    srand(time(0)); //using current time as seed for random numbers

    int number1 = (rand() % 6) + 1; //random number between 1-6

    printf("%d", number1);
}

//exercise - number guessing game
int main36()
{
    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int guesses;
    int answer;

    srand(time(0));

    //generate random number between MIN and MAX
    answer = (rand() % MAX) + MIN;

    do{
        printf("Enter a guess between %d and %d: ", MIN, MAX);
        scanf("%d", &guess);
        if(guess>answer)
        {
            printf("Too high!\n");
        }
        else if(guess<answer)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("CORRECT!\n");
        }
        guesses++;
    }
    while(guess!=answer);

    printf("answer: %d\n", answer);
    printf("guesses: %d\n", guesses);
}

//exercise - quiz game
int main37()
{
    char questions[][100] =  {
        "1. What year did the C language debut?",
        "2. Who created C?",
        "3. What is the predecessor of C?"
    };

    char options[][100] = {
        "A. 1969", "B. 1972", "C. 1975", "D. 1999",
        "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
        "A. Objective C", "B. B", "C. C++", "D. C#"
    };

    char answers[3] = {'B', 'A', 'B'};
    int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);

    char guess;
    int score;

    printf("QUIZ GAME\n");

    for(int i=0; i<numberOfQuestions; i++)
    {
        //print questions
        printf("\n%s\n", questions[i]);

        //print options
        for(int j=(i*4); j<(i*4)+4; j++)
        {
            printf("%s\n", options[j]);
        }

        printf("guess: ");
        scanf(" %c", &guess);
        // scanf("%c"); //clear \n from input buffer

        guess = toupper(guess);

        if(guess==answers[i])
        {
            printf(">>> CORRECT!\n");
            score++;
        }
        else
        {
            printf(">>> WRONG!\n\n");
        }
    }

    printf("\n");
    printf("*******************************************\n");
    printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
    printf("*******************************************\n");
}

//bitwise operators => special operators used in bit level programming
/*
&  AND
|  OR
^  XOR
<< LEFT SHIFT
>> RIGHT SHIFT
*/
int main38()
{
    int x = 6;  // 6 = 00000110
    int y = 12; //12 = 00001100
    int z = 0;  // 0 = 00000000

    z = x & y;
    printf("AND = %d\n", z); // 4

    z = x | y;
    printf("OR = %d\n", z); // 14

    z = x ^ y;
    printf("XOR = %d\n", z); // 10

    z = x << 1;
    printf("SHIFT LEFT ONCE = %d\n", z); // 12

    z = y >> 2;
    printf("SHIFT RIGHT TWICE = %d\n", z); // 3
}

//memory addresses
int main39()
{
    char   a = 'X';
    short  b = 'Y';
    int    c = 'Z';
    double d = 'W';

    printf("%d bytes\n", sizeof(a)); //1 byte
    printf("%d bytes\n", sizeof(b)); //2 bytes
    printf("%d bytes\n", sizeof(c)); //4 bytes
    printf("%d bytes\n", sizeof(d)); //8 bytes

    printf("%p address\n", &a); //%p pointer?
    printf("%p address\n", &b);
    printf("%p address\n", &c);
    printf("%p address\n", &d);
}

//pointers
/*
a "variable-like" reference that holds a memory address to another variable, array, etc
some tasks are performed more esasily with pointers
* = indirection operator (value at address)
*/
void printAge(int *pAge)
{
    printf("You are %d years old", *pAge);  //dereference
}

int main40()
{
    int age = 21;
    int *pAge = NULL; //good practice to assign NULL if declaring a pointer
    pAge = &age;

    printf("address of age: %p\n", &age);
    printf("value of pAge: %p\n", pAge);

    printf("value of age: %d\n", age);
    printf("value at stored address: %d\n", *pAge); //dereferencing

    printAge(pAge);
}

//writing files
int main41()
{
    FILE *pF = fopen("C:\\Users\\GOOZ\\Desktop\\test.txt", "w"); //w write, a append, r read

    fprintf(pF, "Spongebob");

    fclose(pF);

    //delete a file
    if(remove("test.txt")==0) //remove function returns 0 if the file was deleted
    {
        printf("That file was deleted");
    }
    else
    {
        printf("File was NOT deleted");
    }
}

//read file
int main42()
{
    FILE *pF = fopen("files/poem.txt", "r");

    char buffer[255];

    // fgets(buffer, 255, pF); //read single line

    if(pF == NULL) //check if file exists
    {
        printf("Unable to open file\n");
    }
    else
    {
        while(fgets(buffer, 255, pF) != NULL) //read until fgets returns NULL which means end of file
        {
            printf("%s", buffer);
        }
    }

    fclose(pF);
}

//exercise tic tac toe game

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

//functions prototypes
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
int isGameFinished(char);
void printWinner(char);

int main()
{
    char winner;
    char response;

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while(!isGameFinished(winner))
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if(isGameFinished(winner))
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if(isGameFinished(winner))
            {
                break;
            }
        }
        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);

    } while (response == 'Y');
    
    printf("\nThanks for playing!\n");
    return 0;
}

void resetBoard()
{
    //fill board with spaces
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    system("cls");
    char sep[] = "\n---|---|---\n";

    printf("TIC TAC TOE GAME\n\n");
    for(int i=0; i<3; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i<2)
        {
            printf("%s", sep);
        }
    }
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove()
{
    int x;
    int y;

    do
    {
        printf("\nEnter row #(1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter colw #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }
    while (board[x][y] != ' ');
}

void computerMove()
{
    //create a seed based on current time
    srand(time(0));
    int x;
    int y;
    
    if(checkFreeSpaces() > 0)
    {
        do
        {
            //generates random numbers until find an open space
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else
    {
        //no winner, draw
        printWinner(' ');
    }
}

char checkWinner()
{
    //check rows
    for(int i=0; i<3; i++)
    {
        if(
            board[i][0] == board[i][1] &&
            board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //check cols
    for(int i=0; i<3; i++)
    {
        if(
            board[0][i] == board[1][i] &&
            board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //check diagonal 1
    if(
        board[0][0] == board[1][1] &&
        board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    //check diagonal 2
    if(
        board[0][2] == board[1][1] &&
        board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    //currently no winner
    return ' ';
}

int isGameFinished(char winner)
{
    return winner != ' ' || checkFreeSpaces() == 0;
}

void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT'S A TIE!");
    }
}
