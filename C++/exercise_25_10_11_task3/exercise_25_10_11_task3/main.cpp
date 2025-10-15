#include <iostream>
#include <memory>

struct IButton
{
    virtual ~IButton() = default;
    virtual void draw() = 0;
};

struct IText
{
    virtual ~IText() = default;
    virtual void draw() = 0;
};

struct GUIFactory
{
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<IButton> createButton() = 0;
    virtual std::unique_ptr<IText>   createText() = 0;
};

class WinButton : public IButton
{
public:
    void draw() override
    {
        std::cout << "Draw WinButton\n";
    }
};

class WinText : public IText
{
public:
    void draw() override
    {
        std::cout << "Draw WinText\n";
    }
};

class WinFactory : public GUIFactory
{
public:
    std::unique_ptr<IButton> createButton() override
    {
        return std::make_unique<WinButton>();
    }
    std::unique_ptr<IText> createText() override
    {
        return std::make_unique<WinText>();
    }
};

class LinuxButton : public IButton
{
public:
    void draw() override
    {
        std::cout << "Draw LinuxButton\n";
    }
};

class LinuxText : public IText
{
public:
    void draw() override
    {
        std::cout << "Draw LinuxText\n";
    }
};

class LinuxFactory : public GUIFactory
{
public:
    std::unique_ptr<IButton> createButton() override
    {
        return std::make_unique<LinuxButton>();
    }
    std::unique_ptr<IText> createText() override
    {
        return std::make_unique<LinuxText>();
    }
};

class MacButton : public IButton
{
public:
    void draw() override
    {
        std::cout << "Draw MacButton\n";
    }
};

class MacText : public IText
{
public:
    void draw() override
    {
        std::cout << "Draw MacText\n";
    }
};

class MacFactory : public GUIFactory
{
public:
    std::unique_ptr<IButton> createButton() override
    {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<IText> createText() override
    {
        return std::make_unique<MacText>();
    }
};

int main()
{
    std::unique_ptr<GUIFactory> factory = std::make_unique<LinuxFactory>();

    auto btn = factory->createButton();
    auto text = factory->createText();

    btn->draw(); 
    text->draw(); 

    return 0;
}
