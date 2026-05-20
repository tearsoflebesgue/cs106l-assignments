#include "bounded_value.h"
template <typename T>
BoundedValue<T>::BoundedValue(T value, T minvalue, T maxvalue): minvalue{minvalue}, maxvalue{maxvalue} {
    if (value < minvalue) {
        this->value = minvalue;
    } else if (value > maxvalue) {
        this->value = maxvalue;
    } else {
        this->value = value;
    }
}

template <typename T>
T BoundedValue<T>::get() const {
    return value;
}

template <typename T>
void BoundedValue<T>::set(T newvalue) {
    value = newvalue;
}

template <typename T>
T BoundedValue<T>::getMin() const {
    return minvalue;
}

template <typename T>
T BoundedValue<T>::getMax() const {
    return maxvalue;
}

