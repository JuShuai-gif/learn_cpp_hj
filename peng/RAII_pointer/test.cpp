#include <memory>
#include <vector>

class ShaderProgram;

class Shader {
public:
    Shader(std::shared_ptr<ShaderProgram> program) : program(program) {}

private:
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

int main() {
    auto program = std::make_shared<ShaderProgram>();
    auto shader = std::make_shared<Shader>(program);

    program->attachShader(shader);

    // 此时 program 和 shader 互相持有 shared_ptr，形成循环引用
    // 即使 main 函数结束，它们的引用计数也不会归零，导致内存泄漏
    return 0;
}
