#include <iostream>
#include <cstring>
using namespace std;

class student {
    public:
        student(const char* name, const double& score){
            this->name = new char[strlen(name)+1];
            strcpy(this->name,name);
            this->score = score;
        }
        void output() {
            cout << "Student's name is: " << name << endl;
            cout << "Score is: " << score << endl;
        }
        ~student(){delete[] name;}

    private:
        char* name;
        double score;
};

int main() {
    student A("ABC", 100);
    student B = A;
    B.output();
    student* C = &A;
    C->output();
}