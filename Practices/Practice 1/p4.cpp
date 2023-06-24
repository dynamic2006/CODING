#include <iostream>
#include <string>

using namespace std;

class student {
    public:
        student(const string &name, const double &score){
            this->name = name;
            this->score = score;
        }
        void output() {
            cout << "Student's name is: " << name << endl;
            cout << "Score is: " << score << endl;
        }
    private:
        string name;
        double score;
};

int main() {
    student s("Terry", 2.3);
    s.output();
}