#include <iostream>
#include <vector>
#include <algorithm>

class info {

   
public:
    int process_time;
    char name;
    int due_date;
    
    // Kurucu fonksiyon
    info(int i, char c, int d) : process_time(i), name(c), due_date(d) {}
};



void print(std::vector<info> myVector)
{
    int i = 1;
    for (const auto& item : myVector) {

        std::cout <<"\n" << i << ".  time: " << item.process_time << ", Name.: " << item.name << " due date : " << item.due_date << std::endl;
        i++;
    }

}



// Sıralama fonksiyonu

bool compareProcess_B(const info& a, const info& b) {

    return a.process_time > b.process_time;
}

bool compareProcess_l(const info& a, const info& b) {

    return a.process_time < b.process_time;
}

bool compreDuedate(const info& a, const info& b) {

    return a.process_time < b.process_time;
}


int main() {
    // MyClass tipinde elemanları içeren bir vektör
    std::vector<info> myVector;



    int processigTime;
    char Product;
    int due_date;

    int Np;
    std::cout << "number of product: ";
    std::cin >> Np;
     

    for (int i = 0; i < Np; ++i)
    {
        std::cout << std::endl << "Product name: ";
        std::cin >> Product;

        std::cout << std::endl<<"product "<< Product<<" processig time value: ";
        std::cin >> processigTime;

        std::cout << std::endl << "product " << Product << " Due date : ";
        std::cin >> due_date;


        

        myVector.emplace_back(processigTime, Product,due_date);

    }


    std::cout << " OK ALL OF INFOS IN MY MEMORY" << std::endl  << "     -if min SUM Ci(enter 1)\n" << "     -if your pupose Min Makespan(enter 2)\n" << "       -if your purpose Min Lmax (enter 3)" << "\nWhat is your purpose?";

    int purpose;
    std::cin >> purpose;

   
    switch (purpose) {
    case 1:
        std::sort(myVector.begin(), myVector.end(), compareProcess_l);
        print(myVector);
        break;
    case 2:
        std::sort(myVector.begin(), myVector.end(), compareProcess_B);
        print(myVector);
        break;
    case 3:
        std::sort(myVector.begin(), myVector.end(), compreDuedate);
        print(myVector);
        break;
    }

        

    return 0;
}
