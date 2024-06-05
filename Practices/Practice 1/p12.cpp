#include <iostream>
using namespace std;

class mystring{
    public:
        mystring() {str=new char[1]; str[0] = '\0'; length = 0;}
        mystring(const char* source){
            length = 0;
            const char* ptr = source;
            while(*(ptr++) != '\0'){
                length++;
            }

            str = new char[length+1];
            for(int i=0; i<length; i++){
                str[i] = source[i];
            }
            // for(int i=0; i<length; i++){
            //     *(str+i) = *(source+i);
            // }
            // *(str+length) = '\0';
            cout << "WORKS!" << endl;
        };
        mystring(const mystring& s){
            // length = s.length; //can access private vars within class
            // str = new char[length+1];
            // for(int i=0; i<length; i++){
            //     *(str+i) = *(s.str+i);
            // }
            // *(str+length) = '\0';
            length = s.size();
            str = new char[length];
            for(int i=0; i<length; i++){
                *(str+i) = *(s.str + i);
            }
            cout << "Also Works" << endl;
        };
        mystring& operator=(const mystring& s){
            delete this->str;
            length = s.length;
            this->str = new char[length+1];
            for(int i=0; i<length; i++){
                *(str+i) = *(s.str+i);
            }
            *(str+length) = '\0';
            return* this;
        };
        ~mystring(){
            delete [] str; //needed so that you delete the new memory used when creating str array
        };
        inline int size() const{
            return length; //return length back
        };
        inline char* c_str(){
            return str;  //return c-string back
        };
    private:
        char* str;
        int length;
};

int main() {
    int i;
    mystring* s[2]; //creates an array of 2 pointers to the mylist class using
    for(i=0;i<2;i++){
        s[i] = new mystring(); //sets each of the addresses previously created to a new mystring() using the mystring() constructor
    }
    *s[0] = "Review"; //uses the assignment operator to assign *s[0] to "Review"
    *s[1] = "Session";

    mystring og("juju");
    mystring cpy = og;

    cout << s[0]->c_str() << " " << s[1]->c_str() << endl;

    *s[0] = "For";
    *s[1] = "CS32";

    cout << s[0]->c_str() << " " << s[1]->c_str() << endl;

    for(i=0;i<2;i++){
        delete s[i]; //deletes each of the addresses to the new mystrings we previously created
    }

}