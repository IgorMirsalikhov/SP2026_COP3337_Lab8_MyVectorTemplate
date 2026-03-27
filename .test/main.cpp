#include "MyVector.hpp"
#include <random>
#include <string>

int main(void) {
    // Part 0 goes here


    // Part 1 testing
    // Test copy constructor
    MyVector<double>* mvd1 = new MyVector<double>(10);
    mvd1->push_back(5.5);
    MyVector<double>* mvd2 = new MyVector<double>(*mvd1);

    delete mvd1;
    delete mvd2;

    // Test other methods
    MyVector<std::string> v;
    std::cout << v.empty() << std::endl;
    std::cout << v.getCapacity() << std::endl;
    v.push_front("hello");
    v.push_front("hi");
    v.push_front("good morning");
    std::cout << v.empty() << std::endl;
    std::cout << v.at(-1) << std::endl;
    
    v.insert(2, "bye");
    std::cout << v.getSize() << std::endl;
    for (int i = 0; i < v.getSize(); i++) {
        std::cout << v.at(i) << ' ';
    }
    std::cout << "\n";
    v.clear();

    // Test erase and remove_dups

    std::mt19937 eng(1);
    std::uniform_int_distribution<int> dist(0, 20);
    
    MyVector<int> *p = new MyVector<int>(100);
    for (int i = 0; i < 20; i++) {
        p->push_front(dist(eng));
    }
    
    
    p->print();
    while (p->getSize() > 5) {
        std::uniform_int_distribution<int> dist2(p->getSize() * -1, p->getSize() - 1);
        int index = dist2(eng);
        std::cout << "index to delete " << index << std::endl;
        p->erase(index);
        p->print();
    }

    for (int i = 0; i < 20; i++) {
        p->push_front(dist(eng));
    }

    std::cout << "Before remove_dups()\n";
    p->print();
    p->remove_dups();
    std::cout << "After remove_dups()\n";
    p->print();

    delete p;
    


    return 0;
}
