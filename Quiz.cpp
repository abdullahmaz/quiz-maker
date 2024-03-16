class TF{
    public:
    string question;
    char answer;

    TF(){
        question="";
        answer=0;
    }
};

class MCQ{
    public:
    string question,answer;
    string options[4];
    MCQ(){
        question="";
    }

};
class Subjective{
    public:
    string question,answer;
    Subjective(){
        question=answer="";
    }
};

class Quiz{
    public:
    TF TFQuestions[5];
    MCQ MCQQuestions[5];
    Subjective SubjectiveQuestions[5];
    long long start,end;
    int time;
    float marks[216];
    int barGraphPerQuestion[10];
    int totalquestions,tf_count,mcq_count,subjective_count;

    Quiz(){
        start = end = 0;
        totalquestions = time = 0;
        for(int i=0; i<216; i++){
            marks[i]=100;
        }
        for(int i=0; i<10; i++){
            barGraphPerQuestion[i]=-1;
        }
    }

    Quiz(int c1,int c2,int c3,int t){
        totalquestions = time = 0;
        start = end = 0;
        time = t;
        tf_count = c1;
        mcq_count = c2;
        subjective_count = c3;
        totalquestions = c1 + c2 + c3;
        for(int i=0; i<216; i++){
            marks[i]=100;
        }
        for(int i=0; i<10; i++){
            barGraphPerQuestion[i]=-1;
        }
    }

    void printGraph(){
        for (int i = 0; i < 5; i++) {
            if(barGraphPerQuestion[i] == -1)
                continue;
            cout<<"True/False Q"<<i+1<<": |";
            for (int j = 0; j<barGraphPerQuestion[i]; j++){
                cout<<"=";
            }
            cout<<endl;
        }
        for (int i = 0; i < 5; i++) {
            if(barGraphPerQuestion[i+5] == -1)
                continue;
            cout<<"MCQs Q"<<i+1<<":       |";
            for (int j = 0; j<barGraphPerQuestion[i+5]; j++){
                cout<<"=";
            }
            cout<<endl;
        }
    }

    void display(){
        cout<<endl<<"T/F Questions: "<<endl;
        for(int i=0; i<tf_count; i++){
            cout<<TFQuestions[i].question<<endl;
        }
        cout<<endl<<"Answers: "<<endl;
        for(int i=0; i<tf_count; i++){
            cout<<TFQuestions[i].answer<<endl;
        }
        cout<<endl<<"MCQ Questions: "<<endl;
        for(int i=0; i<mcq_count; i++){
            cout<<MCQQuestions[i].question<<endl;
            cout<<"Answer: "<<MCQQuestions[i].answer<<endl;
        }
        
        cout<<endl<<"Subjective Questions: "<<endl;
        for(int i=0; i<subjective_count; i++){
            cout<<SubjectiveQuestions[i].question<<endl;
            cout<<"Answer: "<<SubjectiveQuestions[i].answer<<endl;
        }
    }
    ~Quiz(){
        
    }

};