// Machine Coding Round Prep-5

// Design of Ecommerce App

//Getters and Setters make our code more SOLID Principles oriented..

enum PaymentMethod {
    CashOnDelivery, PrePaid, UPIOndelivery
};

enum ProductCategory {
    Electronics, Apparels, FoodItems
};


class ecommerceSystem{
    private:
        Buyer buyer;
        Product product;
        Order order;
        SellingCompany sellingCompany;
        // to keep track
        map<Order,pair<buyer,product>>successfullOrders;
        set<Buyer> buyerList;
        set<Product>productList;
        set<sellingCompany> sellingCompanyList;
        
        
    public:
        void createBuyer(Buyer buyer){
            // can store all the data by registring a new buyer on the platform.
            if(!buyerList.count(buyer)){
                buyerList.insert(buyer);
            }
            else{
                // can throw error-user already exist
            }
        }
        void createProduct(Product product){
            // can store all the data by registring a new buyer on the platform.
            if(!productList.count(product)){
                productList.insert(product);
            }
            else{
                // can throw error-product already exist
            }
        }
        // can add an extra facility of updating buyer or product information
    
        bool checkPinCodeAvailablity(Product product, Buyer buyer){
            int requestedPinCode=buyer.pinCode;
            if(product.availablePinCodes.count(requestedPinCode)){
                return true;
            }
            else{
                return false;
            }
        }
        void placeOrder(Order order,Product product,Buyer buyer){
            // fill all the reqd details from order
            order.productId=product.productId;
            order.buyerId=buyer.buyerId;   // suggested to use these values coming from getters
            successfullOrders[order]={buyer,product}; // storing all the successfull ones in a map to track
        }
        bool checkOrder(Order order, SellingCompany sellingCompany,Product product){
            // just confirm that there is enough quantity to place the order
            int requiredQuantity=order.quantity;
            int availableQuantity=availableQuantites[product];
            if(availableQuantity>=requiredQuantity){
                return true;
            }
            else{
                return false;
            }
        }
}

class Buyer{
    private:
        int buyerId;
        string buyerName;
        string address;
        int mobileNumber;
        int pinCode;
        
    //defining constructor
    public:
        Buyer(int buyerId,string buyerName,string address,int mobileNumber,int pinCode){
            this.buyerId=buyerId;
            this.buyerName=buyerName;
            this.address=address;
            this.mobileNumber=mobileNumber;
            this.pinCode=pinCode;
        }
    
    // can define getters and setters as well
};
class Product{
    private:
        int productId;
        int price;
        vector<PaymentMethod> allowedPaymentMethods; // To be defined as in ENUMS.
        string productName;
        set<int> availablePinCodes;
        ProductCategory productCategory;  // To be defined as in ENUMS.
        SellingCompany sellingCompany;
};

class SellingCompany{
    private:
        Product product;
        string companyName;
        int companyId;
        string contactPersonName;
        vector<Order> allOrdersReceived;
        map<Product,int> availableQuantites;  
};

class Order{
    private:
        int orderId;
        int productId;
        int buyerId;
        int quantity;
        bool isSuccessful;
        PaymentMode paymentMode;
    
};
int main() {
    
}