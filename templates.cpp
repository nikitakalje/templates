#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
  string name;
  int id;
  float gpa;

  bool operator<(Student s)
  {

    return (this->gpa<s.gpa);
  };
};
class IntSet {
public:
  void Set() { data.clear(); };
  void Insert(int val) {
    if (Find(val)) return;
    data.push_back(val);
  };
  bool Find(int val) {
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == val) {
        return true;
      }
    }
    return false;
  };
  int GetSize() { return data.size(); };
  void Print() {
    for (int i = 0; i < data.size(); i++) {
      cout << data[i];
    }
    cout << endl;
  };
private:
  vector<int> data;
};


template <class T> class TemSet
{
public:
  void Set() { data.clear(); };
  void Insert(T val) {
    if (Find(val)) return;
    data.push_back(val);
  };
  bool Find(T val) {
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == val) {
        return true;
      }
    }
    return false;
  };
  int GetSize() { return data.size(); };
  void Print() {
    cout<<"name, size, gpa"<<endl;
    for (int i = 0; i < data.size(); i++) {
      cout << data[i];
    }
    cout << endl;

  };
  void Sort()
  {
    int size=GetSize();
    T temp;
    for(int i=0; i<size;i++)
    {
      if(data[i]<data[i+1])
      {
        temp=data[i];
        data[i]=data[i+1];

        data[i+1]=temp;
      }

    }
  };

private:
  vector<T> data;
};

//ostream operator
ostream& operator<<(ostream& os, Student s)
{
  os<<s.name<<endl;
  os<<s.id<<endl;
  os<<s.gpa<<endl;

  return os;
}

bool operator==(Student s, Student s1)
{
  return(s.gpa==s1.gpa);
}



template <class T> class TemOrSet: public TemSet<T>
{
public:
  void Insert(T val) {
    if (this->Find(val)) return;

    TemSet<T>::Insert(val);
    TemSet<T>::Sort();
  };
};

int main() {

  TemSet<int> s1;
  s1.Insert(7);
  s1.Insert(5);
  s1.Insert(5);
  s1.Insert(1);
  s1.Insert(7);
  cout << "Set size is: " << s1.GetSize() << endl;
  if (s1.Find(7)) cout << "7 found" << endl;
  if (s1.Find(2)) cout << "2 found" << endl;

  TemOrSet<Student> s2;

  Student t1 = { "Ann", 17, 4.0 };
  Student t2 = { "Bob", 5, 2.6 };
  Student t3 = { "Chris", 26, 3.7 };
  Student t4 = { "David", 9871, 3.9 };
  s2.Insert(t1);
  s2.Insert(t1);
  s2.Insert(t2);
  s2.Insert(t2);
  s2.Insert(t1);
  s2.Insert(t3);
  cout << "Set size is: " << s2.GetSize() << endl;
  s2.Print();
  //if (s2.TemSet<Student>::Find(t3)) cout << "t3 found" << endl;
  if (s2.Find(t3)) cout << "t3 found" << endl;
  if (s2.Find(t4)) cout << "t4 found" << endl;

  return 0;
}
