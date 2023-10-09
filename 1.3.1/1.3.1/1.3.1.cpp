#include <iostream>

class Calculator {
public:

   double add() { return num1 + num2;}
   double multiply() { return num1 * num2;}

   double substact_1_2() {return num1 - num2;}
   double substact_2_1() {return num2 - num1;}

   double divide_1_2() {return num1 / num2;}
   double divide_2_1() {return num2 / num1;}

   bool set_num1(double num1) {
      if(num1 != 0){
         this->num1 = num1;
         return true;
      }
      else
         return false;
   }

   bool set_num2(double num2) {
      if(num2 != 0){
         this->num2 = num2;
         return true;
      }
      else
         return false;
   }

   void ask_user() {
      double temp1 = 0, temp2 = 0;

      while (!set_num1(temp1)) {
         std::cout << "Введите num1: ";
         std::cin >> temp1;
         if (!set_num1(temp1))
            std::cout << "Неверный ввод!" << std::endl;
      }
      std::cout << std::endl;
      while (!set_num2(temp2)) {
         std::cout << "Введите num2: ";
         std::cin >> temp2;
         if (!set_num2(temp2))
            std::cout << "Неверный ввод!" << std::endl;
      }
   }
   void print_functions() {
      std::cout << "num1 + num2 = " << add() << std::endl;
      std::cout << "num1 - num2 = " << substact_1_2() << std::endl;
      std::cout << "num2 - num1 = " << substact_2_1() << std::endl;
      std::cout << "num1 * num2 = " << multiply() << std::endl;
      std::cout << "num1 / num2 = " << divide_1_2() << std::endl;
      std::cout << "num2 / num1 = " << divide_2_1() << std::endl;
   }

private:
   double num1;
   double num2;
};

int main() {
   setlocale(LC_ALL, "Russian");
   Calculator calculator;

   while (1) {
      calculator.ask_user();
      calculator.print_functions();
   }

   return 0;
}