// Machine Coding Round Prep-7

// Design of Library Management System 

//https://workat.tech/machine-coding/practice/design-library-management-system-jgjrv8q8b136

class librarySystem{
    private:
        Book book;
        User user;
        
        map<pair<Book,User>,int> holdingBooks;
        set<User>userData;   // these are to keep a track of users and books registered with library 
        set<Book>bookData;
        map<string,Book> titleMappings; // to search for an available book.
    public:
    
        void checkABook(string title){
            // User gives a title, to check if the book is present or not,
            //as rest of the details are for library management uses.
            if(titleMappings.count(title)){
                cout<<"Yes, the book is there";
            }
            else{
                cout<<"No, the book is not there";
            }
        }
    
        void lendABook(User user,Book book,int days){
            int noOfBooks=user.booksHolding.size();
            if(noOfBooks>=5){
                cout<<"You already have 5 books. Return atleast 1 book to issue further"<<endl;
            }
            else{
                holdingBooks[{book,user}]=days;   // as a book can have only 1 user, but user can have many books.
                user.booksIssuedTillNow.push_back(book);
            }
        }
    
    // for keeping a track of extradays parameter, we can also keep a track of issuedate & return date.
        void returnABook(User user,Book book,int extradays){
            holdingBooks.erase({book,user});
            if(extradays<=0){
                cout<<"Book Successfully returned!"<<endl;
            }
            else{
                int priceToPay=extradays*book.finePerDay;
                cout<<"Book Successfully returned, but you need to pay Rs. "<<priceToPay<<"as a fine ";
            }
        }
        
        void remindUser(User user,int extradays){
            if(extradays>=1){
                // in this case,notify the user that his due date is up and has to return the book
                // as soon as possible to minimise fine
            }
        }
        
        void registerUser(User user){
            userData.insert(user);
        }
        
        void addBook(Book book){
            string title=book.bookTitle;
            titleMappings[title]=book;
            bookData.insert(book);
        }
        
        
};

class Book{
    private:
        int bookId;
        vector<string> authors;
        int currentRackNumber;
        string bookTitle;
        User currentlyHolding; //NULL if no one..
        int finePerDay; // for this book,this is the fine to be paid everyday late.
        
    // defining the constructor
    public Book(int bookId,vector<string> authors,int currentRackNumber,string bookTitle){
        this.bookId=bookId;
        this.authors=authors;
        this.currentRackNumber=currentRackNumber;
        this.bookTitle=bookTitle;
    }
    
    // define the getters and setters as per requirements
        
};

class User{
    private:
        int userId;
        string userName;
        int mobileNumber;
        vector<Book> booksHolding;
    
    // getter,setters and constructors can be defined
};

class bookCatalog{
    private:
        vector<Book> searchByTitle(string title);
	    vector<Book> searchByAuthor(string name);
        
};

int main() {
    
}