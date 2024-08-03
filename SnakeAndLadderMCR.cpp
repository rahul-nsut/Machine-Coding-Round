// Machine Coding Round Prep-1

// Design of Snake & Ladder game

class Entities{  // to be used-> can also say ENUMS
    //to handle the board as well
    public:
        map<int,int>snakes;
        map<int,int>ladders;
        vector<int>players;
    // calling constructors
    public Entities(){
        this->snakes=snakes;
        this->ladders=ladders;
        this->players=players;
    }
    public:
    //initiliased all the values
        void setPlayer(int uniqueId){
            //taking input and pushing in players
            players.push_back(uniqueId);
        }
        void setLadders(int a,int b){
            ladders[a]=b;
        }
        void setSnakes(int a, int b){
            snakes[a]=b;
        }
        int getNextPosition(int currPosition,int diceRollValue){
            int nextPosition=currentPosition+diceRollValue;
            // kept snake and ladder intial position as unique only
            if(ladders.count(nextPostion)){
                nextPosition=ladders[nextPosition];
            }
            if(snakes.count(nextPostion)){
                nextPosition=snakes[nextPosition];
            }
            if(!isValidMove(nextPosition)){
                nextPostion=currPosition;
            }
            if(isWinner(nextPosition)){
                // add the logic for returning the winner ID along with asked information
                cout<<"Game Ends!!"<<endl;
            }
            return nextPosition;
        }
        bool isWinnner(int currPosition){
            return currPosition==100;
        }
        bool isValidMove(int currPosition){
            return currPosition>=1&&currPosition<=100;
        }
    
};
class Player{
    protected:
        string name;
        int uniqueId;
        int winningPosition;
    
    // calling the constructor
     Player(string playerName, int id) : name(playerName), uniqueId(id), position(0) {}
};
class Dice{
    private:
    // defining the range of dice (1->6 generally)
        int minValue;
        int maxValue;
    public:
        int rollDice(){
            return (rand()%6)+1;
        }
};
class SnakeAndLaddersGame{
    // want to use these instances only inside this func, hence we declare them as private.
    // Constructor->
        SnakeAndLaddersGame(Player p1, Player p2) : player1(p1), player2(p2) {}
    private:
        Dice dice;
        Entities entities;
        Player player1;
        Player player2;  // considering only 2 are playing the game
        
    public:
        void playGame(){
            // Logic of playing the game.
            //using all the instances of classes taken
        }
};

int main() {
    
}