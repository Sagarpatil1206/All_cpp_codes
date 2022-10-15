
#include "Student.cpp"
#ifndef FILEOPERATION_H_
#define FILEOPERATION_H_
using namespace std;
class FileOperation {
Student student;
public:
FileOperation();
void create();
void addnew();
void display();
void search();
void modify();
void delet();
virtual ~FileOperation();
};
#endif /* FILEOPERATION_H_ */