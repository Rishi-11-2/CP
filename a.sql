CREATE TABLE Customer (
    Customer_ID VARCHAR(50) PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Address VARCHAR(255),
    Phone_Number VARCHAR(15)
);

CREATE TABLE Car (
    Car_ID VARCHAR(50) PRIMARY KEY,
    Customer_ID VARCHAR(50) NOT NULL,
    Make VARCHAR(50) NOT NULL,
    Model VARCHAR(50) NOT NULL,
    Purchase_Date DATE NOT NULL,
    FOREIGN KEY (Customer_ID) REFERENCES Customer(Customer_ID)
);

CREATE TABLE Insurance_Policy (
    Policy_ID VARCHAR(50) PRIMARY KEY,
    Policy_Name VARCHAR(100) NOT NULL,
    Coverage_Details TEXT
);

CREATE TABLE Policy_Car (
    Policy_ID VARCHAR(50) NOT NULL,
    Car_ID VARCHAR(50) NOT NULL,
    PRIMARY KEY (Policy_ID, Car_ID),
    FOREIGN KEY (Policy_ID) REFERENCES Insurance_Policy(Policy_ID),
    FOREIGN KEY (Car_ID) REFERENCES Car(Car_ID)
);

CREATE TABLE Premium_Payment (
    Payment_ID VARCHAR(50) PRIMARY KEY,
    Policy_ID VARCHAR(50) NOT NULL,
    Payment_Amount DECIMAL(15, 2) NOT NULL,
    Payment_Date DATE NOT NULL,
    Due_Date DATE NOT NULL,
    Payment_Received_Date DATE,
    FOREIGN KEY (Policy_ID) REFERENCES Insurance_Policy(Policy_ID)
);
