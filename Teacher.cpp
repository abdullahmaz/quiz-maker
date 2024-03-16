class Teacher : public User{
    public:
    string course, course_code;
    bool quiz_active;
    Quiz Q;

    Teacher(){
        name = "";
        username = "";
        password = "";
        course = "";
        course_code = "";
        active=0;
        quiz_active=0;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Course Code: "<<course_code<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;
    }
    
};