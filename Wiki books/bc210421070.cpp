#include <iostream>
#include <string.h>
using namespace std;

class student{
    private:
        char std_id[20];
        char vac_name[10];
        int age;
        int num_dose;

    public:
    student();
    student(char Students_id[], char Vaccine[], int Age, int Dose);

    void setName(char Students_id[])
    {
        strcpy(std_id, Students_id);
    }
    void setAge(int Age)
    {
        age = Age;
    }
    void setVaccine(char Vaccine[])
    {
        strcpy(vac_name, Vaccine);
    }
    void setDose(int Dose)
    {
        num_dose = Dose;
    }
    void getName()
    {
        cout << "Student ID: " << std_id << endl;
    }
    void getAge()
    {
        cout << "Age: " << age << endl;
    }
    void getVaccine()
    {
        cout << "Vaccine: " << vac_name << endl;
    }
    void getDose()
    {
        cout << "Dose: " << num_dose << endl;
    }
    friend void display(student std1, student std2);
};

student::student()
{
    strcpy(std_id, "BC210421070");
    strcpy(vac_name, "Sinopharm");
    age = 21;
    num_dose = 2;
}

student::student(char Students_id[], char Vaccine[], int Age, int Dose)
{
    strcpy(std_id, Students_id);
    strcpy(vac_name, Vaccine);
    age = Age;
    num_dose = Dose;
}

void display(student std1, student std2)
{
    cout << "Printing std1 object values using display()..." << endl;
    cout << "Student ID: " << std1.std_id << endl;
    cout << "Age: " << std1.age << endl;
    cout << "Vaccine: " << std1.vac_name << endl;
    cout << "Dose: " << std1.num_dose << endl;
    cout << " " << endl;

    cout << "Printing std2 object values using display()..." << endl;
    cout << "Student ID: " << std2.std_id << endl;
    cout << "Age: " << std2.age << endl;
    cout << "Vaccine: " << std2.vac_name << endl;
    cout << "Dose: " << std2.num_dose << endl;
    cout << " " << endl;
}

int main()
{
    char student_2_id[20] = "BC123456789";
    int student_2_age= 21;
    char student_2_vaccine[10] = "Sinopharm";
    int student_2_dose = 2;
    
    student std1, std2(student_2_id, student_2_vaccine, student_2_age, student_2_dose);
    display(std1, std2);

    char id[20]="MC123456789";
    int age=22;
    char vaccine[10]="Moderna";
    int dose=3;
    student std3(id, vaccine, age, dose);
    std3.setName(id);
    std3.setAge(age);
    std3.setVaccine(vaccine);
    std3.setDose(dose);

    cout<<" "<<endl;
    cout<<"Printing std3 object values using getter() method..."<<endl;
    std3.getName();
    std3.getAge();
    std3.getVaccine();
    std3.getDose();
    cout<<" "<<endl;

    return 0;
}
