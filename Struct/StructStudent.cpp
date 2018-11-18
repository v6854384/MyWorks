#include<iostream>

struct Student {
        std::string fio;
        std::string date;
        unsigned int course;
        unsigned int group;
};

int main() {
        Student st1;
        st1.fio="Ivanchenko Viktor Aleksandrovich";
        st1.date="20/08/99";
        st1.course=1;
        st1.group=13;
        Student*st2=new Student;
        (st2).fio=st1.fio;
        st2->st1.fio;
        Student st3={st1.fio, "20/08/99", 1, 13};
}
