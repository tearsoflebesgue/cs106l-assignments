#include <iostream>
#include <iterator>

int main() {
    // 输出到cout，元素之间用", "分隔
    std::ostream_iterator<int> it(std::cout, ", ");

    *it = 10;  // 输出 "10, "
    ++it;      // 前进，对流来说是无操作
    *it = 20;  // 输出 "20, "
    ++it;
    *it = 30;  // 输出 "30, "
}
// 最终输出：10, 20, 30, 