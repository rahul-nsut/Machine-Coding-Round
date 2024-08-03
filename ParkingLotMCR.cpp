// Machine Coding Round Prep-2

// Design of a Parking Lot

class ParkingLot{
    Floor floor; 
    Vehicle vehicle // instance of vehicle we considered is coming as input
    private:
        int parkingLotId;
        vector<floor>Floors;
        int totalFloors;
        int totalCarsCapacity;
        int totalTrucksCapacity;
        int totalBikesCapacity;
    public:
        // let's say we have the slot
        Slot slot;
        void assignVehicleToSlot(vehicle,slot){
            // assign the vehicle.
        }
        void unassignVehicle(vehicle,slot){
            // unassign the vehicle from this slot.
        }
        void addFloor(){
            // add the floors to vector with all info
        }
};

class Vehicle{
    public:
        string typeOfVehicle;
        int vehicleId;
        string company;
        
};

class Floor{
    Slot slot;  //an instance taken
    private:
        int totalSlots;
        int floorId;
        int carsCapacity;
        int trucksCapacity;
        int bikesCapacity;
    public:
        map<slot,bool> slotsInformation; //to track whether this slot is booked or not
        string availableSlot(){
            bool check=0;
            for(auto i:slotsInformation){
                if(i.second==0){
                    cout<<"The slot"<<" "<<i.first.slotId<<" "<<"on floor"<<" "<<floorId<<" "<<"is empty";
                    check=1;
                    return i.first.slotId;
                    break;
                }
            }
            if(!check){
                cout<<"No empty slot on this floor. Please check another floor!"
            }
        }
        void addSlot(){
            // add the slot to current floor ID.
        }
};

class Slot{
    private:
        string slotId;
        bool isFree;
        string typeOfVehicleAllowed;
    public:
        string floorId;
    // constructor->
    public:
        Slot(){
            this->slotId=slotId; // considering these comes from input
            this>-isFreeSlot=isFreeSlot;
            this->typeOfVehicleAllowed=typeOfVehicleAllowed;
        }
};


int main() {
    
}