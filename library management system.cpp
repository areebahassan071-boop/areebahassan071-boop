//areeba
//SU91-BIETM-F23-038
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
class library;
//class of book
class Book
{
	protected:
		string title;
		string authur;
		string isbn;
		int publication_year;
		string type;
		bool borrow;
	public:
		Book(const string& t, const string& a, const string& i, int p, const string& ty)
		: title(t), authur(a), isbn(i), publication_year(p), type(ty), borrow(false) {}
		void borrowed()
		{
			if (!borrow)
			{
				borrow=true;
				cout<<title<<" is borrowed"<<endl;
			}
			else
			{
				cout<<title<<" is already borrowed"<<endl;
			}
		}
		void returned()
		{
			if (borrow)
			{
				borrow=false;
				cout<<title<<" is return"<<endl;
			}
			else
			{
				cout<<title<<" is not borrowed"<<endl;
			}
		}
		string getISBN() const
		{
			return isbn;
		}
			string gtitle() const
		{
			return title;
		}
			string gauthur() const
		{
			return authur;
		}
			string gtype() const
		{
			return type;
		}
			int gpublication_year() const
		{
			return publication_year;
		}
	
		
		
		~Book(){}
	void file_book()
	{
	    ofstream file("book.txt",ios::app);
		if(file.is_open())
		{
			file<<"title: "<<title<<" authur: "<<authur<<" isbn: "<<isbn<<" publication year: "<<publication_year<<" type: "<<type<<endl;
			file.close();
		}
		else
		{
			cout<<"file is not created"<<endl;
		}
	}
  static void remove_from_file(const string& isbn) 
   {
        ifstream inFile("book.txt");
        ofstream outFile("book.txt");
        string line;
        bool found = false;

        while (getline(inFile, line)) 
		{
            if (line.find(isbn) == string::npos) 
			{
                outFile << line << endl;  
            } else 
			{
                found = true;  
            }
        }
        inFile.close();
        outFile.close();
        remove("book.txt");      
        rename("temp.txt", "book.txt");  
        if (found) 
		{
            cout << "Book with ISBN " << isbn << " removed from file." << endl;
        } else 
		{
            cout << "Book with ISBN " << isbn << " not found in file." << endl;
        }
    }
    static void updatebook(const Book& updatedBook)
	{
		
		ifstream file("books.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            if (line.find(updatedBook.getISBN()) == string::npos) 
			{
                temp<<line<<endl;
            } 
			else 
			{
                temp<<updatedBook.gtitle()<<" , "<<updatedBook.gauthur()<<" , "<<updatedBook.getISBN()<<" , "<<updatedBook.gpublication_year()<<" , "<<updatedBook.gtype()<<endl;
            }
        }
        file.close();
        temp.close();
        ::remove("books.txt");
        rename("temp.txt", "books.txt");
    }
				
};
//subclass of book
class fiction: public Book
{
	private: 
	string genre;
	public:
		fiction(const string& g, const string& t, const string& a, const string& i, int p, const string& ty): Book(t, a, i, p, ty), genre(g) {}
		string getgenre()const
		{
			return genre;
		}
		~fiction(){}
		void file_book()
		{
			ofstream file("book.txt",ios::app);
			if(file.is_open())
			{
				file<<"title: "<<title<<" authur: "<<authur<<" isbn: "<<isbn<<" publication year: "<<publication_year<<" type: "<<type<<" genre: "<<genre<<endl;
				file.close();
			}
			else
			{
				cout<<"file is not created"<<endl;
			}
		}
		
};
//subclass of book
class non_fiction :public Book
{
	private: 
	string subject;
	public:
		non_fiction(const string& t, const string& a, const string& i, int p, const string& ty, const string& s)
		: Book(t, a, i, p, ty), subject(s) {}
		string  getsubject() const
		{
			return subject;
		}
		~non_fiction(){}
		void file_book()
		{
			ofstream file("book.txt",ios::app);
			if(file.is_open())
			{
				file<<"title: "<<title<<" authur: "<<authur<<" isbn: "<<isbn<<" publication year: "<<publication_year<<" type: "<<type<<" subject: "<<subject<<endl;
				file.close();
			}
			else
			{
				cout<<"file is not created"<<endl;
			}
			}
};
//subclass of book
class reference :public Book
{
	private: 
	string edition;
	public:
        reference(const string& t, const string& a, const string& i, int p, const string& ty, const string& e)
		: Book(t, a, i, p, ty), edition(e) {}
		string getedition() const
		{
			return edition ;
		}
		~reference(){}
		void file_book()
		{
			ofstream file("book.txt",ios::app);
			if(file.is_open())
			{
				file<<"title: "<<title<<" authur: "<<authur<<" isbn: "<<isbn<<" publication year: "<<publication_year<<" type: "<<type<<" edition: "<<edition<<endl;
				file.close();
			}
			else
			{
				cout<<"file is not created"<<endl;
			}
			}
};
//class of member
class Member
{
	protected:
		string name;
		int id;
		string membership_type;
		Book* borrowed_book;
		int numBooks;
	public:
        Member(const string& n, int i, const string& m)
	: name(n), id(i), membership_type(m){}
	string get_name()const 
	{
		return name;
	}
	int get_id() const 
	{
		return id;
	}
	string get_membership_type() const 
	{
		return membership_type;
	}
    void borrowBook(const Book& k)
	{
        if (numBooks < 10)
		{
            borrowed_book[numBooks++] = k;
            cout << "Book borrowed: " << k.gtitle() << " by " << k.gauthur() << endl;
        } 
		else 
		{
            cout << "You have reached the maximum number of borrowed books." << endl;
        }
    }
    void returnBook(const Book& book) 
	{
        int index = -1;
        for (int i = 0; i < numBooks; ++i) 
		{
            if (borrowed_book[i].gtitle() == book.gtitle() &&
            borrowed_book[i].gauthur() == book.gauthur()) 
			{
                index = i;
                break;
            }
        }
        if (index != -1) 
		{
            for (int j = index; j < numBooks - 1; ++j) 
			{
                borrowed_book[j] = borrowed_book[j + 1];
            }
            numBooks--;
            cout << "Book returned: " << book.gtitle() << " by " << book.gauthur() << endl;
        } 
		else 
		{
            cout << "Book not borrowed by this member." << endl;
        }
    }
    ~Member(){}
    	void file_member()
		{
			ofstream file("member.txt",ios::app);
			if(file.is_open())
			{
				file<<"name : "<<name<<" id : "<<id<<" membership_type: "<<membership_type<<endl;
				file.close();
			}
			else
			{
				cout<<"file is not created"<<endl;
			}
			}
    static void removeMember(int id) 
	{
        ifstream file("member.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            stringstream ss(line);
            string token;
            getline(ss, token, ','); 
            stringstream id_ss(token);
            int memberId;
            id_ss >> memberId; 
            if (memberId != id) 
			{
                temp<<line<<endl; 
            }
        }
        file.close();
        temp.close();
        remove("member.txt");
        rename("temp.txt", "member.txt");
    }
    static void updateMember(int id, const Member& updatedMember) 
	{
        ifstream file("member.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            stringstream ss(line);
            string token;
            getline(ss, token, ','); 
            stringstream id_ss(token);
            int memberId;
            id_ss >> memberId;
            if (memberId != updatedMember.get_id()) 
			{
                temp<<line<<endl; 
            } 
			else 
			{
                temp<<updatedMember.get_name()<<" , "<<updatedMember.get_id()<< " , "<<updatedMember.get_membership_type()<<endl;
            }
        }
        file.close();
        temp.close();
        remove("member.txt");
        rename("temp.txt", "member.txt");
    }
    

};
class student : public Member
{
 private:
 string grade;
 public:
    student(const string& n, int i, const string& m, const string& g)
	: Member(n, i, m), grade(g) {}	
	~student(){} 
	void file_member()
	{
		ofstream file("member.txt",ios::app);
		if(file.is_open())
		{
			file<<"name : "<<name<<" id : "<<id<<" membership_type: "<<membership_type<<" grade: "<<grade<<endl;
			file.close();
		}
		else
		{
			cout<<"file is not created"<<endl;
		}
	}	
};
class faculty : public Member
{
 private:
 string department;
 public:
  faculty(const string& n, int i, const string& m, const string& d)
  : Member(n, i, m), department(d) {}
   ~faculty(){}
   void file_member()
	{
		ofstream file("member.txt",ios::app);
		if(file.is_open())
		{
			file<<"name : "<<name<<" id : "<<id<<" membership_type: "<<membership_type<<" department: "<< department<<endl;
			file.close();
		}
		else
		{
			cout<<"file is not created"<<endl;
		}
	}
};
class staff 
{
	protected:
		string name;
		int id;
		string role;
		double salary;
	public:
		staff(const string& n, int i, const string& r, double s)
		:name(n),id(i),role(r),salary(s){}
		void calculate_salary()
		{
		 cout<<"name: " <<name<<endl;
		 cout<<"id: " <<id<<endl;
		 cout<<"role: " <<role<<endl;
		 cout<<"salary: " <<salary<<endl;	 
		}
	~staff(){}
	void file_staff()
	{
		ofstream file("staff.txt",ios::app);
			if(file.is_open())
			{
				file<<"name: "<<name<<" id: "<<id<<" role: "<<role<<" salary: "<<salary<<endl;
				file.close();
			}
			else
			{
				cout<<"file is not created"<<endl;
			}
			}
	static void removestaff(int id) 
	{
        ifstream file("staff.txt");
        ofstream temp("temp.txt");
        string line;
        while (getline(file, line)) 
		{
            stringstream ss(line);
            string token;
            getline(ss, token, ','); 
            stringstream id_ss(token);
            int memberId;
            id_ss >> memberId; 
            if (memberId != id) 
			{
                temp<<line<<endl; 
            }
        }
        file.close();
        temp.close();
        remove("staff.txt");
        rename("temp.txt", "staff.txt");
    }	
	};
class librarian : public staff
{
	public:
    librarian(const string& n, int i, const string& r, double s)
	: staff(n, i, r, s) {}
	~librarian(){}	
};
class assistant : public staff
{
	public:
		assistant(const string& n, int i, const string& r, double s)
		: staff(n, i, r, s) {}
	~assistant(){}
	};
class transaction
{
	protected:
		int transaction_id;
		int member_id;
		string book_isbn;
		string borrow_date;
		string return_date;
		string type;
		int overdue_days;
		double fine;
	public:
	transaction(int t_id,const string& i, const string& b_d, const string& r_d, int m_id,string t)
	: transaction_id(t_id), member_id(m_id), book_isbn(i),borrow_date(b_d), return_date(r_d),type(t){}
	void calculate_fine()
	{
		cout<<"Calculating fine for transaction ID " << transaction_id << endl;
		if(type=="student")
		{
        cout<<"10 days allowed"<<endl;
        cout<<"how many days are overdue:";
		cin>>overdue_days;
		 fine = overdue_days * 500.0; 
        cout << "Fine calculated: Rs " << fine << endl;	
        }
        else
        {
		 cout<<"30 days allowed"<<endl;
		cout<<"how many days are overdue:";
		cin>>overdue_days;
		 fine = overdue_days * 1000.0;
         cout << "Fine calculated: Rs " << fine << endl;		
		}
	}
	void generate_report()
	{
		cout<<"Transaction report "<<endl;
		cout<<"Transaction id: "<<transaction_id<<endl;
		cout<<"Member id: "<<member_id<<endl;
		cout<<"Book isbn: "<<book_isbn<<endl;
		cout<<"borrow date: "<<borrow_date<<endl;
		cout<<"Return date: "<<return_date<<endl;
		cout<<"Member type: "<<type<<endl;
	}
	~transaction(){}
	void file_transaction()
	{
	    ofstream file("transaction.txt",ios::app);
		if(file.is_open())
		{
			file<<"transaction_id: "<<transaction_id<<" member_id: "<<member_id<<" book_isbn: "<<book_isbn<<" borrow_date: "<<borrow_date<<" return_date "<<return_date<<" member type: "<<type<<" fine: "<<fine<<endl;
			file.close();
		}
		else
		{
			cout<<"file is not created"<<endl;
		}
	}
	    void recordBorrowTransaction() const {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << "Borrow book : " << endl;
            file << "Transaction Id : " << transaction_id << " , " << "Member Id : " << member_id << " , " << "Book Isbn : " << book_isbn << " , " << "Borrow date : " << borrow_date << endl;
            file.close();
        } else {
            cout << "Error opening transactions.txt for writing." << endl;
        }
    }
    void recordReturnTransaction() const 
	{
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) 
		{
            file<<"Return book : "<<endl;
			file<<"transaction Id : "<<transaction_id<<" , "<<"member Id : "<<member_id<<" , "<<"book Isbn : "<<book_isbn<<" , "<<"return date : "<<return_date<<endl;
            file.close();
        } 
		else
		{
            cout<<"Error opening transactions.txt for writing."<<endl;
        }
    }		
};
class library 
{
  public:
  string name;
  string address;
  Book* books[1000];
  int book_count;
  Member* members[300];
  int member_count;
  staff* staffs[100];
  int staff_count;
  public:
   library(string n, string a)
   {
    name=n;
   	address=a;
   	book_count=0;
   	member_count=0;
   	staff_count=0;
   	
   }
   void add_book(Book* book)
   {
   	 if(book_count<1000)
   	 {
		books[book_count++] =book;
		cout<<"book added"<<endl;	
	 }
	 else
	 {
	 	cout<<"book reached the limit"<<endl;
	 }
   }
   void list_book()
   {
   	cout<<"listing book"<<endl;
   	for(int i=0;i<book_count;i++)
   	 {
		cout<<i+1<<" . "<<books[i]<<endl;	
	  }
   }
    void add_members(Member* member)
   {
   	 if(member_count<300)
   	 {
		members[member_count++] =member;
		cout<<"member added"<<endl;	
	 }
	 else
	 {
	 	cout<<"member reached the limit"<<endl;
	 }
   }
   void list_members()
   {
   	cout<<"listing member"<<endl;
   	for(int i=0;i<member_count;i++)
   	 {
		cout<<i+1<<" . "<<members[i]<<endl;	
	  }
   }
    void add_staff(staff* staff)
   {
   	 if(staff_count<1000)
   	 {
		staffs[staff_count++] =staff;
		cout<<"staff added"<<endl;	
	 }
	 else
	 {
	 	cout<<"staff reached the limit"<<endl;
	 }
   }
   void list_staff()
   {
   	cout<<"listing staff"<<endl;
   	for(int i=0;i<staff_count;i++)
   	 {
		cout<<i+1<<" . "<<staffs[i]<<endl;	
	  }
   }
   void remove_book(const string& bisbn) {
        bool found = false;
        for (int i = 0; i < book_count; i++) {
            if (books[i]->getISBN() == bisbn) {
                delete books[i];
                for (int j = i; j < book_count - 1; j++) {
                    books[j] = books[j + 1];
                }
                book_count--;
                found = true;
                cout << "Book with ISBN " << bisbn << " removed." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Book with ISBN " << bisbn << " not found." << endl;
        }
    }
  void remove_member(int member_id)
    { 
     if(member_id > 0 && member_id <= member_count)
     {
      for(int i = member_id - 1; i < member_count - 1; i++)
      {
        members[i] = members[i + 1];
      }
      member_count--;
      cout << "Member removed" << endl;
     }
     else
     {
      cout << "Invalid member ID" << endl;
     }
    }
    void remove_staff(int staff_id)
    { 
     if(staff_id > 0 && staff_id <= staff_count)
     {
      for(int i = staff_id - 1; i < staff_count - 1; i++)
      {
        staffs[i] = staffs[i + 1];
      }
      staff_count--;
      cout << "Staff removed" << endl;
     }
     else
     {
      cout << "Invalid staff ID" << endl;
     }
    }
	~library(){}	
};
int main()
{
system("cls");
 string n,a;
 cout<<"enter the name and address of library  "<<endl;
 cout<<"name : ";
 getline(cin,n);
 cout<<"address : ";
 getline(cin,a);
library l(n,a);
int c;
do
{	
cout<<"########################################"<<endl;
cout<<"#         choose the option            #"<<endl;
cout<<"# 1.Add book                           #"<<endl;
cout<<"# 2.Add member                         #"<<endl;
cout<<"# 3.Add libararian                     #"<<endl;
cout<<"# 4.Add asistant                       #"<<endl;
cout<<"# 5.Add transaction                    #"<<endl;
cout<<"# 6.List the book                      #"<<endl;
cout<<"# 7.List the member                    #"<<endl;
cout<<"# 8.List the staff                     #"<<endl;
cout<<"# 9.Borrow book                        #"<<endl;
cout<<"# 10.Return book                       #"<<endl;
cout<<"# 11.Remove book                       #"<<endl;
cout<<"# 12.Remove member                     #"<<endl;
cout<<"# 13.Remove staff                      #"<<endl;
cout<<"# 14.update member                     #"<<endl;
cout<<"# 15.update book                       #"<<endl;
cout<<"# 16.Exit                              #"<<endl;
cout<<"########################################"<<endl;
cout<<"Enter your choice: ";
cin>>c;
switch(c)
{
	case 1:
		system("cls");
		{
		string title;
		string authur;
		string isbn;
		int publication_year;
		string type;
		cin.ignore(); 
		cout<<"Enter book title : ";
		getline(cin,title);
		cout<<"Enter book authur : ";
		getline(cin,authur);
		cout<<"Enter book isbn : ";
		getline(cin,isbn);
		cout<<"Enter book publication_year : ";
		cin>>publication_year;
		cin.ignore(); 
		cout<<"Enter book type (fiction , non_fiction , reference) : ";
		getline(cin,type);
		if (type == "fiction") 
		{
			string genre;
            cout<<"Enter genre: ";
            getline(cin, genre);
            fiction* b=new fiction(genre, title, authur, isbn, publication_year, type);
            l.add_book(b);
            cout<<"Fiction book added successfully." << endl;
            b->file_book();
		}
	   else if(type == "non_fiction") 
		{
			string subject;
            cout<<"Enter subject: ";
            getline(cin, subject);
            non_fiction* b=new non_fiction(title, authur, isbn, publication_year, type,subject);
            l.add_book(b);
            cout<<"Non Fiction book added successfully." << endl;
             b->file_book();
		}
		else if(type == "reference") 
		{
			string edition;
            cout<<"Enter edition: ";
            getline(cin, edition);
            reference* b=new reference(title, authur, isbn, publication_year, type,edition);
            l.add_book(b);
            cout<<"Reference book added successfully." << endl;
            b->file_book();
		}
		else
		{
		 cout<<"invalid tye please write a invalid type"<<endl;
		}
	}
		break;
		case 2:
		system("cls");	
		{
		string name;
		int id;
		string membership_type;
		cin.ignore();
		cout<<"name of member: "; 
		getline(cin,name); 
		cout<<"id of member: "; 
		cin>>id;
		cin.ignore();
		cout<<"membership type (student,faculty): "; 
		getline(cin,membership_type);
		if(membership_type=="student")
		{
			string grade;
			cout<<"Enter the grade: ";
			getline(cin,grade);
			student* b=new student(name,id,membership_type,grade);
            l.add_members(b);
            cout<<"student added successfully." << endl;
            b->file_member();
		}
		else if(membership_type=="faculty")
		{
			string department;
			cout<<"Enter the department: ";
			getline(cin,department);
            faculty* b=new faculty(name,id,membership_type,department);
            l.add_members(b);
            cout<<"faculty added successfully." << endl;
			b->file_member();   
		}
		else
		{
		 cout<<"invalid tye please write a invalid type"<<endl;
		}
		}
			break;
			case 3:
			system("cls");
				{
				string name;
		        int id;
		        string role;
		        double salary;
				cin.ignore();	
		        cout<<"enter the name: ";
				getline(cin,name);
				cout<<"enter the id: ";
				cin>>id;
				cin.ignore();
				cout<<"enter the role: ";
				getline(cin,role);
				cout<<"enter the salary: ";
				cin>>salary;
				staff* b=new librarian(name,id,role,salary);
                l.add_staff(b);
                cout<<"librarian added successfully." << endl; 	
				b->file_staff();			
				}
				break;
				case 4:
					system("cls");
					{
					string name;
		            int id;
		            string role;
		            double salary;
					cin.ignore();	
		            cout<<"enter the name: ";
				    getline(cin,name);
				    cout<<"enter the id: ";
			    	cin>>id;
			    	cin.ignore();
				    cout<<"enter the role: ";
				    getline(cin,role);
				    cout<<"enter the name: ";
				    cin>>salary;
				    staff* b=new assistant(name,id,role,salary);
                    l.add_staff(b);
                    cout<<"assistant added successfully." << endl;
                    b->file_staff();
					}
					break;
					case 5:
						system("cls");
						{
						    int transaction_id;
		                    int member_id;
		                    string book_isbn;
		                    string borrow_date;
		                    string return_date;
		                    double fine;
		                    string type;
							cout<<"enter the transaction id: ";
							cin>>transaction_id;
							cout<<"enter the member id: ";
							cin>>member_id;	
							cin.ignore();
							cout<<"enter the book isbn: ";
							getline(cin,book_isbn);	
							cout<<"enter the borrow date: ";
							getline(cin,borrow_date);	
							cout<<"enter the return_date: ";
							getline(cin,return_date);
							cout<<"enter the member type: ";
							getline(cin,type);
							cin.ignore();
							transaction t(transaction_id,book_isbn,borrow_date,return_date,member_id,type);
							t.generate_report();
							t.calculate_fine();
							t.file_transaction();				
							}
						break;
						case 6:
							system("cls");
							{
							cout<<"book in library"<<endl;
							l.list_book();
							}
							break;
							case 7:
							 system("cls");
							{
							cout<<"member in library"<<endl;
							l.list_members();
							}	
								break;
								case 8:
									system("cls");
							        {
							          cout<<"staff in library"<<endl;
							          l.list_staff();
							        } 
							        case 9:
							        	system("cls");
							        	{ 
							        	  int memberId,transactionId;
                                          string bookIsbn;
                                          string borrowDate;
                                          cout<<"Enter transaction ID: ";
                                          cin>>transactionId;
                                          cout<<"Enter member ID: ";
                                          cin>>memberId;
                                          cin.ignore();
                                          cout << "Enter book ISBN: ";
                                          getline(cin, bookIsbn);
                                         cout << "Enter borrow date (YYYY-MM-DD): ";
                                         getline(cin, borrowDate);
                                         Member* member = 0;
                                       for (int i = 0; i < l.member_count; ++i) 
				                        {
                                          if (l.members[i]->get_id() == memberId) 
					                      {
                                            member = l.members[i];
                                            break;
                                            }
                                        }
                                       if (member!= 0) 
				                        {
                                        Book* book = 0;
                                        for (int i = 0; i < l.book_count; ++i) 
					                        {
                                             if (l.books[i]->getISBN() == bookIsbn) 
						                        {
                                                 book = l.books[i];
                                                  break;
                                                }
                                            }
                                        if (book!= 0) 
					                    {
                                          if (book->gtitle() != "") 
						                 {
                                            member->borrowBook(*book);
                                          transaction t(transactionId,bookIsbn, borrowDate, "",memberId, "Borrow");
                                          t.recordBorrowTransaction();
                                         cout << "Book borrowed successfully." << endl;
                                          }  
					                  	else  
					                  	{
                                           cout << "Book is not available." << endl;
                                         }
                                        } 
				                 	else 
					                  {
                                       cout << "Book not found." << endl;
                                        }
                                      } 
				                  else 
				                   {
                                    cout << "Member not found." << endl;
                                        }
                                             } 
									
							        	break;
							        	case 10:
							        		system("cls");
							        		{
							        	  	int memberId,transactionId;
                                            string bookIsbn;
                                            string returnDate;
                                           cout<<"Enter transaction ID: ";
                                            cin>>transactionId;
                                           cout << "Enter member ID: ";
                                            cin >> memberId;
                                           cin.ignore();
                                           cout << "Enter book ISBN: ";
                                            getline(cin, bookIsbn);
                                           cout << "Enter return date (YYYY-MM-DD): ";
                                           getline(cin, returnDate);
                                           Member* member = 0;
                                           for (int i = 0; i < l.member_count; ++i) 
			                               	{
                                             if (l.members[i]->get_id() == memberId) 
					                           {
                                                 member = l.members[i];
                                                  break;
                                               }
                                            }
                                           if (member!= 0) 
				                            {
                                              Book* book = 0;
                                             for (int i = 0; i < l.book_count; ++i) 
					                          {
                                                 if (l.books[i]->getISBN() == bookIsbn) 
						                            {
                                                        book = l.books[i];
                                                        break;
                                                    }
                                                }
                                              if (book!= 0) 
				                               	{
                                                  member->returnBook(*book);
                                                transaction t(transactionId, bookIsbn, "", returnDate,memberId, "Return");
                                                t.recordReturnTransaction();
                                              cout << "Book returned successfully." << endl;
                                                  } 
				                              else 
				                                   {
                                                    cout << "Book not found." << endl;
                                                    }
                                                  } 
				                                else 
				                                {
                                                cout << "Member not found." << endl;
                                                }
							        			}
							        		break;
									case 11:
										system("cls");
							            {
										string i;
										Book* b;
										cout<<"Enter the book isbn: ";
										cin>>i;
										l.remove_book(i);
										b->remove_from_file(i);
										
										}
										break;
										case 12:
											system("cls");
											int m_id;
											Member* m;
										cout<<"Enter the member id: ";
										cin>>m_id;
										l.remove_member(m_id);
										m->removeMember(m_id);
										
											break;
											case 13:
												system("cls");
												int s_id;
												staff* s;
										        cout<<"Enter the staff id: ";
										        cin>>s_id;
										        l.remove_staff(s_id);
										        s->removestaff(s_id);
												break;
												case 14:
													{
												       string name, membership_type, grade, department;
                                                      int id;
                                                     cout<<"Enter the member ID to update: ";
                                                     cin>>id;
				                                     cout<<"Enter new name: ";
			                                       	 cin.ignore();
			                                       	 getline(cin, name);
				                                     cout<<"Enter new membership type: ";
			                                    	 getline(cin, membership_type);
				                                     cout<<"Enter member type (1 for Student, 2 for Faculty): ";
				                                     int memberType;
				                                     cin>>memberType;
                                                     if (memberType == 1) 
			                                         {
                                                         cout<<"Enter new grade: ";
                                                         cin.ignore();
                                                         getline(cin, grade);
                                                         student updatedMember(name, id, membership_type, grade);
                                                         Member::updateMember(id,updatedMember);
                                                       } 
			                                          else if (memberType == 2) 
			                                            {
                                                          cout<<"Enter new department: ";
                                                          cin.ignore();
                                                          getline(cin, department);
                                                          faculty updatedMember(name, id, membership_type, department);
                                                           Member::updateMember(id,updatedMember);
                                                           }
										           }
													break;
												case 15 :
													{
													    string title, author, isbn, type;
                                                        int pub_Year;
			                                            cout<<"Enter the book ISBN to update: ";
			                                            cin>>isbn;
			                                            cout<<"Enter new title: ";
			                                            cin.ignore();
			                                            getline(cin, title);
			                                            cout<<"Enter new author: ";
			                                            getline(cin, author);
			                                            cout<<"Enter new publication year: ";
			                                            cin>>pub_Year;
			                                            cout<<"Enter new type: ";
			                                            cin.ignore();
			                                            getline(cin, type);
			                                            Book updatedBook(title, author, isbn, pub_Year, type);
			                                            Book::updatebook(updatedBook);
			                                            if (type == "fiction") 
	                                                    {
                                                          string genre;
                                                          cout<<"Enter genre: ";
                                                          getline(cin, genre);
                                                         fiction updatedBook(genre,title, author, isbn, pub_Year,type);
                                                         fiction::updatebook(updatedBook);
                                                         } 
	                                                   else if (type == "non_fiction") 
                                                       	{
                                                          string subject;
                                                          cout<<"Enter subject: ";
                                                          getline(cin, subject);
                                                          non_fiction updatedBook(title, author, isbn, pub_Year,type, subject);
                                                          non_fiction::updatebook(updatedBook);
                                                        } 
	                                                  else if (type == "reference") 
	                                                  {     
                                                            string edition;
                                                            cout<<"Enter edition: ";
                                                            getline(cin,edition);
                                                            reference updatedBook(title, author, isbn, pub_Year,type, edition);
                                                            reference::updatebook(updatedBook);
                                                        } 
			                                         cout<<"Book updated successfully."<<endl;
										           }
													break;
												case 16:
													system("cls");
													cout<<endl<<endl;
    				                                cout<<endl<<endl;;
    				                                cout<<"              ***************************************"<<endl;
    			                                	cout<<"              *                                     *"<<endl;
    				                                cout<<"              *    Thank u for using my LMS         *"<<endl;
    				                                cout<<"              *                                     *"<<endl;
    				                                cout<<"              ***************************************"<<endl;                     
													break;
													default:
														cout<<"invalid number please choose correct number from menu..."<<endl;
														break;
									
}
}while(c!=16);
return 0;
}
