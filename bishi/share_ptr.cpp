//
// Created by Administrator on 2019/4/1 0001.
//

#include <iostream>
#include <memory>

template<typename T>
class SmartPointer {
private:
    T* _ptr;
    size_t* _count;
public:
    SmartPointer(T* ptr = nullptr) :
            _ptr(ptr) {
        if (_ptr) {
            _count = new size_t(1);
        } else {
            _count = new size_t(0);
        }
    }

    SmartPointer(const SmartPointer& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;
            this->_count = ptr._count;
            (*this->_count)++;
        }
    }

    SmartPointer& operator=(const SmartPointer& ptr) {
        if (this->_ptr == ptr._ptr) {
            return *this;
        }

        if (this->_ptr) {
            (*this->_count)--;
            if (*(this->_count) == 0) {
                delete this->_ptr;
                delete this->_count;
                std::cout<<"destroy ptr"<<std::endl;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    T& operator*() {
        assert(this->_ptr == nullptr);
        return *(this->_ptr);

    }

    T* operator->() {
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    ~SmartPointer() {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    size_t use_count(){
        return *this->_count;
    }
};

int main() {
    {
        SmartPointer<int> sp(new int(10));
        SmartPointer<int> sp2(sp);
        SmartPointer<int> sp3(new int(20));
        sp3 = sp2;
        std::cout << sp.use_count() << std::endl;
        std::cout << sp3.use_count() << std::endl;
    }
    //delete operator
}

//
////weak_ptr
//#include <iostream>
//#include <memory>
//
//int main() {
//    {
//        std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
//        std::cout << sh_ptr.use_count() << std::endl;
//
//        std::weak_ptr<int> wp(sh_ptr);
//        std::cout << wp.use_count() << std::endl;
//
//        if(!wp.expired()){
//            std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
//            *sh_ptr = 100;
//            std::cout << wp.use_count() << std::endl;
//        }
//        std::cout << sh_ptr.use_count() << std::endl;
//    }
//    //delete memory
//}