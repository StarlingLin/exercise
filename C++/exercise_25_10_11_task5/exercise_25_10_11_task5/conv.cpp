#include "conv.h"

// �ڲ���������
struct SecretCache { /* ... */ };

// ����ʵ��
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