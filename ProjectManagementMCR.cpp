// Machine Coding Round Prep-8

// Design of Project Management App (Eg-Trello)

//Getters and Setters make our code more SOLID Principles oriented..
// Can define constructors for each class

class ManagemnetSystem{
    public:
        Board board;
        Card card;
        List list;
        User user;
        vector<board>allBoards;
        map<board,user> boardUserMapping;
        map<board,vector<List>> listBoardMapping;
        map<list,user>listUserMapping;
        map<card,user>cardUserMapping;
        map<list,vector<card>> listCardMapping;
        void createBoard(User user,Board board){
            if(user.designation!="Board Manager"){
                cout<<"Sorry, you are not permitted to create a board";
            }
            else{
                // user will add details to created board.
                allBoards.push_back(board);
            }
        }
        void addList(Board board,List list,User user){
            if(user.designation!="List Manager"){
                cout<<"Sorry, you are not permitted to create a list";
                // the list manager will have access only to specific boards, allowed by Board Manager.
            }
            else{
                listBoardMapping[board].push_back(list);
                listMapping[list]=user; // assigned to manage the list.
            }
        }
        
        void addCard(List list,Card card,User user){
            if(user.designation!="Cards Manager"){
                cout<<"Sorry, you are not permitted to create a card"<<endl;
            }
            else{
                listCardMapping[list].push_back(card);
                cardMapping[card]=user;
                cout<<"Card successfully created and stored in our database."
            }
        }
        void showBoard(int boardId){
            for(int i=0;i<allBoards.size();i++){
                if(allBoards[i].boardId==boardId){
                    // show all the information of this board, whatever is asked.
                }
            }
        }
    //similarly can delete all the three, as per reqd
        void deleteList(int listId){
            // check from listBoard mapping
            List temp;
            for(auto i:listBoardMapping){
                for(auto j:i.second){
                    if(j.listId==listId){
                        temp=j; break;  // as all list ids are going to be unique
                    }
                }
            }
            if(listUserMapping.count(temp)){
                listUserMapping.erase(temp);
            }
            
            if(listCardMapping.count(temp)){
                listCardMapping.erase(temp);
            }
        }
        
        void updateCard(User user1,User user2,Card card){
            // user1 will update the owner of card to user2
            if(user1.designation!="Card Manager"){
                cout<<"You are not authorized to update this card"<<endl;
            }
            else{
                cardUserMapping[card]=user2;
            }
        }
};

class User{
    private:
        int userId;
        string name;
        string emailId;
        string designation;  // manager of board,list,assignee,etc.
        vector<Card> cardsAssigned; // Can also be added in main class,but fine here also
};

class Board{
    private:
        int boardId;
        string name;
        string privacyType; // can define these types in ENUM;
        vector<List> listsInBoard;
        User boardManager;
};

class List{
    private:
        int listId;
        string name;
        vector<Card> cardsInList;
        User listManager;
    
};

class Card{
    private:
        int cardId;
        string name;
        string dueDate; // can also define properly by taking date class separately
        User assignedTo; //initially null, will be assigned by List Manager
        string description; //one liner on it
        int priority; //1 being highest and 5 being lowest-> decided by listManager.
};



int main() {
    std::cout << "Hello World!\n";
}