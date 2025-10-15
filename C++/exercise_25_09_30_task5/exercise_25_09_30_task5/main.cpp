#include <iostream>
#include <memory>
#include <string>

// �Ա�ӿ�
class IGender
{
public:
    virtual const std::string& text() const = 0;
    virtual ~IGender() = default;
};

// ������
class MaleGender : public IGender
{
public:
    const std::string& text() const override
    {
        static const std::string maleText = "��";
        return maleText;
    }
};

// Ů����
class FemaleGender : public IGender
{
public:
    const std::string& text() const override
    {
        static const std::string femaleText = "Ů";
        return femaleText;
    }
};

// �򵥹���
class GenderFactory
{
public:
    enum class GenderType
    {
        Male,
        Female
    };

    static std::unique_ptr<IGender> createGender(GenderType type)
    {
        switch (type)
        {
        case GenderType::Male:
            return std::make_unique<MaleGender>();
        case GenderType::Female:
            return std::make_unique<FemaleGender>();
        default:
            return nullptr;
        }
    }
};

int main()
{
    // ���ݲ�ͬ���봴����ͬ�Ա����
    auto male = GenderFactory::createGender(GenderFactory::GenderType::Male);
    auto female = GenderFactory::createGender(GenderFactory::GenderType::Female);

    std::cout << male->text() << std::endl;   // �������
    std::cout << female->text() << std::endl; // �����Ů

    return 0;
}
