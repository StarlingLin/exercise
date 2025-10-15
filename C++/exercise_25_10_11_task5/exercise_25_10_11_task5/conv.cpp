#include "conv.h"

// 内部保密类型
struct SecretCache { /* ... */ };

// 真正实现
struct Converter::Impl
{
    SecretCache cache;
    PDF  word2Pdf() { /* ... */ }
    PNG  word2Png() { /* ... */ }
    Word markdown2Word() { /* ... */ }
};

Converter::Converter()
    : p_(std::make_unique<Impl>())
{
}

Converter::~Converter() = default;

Converter::Converter(Converter&&) noexcept = default;
Converter& Converter::operator=(Converter&&) noexcept = default;