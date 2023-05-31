#include <iostream>
using namespace std;
struct dateType
{
     int day;
     string month;
     int year;
     dateType *next;
};
struct addressType
{
     string streetAddress;
     string city;
     string state;
     int ZipCode;
     addressType *next;
};
struct Book
{
     string name;
     addressType address;
     string phoneNo;
     dateType date_of_birth;
     Book *next;
};
// findlin last
Book *FindlastforBOOK();
dateType *Findlastfordate();
addressType *Findlastforadress();
// finding last end edn
void print_all();
void print_data(Book *temp);

dateType *headdate = NULL;
addressType *headaddees = NULL;
Book *headBook = NULL;
void add_data_of_person_in_Book();
void AddDataIntoLinkList(string name, addressType a, string phone, dateType b);
void delete_Person_data();
void print_single_person();// kerna ha
void print_Data_Of_person_in_month();// krna  ha
main()
{
     add_data_of_person_in_Book();
     print_all();

}
void add_data_of_person_in_Book()
{
     string name, phoneNumber;
     dateType var_for_dateType;
     addressType var_for_addressType;

     cout << "Enter the name of person" << endl;
     cin >> name;
     cout << "\t\tEnter the address (details)" << endl;
     cout << "ENter the street address of person" << endl;
     cin >> var_for_addressType.streetAddress;
     cout << "ENter the city" << endl;
     cin >> var_for_addressType.city;
     cout << "ENter the state" << endl;
     cin >> var_for_addressType.state;
     cout << "ENter the ZipCode" << endl;
     cin >> var_for_addressType.ZipCode;

     cout << "\tEnter the phone number of the person" << endl;
     cin >> phoneNumber;
     cout << "\t\tEnter the date type (details)" << endl;
     cout << "ENter the day" << endl;
     cin >> var_for_dateType.day;
     cout << "Enter the month " << endl;
     cin >> var_for_dateType.month;
     cout << "Enter the year" << endl;
     cin >> var_for_dateType.year;

     AddDataIntoLinkList(name, var_for_addressType, phoneNumber, var_for_dateType);
}

Book *FindlastforBOOK()
{
     Book *temp = headBook;
     while (temp->next != NULL)
     {
          temp = temp->next;
     }
     return temp;
}

void AddDataIntoLinkList(string name, addressType a, string phone, dateType b)
{
     Book *temp = new Book;
     // dateType *temp2= new dateType;
     // addressType *temp3= new addressType;
     temp->name = name;
     temp->address.streetAddress = a.streetAddress;
     temp->address.city = a.city;
     temp->address.state = a.state;
     temp->address.ZipCode = a.ZipCode;
     temp->phoneNo = phone;
     temp->date_of_birth.day = b.day;
     temp->date_of_birth.month = b.month;
     temp->date_of_birth.year = b.year;
     temp->address.next = NULL;
     temp->date_of_birth.next = NULL;
     temp->next = NULL;
     if (headBook == NULL)
     {
          headBook = temp;
     }
     else
     {
          Book *record1 = FindlastforBOOK();
          // dateType *record2= Findlastfordate();
          // addressType *record3= Findlastforadress();
          record1->next = temp;
          // record2->date_of_birth.next= temp;
     }
}

dateType *Findlastfordate()
{

     dateType *temp = headdate;
     while (temp->next != NULL)
     {
          temp = temp->next;
     }
     return temp;
}
addressType *Findlastforadress()
{

     addressType *temp = headaddees;
     while (temp->next != NULL)
     {
          temp = temp->next;
     }
     return temp;
}
void print_data(Book *temp)
{

     cout << temp->name << " " << temp->address.streetAddress << " " << temp->address.city << " " << temp->address.state << " " << temp->address.ZipCode << " " << temp->phoneNo << " " << temp->date_of_birth.day << " " << temp->date_of_birth.month << " " << temp->date_of_birth.year << endl;
}
void print_all()
{
     Book *temp = headBook;
     while (temp != NULL)
     {
          print_data(temp);
          temp = temp->next;
     }
}

bool search(string name)
{
     Book *temp = headBook;
     while (temp != NULL)
     {
          if (name == temp->name)
          {
               return true;
          }
          temp = temp->next;
     }
     return false;
}
void print_single_person()
{
     string nameofperson;
     cout<<"enter the name of person u want to find "<<endl;
     cin>>nameofperson;
     if(search(nameofperson)==true)
     {
      print_data(headBook);    
     }

}