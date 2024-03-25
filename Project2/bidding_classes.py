class Handler:
    def __init__(self):
        self.successor = None

    def set_successor(self, successor):
        self.successor = successor

    def handle_request(self, request):
        pass

class SuiteHandler(Handler):
    def __init__(self):
        super().__init__()
        self.available_rooms = 10
        self.min_price = 280

    def handle_request(self, request):
        if request >= self.min_price and self.available_rooms > 0:
            self.available_rooms -= 1
            return "Suite booked successfully!"
        elif self.successor is not None:
            return self.successor.handle_request(request)
        else:
            return "No rooms available!"

class DeluxeHandler(Handler):
    def __init__(self):
        super().__init__()
        self.available_rooms = 15
        self.min_price = 150

    def handle_request(self, request):
        if request >= self.min_price and self.available_rooms > 0:
            self.available_rooms -= 1
            return "Deluxe room booked successfully!"
        elif self.successor is not None:
            return self.successor.handle_request(request)
        else:
            return "No rooms available!"

class StandardHandler(Handler):
    def __init__(self):
        super().__init__()
        self.available_rooms = 45
        self.min_price = 80

    def handle_request(self, request):
        if request >= self.min_price and self.available_rooms > 0:
            self.available_rooms -= 1
            return "Standard room booked successfully!"
        elif self.successor is not None:
            return self.successor.handle_request(request)
        else:
            return "No rooms available!"
        