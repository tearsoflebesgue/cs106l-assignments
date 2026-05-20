#include <string>

class Dog {
    private:
    std::string name;
    int weight;
    bool feeded;
    bool is_hungry() const;
    public:
    Dog();
    Dog(std::string name, int weight, bool feeded);
    int get_weight() const;
    void set_weight(int value);
};