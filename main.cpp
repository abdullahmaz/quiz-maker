#include "functions.cpp"

int main(){
    try {
        Student S[216];
        Teacher T[11];
        ImportStudents(S);
        ImportTeachers(T);
        SetUsername(S);
        SetUsernameTeacher(T);
        SetPassword(S);
        SetPasswordTeacher(T);

        menu(S,T);    
    }
    catch(...) {
        cout << "Something went wrong.\nRestarting the program!";
        sleep(2);
        main();
    }
}