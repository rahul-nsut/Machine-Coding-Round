// Machine Coding Round Prep-9

// Design of a Cricbuzz or Live Scoring App (Asked in Udaan)

// can define separately- constructors, getters and setters as reqd


class cricbuzzSystem{
    private:
        Match match;
        Team team;
        vector<Match> currentLiveMatches;
        vector<Team> teams;
        
        void addMatch(Match match){
            if(match.isLive==1){
                currentLiveMatches.push_back(match);
            }
            else{
                cout<<"Match is not currently live!";
            }
        }
        
        void setMatchLive(Match match){
            match.isLive=1;  //Similarly can add to unset live status.
        }
        
        void addTeam(Team team){
            teams.push_back(team);
        }
    
        void addPlayerInTeam(Team team, Player player){
            if(team.players.count(player)){
                cout<<"The Player is already a part of this team";
            }
            else{
                team.players.insert(player);
            }
        }
    
        void addOfficial(Match match,Official official){
            match.involvedOfficials.push_back(official);
        }
    
        void displayMatchFormat(Match match){
            string format=Match.formatOfMatch;
            cout<<"This match is going on in "<<format<<" format";
        }
    
    
};


class Match{
    private:
        int matchId;
        string date;
        Team team1;
        Team team2;  // data of the teams participating.
        vector<Offical> involvedOfficials;
        string formatOfMatch;  //defined as ENUMS-ODI,T20,Test
        vector<Inning>innings; // can be 2 or 4, depending upon match
        string typeOfMatch;  //means-international,IPL or any other tournament in it.
        string matchLocation;  // includes ground & country name
        bool isLive; //will only add live matches in display list
    
};

class Team{
    private:
        string teamName;
        bool isACountry; //to keep track of international matches separately
        Player captain;
        set<Player> players;
};

class Player{
    private:
        string playerName;
        int age;
        string role; //define as ENUMS-batsman, bowler, allrounder
        double strikeRate;
        int currentScore;  //can be used while we create the instance
        int oversBowled;
        int runsConceeded;

        //can add more stats members as per reqd.. 
        
};

class Inning{
    private:
        int totalOvers;
        double runRate;
        // we must also know which team is currently batting or bowling;
        Team battingTeam;
        Team bowlingTeam;
        bool isFirstInning;  // 1 if 1st,else 2nd
        vector<Over>overs;
        
};

class Over{
    private:
        int overNumber;
        vector<Ball>balls;
        Player bowledBy;
}

class Ball{
    private:
        string typeOfBall;
        Player playedBy;
        Player bowledBy;
        double ballSpeed;
        Wicket wicket; // optional, if out only then consider it. keep as NULL if not a wicket on this ball
        
};

class Wicket{
    private:
        string wicketType;  //can define in enums-bowled,lbw,etc
        Player bowler;
        Player batsman;
        //can keep track of catch or runout as well..
};

class Official{
    private:
        string name;
        int age;
        int officialId;
        string title; // umpire,3rd umpire,referee->define in ENUMS
        bool isOnField;
};


int main() {
     
    
}