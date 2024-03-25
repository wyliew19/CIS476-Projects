```mermaid
classDiagram
    class BidRequest {
        +double bidPrice
        +BidRequest(double bidPrice)
        +double getBidPrice()
    }
    class Handler {
        +Handler successor
        +void setSuccessor(Handler successor)
        +abstract boolean handleRequest(BidRequest request)
    }
    class SuiteHandler {
        -int availableRooms = 10
        -double minPrice = 280
        +SuiteHandler()
        +boolean handleRequest(BidRequest request)
    }
    class DeluxeHandler {
        -int availableRooms = 15
        -double minPrice = 150
        +DeluxeHandler()
        +boolean handleRequest(BidRequest request)
    }
    class StandardHandler {
        -int availableRooms = 45
        -double minPrice = 80
        +StandardHandler()
        +boolean handleRequest(BidRequest request)
    }
    class GUI {
        +void enterBidPrice(double price)
        +void displayOutcome(String message)
    }
    BidRequest "1" --> "1" Handler : makes
    Handler <|-- SuiteHandler
    Handler <|-- DeluxeHandler
    Handler <|-- StandardHandler
    SuiteHandler "1" --> "1" DeluxeHandler : next
    DeluxeHandler "1" --> "1" StandardHandler : next
    GUI --> BidRequest : creates
    GUI --> Handler : interacts
    ```