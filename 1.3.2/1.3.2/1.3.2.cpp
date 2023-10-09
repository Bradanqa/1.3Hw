#include <iostream>
#include <locale.h>
#include <string>

class Counter {
public:
   Counter() {
      counter1 = 1;
   }

   Counter(int counter1) {
      this->counter1 = counter1;
   };

   void addCounter(){
      ++counter1;
   }

   void subCounter() {
      --counter1;
   }

   void printCounter() {
      std::cout << counter1;
      std::cout << std::endl;
   }

   bool setOptions() {
      char option;
      std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
      std::cin >> option;

      switch (option) {
      case '+':
         this->addCounter();
         return true;
         break;
      case '-':
         this->subCounter();
         return true;
         break;
      case '=':
         this->printCounter();
         return true;
         break;
      case 'x':
         std::cout << "�� ��������!";
         return false;
      default:
         return false;
      }
   }

private:
   int counter1;
};

int main() {
   setlocale(LC_ALL, "Russian");

   std::string option;
   int count;
   char userOption;
   bool cycle = true;

   std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
   std::cin >> option;
   std::cout << std::endl;

   if (option == "��") {
      std::cout << "������� ��������� �������� ��������: ";
      std::cin >> count;
      Counter* counter = new Counter(count);
      while (cycle) {
         cycle = counter->setOptions();
      }
      delete counter;
   }
   else if (option == "���") {
      Counter *counter = new Counter();
      while (cycle) {
         cycle = counter->setOptions();
      }
      delete counter;
   }
   else
      return 1;

   return 0;
}