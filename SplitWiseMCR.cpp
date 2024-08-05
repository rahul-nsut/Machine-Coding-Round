// Machine Coding Round Prep-3

// Design of Splitwise App (Asked in Meesho-R1, Backend SDE)

// Can define the ENUMS outside as well

// Like we can also define each service separately to make a clean structure..
// Expenses Service, User Service, SplitWise Serives. 
// TO perform this we have already implemented in main SplitWiseSystems

enum ExpenseType {
    EQUAL, EXACT, PERCENTAGE
};
enum QueryType {
    SHOW, EXPENSE
};

class SplitWiseSystem{
    private:
        // consider it as a main class head
        map<string,vector<pair<string,int>>> pendingAmountsMap;
        string queryType;
        
        // depending upon the queryType, we will perform our logic
        // Logic of only Show Query
    public:
        void showPendingAmount(){
            for(auto i:pendingAmountsMap){
                string expensedBy=i.first;
                auto vector=i.second;
                for(auto j:vector){
                    cout<<expensedBy<<" Owes User "<<j.first<<" rupees "<<j.second<<endl;
                }
            }
        }
        // Logic of show query per user
        void showUserPendingAmount(string userId){
            auto vector=pendingAmountsMap[userId];
            for(auto j:vector){
                cout<<userId<<" Owes User "<<j.first<<" rupees "<<j.second<<endl;
            }
        }
        // Expenses query->3 types
        Expense expense;
        void updateExpenses(){
            if(expense.typeOfExpenses=='EQUAL'){
                double splittedAmount=expense.total/expense.UsersAmongSplitted.size();
                string userId=expense.expensedBy;
                auto usersSplitted=expense.UsersAmongSplitted;
                // the logic of updating the map can be added. by Looping on usersSplitted.
                updateExpensesMap("EQUAL");
            }
            else if(expense.typeOfExpenses=='EXACT'){
                auto array=expense.exactSplitArray;
                // the logic of updating the map can be added. by Looping on usersSplitted.
                updateExpensesMap("EXACT");
            }
            else{
                auto array=expense.percentages;
                for(auto i:array){
                    double percent=(double)i/(double)100;
                    double amt=double(expense.totalAmount)*percent;
                    updateExpensesMap("PERCENT");
                }
            }
        }
        void updateExpensesMap(string queryType){
            // putting the logic of updating the map
        }
};

class Expense{
    public:
        string expensedBy;
        int totalAmount;
        User user;
        list<user> UsersAmongSplitted;
        string typeOfExpenses; //exact,equal,percent
        // depending on the type, we may require extra parameters
        vector<int>percentages;         // Depending upon query
        vector<int>exactSplitArray;
    // Constructor
    Expense(string expBy, int total, list<string> users, ExpenseType type)
        : expensedBy(expBy), totalAmount(total), usersAmongSplitted(users), typeOfExpenses(type) {}
    
};

class User{
    private:
        string userId;
        string userEmail;
        int userMobile;
        
    //constructor can be defined
    User(string id, string email, string mobile) : userId(id), userEmail(email), userMobile(mobile) {}

    // getters and setters for userId (to follow SOLID Principles)
    public:
        void set(string id){
            this->userId=id;
        }
        int get(){
            return userId;
        }
};



int main() {
    
}
