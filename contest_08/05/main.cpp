#include <iostream>

// Ваш код здесь
#include <algorithm>

class IntSharedPointer {
private:
	int* ptr;
	int* refCount;

public:
	IntSharedPointer(int* p) : ptr(p), refCount(new int(1)) {}
	
	IntSharedPointer(const IntSharedPointer& other) : ptr(other.ptr), refCount(other.refCount) {
		++*refCount;
	}
	~IntSharedPointer() {
		if (--*refCount == 0) {
			delete ptr;
			delete refCount;
		}
	}

	IntSharedPointer& operator=(IntSharedPointer other) {
		std::swap(ptr, other.ptr);
		std::swap(refCount, other.refCount);
		return *this;
	}
	int& operator*() {
		return *ptr;
	}

	int* operator->() {
		return ptr;
	}
};
// Конец вашего кода
void print(IntSharedPointer p){
    std::cout << *p << std::endl;
}

void print_with_exception(IntSharedPointer p){
    std::cout << *p << std::endl;
    if (*p % 2) throw std::string("error");
}

int main(){
    IntSharedPointer p(new int);
    std::cin >> *p;
    p = p;
    print(p);

    IntSharedPointer p2(p);
    std::cin >> *p2;
    print(p);
    print(p2);
    
    {
        int value;
        std::cin >> value;
        IntSharedPointer p3(new int(value));
        p2 = p3;
    }
    print(p2);
    
    p = p2;
    try{
        print_with_exception(p);
    }
    catch (const std::string& e) {
        std::cout << e << std::endl;
    }
}
