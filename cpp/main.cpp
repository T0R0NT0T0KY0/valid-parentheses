#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string text) {
        stack<char> bracketsStack;
        unordered_map<char, char> bracketsMap = {{')', '('},
                                                 {']', '['},
                                                 {'}', '{'}};

        for (const char &item: text) {
            if (!bracketsStack.empty() && bracketsMap[item] == bracketsStack.top()) {
                bracketsStack.pop();
            } else {
                bracketsStack.push(item);
            }
        }

        return bracketsStack.empty();
    }
};

int main() {
    Solution solution;
    bool res1 = solution.isValid("()");
    std::cout << "test1: " << res1 << std::endl;

    bool res2 = solution.isValid("()[]{}");
    std::cout << "test2: " << res2 << std::endl;

    bool res3 = solution.isValid("(]");
    std::cout << "test3: " << res3 << std::endl;

    return 0;
}
