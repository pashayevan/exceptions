#include <iostream>
struct WrongAgeExceptions {
    int age;
};

int ReadAge() {
    std::cin.exceptions(std::istream::failbit);
    int age;
    std::cin>> age;
    if(age<0 || age>=120) {
        throw WrongAgeExceptions(age);
    }
    return age;
}

int main() {
    try {
        int age = ReadAge();
    }
    catch (const WrongAgeExceptions&  ex) {
        std::cerr<<"Age is not correct:"<<ex.age<<"\n";
        return 1;
    }
    catch(const std::istream::failure& ex) {
        std::cerr<<"Failed to read stream:"<<ex.what()<<"\n";
        return 1;
    }
    catch(...) {
        std::cout<<"Unknown exception\n";
        return 1;
    }
}
    /*if(int age= RealAge(); age ==-1) {
        std::cout<< "not real\n";
    }
    else {
        std::cout<<"real\n";
    }*/
