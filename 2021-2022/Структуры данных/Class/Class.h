#define CLASS_H
#include <string>
#include <iostream>
using namespace std;

class arts // имя класса
{
private:
    string _name_of_art;
    string _author;
    int _date_of_create;
    int _price;
public:
    arts();
    arts(string, string, int, int);
    arts(const arts& art);
    ~arts();

    friend ostream& operator<<(ostream&, const arts&);
    friend istream& operator>>(istream&, arts&);

    void set_name_of_art(string name_of_art) { _name_of_art = name_of_art; }
    string get_name_of_art() const { return _name_of_art; }

    bool operator >(const arts& obj);
    arts operator --(int);
}; 

inline ostream& operator<<(ostream& output, const arts& art) {
    output << "art " << art._name_of_art << "\n";
    output << "author " << art._author << "\n";
    output << "date " << art._date_of_create << "\n";
    output << "price " << art._price << "\n";
    return output;
}

inline istream& operator>>(istream& input, arts& art) {
    cout << "Название картины" << "\n";
    input >> art._name_of_art;
    cout << "Имя автора" << "\n";
    input >> art._author;
    cout << "Дата написания" << "\n";
    input >> art._date_of_create;
    cout << "Стоимость" << "\n";
    input >> art._price;
    return input;
}


#endif
