#include <iostream>
#include <vector>

using FString = std::string;
using int32 = int;
using int32Vector = std::vector <int32>;
using FStringVector = std::vector <FString>;

int32Vector fibVector (int32 max) {
    int32 a = 0;
    int32 b = 1;
    int32Vector out;
    out.push_back(a);
    out.push_back(b);
    while (a <= max) {
        a = a + b;
        b = a + b;
        if (a < max) {
            out.push_back(a);
        }
        if (b < max) {
            out.push_back(b);
        }
    }
    return out;
}

FString fibVectorToString (int32Vector vector, FString delim) {
    FString out = "";
    for (auto element : vector) {
        out += delim + std::to_string(element);
    }
    return out;
}

int32 main(int32 argc, char *argv[]) {
    int32 limit = argc >= 2 ? std::stoi(argv[1]) : 7000;
    if (argc < 2) {
        std::cout << "USAGE: `$ fib ${NUMBER}` where `${NUMBER}` is whatever 32-BIT positive number " <<
                             "you would like to enter." << std::endl;
        std::cout << "Showing Fibonacci numbers up to default limit `7000`." << std::endl;
    }
    std::cout << fibVectorToString(fibVector(limit), " ") <<  std::endl;
    return 0;
}
