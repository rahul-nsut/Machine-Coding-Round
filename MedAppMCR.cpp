// Machine Coding Round Prep-2

// Design of a Medical app to book doctors (Flipkart SDE Interview)

// the major class->
class MedAppSystem{
    private:
        vector<Doctor,vector<Slot>> currentAvailableSlots;
        Doctor doctor;
        Patient patient;
        Slot slot;
        Booking booking;
    public:
        void registerDoctor(Doctor newDoctor){
            // here just add all details of doctor which are being required to initialise a doctor
        }
        void addSlots(Doctor d,Slot s){
            d.slotDetails[s]=1;   // mark the map in boolean as true for the slot.
        }
        void displayDoctorsOfSpeciality(string speciality){
            // consider that we are having 
            for(auto i:currentAvailableSlots){
                if(i.first.specialisation==speciality){
                    cout<<i.first.doctorName<<" ";
                }
            }
        }
        // Many users have specific interest with a doctor. So they can check if the doctor is available
        bool isDoctorAvaialble(Doctor d,Slot s){
            return d.slotDetails[s];
        }
        void mostSuitableDoctor(string speciality,Doctor d){
            // will loop through avaiable doctors map,match the speciality and return the 1st free doctor.
            //As we are already considering it is arranged in form of rating.
            // Can achieve this by using a priority queue or set
        }
};

class Doctor{
    private:
        int doctorId;
        string specialisation;
        string doctorName;
        int rating; // Stars out of 5.
        map<Patient,Slot> patientBookedSlots; // mapping of patient to the booked time slot;
        map<Slot,bool> slotDetails;  // to tell if slot is empty
        vector<Patient> patientsInWaitlist;
    
    //Can define getters and setters
};
void Doctor::bookSlot(Patient& patient, Slot slot) {
    if (isSlotAvailable(slot)) {
        availableSlots.erase(slot);
        patientBookedSlots[patient] = slot;
        patient.bookSlot(doctorId, slot);
    } else {
        patientsInWaitlist.push_back(patient);
    }
}

void Doctor::cancelBooking(Patient& patient, Slot slot) {
    availableSlots.insert(slot);
    patientBookedSlots.erase(patient);
    patient.cancelSlot(doctorId);
}
class Patient{
    private:
        string patientName;
        int patientId;
        map<Doctor,Slot> bookedSlots;
};
class Slot{
    private:
        string startTime;
        string endTime;
    //Can define getters and setters
    //Also can define the constructors..
    public:
        void getStartTime(){
            cout<<startTime<<" " ;
        }
        void getEndTime(){
                cout<<endTime<<" " ;
        }
        
};
class Booking{
    private:
        Doctor doctor;
        Patient patient;
        Slot slot;  
        bool isWaitlisted;
        int bookingId;
    // can define the constructors..
    public:
        void bookASlot(doctor,patient,slot){
            // means the slot is free, just directly add the patient
            if(doctor.slotDetails[slot]==0){
                doctor.slotDetails[slot]=1;
                doctor.patientBookedSlots[patient]=slot;
            }
            else{
                // need to add in the waitlist
                doctor.patientsInWaitlist.push_back(patient);
            }
        }
};
int main() {
    
}