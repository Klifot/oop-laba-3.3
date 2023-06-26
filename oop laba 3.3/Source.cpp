#include <iostream>

class Matrix {
private:
    double* elements;
    int rows;
    int cols;

public:
    Matrix() : elements(nullptr), rows(4), cols(3) {
        elements = new double[rows * cols]();
    }

    Matrix(int n) : elements(nullptr), rows(n), cols(n) {
        elements = new double[rows * cols]();
    }

    Matrix(int n, int m, double value) : elements(nullptr), rows(n), cols(m) {
        elements = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            elements[i] = value;
        }
    }

    Matrix(const Matrix& other) : elements(nullptr), rows(other.rows), cols(other.cols) {
        elements = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            elements[i] = other.elements[i];
        }
    }

    ~Matrix() {
        delete[] elements;
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        delete[] elements;

        rows = other.rows;
        cols = other.cols;
        elements = new double[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            elements[i] = other.elements[i];
        }

        return *this;
    }

    double& operator()(int i, int j) {
        return elements[i * cols + j];
    }

    double operator()(int i, int j) const {
        return elements[i * cols + j];
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << elements[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix add(const Matrix& other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols, 0.0);
            for (int i = 0; i < rows * cols; i++) {
                result.elements[i] = elements[i] + other.elements[i];
            }
            return result;
        }
        else {
            // Створіть виняток або обробіть помилку іншим способом
            std::cerr << "Error: Matrix dimensions mismatch!" << std::endl;
            return Matrix();
        }
    }

    Matrix multiply(double scalar) const {
        Matrix result(rows, cols, 0.0);
        for (int i = 0; i < rows * cols; i++) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }

    Matrix subtract(const Matrix& other) const {
        if (rows == other.rows && cols == other.cols) {
            Matrix result(rows, cols, 0.0);
            for (int i = 0; i < rows * cols; i++) {
                result.elements[i] = elements[i] - other.elements[i];
            }
            return result;
        }
        else {
            // Створіть виняток або обробіть помилку іншим способом
            std::cerr << "Error: Matrix dimensions mismatch!" << std::endl;
            return Matrix();
        }
    }

    bool operator==(const Matrix& other) const {


        if (rows != other.rows || cols != other.cols) {
            return false;
        }    for (int i = 0; i < rows * cols; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }

};

int main() {
    //Тестування класу Matrix
    Matrix m1; // Конструктор за замовчуванням
    m1.print(); Matrix m2(3);  // Конструктор з розміром
    m2.print();

    Matrix m3(2, 4, 1.5);  //Конструктор з розміром і значенням
    m3.print();

    Matrix m4 = m3;  // Конструктор копіювання
    m4.print();

    Matrix m5;
    m5 = m2;  // Оператор присвоювання
    m5.print();

    std::cout << m3(1, 2) << std::endl;  // Отримати елемент у позиції (1, 2)

    Matrix m6 = m4.add(m5);  // Доповнення
    m6.print();

    Matrix m7 = m4.subtract(m5);  // Віднімання
    m7.print();

    Matrix m8 = m4.multiply(2.0);  // Множення на скаляр
    m8.print();

    if (m4 == m5) {  // Порівняння рівності
        std::cout << "m4 and m5 are equal" << std::endl;
    }
    else {
        std::cout << "m4 and m5 are not equal" << std::endl;
    }

    if (m6 != m7) {  // Порівняння нерівностей
        std::cout << "m6 and m7 are not equal" << std::endl;
    }
    else {
        std::cout << "m6 and m7 are equal" << std::endl;
    }

    return 0;

}