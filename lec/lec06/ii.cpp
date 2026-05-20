#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::cout << "输入数字（按Ctrl+D结束）:\n";
    // 从cin读取int，初始指向第一个输入
    std::istream_iterator<int> start(std::cin);
    // 默认构造的迭代器代表“流结束”
    std::istream_iterator<int> end;

    // 直接用[start, end)范围初始化vector
    std::vector<int> numbers(start, end);

    // 遍历输出
    for (int n : numbers) std::cout << n << " ";
}