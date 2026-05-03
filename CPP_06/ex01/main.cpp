#include "Serializer.hpp"

int main() {
    Data* original = new Data();
    original->type = 77;

    std::cout << "original type: " << original->type << "\n";
    std::cout << "address of data before Serializer: " << original << "\n";
    uintptr_t a = Serializer::serialize(original);
    std::cout << "address of data after Serializer: " << a << "\n";
    Data* copy = Serializer::deserialize(a);
    std::cout << "address of data after Deserializer: " << copy << "\n";
    std::cout << "copy type: " << copy->type << "\n";

    delete original;
}
