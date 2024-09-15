#include <iostream>

class String {
protected:
    char* data;
    size_t size;

public:

    String() : data(nullptr), size(0) {}

    String(const char* str) {
        size = 0;
        while (str[size] != '\0') {
            ++size;
        }
        data = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            data[i] = str[i];
        }
        data[size] = '\0';
    }

    String(const String& other) {
        size = other.size;
        data = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        data[size] = '\0';
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            data[size] = '\0';
        }
        return *this;
    }

    size_t length() const {
        return size;
    }

    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    ~String() {
        delete[] data;
    }

    String operator+(const String& other) const {
        char* newData = new char[size + other.size + 1];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        for (size_t i = 0; i < other.size; ++i) {
            newData[size + i] = other.data[i];
        }
        newData[size + other.size] = '\0';
        String newString(newData);
        delete[] newData;
        return newString;
    }

    bool operator==(const String& other) const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    void print() const {
        if (data) {
            for (size_t i = 0; i < size; ++i) {
                std::cout << data[i];
            }
        }
    }
};

class BitString : public String {
private:
    bool CheckingInput(const char* str) {
        size_t i = 0;
        while (str[i] != '\0') {
            if (str[i] != '0' && str[i] != '1') {
                clear();
                return false;
            }
            ++i;
        }
        return true;
    }
public:
    BitString(const char* str) : String() {
        if (CheckingInput(str)) {
            size = 0;
            while (str[size] != '\0') {
                ++size;
            }
            data = new char[size + 1];
            for (size_t i = 0; i < size; ++i) {
                data[i] = str[i];
            }
            data[size] = '\0';
        }
    }


};

int main() {
    String s1("Hello ");
    String s2("World");
    String s3 = s1 + s2;
    s3.print();
    std::cout << std::endl;

    BitString b1("101010");
    BitString b2("1001");
    BitString b3("10a01");

    b1.print();
    std::cout << std::endl;
    b2.print();
    std::cout << std::endl;
    b3.print();

    return 0;
}