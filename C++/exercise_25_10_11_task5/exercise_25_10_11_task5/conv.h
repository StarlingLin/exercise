#pragma once

class __declspec(dllexport) PDF { /* ... */ };
class __declspec(dllexport) PNG { /* ... */ };
class __declspec(dllexport) Word { /* ... */ };

#include <memory>

class __declspec(dllexport) Converter
{
public:
    Converter(); 
    ~Converter();        

    Converter(Converter&&) noexcept;
    Converter& operator=(Converter&&) noexcept;

    Converter(const Converter&) = delete;
    Converter& operator=(const Converter&) = delete;

    PDF  word2Pdf();
    PNG  word2Png();
    Word markdown2Word();

private:
    struct Impl;                 // Ç°ÖÃÉùÃ÷
    std::unique_ptr<Impl> p_; 
};