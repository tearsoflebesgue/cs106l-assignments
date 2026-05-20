template <typename T>
class BoundedValue {
    private:
    T value;
    T minvalue;
    T maxvalue;

    public:
    BoundedValue(T value, T minvalue, T maxvalue);

    T get() const;
    void set(T newvalue);
    T getMin() const;
    T getMax() const;
    void adjust(T delta);
}

#include "bounded_value.cpp"