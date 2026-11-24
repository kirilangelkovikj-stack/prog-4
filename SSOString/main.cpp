#include <iostream>
#include <cstring>
using namespace std;

class SSOString {
private:
    char* array;
    short _size;
    short _cap;

public:
    SSOString(const char* str = "") {
        _size = strlen(str);
        _cap = _size;
        array = new char[_cap + 1];
        strcpy(array, str);
    }

    SSOString(const SSOString& other) {
        _size = other._size;
        _cap = other._cap;
        array = new char[_cap + 1];
        strcpy(array, other.array);
    }

    ~SSOString() {
        delete[] array;
    }

    SSOString& operator=(const SSOString& other) {
        if (this != &other) {
            delete[] array;
            _size = other._size;
            _cap = other._cap;
            array = new char[_cap + 1];
            strcpy(array, other.array);
        }

        return *this;
    }
    char& operator[](int index) {
        return array[index];
    }
    const char& operator[](int index) const {
        return array[index];
    }
    short size() const {
        return _size;
    }
    short capacity() const {
        return _cap;
    }
    SSOString operator+(const SSOString& other) const {
        char* temp = new char[_size + other._size + 1];
        strcpy(temp, array);
        strcat(temp, other.array);
        SSOString result(temp);
        delete[] temp;
        return result;
    }
};

int main() {
     char a[100], b[100];
     cin >> a;
     cin >> b;

     SSOString s1(a);
     SSOString s2(b);
     SSOString s3=s1+s2;
     cout << "Spoen string: ";
     for (int i = 0; i < s3.size(); i++) {
         cout << s3[i];
     }
     cout<<endl;
     cout<<s3.size()<<endl;
     cout<< s3.capacity()<<endl;
     return 0;
 }

