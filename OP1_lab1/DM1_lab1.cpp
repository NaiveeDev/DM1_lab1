#include <iostream>
#include <math.h>
#include <vector>
#include <Windows.h>
#include <string>
#include <fstream>



//#1
template <typename T>
void PerimeterAndAreaAB(T a, T b) {

   
    T S = a * b;
    T P = 2 * (a + b);

    std::cout << "A: " << a << " " << "B: " << b << std::endl;
    std::cout << "Площа: " << S << " " << "Периметр: " << P << std::endl;

}

//#2
template <typename T>
void GeometricMean(T a, T b) {

    T result;

    if (a && b > 0) {

        result = sqrt(a * b);
    }

    std::cout << "A: " << a << " " << "B: " << b << std::endl;
    std::cout << "Result: " << result << std::endl;

}

//#3
template <typename T>
void RectangleDo(T x1, T y1, T x2, T y2) {

    T width = abs(y2 - y1);
    T length = abs(x2 - x1);
    
    T area = length * width;
    T perimeter = 2 * (length + width);

    std::cout << "Площа: " << area << "\n" << "Периметр: " << perimeter << std::endl;
   

}

//#4
void isPair(int a) {

    if (a % 2 == 0)
        std::cout << "Число " << a << " парне!";
    else if (a % 2 != 0)
        std::cout << "Число " << a << " не парне!";
    
}

//#5
template <typename T>
void abcDo(T a, T b, T c) {

    bool isABC = false, leastPositive = false, onlyOnePositive = false;

    //-3 -2 -1
    if (a < b && b < c) {
        isABC = true;
    }

    if (a > 0 || b > 0 || c > 0) {
        leastPositive = true;
    }

    if (a > 0 && b < 0 && c < 0) {
        onlyOnePositive = true;
    }
    if (a < 0 && b > 0 && c < 0) {
        onlyOnePositive = true;
    }
    if (a < 0 && b < 0 && c > 0) {
        onlyOnePositive = true;
    }

    /*^^^ if ((a > 0 && b < 0 && c < 0) || 
    (a < 0 && b > 0 && c < 0) || 
    (a < 0 && b < 0 && c > 0)) {
    onlyOnePositive = true;
    }*/

    std::cout << "a < b < c: " << isABC << "\n" <<
        "Хоча б одне додатнє: " << leastPositive << "\n" <<
        "Тільки одне додатнє: " << onlyOnePositive;
}

//#6
void BlackOrWhite(int x, int y) {

    if (x > 8 || y > 8 || x < 0 || y < 0) {
        std::cout << "Недопустимі значення!\n";
        exit(0);
    }
    
    if ((x + y) % 2 == 0) {
        std::cout << "Клітка чорна\n";
    }
    else {
        std::cout << "Клітка біла\n";
    }

}

//#7
void QueenMove(int x1, int y1, int x2, int y2) {


    if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 || x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8) {
        std::cout << "Некоректні дані!" << std::endl;
        exit(0);
    }

    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);


    
    if (x1 == x2 || y1 == y2 || dx == dy) {
        std::cout << "Ферзь може перейти на заданих полях\n";
    }
    else
    {
        std::cout << "Ферзь не може перейти на заданих полях\n";
    }

}

//#8
void beetweenAB(int a, int b) {
    
    if (a > b || a == b) {
        std::cout << "Помилка! Некорректні дані." << std::endl;
        exit(0);
    }


    short n = 0;
    std::vector<int> numArr;

    for (size_t i = a+1; i < b; i++) {

        numArr.push_back(i);
        n++;
    }

    for (int i = 0; i < numArr.size(); i++) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << numArr[i];
    }

    std::cout << "\nN: " << n << std::endl;

}

//#9
void reverseNum(int n) {
    
    if (n <= 0) {
        std::cout << "Помилка! Значення менше або дорівнює нулю.";
    }
 
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    std::cout << reversed << std::endl;

}

//#10
void doArray(std::vector<int> arr) {

    int sum = 0;
    int n = 0;

    for (size_t i = 0; i < arr.size(); i++) {

        sum += arr[i];
        n++;
    }
    std::cout << "Початковий масив: " << std::endl;

    for (int i = 0; i < arr.size(); i++) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }

    int averageArr = sum / n;
    std::cout << "\nСереднє арифметичне масиву: " << averageArr;

    for (size_t i = 0; i < arr.size(); i++) {

        if (arr[i] < averageArr) {
            arr[i] -= 18;
        }
        else 
            continue;

    }

    std::cout << "\nПеретворений масив: " << std::endl;
    for (int i = 0; i < arr.size(); i++) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }
}

//#11
void isSimple(int a) {

    bool simpleNum = true;

    if (a <= 0) {
        std::cout << "Помилка! Число менше або дорівнює нулю.";
        exit(0);
    }

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            simpleNum = false;
            std::cout << simpleNum  << " число " << a << " не просте." << std::endl;
            exit(0);
        }
    }

    std::cout << simpleNum << " число "<< a <<" просте." << std::endl;
}

//#12
void Calculate(double x, double y, double z) {

    double a = x + (pow(y, 3) / (z + pow(z, 2) + (z + pow(y, 3))));

    std::cout << a << std::endl;

}

//#13
bool isHaveSpace(std::string str) {

    for (size_t i = 0; i < str.length(); i++) {

        if (!str.find(' ')) {
            return true;
        }

    }

    return false;
}

void ContactForm() {

    std::string firstName, lastName, phone;
    bool isError = false;

    std::cout << "Введіть ім'я: ";
    std::getline(std::cin, firstName);

    std::cout << "Введіть прізвище: ";
    std::getline(std::cin, lastName);

    std::cout << "Введіть номер телефону (не обов'язково): ";
    std::getline(std::cin, phone);

    if (isHaveSpace(firstName) || isHaveSpace(lastName) || isHaveSpace(phone)) {
        isError = true;
    }

    if (isError) {
        std::cout << "Не залишайте жодні поля порожніми!" << std::endl;
        exit(0);
    }
    else {
        std::cout << "Спасибі!" << std::endl;
    }


}

//#14
void FiveTry() {

    int counter = 0;
    int num = 0;

    for (size_t i = 0; i < 5; i++) {

        std::cout << "Введіть число: ";
        std::cin >> num;

        if (num != 5) {
            counter++;
        }
        else {
            std::cout << "Гарна робота!";
            exit(0);
        }

        if (counter == 5) {
            std::cout << ":(";
            exit(0);
        }

    }

}

//#15
void divisibleBy() {

    for (size_t i = 0; i < 100; i += 13) {
        std::cout << i << " ";
    }

}

//#16
void doString() {

    std::string str = "Hello";

    std::cout << "Третій символ: " << str[2] << std::endl;

    std::string str2 = " World";

    std::string combinedStr = str + str2;
    std::cout << "Об'єднані рядки: " << combinedStr << std::endl;

    std::string multipliedStr;

    for (int i = 0; i < 10; i++) {
        multipliedStr += str;
    }
    std::cout << "Розмножений рядок: " << multipliedStr << std::endl;

    combinedStr.insert(5, "!");
    std::cout << "Рядок з вставленим символом: " << combinedStr << std::endl;

    std::string modifiedStr = str;
    modifiedStr[1] = 'a';
    std::cout << "Змінений рядок: " << modifiedStr << std::endl;

}




int main(int argc, char *argv[]) {

    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    std::cout.setf(std::ios_base::boolalpha);


    //#1
    //PerimeterAndAreaAB(2, 2);

    //#2
    //GeometricMean(4.5, 4.3);

    //#3
    //RectangleDo(3, 4, 5, 10);

    //#4
    //isPair(3);

    //#5
    //abcDo(-3, -2, 1);
    
    //#6
    //BlackOrWhite(9, 9);

    //#7
    //QueenMove(1, 4, 1, 5);

    //#8
    //beetweenAB(13, 10);

    //#9
    //reverseNum(1231);

    //#10 
    //std::vector<int> arr = { 1,2,3,4,5,6,7,8 };
    //doArray(arr);

    //#11
    //isSimple(3);

    //#12
    //Calculate(4, -0.8, -5);

    //#13
    //ContactForm();

    //#14
    //FiveTry();

    //#15
    //divisibleBy();

    //#16
    //doString();

}
