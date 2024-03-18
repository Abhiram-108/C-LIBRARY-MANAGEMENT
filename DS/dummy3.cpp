
#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include<ctime>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    Book* left;
    Book* right;
    

    Book(int bookId, const string& bookTitle, const string& bookAuthor)
        : id(bookId), title(bookTitle), author(bookAuthor), left(nullptr), right(nullptr) {}
};
    Book* bookRoot = nullptr;


struct Student {
    int id;
    
    string name;
    Student* left;
    Student* right;

    Student(int studentId, const string& studentName)
        : id(studentId), name(studentName), left(nullptr), right(nullptr) {}
};
      Student* studentroot = nullptr;
struct Transaction {
    Book* book;
    time_t dueDate;

    Transaction(Book* transactionBook)
        : book(transactionBook) {
        // Due date set to 14 days from the transaction date
        dueDate = time(nullptr) + 86400 * 14;  // 86400 seconds in a day
    }
};
vector<string>arr2={"insertbook","searchbook","displaybook","deleteBook","displaystudent"};
vector<string>arr3={"librarin","student"};
vector<string>arr4={"addstudent","borrowbook","returnbook"};


void printmat(int line_ct,vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i == line_ct)
        {
            cout << "\t\t\t\t\t>";
            cout << "\x1b[1;36m" << v[i] << "\x1b[22;0m\n";
        }
        else
        {
            cout << "\t\t\t\t\t" << v[i] << "\n";
            printf(" ");
        }
    }
}


int  operations(vector<string>&arr2){
      int ch;
    system("cls");
    printmat(0,arr2);
    int ct = 0;
    int n=arr2.size();
    n--;
    while (true)
    {
        ch = getch();
        if (ch == 72)
        {
            if (ct <= 0)
                ct = n;
            else
                ct--;
        }
        else if (ch == 80)
        {
            if (ct == n)
                ct = 0;
            else
                ct++;
        }
        else if (ch == 13)
        {
            system("cls");
            return ct;
            break;
        }
        system("cls");
        printmat(ct,arr2);
    }
}
int  users(vector<string>&arr3){
      int ch;
    system("cls");
    printmat(0,arr3);
    int ct = 0;
    int n=arr3.size();
    n--;
    while (true)
    {
        ch = getch();
        if (ch == 72)
        {
            if (ct <= 0)
                ct = n;
            else
                ct--;
        }
        else if (ch == 80)
        {
            if (ct == n)
                ct = 0;
            else
                ct++;
        }
        else if (ch == 13)
        {
            system("cls");
            return ct;
            break;
        }
        system("cls");
        printmat(ct,arr3);
    }
}
// Functions for managing books
Book* insertBook(Book* node, int id, const string& title, const string& author) {
    if (node == nullptr) {
        return new Book(id, title, author);
    }

    if (id < node->id) {
        node->left = insertBook(node->left, id, title, author);
    } else if (id > node->id) {
        node->right = insertBook(node->right, id, title, author);
    }

    return node;
}
Book *insertintobst(Book*node,int id,string&title,string&author){
    if(node==NULL){
        node=new Book(id,title,author);
        return node;
    }
    Book*curr=node;
    while(curr){
        if(curr->id<id){
            if(curr->right!=NULL)
            curr=curr->right;
            else{
                curr->right=new Book(id,title,author);
                break;
            }
        }
        else{
            if(curr->left!=NULL)
            curr=curr->left;
            else{
                curr->left=new Book(id,title,author);
                break;
            }
        }
    }
    return node;
}
Book*find(Book*root){
    if(root->right==NULL)
    return root;
    return find(root->right);
}
Book* helper(Book *root){
    if(root->left==NULL)
    return root->right;
    else if(root->right==NULL)
    return root->left;
    Book*curr=root->right;
    Book*last_left_right_node=find(root->left);
    last_left_right_node->right=curr;
    return root->left;
}
Book* deleteBook(Book*root,int id){
if(root==NULL)
return NULL;
if(root->id==id)
return helper(root);
Book*curr=root;
while(root){
    if(root->id>id){
        if(root->left!=NULL && root->right->id==id){
            root->left=helper(root->left);
            break;
        }
        else
        root=root->left;
    }
    else{
        if(root->right!=NULL && root->right->id==id){
            root->right=helper(root->right);
            break;
        }
        else
        root=root->right;
    }
}
return curr;
}
Book* searchBook(Book* node, int id) {
    if (node == nullptr || node->id == id) {
        return node;
    }

    if (id < node->id) {
        return searchBook(node->left, id);
    }

    return searchBook(node->right, id);
}

void displayBook(const Book* book) {
    cout << "ID: " << setw(3) << book->id
         << " | Title: " << setw(25) << book->title
         << " | Year-Published: " << setw(20) << book->author << endl;
}

// Functions for managing students


void display(Book *bookroot){
    cout<<bookroot->id<<" ";
    cout<<bookroot->author<<" ";
    cout<<bookroot->title<<endl;
}
void displayStudent(const Student* student) {
    cout << "ID: " << setw(3) << student->id
         << " | Name: " << setw(25) << student->name << endl;
}
Student* searchStudent(Student* node, int id) {
    if (node == nullptr || node->id == id) {
        return node;
    }

    if (id < node->id) {
        return searchStudent(node->left, id);
    }

    return searchStudent(node->right, id);
}
void inorder(Book* bookroot){
    if(bookroot!=NULL){
        inorder(bookroot->left);
        display(bookroot);
        inorder(bookroot->right);
    }
}
void displaybook(){
    inorder(bookRoot);
}
void librarian(){
    // reset1:

    system("cls");
        for(int i=0;i<137;i++){
    cout<<"\xdb";
    
    Sleep(1);
}
    ifstream ob3;
    ob3.open("library.txt");
    string x,y;
    cout<<"\nEnter your password:"<<endl;
    cin>>x;
    ob3>>y;
    if(x!=y){
        cout<<"Invalid user access"<<endl;
    }
    else{
 ab:
        int index=operations(arr2);
        if(index==0){
            system("cls");
            int id;
            string s1,s2;
            cout<<"id"<<endl;
            cin>>id;
            cout<<"enter the book name:"<<endl;
            cin>>s1;
            cout<<"enter the year published:"<<endl;
            cin>>s2;
            ofstream ob2;
            ob2.open("in.txt",ios::app);
            ob2<<id<<" "<<s1<<" "<<s2<<endl;
    bookRoot=insertintobst(bookRoot,id,s1,s2);
            ob2.close();
        }
        if(index==1){
            system("cls");
            int id;
            cout<<"Enter the book id:"<<endl;
            cin>>id;

    Book* foundBook = searchBook(bookRoot, id);
    if (foundBook) {
        cout << "Book Found: ";
        displayBook(foundBook);
    } else {
        cout << "Book not found." << endl;
    }
        }
        if(index==2){
            system("cls");
        displaybook();

        }
        if(index==3){
            system("cls");
            int id;
            cout<<"Enter the id for deletion"<<endl;
            cin>>id;
            bookRoot=deleteBook(bookRoot,id);
            system("cls");
            displaybook();
        }
        if(index==4){
            system("cls");
            int id;
            cout<<"Enter the student id:"<<endl;
            cin>>id;
            Student* foundstudent=searchStudent(studentroot,id);
            displayStudent(foundstudent);

        }
    }
    // if(x!=y)
   cout<<"Enter any character to return library properties:"<<endl;
   char x1;
  x1= getch();
    

       goto ab;


}
Student* insertstudent(Student* node, int id, const string& name) {
  if(node==NULL){
        node=  new  Student(id,name);
        return node;
    }
    Student*curr=node;
    while(curr){
        if(curr->id<id){
            if(curr->right!=NULL)
            curr=curr->right;
            else{
                curr->right=new Student(id,name);
                break;
            }
        }
        else{
            if(curr->left!=NULL)
            curr=curr->left;
            else{
                curr->left=new Student(id,name);
                break;
            }
        }
    }
    

    return node;
}



void student(){
    system("cls");
        for(int i=0;i<150;i++){
    cout<<"\xdb";
    
    Sleep(1);
}

fflush(stdin);
    ifstream ob1;
    ob1.open("student.txt");
    int id;
   string s1,s2;
    
    
    string id1;
    cout<<endl;
    cout<<"\n\nEnter your student password"<<endl;
    cin>>id1;
    int count=0;
    while(!ob1.eof()){
        ob1>>id>>s1>>s2;
        if(id1==s1)
        count=1;
    }
    ob1.close();
    if(count!=1)
    {
        cout<<"Invalid student acess"<<endl;
    }
    else{
        ab:
        int index=operations(arr4);
        if(index==0){
            system("cls");
            int id;
            string password,s1;
            cout<<"Enter your id"<<endl;
            cin>>id;
            cout<<"Enter your password"<<endl;
            cin>>password;
            cout<<"Enter your name"<<endl;
            cin>>s1;
            ofstream ob2;
            ob2.open("student.txt",ios::app);
            ob2<<id<<" "<<password<<" "<<s1<<endl;
            studentroot=insertstudent(studentroot,id,s1);
            ob2.close();

        }
        if(index==1){
            system("cls");
            int id;
            string password,name;
            cout<<"enter your student id"<<endl;
            cin>>id;
            ifstream ob1;
            ob1.open("student.txt");
            int id1;
            while(!ob1.eof()){
                
                ob1>>id1>>password>>name;
                if(id==id1)
                break;
            }
            cout<<"Enter the book id"<<endl;
            int id2;
            cin>>id2;
            ofstream ob3;
            ob3.open("transaction.txt",ios::app);
            Book* foundBook = searchBook(bookRoot, id);
            if(foundBook){
                ob3<<"book is issued to  "<<name;
                ob3<<"  student id :"<<id;
                ob3<<"   book name:"<<foundBook->title;
                  time_t now = time(0);
                    char*dt = ctime(&now);
                    ob3<<"  DUE date"<<dt<<endl;
                    ob3.close();
            }

            
      
        }
    }
       char x1;
    x1=getch();
    cout<<"Enter any characters to return for student properties:"<<endl;
    goto ab;

}
void trees(){
    system("cls");

     ifstream ob1,ob3;
    ofstream ob2;
    int a;
    string s1,s2;
    ob1.open("in.txt");
    while(!ob1.eof()){
        if(ob1.eof()) ob1.close();
        ob1>>a;
        fflush(stdin);
        ob1>>s1>>s2;
    bookRoot = insertBook(bookRoot, a,s1,s2);
        
        }
    ob3.open("student.txt");
    while(!ob3.eof()){
        if(ob3.eof()) ob3.close();
        ob3>>a;
        fflush(stdin);
        ob3>>s1>>s2;
        studentroot=insertstudent(studentroot,a,s2);
    } 
 
}

void loadingProcess() {
    std::cout << "Loading: ";
    int progress = 0;

    for (int i = 0; i <= 100; ++i) {
        progress = i;
        cout << "\rLoading: " << setw(3) << progress << "%";
        cout.flush();
        
        clock_t start_time = clock();
        while ((clock() - start_time) / CLOCKS_PER_SEC <0.1) {
            // Wait for 50 milliseconds
        }
    }

    // std::cout << std::endl << "Loading complete!" << std::endl;
}





int main() {
    // // Book management
    
        // system("cls");
//  loadingProcess();
for(int i=0;i<137;i++){
    cout<<"\xdb";
    Sleep(1);
}

trees();
int x=users(arr3);
if(x==0){

    librarian();
}
if(x==1){
    student();
}

   
    return 0;                                                                                                       
}