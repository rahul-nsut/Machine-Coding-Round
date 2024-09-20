// Machine Coding Round Prep-11

// Design of Movie ticket booking system

//Getters and Setters make our code more SOLID Principles oriented..

class MovieTickcetSystem{
    private:
        map<Movie,set<Theatre>> movieAvaialblePlaces;
        map<Theater,set<Movie>> moviesInTheatre;
        map<Movie,set<movieShow>> availableMovieShows;
        
    
        void exploreAvaiableTheaters(Movie movie){
            // for a movie, in which theaters has it been put up
            for(auto i:movieAvaialblePlaces){
                if(i.first==movie){
                    for(auto j:i.second){
                        cout<<j<<" ";
                    }
                }
            }
        }
        
        void addMovieShow(Movie movie,movieShow show){
            // added all the details of show reqd.
            movie.insert(show);
        }
        
        int NoOfAvailableSeats(Movie movie, movieShow show){
            int countOfSeats=0;
            for(auto i:availableMovieShows){
                if(i.first==movie){
                    for(auto j:i.second){
                        if(j.isBooked==0) countOfSeats++;
                    }
                }
            }
            return countOfSeats;
        }
    
        void bookASeat(User user, Movie movie, movieShow show, Seat seat){
            
            for(auto i:show){
                auto seatsVector=show.seats;
                for(auto j:seatsVector){
                    if(j==seat){
                        if(j.isBooked==1){
                            cout<< "Sorry, the seat is already booked!";
                        }
                        else{
                            j.isBooked=1;
                            j.occupiedBy=user;
                        }
                    }
                }
            }
        }
        
        void cancelASeat(User user, Movie movie, movieShow show, Seat seat){
            for(auto i:show){
                auto seatsVector=show.seats;
                for(auto j:seatsVector){
                    if(j==seat){
                        //now vacant for other users.
                        j.isBooked=0;
                        j.occupiedBy=NULL;
                    }
                }
            }
        }
    
        void setTicketPrice(Theatre theatre, movieShow show, Seat seat,int amount){
            seat.price=amount;
        }
    
        void showMovieTimings(movieShow show){
            cout<<"The movie starts at "<<startTime<<" and will end at "<<endTime<<endl; 
        }
        
    
};

class movieShow{
    private:
        Movie movie;
        Theatre theatre;
        Data date;
        Time startTime;
        Time endTme;
        vector<Seat>seats;
        
};


class User{
    private:
        string name;
        int userId;
        int mobileNumber;
        int role; //define in ENUMS-> producer,casting,spectator
};


class Movie{
    private:
        string title;
        Date dateOfRelease;
        vector<User>cast;
        vector<User>producers;
        User director;
        
};

class Seat{
    private:
        int seatId;
        string typeOfSeat; // gold,platinum,silver -> can define in ENUMS
        int price;
        bool isBooked;
        User occupiedBy; // NULL if it has not been booked.
        int rowNumber;
        int colNumber;
};


class Theatre{
    private:
        string name;
        int theatreId;
        User theatreAdmin;
        set<Movie>currentPostedMvies;      
};

int main() {
    
}