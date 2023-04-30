#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum FIGURE_ENUM {
    TRIANGLE = 1,
    SQUARE = 2,
    RECTANGLE = 3,
    CIRCLE = 4
};

class Figure 
{
public:
    Figure() {};
    virtual ~Figure() {};
    virtual string getFigure() { return _figure; };

private:
    string _figure;
};

class Triandle : public  Figure 
{
public:
    explicit Triandle()
    {
        
    };
    ~Triandle() override {};
    string getFigure() override
    {
        int height = 10;
        char symbol = '$';
        for (int i = 1; i <= height; i++) {
            _figure += std::string(height - i, ' ');
            _figure += std::string(i, symbol);
            _figure += '\n';
        }

        return _figure;
    };

private:
    string _figure;
};

class Square : public  Figure
{
public:
    explicit Square() 
    {
        _figure = string(R"d(
                    **********
                    **********
                    **********
                    **********
                    **********
                        )d");
    };
    ~Square() override {};
    string getFigure() override
    {
        return _figure;
    };

private:
    string _figure;
};

class Rectangle : public  Figure
{
public:
    explicit Rectangle() 
    {
        
    };
    ~Rectangle() override {};
    string getFigure() override
    {
        _figure = string(R"d(
                    **********
                    **********
                    **********
                    **********
                    **********
                    **********
                    **********
                    **********
                    **********
                        )d");

        return _figure;
    };

private:
    string _figure = "^";
};

class Circle : public  Figure
{
public:
    explicit Circle() {};
    ~Circle() override {};
    string getFigure() override
    {
        _figure = string(R"d(
        ***
      *******
      *******
        ***
                        )d");

        return _figure;
    };

private:
    string _figure;
};

static Figure* setFigureObject(int num)
{
    Figure* obj = nullptr;

    switch (num) {
    case TRIANGLE:
        return obj = new Triandle();
    case SQUARE:
        return obj = new Square();
    case RECTANGLE:
        return obj = new Rectangle();
    case CIRCLE:
        return obj = new Circle();
    default:
        return nullptr;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Выберите фигуру и впишите её номер:\n1.Треугольник\n2.Квадрат\n3.Прямоугольник\n4.Круг\nДля выхода введите 0" << endl;

    int num = 0;
    cout << "Фигура номер: ";
    cin >> num;

    if (num == 0)
        return num;

    Figure* figure;

    figure = setFigureObject(num);

    if (figure != nullptr) {
        cout << figure->getFigure();
        delete figure; //Можно объект figure засунуть в умный указатель: тогда его в ручную можно не удалять и при при ошибке не будет утечек
    }

    cout << endl;

    return main();
}
