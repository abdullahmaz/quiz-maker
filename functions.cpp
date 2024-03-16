#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>
#include <cctype>
#include <ctime>

using namespace std;

#include "User.cpp"
#include "Quiz.cpp"
#include "Teacher.cpp"
#include "Student.cpp"

void ImportStudents(Student S[]){
    ifstream inputFile("./Course Registration Data - Sheet1.csv");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
    }

    string line;
    int row = 0, comma = 0, x = -2;
    while (getline(inputFile, line)) {
        if(row >= 2 && row <218){
            for(int i=0; line[i]!='\0'; i++){
                if(line[i]==','){
                    comma++;
                    i++;
                }
                if(comma==1){
                    S[x].rollno += line[i];
                }
                else if(comma==2){
                    S[x].name += line[i];
                }
                else if(comma==3){
                    if(line[i]=='1'){
                        S[x].courses[0] = 1;
                    }
                }
                else if(comma==4){
                    if(line[i]=='1'){
                        S[x].courses[1] = 1;
                    }
                }
                else if(comma==5){
                    if(line[i]=='1'){
                        S[x].courses[2] = 1;
                    }
                }
                else if(comma==6){
                    if(line[i]=='1'){
                        S[x].courses[3] = 1;
                    }
                }
                else if(comma==7){
                    if(line[i]=='1'){
                        S[x].courses[4] = 1;
                    }
                }
                else if(comma==8){
                    if(line[i]=='1'){
                        S[x].courses[5] = 1;
                    }
                }
                else if(comma==9){
                    if(line[i]=='1'){
                        S[x].courses[6] = 1;
                    }
                }
                else if(comma==10){
                    if(line[i]=='1'){
                        S[x].courses[7] = 1;
                    }
                }
                else if(comma==11){
                    if(line[i]=='1'){
                        S[x].courses[8] = 1;
                    }
                }
                else if(comma==12){
                    if(line[i]=='1'){
                        S[x].courses[9] = 1;
                    }
                }
                else if(line[i+1]=='\0'){
                    if(line[i]=='1'){
                        S[x].courses[10] = 1;
                    }
                }
            }
        }
        comma = 0;
        x++;
        row++;
    }
    inputFile.close();
}
void ImportTeachers(Teacher T[]){
    ifstream inputFile("./Course Registration Data - Sheet1.csv");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
    }

    string line;
    string courses[11], course_code[11];
    string name[11] = {"Sato baka1","Suzuki baka2","Takahashi baka3","Tanaka baka4","Watanabe baka5","Yamamoto baka6","Nakamura baka7","Ito baka8","Abe baka9","Mori baka10","Kato baka11"};

    int row = 0, x=0;
    getline(inputFile, line);
    for(int i=3; line[i]!='\0'; i++){
        if(line[i]==','){
            x++;
        }else{
            courses[x] += line[i];
        }
    }
    x=0;
    getline(inputFile, line);
    for(int i=25; line[i]!='\0'; i++){
        if(line[i]==','){
            x++;
        }else{
            course_code[x] += line[i];
        }
    }
    
    for(int i=0; i<11; i++){
        T[i].name = name[i];
        T[i].course = courses[i];
        T[i].course_code = course_code[i];
    }

}
void ImportTFQuestions(TF T_F[], int& count,Teacher T[]){
    srand(time(NULL));
    ifstream inputFile("./truefalse.txt");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
    }

    TF temp[5];
    int x=0,index=0,random=0;
    string line;
    int item[5]={0},indexes[5]={0};
    for(int i=0; i<5; i++){
        item[i]=i;
    }

    for(int i=5,j=0;i>0;i--,j++){
        random=rand()%i;
        indexes[j]=item[random];
        while(random<i-1){
            item[random]=item[random+1];
            random++;
        }
    }
    for(int i=0; i<11; i++){
        while (getline(inputFile, line)) {
            if(x%12==0){
                line = line.substr(0,line.length()-1);
                if(T[i].course==line && T[i].active==1){
                    T[i].quiz_active = 1;
                    x=0;
                    random=0;
                    while(getline(inputFile,line)){
                        if(line[0]=='>'){
                            break;
                        }
                        if(x%2==0){
                            temp[indexes[random]].question=line;
                        }else{
                            temp[indexes[random++]].answer=line[0];
                        }
                        x++;
                    }
                    break;
                }
            }
            x++;
        }
        inputFile.close();
        inputFile.open("./truefalse.txt");
    }
    for(int i=0; i<count; i++){
        T_F[i] = temp[i];
    }
}

void ImportMCQQuestions(MCQ mcq[], int& count,Teacher T[]){
    srand(time(NULL));
    ifstream inputFile("./mcqs.txt");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
    }

    MCQ temp[5];
    int x=0,index=0,random=0,temp1=0;
    string line;
    int item[5]={0},indexes[5]={0};
    for(int i=0; i<5; i++){
        item[i]=i;
    }

    for(int i=5,j=0;i>0;i--,j++){
        random=rand()%i;
        indexes[j]=item[random];
        while(random<i-1){
            item[random]=item[random+1];
            random++;
        }
    }
    // for(int i=0; i<count; i++){
    //     cout<<indexes[i]<<" ";
    // }

    for(int i=0; i<11; i++){
        // cout<<T[i].active<<endl;
        while (getline(inputFile, line)) {
            if(x%32==0){
                line = line.substr(0,line.length()-1);
                // cout<<T[i].course.length()<<":"<<line.length()<<endl;
                if(T[i].course==line && T[i].active==1){
                    T[i].quiz_active = 1;
                    x=0;
                    random=0;
                    while(getline(inputFile,line)){
                        if(line[0]=='>'){
                            break;
                        }
                        if(x%6 == 0){
                            temp[indexes[random]].question=line;
                        }else{
                            if(temp1==4){
                                temp[indexes[random++]].answer=line;
                                temp1=0;
                            }else{
                                // cout<<line<<endl;
                                temp[indexes[random]].options[temp1++]=line;
                            }
                        }
                        x++;
                    }
                    break;
                }
            }
            x++;
        }
        inputFile.close();
        inputFile.open("./mcqs.txt");
    }
    for(int i=0; i<count; i++){
        mcq[i] = temp[i];
    }
}

void ImportSubjectiveQuestions(Subjective subj[], int& count,Teacher T[]){
    srand(time(NULL));
    ifstream inputFile("./subjective.txt");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
    }

    Subjective temp[5];
    int x=0,index=0,random=0;
    string line;
    int item[5]={0},indexes[5]={0};
    for(int i=0; i<5; i++){
        item[i]=i;
    }

    for(int i=5,j=0;i>0;i--,j++){
        random=rand()%i;
        indexes[j]=item[random];
        while(random<i-1){
            item[random]=item[random+1];
            random++;
        }
    }
    for(int i=0; i<11; i++){
        inputFile.close();
        ifstream inputFile("./subjective.txt");
        while (getline(inputFile, line)) {
            if(x%12==0){
                // cout<<T[i].course<<endl;
                // line = line.substr(0,line.length()-1);
                // cout<<T[i].course<<":"<<line<<endl;
                if(T[i].course==line && T[i].active==1){
                    // cout<<line<<endl;
                    T[i].quiz_active = 1;
                    x=0;
                    random=0;
                    while(getline(inputFile,line)){
                        if(line[0]=='>'){
                            break;
                        }
                        if(x%2==0){
                            temp[indexes[random]].question=line;
                        }else{
                            temp[indexes[random++]].answer=line;
                        }
                        x++;
                    }
                    break;
                }
            }
            x++;
        }
    }
    for(int i=0; i<count; i++){
        subj[i] = temp[i];
    }
}

void SetUsername(Student S[]){
    int j=0;
    for(int i=0; i<11; i++){
        for(; S[i].name[j]!=' ';){
            S[i].username += S[i].name[j++];
        }
        j=0;
        S[i].username += S[i].rollno.substr(4);
    }
}
void SetUsernameTeacher(Teacher T[]){
    int j=0;
    for(int i=0; i<11; i++){
        for(; T[i].name[j]!=' ';){
            T[i].username += T[i].name[j++];
        }
        j=0;
        T[i].username += T[i].course_code.substr(3);
    }
}

void SetPassword(Student S[]){
    int temp=0;
    for(int i=0; i<216; i++){
        for(int j=0; S[i].name[j]!='\0'; j++){
            if(S[i].name[j]==' '){
                break;
            }else{
                temp++;
            }
        }
        for(int j=temp+1; S[i].name[j]!='\0'; j++){
            S[i].password += S[i].name[j];
        }
        S[i].password += "123";
        temp=0;
    }
}
void SetPasswordTeacher(Teacher T[]){
    int temp=0;
    for(int i=0; i<11; i++){
        for(int j=0; T[i].name[j]!='\0'; j++){
            if(T[i].name[j]==' '){
                break;
            }else{
                temp++;
            }
        }
        for(int j=temp+1; T[i].name[j]!='\0'; j++){
            T[i].password += T[i].name[j];
        }
        T[i].password += "123";
        temp=0;
    }
}

bool CheckUsername(int x, int& index,string& temp, Student S[], Teacher T[]){
    string temp2;
    if(x==1){
        for(int i=0; i<11; i++){
            temp2 = T[i].username;
            if(temp == temp2){
                index = i;
                return 1;
            }
        }
    }else{
        for(int i=0; i<216; i++){
        temp2 = S[i].username;
            if(temp == temp2){
                index = i;
                return 1;
            }
        }
    }
    return 0;
}

bool CheckPassword(int x, string& temp, string& temp1, Student S[], Teacher T[]){
    if(x==1){
        for(int i=0; i<11; i++){
            if(temp == T[i].username){
                if(temp1 == T[i].password){
                    return true;
                }
            }
        }
    }else{
        for(int i=0; i<216; i++){
            if(temp == S[i].username){
                if(temp1 == S[i].password){
                    return true;
                }
            }
        }
    }
    return false;
}
bool timercheck(int start, int end, int timer){
    int difference = difftime(end, start);
    int temp = timer - difference;
    if(temp<=0){
        system("CLS");
        cout<<"Time has ended!!"<<endl;
        return true;
    }
    return false;
}

long long toTimestamp(int day, int month, int year, int hour, int minute, int second){
    struct tm tm;
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;

    time_t time = mktime(&tm);
    return time;
}

int InputDateTime(long long &s, long long &e){
    int day, month, year, hour, minute, second;

    cout << "Enter date in the format MM/DD/YYYY: ";
    cin >> month >> day >> year ;
    cout << "Enter time in the format HH:MM:SS: ";
    cin >> hour >> minute >> second;

    if (month < 1 || month > 12) {
      cout << "Invalid month" << endl;
      return 1;
    }
    if (day < 1 || day > 31) {
      cout << "Invalid day" << endl;
      return 1;
    }
    if (year < 1900 || year > 2100) {
      cout << "Invalid year" << endl;
      return 1;
    }
    if (hour < 0 || hour > 23) {
      cout << "Invalid hour" << endl;
      return 1;
    }
    if (minute < 0 || minute > 59) {
      cout << "Invalid minute" << endl;
      return 1;
    }
    if (second < 0 || second > 59) {
      cout << "Invalid second" << endl;
      return 1;
    }
    s = toTimestamp(day, month, year, hour, minute, second);
    e = toTimestamp(day, month, year, hour+1, minute, second);
    return 1;
}

void MakeQuiz(Teacher T[]){
    char temp_input;
    for(int i=0; i<11; i++){
        if(T[i].active && T[i].quiz_active){
            cout<<"Quiz has already been made !"<<endl;
            break;
        }
        if(T[i].active && (T[i].quiz_active==0)){
            int c1,c2,c3,time;
            c1=c2=c3=0;
            cout<<"How many T/F questions do you want (1-5): ";
            cin>>c1;
            cout<<"How many MCQ's do you want (1-5): ";
            cin>>c2;
            cout<<"How many Subjective questions do you want (1-5): ";
            cin>>c3;
            cout<<"Duration of Quiz(seconds): ";
            cin>>time;
            Quiz X(c1,c2,c3,time);
            InputDateTime(X.start,X.end);
            ImportTFQuestions(X.TFQuestions,c1,T);
            ImportMCQQuestions(X.MCQQuestions,c2,T);
            ImportSubjectiveQuestions(X.SubjectiveQuestions,c3,T);
            T[i].Q = X;
            X.display();
            cout<<endl<<"Quiz successfully created !!"<<endl;
            break;
        }
    }
    cout<<endl<<"Press any button to continue ..."<<endl;  
    temp_input = getch();
    return;
}
void AttemptQuiz(Teacher T[], Student S[]){
    int input,input1,temp=0, total_questions,x=0,timer = 10;
    time_t start,end,current_time;
    char temp_input;
    bool flag = false, flag1 = false, timeup = false;
    int indexes[11]{0};
    system("CLS");
    cout<<"Courses: "<<endl;
    for(int i=0; i<11; i++){
        for(int j=0; j<216; j++){
            if(S[j].active && S[j].courses[i]){
                cout<<x+1<<". "<<T[i].course<<endl;
                indexes[x++]=i;
            }
        }
    }
    cout<<"Which course? (1,2,3......) "<<endl;
    cin>>input;

    for(int i=0; i<216; i++){
        if(S[i].active && S[i].courses[indexes[input-1]] && T[indexes[input-1]].quiz_active){
            flag1 = true;
            current_time = time(0);
            if(current_time < T[indexes[input-1]].Q.start){
                cout<<"Quiz hasn't started yet!"<<endl;
                break;
            }else if(current_time > T[indexes[input-1]].Q.end){
                cout<<"Quiz has expired!"<<endl;
                break;
            }else{
                cout<<"!!! Quiz Available !!!"<<endl;
                cout<<"Start ? (1/0): ";
                cin>>input1;
            }
            if(input1==0){
                return;
            }
            start = time(NULL);

            flag = true;
            S[i].attendance = 1;
            total_questions = T[indexes[input-1]].Q.totalquestions;
            timer = T[indexes[input-1]].Q.time;
            T[indexes[input-1]].Q.marks[i]=0;
            temp = i;

            system("CLS");

            if(input == 0)
                return;

            cout<<T[indexes[input-1]].course<<" Quiz"<<endl<<"Course Instructor: "<<T[indexes[input-1]].name<<endl<<endl;
            cout<<"T/F Questions: "<<endl;
            for(int k=0; k<T[indexes[input-1]].Q.tf_count; k++){
                end = time(NULL);
                if(timercheck(start,end,timer)){
                    timeup = true;
                    break;
                }
                cout<<k+1<<". "<<T[indexes[input-1]].Q.TFQuestions[k].question<<endl;
                cout<<"True of False? (1/0): ";
                cin>>S[i].tf_answers[k];
                cout<<endl;
                if(S[i].tf_answers[k] == T[indexes[input-1]].Q.TFQuestions[k].answer){
                    T[indexes[input-1]].Q.marks[i] += 1;
                    if(T[indexes[input-1]].Q.barGraphPerQuestion[k] == -1)
                        T[indexes[input-1]].Q.barGraphPerQuestion[k] = 1;
                    else    
                        T[indexes[input-1]].Q.barGraphPerQuestion[k] += 1;
                }
            }
            if(timeup == false){
                cout<<endl<<"MCQ's: "<<endl;
                for(int k=0; k<T[indexes[input-1]].Q.mcq_count; k++){
                    end = time(NULL);
                    if(timercheck(start,end,timer)){
                        timeup = true;
                        break;
                    }
                    cout<<k+1<<". "<<T[indexes[input-1]].Q.MCQQuestions[k].question<<endl;
                    cout<<"Options: "<<endl;
                    for(int l=0; l<4; l++){
                        cout<<l+1<<". "<<T[indexes[input-1]].Q.MCQQuestions[k].options[l]<<endl;
                    }
                    cout<<"Select Option (1-4)"<<endl;
                    cin>>S[i].mcq_answers[k];
                    if(T[indexes[input-1]].Q.MCQQuestions[k].options[S[i].mcq_answers[k]-1] == T[indexes[input-1]].Q.MCQQuestions[k].answer){
                        T[indexes[input-1]].Q.marks[i] += 1;
                        T[indexes[input-1]].Q.barGraphPerQuestion[k+5] += 1;
                        if(T[indexes[input-1]].Q.barGraphPerQuestion[k+5] == -1)
                            T[indexes[input-1]].Q.barGraphPerQuestion[k+5] = 1;
                        else    
                            T[indexes[input-1]].Q.barGraphPerQuestion[k+5] += 1;
                    }
                }
            }
            if(timeup == false){
                cout<<endl<<"Subjective Questions: "<<endl;
                cin.ignore( 2, '\n');
                for(int k=0; k<T[indexes[input-1]].Q.subjective_count; k++){
                    end = time(NULL);
                    if(timercheck(start,end,timer)){
                        timeup = true;
                        break;
                    }
                    cout<<k+1<<". "<<T[indexes[input-1]].Q.SubjectiveQuestions[k].question<<endl;
                    getline(cin,S[i].subjective_answers[k]);
                    int count = 0;
                    for(int l=0; S[i].subjective_answers[k][l]!='\0'; l++){
                        if(S[i].subjective_answers[k][l] ==' ' || S[i].subjective_answers[k][l]=='\0'){
                            T[indexes[input-1]].Q.marks[i] += 0.01;
                        }
                    }
                }
            }
        }
    }
    if(flag){
        cout<<endl<<"Obtained Marks: "<<T[indexes[input-1]].Q.marks[temp]<<"/"<<total_questions<<endl;
    }
    if(flag1==false){
        cout<<"No Quizzes are available at the moment"<<endl;
    }
    cout<<endl<<"Press any button to continue ..."<<endl;
    temp_input = getch();

}

void MarkSheet(Teacher T[], Student S[]){
    char temp;
    ofstream myfile("./marksheet.txt",ios::trunc | ios::out);
    // cout<<"\tNAME\t\t||\tMARKS"<<endl;
    myfile<<left<<setw(24)<<"NAME"<<setw(24)<<left<<"MARKS"<<endl;
    for(int i=0; i<216; i++){
        for(int j=0; j<11; j++){
            if(S[i].courses[j] && T[j].active){
                // cout<<"\t"<<S[i].name<<"\t||\t"<<S[i].marks<<endl;
                if(T[j].Q.marks[i]==100){
                    myfile<<left<<setw(24)<<S[i].name<<setw(24)<<left<<"0"<<endl;
                }else{
                    myfile<<left<<setw(24)<<S[i].name<<setw(24)<<left<<T[j].Q.marks[i]<<endl;
                }
            }
        }
    }
    myfile.close();
    cout<<"Mark Sheet Generated !!"<<endl;
    cout<<endl<<"Press any button to continue ..."<<endl;
    temp = getch();
}
void Attendance(Teacher T[], Student S[]){
    system("CLS");
    char temp_input;
    char att;
    bool flag = false;
    ofstream myfile("./attendancesheet.txt",ios::trunc | ios::out);
    myfile<<left<<setw(24)<<"Name"<<setw(24)<<left<<"Attendance"<<endl;
    for(int i=0; i<11; i++){
        for(int j=0; j<216; j++){
            if(T[i].active && S[j].courses[i]){
                if(S[j].attendance){
                    att='P';
                }else{
                    att='A';
                }
                myfile<<left<<setw(24)<<S[j].name<<setw(24)<<left<<att<<endl;
            }
        }
        if(flag){
            return;
        }
    }
    myfile.close();
}

void TeacherMenu(Teacher T[], Student S[]){
    int option;
    bool flag = false;
    char temp;
    while(1){
        system("CLS");
        cout<<"------------------------------------"<<endl;
        cout<<"\tMAIN MENU"<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<endl<<"1. Make Quiz"<<endl;
        cout<<endl<<"2. Change Password"<<endl;
        cout<<endl<<"3. Generate Mark Sheet"<<endl;
        cout<<endl<<"4. Generate Attendance"<<endl;
        cout<<endl<<"5. See Bar Graph"<<endl;
        cout<<endl<<"6. Sign Out"<<endl<<endl;
        
        cout<<"Select Option: "<<endl;
        cin>>option;

        if(option == 1){
            system("CLS");
            MakeQuiz(T);
        }else if(option == 2){
            for(int i=0; i<11; i++){
                if(T[i].active){
                    T[i].ChangePassword();
                    break;
                }
            }
        }else if(option == 3){
            for(int i=0; i<11; i++){
                if(T[i].active && T[i].quiz_active){
                    system("CLS");
                    MarkSheet(T,S);
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                system("CLS");
                cout<<"You haven't made a quiz yet !"<<endl;
                cout<<endl<<"Press any button to continue ..."<<endl;
                temp = getch();
            }

        }else if(option == 4){
            Attendance(T,S);
            cout<<"Attendance Sheet Generated !!"<<endl;
            cout<<endl<<"Press any button to continue ..."<<endl;
            temp = getch();  
        }else if(option == 5){
            system("CLS");
            for(int i=0; i<11; i++){
                if(T[i].active){
                    if(T[i].quiz_active)
                        T[i].Q.printGraph();
                    else
                        cout<<"You haven't made a quiz yet !"<<endl;
                        
                    break;
                }
            }
            cout<<endl<<"Press any button to continue ..."<<endl;
            temp = getch();  
        }else if(option == 6){
            for(int i=0; i<11; i++){
                if(T[i].active){
                    T[i].active = 0;
                }
                break;
            }
            break;
        }else{
            cout<<"Incorrect Option !"<<endl;
        }
    }
}

void StudentMenu(Teacher T[], Student S[]){
    int option;
    while(1){
        system("CLS");
        cout<<"------------------------------------"<<endl;
        cout<<"\tMAIN MENU"<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<endl<<"1. Change Password"<<endl;
        cout<<endl<<"2. Check available Quizzes"<<endl;
        cout<<endl<<"3. Sign Out"<<endl<<endl;
        cout<<"Select Option: "<<endl;
        cin>>option;
        if(option == 1){
            for(int i=0; i<216; i++){
                if(S[i].active){
                    S[i].ChangePassword();
                    break;
                }
            }
        }else if(option == 2){
            AttemptQuiz(T,S);
        }else if(option == 3){
            for(int i=0; i<216; i++){
                if(S[i].active){
                    S[i].active = 0;
                    break;
                }
            }
            return;
        }else{
            return;
        }
    }
}

bool login(int x, Student S[], Teacher T[]){
    system("CLS");
    string temp,temp1;
    int index;
    while(1){
        cout<<"Enter Username: ";
        cin>>temp;    
        cout<<"Enter Password: ";
        temp1 = starpassword();

        if(CheckUsername(x,index,temp,S,T) && CheckPassword(x,temp,temp1,S,T)){
            system("CLS");
            if(x==1){
                T[index].active = 1;
                TeacherMenu(T,S);
            }else{
                S[index].active = 1;
                StudentMenu(T,S);
            }
            return true;
        }else{
            system("CLS");
            cout<<"Invalid Username/Password\n\nRemember:\nTeacher Username Format: firstnamecoursecode\nStudent Username Format: firstnamerollnumber (without batch number)\n\n";
        }
    }
    return false;
}

void menu(Student S[], Teacher T[]){
    int option;
    bool flag = false;
    while(1){
        system("CLS");
        cout<<"------------------------------------"<<endl;
        cout<<"\tTHE PORTAL"<<endl;
        cout<<"------------------------------------"<<endl;
        if(flag){
            cout<<"Please choose an available option ! "<<endl;
            flag = false;
        }
        cout<<"1. Teacher"<<endl;
        cout<<"2. Student"<<endl;
        cout<<"3. Exit"<<endl<<endl;

        cout<<"Select Option: "<<endl;
        cin>>option;

        if(option==1 || option ==2){
            login(option, S, T);
        }else if(option == 3){
            return;
        }else{
            flag = true;
            cin.clear();
            cin.ignore();
        }
    }
}