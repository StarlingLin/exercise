#include <iostream>
#include <memory>
#include <string>

// 性别接口
class IGender
{
public:
    virtual const std::string& text() const = 0;
    virtual ~IGender() = default;
};

// 男性类
class MaleGender : public IGender
{
public:
    const std::string& text() const override
    {
        static const std::string maleText = "男";
        return maleText;
    }
};

// 女性类
class FemaleGender : public IGender
{
public:
    const std::string& text() const override
    {
        static const std::string femaleText = "女";
        return femaleText;
    }
};

// 简单工厂
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
    // 根据不同输入创建不同性别对象
    auto male = GenderFactory::createGender(GenderFactory::GenderType::Male);
    auto female = GenderFactory::createGender(GenderFactory::GenderType::Female);

    std::cout << male->text() << std::endl;   // 输出：男
    std::cout << female->text() << std::endl; // 输出：女

    return 0;
}
