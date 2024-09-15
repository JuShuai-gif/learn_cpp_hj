#include <iostream>

template <typename T>
class SharedPtr {
private:
    std::size_t *m_count_;
    T *m_ptr_;

public:
    // Default constructor
    SharedPtr() :
        m_ptr_(nullptr), m_count_(new std::size_t(1)) {
    }

    // Constructor with raw pointer
    SharedPtr(T *ptr) :
        m_ptr_(ptr), m_count_(new std::size_t(1)) {
    }

    // Destructor
    ~SharedPtr() {
        reset();
    }

    // Copy constructor
    SharedPtr(const SharedPtr &ptr) :
        m_ptr_(ptr.m_ptr_), m_count_(ptr.m_count_) {
        ++(*m_count_);
    }

    // Copy assignment operator
    SharedPtr &operator=(const SharedPtr &ptr) {
        if (this != &ptr) {
            reset(); // Release current resource
            m_ptr_ = ptr.m_ptr_;
            m_count_ = ptr.m_count_;
            ++(*m_count_);
        }
        return *this;
    }

    // Move constructor
    SharedPtr(SharedPtr &&ptr) noexcept :
        m_ptr_(ptr.m_ptr_), m_count_(ptr.m_count_) {
        ptr.m_ptr_ = nullptr;
        ptr.m_count_ = nullptr;
    }

    // Move assignment operator
    SharedPtr &operator=(SharedPtr &&ptr) noexcept {
        if (this != &ptr) {
            reset(); // Release current resource
            m_ptr_ = ptr.m_ptr_;
            m_count_ = ptr.m_count_;
            ptr.m_ptr_ = nullptr;
            ptr.m_count_ = nullptr;
        }
        return *this;
    }

    // Dereference operators
    T &operator*() const {
        return *m_ptr_;
    }

    T *operator->() const {
        return m_ptr_;
    }

    // Boolean conversion
    explicit operator bool() const {
        return m_ptr_ != nullptr;
    }

    // Getters
    T *get() const {
        return m_ptr_;
    }

    std::size_t use_count() const {
        return (m_count_ != nullptr) ? *m_count_ : 0;
    }

    bool unique() const {
        return use_count() == 1;
    }

    // Swap function
    void swap(SharedPtr &ptr) {
        std::swap(m_ptr_, ptr.m_ptr_);
        std::swap(m_count_, ptr.m_count_);
    }

    // Reset the pointer
    void reset(T *ptr = nullptr) {
        if (m_count_ && --(*m_count_) == 0) {
            delete m_ptr_;
            delete m_count_;
        }
        m_ptr_ = ptr;
        m_count_ = ptr ? new std::size_t(1) : nullptr;
    }
};


struct Student {
public:
    Student(int age_,std::string name_):age(age_),name(name_) {

    };
    ~Student() {
    }

    void do_something(){
        std::cout << "我今年 " << age << " 岁了，" << "我叫 " << name << " !" << std::endl;
    }

private:
    int age{24};
    std::string name{"GHR"};
};

int main(){
    SharedPtr<Student> nn(new Student(30,"KX"));
    nn->do_something();
    return 0;
}
