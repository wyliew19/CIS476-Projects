// Author: Will Wylie
// CIS476 - Project 1:
// Singleton + Abstract Factory design
#include <iostream>
#include <vector>

// Industrial sector (Factories)
class AbstractWordFactory {
    public:
        virtual AbstractPanel* createPanel() {}
        virtual AbstractButton* createButton() {}
        virtual AbstractText* createText() {}
};

class ConcWord90Fact : public AbstractWordFactory {
    int instanceCount;
public:
    ConcWord90Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return (AbstractPanel*)(new Panel90());
    }

    AbstractButton* createButton() {
        return (AbstractButton*)(new Button90());
    }

    AbstractText* createText() {
        return (AbstractText*)(new Text90());
    }

    static ConcWord90Fact* getInstance() {

    }
};

class ConcWord00Fact : public AbstractWordFactory {
    int instanceCount;
public:
    ConcWord00Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return (AbstractPanel*)(new Panel00());
    }

    AbstractButton* createButton() {
        return (AbstractButton*)(new Button00());
    }

    AbstractText* createText() {
        return (AbstractText*)(new Text00());
    }

    static ConcWord00Fact* getInstance() {
        
    }
};

class ConcWord10Fact : public AbstractWordFactory {
    int instanceCount;
public:
    ConcWord10Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return (AbstractPanel*)(new Panel10());
    }

    AbstractButton* createButton() {
        return (AbstractButton*)(new Button10());
    }

    AbstractText* createText() {
        return (AbstractText*)(new Text10());
    }

    static ConcWord10Fact* getInstance() {
        
    }
};

class ConcWord24Fact : public AbstractWordFactory {
    int instanceCount;
public:
    ConcWord24Fact() { instanceCount++; }

    AbstractPanel* createPanel() {
        return (AbstractPanel*)(new Panel24());
    }

    AbstractButton* createButton() {
        return (AbstractButton*)(new Button24());
    }

    AbstractText* createText() {
        return (AbstractText*)(new Text24());
    }

    static ConcWord24Fact getInstance() {
        
    }
};


// Panels
class AbstractPanel {
public:
    virtual void printDescription() {};
};

class Panel90 {
public:
    void printDescription() {
        std::cout << "Panel Word90\n";
    }
};

class Panel00 {
public:
    void printDescription() {
        std::cout << "Panel Word00\n";
    }
};

class Panel10 {
public:
    void printDescription() {
        std::cout << "Panel Word10\n";
    }
};

class Panel24 {
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

class Button90 {
public:
    void printDescription() {
        std::cout << "Button Word90\n";
    }
};

class Button00 {
public:
    void printDescription() {
        std::cout << "Button Word00\n";
    }
};

class Button10 {
public:
    void printDescription() {
        std::cout << "Button Word10\n";
    }
};

class Button24 {
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

class Text90 {
public:
    void printDescription() {
        std::cout << "Textbox Word90\n";
    }
};

class Text00 {
public:
    void printDescription() {
        std::cout << "Textbox Word00\n";
    }
};

class Text10 {
public:
    void printDescription() {
        std::cout << "Textbox Word10\n";
    }
};

class Text24 {
public:
    void printDescription() {
        std::cout << "Textbox Word24\n";
    }
};


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
    
}