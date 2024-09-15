#include <cstdio>
#include <cstdlib>
#include <memory>
#include <vector>
#include <iostream>

struct C {
    int num{15};

    C() {
        printf("分配内存!\n");
    }
    C(int num):num(num) {
        printf("分配内存!\n");
    }

    ~C() {
        printf("释放内存!\n");
    }

    void do_something() {
        printf("我的数字是 %d!\n", num);
    }

    void do_something_no_num() {
        printf("不调用数字 num!\n");
    }
};
/*
如果只要使用它一下，可以使用原始指针的方式
*/
void func(C *p) {
    p->do_something();
}

void func(std::shared_ptr<C> p) {
    p->do_something();
}

/*
如果想要它的生命周期，就要 move
*/
void move_func(std::unique_ptr<C> p) {
    printf("移交前：%p\n", p.get());
    p->do_something();
}

std::vector<std::unique_ptr<C>> objects;

void after_move_func(std::unique_ptr<C> p) {
    objects.push_back(std::move(p));
}

std::vector<std::shared_ptr<C>> shared_objects;

void after_move_func(std::shared_ptr<C> p) {
    shared_objects.push_back(std::move(p));
}

class ShaderProgram;

class Shader {
public:
    Shader(std::shared_ptr<ShaderProgram> program) :
        program(program) {
    }

public:
    std::shared_ptr<ShaderProgram> program;
};

class ShaderProgram {
public:
    void attachShader(std::shared_ptr<Shader> shader) {
        shaders.push_back(shader);
    }

private:
    std::vector<std::shared_ptr<Shader>> shaders;
};

struct Pig {
    std::string m_name;
    int m_weight;
    Pig(std::string name, int weight) :
        m_name(name), m_weight(weight) {
    }

    /*
    如何避免不经意的隐式拷贝？
    explicit Pig(Pig const &other) = default;
    */
    explicit Pig(Pig const &other) :
        m_name(other.m_name), m_weight(other.m_weight) {
        std::cout << "调用了拷贝构造" << std::endl;
    }
};

// 这里show传递的是常引用，实际上只传递了一个指针，避免了拷贝
// Pig const& 等于 const Pig&
void show(Pig const &pig) {
    std::cout << "name: " << pig.m_name << std::endl;
    std::cout << "weight: " << pig.m_weight << std::endl;
}

// 由于show的参数传递的是值传递，所以会进行一次拷贝
//void show(Pig pig) {
//    std::cout << "name: " << pig.m_name << std::endl;
//   std::cout << "weight: " << pig.m_weight << std::endl;
//}

int main() {
    {
        C *p = new C;
        if (rand() != 0) {
            printf("除了点小状况。。。。\n");
            // return 1;
        }
        delete p;
    }

    {
        std::unique_ptr<C> p = std::make_unique<C>();

        printf("提前释放....\n");
        p = nullptr;
        printf("释放成功\n");
    }

    {
        std::unique_ptr<C> p = std::make_unique<C>();
        func(p.get());
    }

    {
        std::unique_ptr<C> p = std::make_unique<C>();
        printf("移交前：%p\n", p.get()); // 不为空
        move_func(std::move(p));
        printf("移交后：%p\n", p.get()); // 为空
    }

    {
        printf("after_move_func\n");
        std::unique_ptr<C> p = std::make_unique<C>();
        printf("移交前：%p\n", p.get()); // 不为空
        after_move_func(std::move(p));
        printf("移交后：%p\n", p.get()); // 为空
        // 这里有个问题就是，如果C的 do_something 没有调用成员变量，这里是不会报错的
        // 现在do_something() 中调用了成员变量 nums 就会报错
        // p->do_something();  调用了sum会报错
        /*
        如果 do_something_no_num() 在实现中没有解引用 this 指针，
        C++ 标准允许它在 p 是 nullptr 时正常工作。
        换句话说，只有当成员函数试图访问对象的成员变量或成员函数时，才需要有效的 this 指针。
        */
        p->do_something_no_num();
    }

    {
        std::unique_ptr<C> p3 = std::make_unique<C>();
        std::unique_ptr<C> p4;
        // p3 = p4; // 非法的
        p4 = std::move(p3);// 可以
    }

    {
        std::cout << "raw_p指向的数据\n";
        std::unique_ptr<C> p = std::make_unique<C>(250);
        p->do_something();
        C *raw_p = p.get();
        after_move_func(std::move(p));

        objects.clear();
        // raw_p始终指向的是p的地址，如果objects被清空之后，raw_p就会变成空悬指针、
        // 有时候它并不会报错，但是它会造成读取值出现错误，这样引起的bug会非常难找
        // 这时候raw_p会变成悬空指针，指针仍然指向无效的内存
        if (raw_p){
            raw_p->do_something();
        }else{
            std::cout << "raw_p为null\n";
        }
        
        
    }

    std::cout << "智能指针\n";

    {
        std::shared_ptr<C> p = std::make_shared<C>();
        std::cout << "p.use_count: " << p.use_count() << std::endl;
        after_move_func(p);
        std::cout << "p.use_count: " << p.use_count() << std::endl;
        after_move_func(p);
        std::cout << "p.use_count: " << p.use_count() << std::endl;
        p->do_something();
        std::cout << "p.use_count: " << p.use_count() << std::endl;
        shared_objects.clear();
        std::cout << "p.use_count: " << p.use_count() << std::endl;
        p->do_something();
    }

    /****    循环引用     ***
    {
        auto parent = std::make_shared<CC>();
        auto child = std::make_shared<CC>();
        // 建立相互引用
        parent->m_child = child;
        child->m_parent = parent;
        // parent 不会被释放，因为child还指向他
        parent = nullptr;
        // child 也不会被释放，因为parent还指向他
        child = nullptr;
        std::cout << "parent.use_count: " << parent.use_count() << std::endl;
        std::cout << "child.use_count: " << child.use_count() << std::endl;
    }
    */
    {
        auto program = std::make_shared<ShaderProgram>();
        auto shader = std::make_shared<Shader>(program);

        program->attachShader(shader);

        // 此时 program 和 shader 互相持有 shared_ptr，形成循环引用
        // 即使 main 函数结束，它们的引用计数也不会归零，导致内存泄漏
        /*
        循环引用引起的内存泄漏不会引起编译器错误，但是长期的内存泄漏会导致系统崩溃
        */
    }

    // shared_ptr和weak_ptr是一对，他俩常常在一起使用
    // unique_ptr和原始指针一起使用
    {
        std::cout << "************************\n";
        std::shared_ptr<C> p = std::make_shared<C>();
        printf("use count = %ld\n", p.use_count());
        std::weak_ptr<C> weak_p = p;
        printf("use count = %ld\n", p.use_count());
        func(std::move(p));

        if (weak_p.expired())
            printf("错误：弱引用已失效！\n");
        else
            weak_p.lock()->do_something();

        objects.clear();

        if (weak_p.expired())
            printf("错误：弱引用已失效！\n");
        else
            weak_p.lock()->do_something();
    }

    {
        std::unique_ptr<C> p = std::make_unique<C>();
        // 下面这种写法是错误的，因为std::unique_ptr是删除拷贝了，所以只能使用std::move
        // std::unique_ptr<C> pp = p;
        std::unique_ptr<C> pp = std::move(p);
    }

    {
        Pig pig{"佩奇", 80};
        show(pig);
    }

    return 0;
}
