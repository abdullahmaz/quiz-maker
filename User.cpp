string starpassword(){
    string pass;
    for (char ch; (ch = getch()) != '\r';) {
        if (ch == '\b') {
        if (!pass.empty()) {
            pass.pop_back();
            cout << "\b";
        }
        } else {
            pass += ch;
            cout << '*';
        }
    }
    return pass;
}

class User{
    public:
    string name,username,password;
    bool active;

    void ChangePassword(){
        system("CLS");
        string temp;
        char temp_input;
        int upper,lower,digit,spch;
        upper=lower=digit=spch=0;
        cout<<"Enter new password: ";
        temp = starpassword();
        for(int i=0; temp[i]!='\0'; i++){
            if(isupper(temp[i])){
                upper++;
            }else if(islower(temp[i])){
                lower++;
            }else if(isdigit(temp[i])){
                digit++;
            }else{
                spch++;
            }
        }

        if(upper>=1 && lower>=1 && digit >=1 && spch >= 1 && temp.length()>= 6){
            cout<<"Password Successfully Changed !!!"<<endl;
            password = temp; 
        }else{
            cout<<endl<<"Invalid Password (Password Rules not followed)!!"<<endl;
        }
        cout<<endl<<"Press any button to continue ..."<<endl;  
        temp_input = getch();
        // cout<<upper<<lower<<digit<<spch<<endl;

    }
};