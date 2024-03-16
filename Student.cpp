class Student : public User{
    public:
    string rollno;
    bool courses[11];
    bool attendance;
    char tf_answers[5];
    int mcq_answers[5];
    string subjective_answers[5];

    Student(){
        name = "";
        username = "";
        password = "";
        rollno = "";
        active=0;
        attendance = 0;
        for(int i=0; i<11; i++){
            courses[i]=0;
        }
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollno<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;
    }
};