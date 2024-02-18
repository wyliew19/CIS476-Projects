// Author: Will Wylie
// CIS476 - Project 1:
// Singleton + Abstract Factory design
#include <iostream>
#include <fstream>

// File name for generation testing
const char* FILENAME = "input.txt";


// Panels
class AbstractPanel {
public:
    virtual void printDescription() {};
};

class Panel90 : public AbstractPanel{
public:
    void printDescription() {
        std::cout << "Panel Word90\n";
    }
};

class Panel00 : public AbstractPanel {
public:
    void printDescription() {
        std::cout << "Panel Word00\n";
    }
};

class Panel10 : public AbstractPanel {
public:
    void printDescription() {
        std::cout << "Panel Word10\n";
    }
};

class Panel24 : public AbstractPanel {
public:
    void printDescription() {
        std::cout << "Panel Word24\n";
    }
};


// Buttons
class AbstractButton {
public:
    virtual void printDescription() {};
};

class Button90 : public AbstractButton {
public:
    void printDescription() {
        std::cout << "Button Word90\n";
    }
};

class Button00 : public AbstractButton {
public:
    void printDescription() {
        std::cout << "Button Word00\n";
    }
};

class Button10 : public AbstractButton {
public:
    void printDescription() {
        std::cout << "Button Word10\n";
    }
};

class Button24 : public AbstractButton {
public:
    void printDescription() {
        std::cout << "Button Word24\n";
    }
};


// Textboxes
class AbstractText {
public:
    virtual void printDescription() {};
};

class Text90 : public AbstractText {
public:
    void printDescription() {
        std::cout << "Textbox Word90\n";
    }
};

class Text00 : public AbstractText {
public:
    void printDescription() {
        std::cout << "Textbox Word00\n";
    }
};

class Text10 : public AbstractText {
public:
    void printDescription() {
        std::cout << "Textbox Word10\n";
    }
};

class Text24 : public AbstractText {
public:
    void printDescription() {
        std::cout << "Textbox Word24\n";
    }
};


// Industrial sector (Factories)
class AbstractWordFactory {
    public:
        virtual AbstractPanel* createPanel() = 0;
        virtual AbstractButton* createButton() = 0;
        virtual AbstractText* createText() = 0;
};

class ConcWord90Fact : public AbstractWordFactory {
    static int instanceCount;
public:
    ConcWord90Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return new Panel90();
    }

    AbstractButton* createButton() {
        return new Button90();
    }

    AbstractText* createText() {
        return new Text90();
    }

    static ConcWord90Fact* getInstance() {
        if (instanceCount < 2) {
            return new ConcWord90Fact();
        } else {
            return nullptr;
        }
    }
};

class ConcWord00Fact : public AbstractWordFactory {
    static int instanceCount;
public:
    ConcWord00Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return new Panel00();
    }

    AbstractButton* createButton() {
        return new Button00();
    }

    AbstractText* createText() {
        return new Text00();
    }

    static ConcWord00Fact* getInstance() {
        if (instanceCount < 2) {
            return new ConcWord00Fact();
        } else {
            return nullptr;
        }
    }
};

class ConcWord10Fact : public AbstractWordFactory {
    static int instanceCount;
public:
    ConcWord10Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return new Panel10();
    }

    AbstractButton* createButton() {
        return new Button10();
    }

    AbstractText* createText() {
        return new Text10();
    }

    static ConcWord10Fact* getInstance() {
        if (instanceCount < 2) {
            return new ConcWord10Fact();
        } else {
            return nullptr;
        }
    }
};

class ConcWord24Fact : public AbstractWordFactory {
    static int instanceCount;
public:
    ConcWord24Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return new Panel24();
    }

    AbstractButton* createButton() {
        return new Button24();
    }

    AbstractText* createText() {
        return new Text24();
    }

    static ConcWord24Fact* getInstance() {
        if (instanceCount < 2) {
            return new ConcWord24Fact();
        } else {
            return nullptr;
        }
    }
};
int ConcWord90Fact::instanceCount = 0;
int ConcWord00Fact::instanceCount = 0;
int ConcWord10Fact::instanceCount = 0;
int ConcWord24Fact::instanceCount = 0;


// Client and main()
class Client {
    AbstractPanel* panel;
    AbstractButton* button;
    AbstractText* text;
public:
    Client(AbstractWordFactory* factory) {
        panel = factory->createPanel();
        button = factory->createButton();
        text = factory->createText();
    }

    void run() {
        panel->printDescription();
        button->printDescription();
        text->printDescription();
    }

};

int main() {
    // Open file
    std::ifstream file(FILENAME);

    // Check if file is open
    if (file.is_open()) {
        std::string line;
        // Read file
        while (std::getline(file, line)) {
            AbstractWordFactory* factory;
            // Parse line
            if (line.compare("Word90") == 0) {
                factory = ConcWord90Fact::getInstance();
            } else if (line.compare("Word00") == 0) {
                factory = ConcWord00Fact::getInstance();
            } else if (line.compare("Word10") == 0){
                factory = ConcWord10Fact::getInstance();
            } else if (line.compare("Word24") == 0) {
                factory = ConcWord24Fact::getInstance();
            } else {
                std::cout << "Invalid input: " << line << std::endl;
                continue;
            }
            // Check if factory is null (too many instances of a generation)
            if (factory == nullptr) {
                std::cout << "Warning: Cannot make more than 2 instances of a generation\n" << std::endl;
                continue;
            }
            // Create and run client
            Client* client = new Client(factory);
            client->run();
            std::cout << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
        return 1;
    }

    return 0;
}