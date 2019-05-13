#include <chrono>
#include <iostream>
#include <memory>

class MoveTestClass
{
public:
    MoveTestClass() = default;

    void MoveMethod(std::shared_ptr<std::string> moveString)
    {
        //std::cout << "moveString: " << moveString << std::endl;
        classVar = std::move(moveString);
        //std::cout << "moveString: " << moveString << std::endl;
    }

    void CopyMethod(std::shared_ptr<std::string> copyString)
    {
        //std::cout << "copyString: " << copyString << std::endl;
        classVar = copyString;
        //std::cout << "copyString: " << copyString << std::endl;
    }

public:
    std::shared_ptr<std::string> classVar;
};

int main() {
    const int interationCount = 1000;
    MoveTestClass moveTest;
    std::shared_ptr<std::string> testString = std::make_shared<std::string>("Test String");

    auto start = std::chrono::steady_clock::now();

    for (auto i = 0; i < interationCount; i++) {
        moveTest.MoveMethod(testString);
    }

    auto end = std::chrono::steady_clock::now();
    std::cout << "Move Elapsed Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;
    std::cout << "testString: " << testString << std::endl;
    std::cout << "moveTest  : " << moveTest.classVar << std::endl;

    start = std::chrono::steady_clock::now();

    for (auto i = 0; i < interationCount; i++) {
        moveTest.CopyMethod(testString);
    }

    end = std::chrono::steady_clock::now();

    std::cout << "Copy Elapsed Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns" << std::endl;
    std::cout << "testString: " << testString << std::endl;
    std::cout << "moveTest  : " << moveTest.classVar << std::endl;

    return 0;
}