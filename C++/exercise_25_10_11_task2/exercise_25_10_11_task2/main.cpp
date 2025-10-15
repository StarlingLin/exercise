#include <iostream>
#include <functional>
#include <vector>
#include <memory>

class Person
{
public:
    int  birthYear()  const { return mBirthYear; }
    int  birthMonth() const { return mBirthMonth; }
    int  workYear()   const { return mWorkYear; }
    int  workMonth()  const { return mWorkMonth; }

    double basicMoney()      const { return mBasicMoney; }
    double selfMoney()       const { return mSelfMoney; }
    double adjustMoney()     const { return mAdjustMoney; }
    double enterpriseMoney() const { return mEnterpriseMoney; }

private:
    friend class SimplePersonBuilder;

    Person() = default;

    int mBirthYear{};
    int mBirthMonth{};
    int mWorkYear{};
    int mWorkMonth{};

    double mBasicMoney{};
    double mSelfMoney{};
    double mAdjustMoney{};
    double mEnterpriseMoney{};
};

class PersonBuilder
{
public:
    virtual ~PersonBuilder() = default;

    virtual void reset(int by, int bm, int wy, int wm) = 0;
    virtual void buildBasic() = 0;
    virtual void buildSelf() = 0;
    virtual void buildAdjust() = 0;
    virtual void buildEnterprise() = 0;

    virtual std::unique_ptr<Person> getResult() = 0;
};

class SimplePersonBuilder : public PersonBuilder
{
public:
    using Compute = std::function<double(const Person&)>;

    // …Ë÷√/ÃÊªªπÊ‘Ú
    void setBasicRule(Compute f) { basicRule_ = std::move(f); }
    void setSelfRule(Compute f) { selfRule_ = std::move(f); }
    void setAdjustRule(Compute f) { adjustRule_ = std::move(f); }
    void setEnterpriseRule(Compute f) { enterpriseRule_ = std::move(f); }

    void reset(int by, int bm, int wy, int wm) override
    {
        p_ = std::make_unique<Person>();
        p_->mBirthYear = by;
        p_->mBirthMonth = bm;
        p_->mWorkYear = wy;
        p_->mWorkMonth = wm;
        p_->mBasicMoney = 0.0;
        p_->mSelfMoney = 0.0;
        p_->mAdjustMoney = 0.0;
        p_->mEnterpriseMoney = 0.0;
    }

    void buildBasic() override
    {
        ensure();
        if (basicRule_) p_->mBasicMoney = basicRule_(*p_);
    }

    void buildSelf() override
    {
        ensure();
        if (selfRule_) p_->mSelfMoney = selfRule_(*p_);
    }

    void buildAdjust() override
    {
        ensure();
        if (adjustRule_) p_->mAdjustMoney = adjustRule_(*p_);
    }

    void buildEnterprise() override
    {
        ensure();
        if (enterpriseRule_) p_->mEnterpriseMoney = enterpriseRule_(*p_);
    }

    std::unique_ptr<Person> getResult() override
    {
        ensure();
        return std::move(p_);
    }

private:
    void ensure()
    {
        if (!p_) throw std::logic_error("call reset() first");
    }

    std::unique_ptr<Person> p_;
    Compute basicRule_, selfRule_, adjustRule_, enterpriseRule_;
};

class PersonDirector
{
public:
    enum class Step { Basic, Self, Adjust, Enterprise };

    void setOrder(std::vector<Step> order)
    {
        order_ = std::move(order);
    }

    std::unique_ptr<Person> construct(PersonBuilder& b,
        int by, int bm, int wy, int wm)
    {
        b.reset(by, bm, wy, wm);
        for (auto s : order_)
        {
            switch (s)
            {
            case Step::Basic:      b.buildBasic(); break;
            case Step::Self:       b.buildSelf(); break;
            case Step::Adjust:     b.buildAdjust(); break;
            case Step::Enterprise: b.buildEnterprise(); break;
            }
        }
        return b.getResult();
    }

private:
    std::vector<Step> order_{ Step::Basic, Step::Self, Step::Adjust, Step::Enterprise };
};