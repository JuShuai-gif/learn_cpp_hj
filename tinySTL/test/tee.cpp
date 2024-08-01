
// 函数模板示例
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main()
{
    add<int>(1,2);
    add<float>(1.2f,3.2f);
}